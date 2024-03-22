#define TIMER_INTERRUPT_DEBUG         2
#define _TIMERINTERRUPT_LOGLEVEL_     0

#define USE_TIMER_1     true

#if ( defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)  || \
        defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO) || defined(ARDUINO_AVR_MINI) ||    defined(ARDUINO_AVR_ETHERNET) || \
        defined(ARDUINO_AVR_FIO) || defined(ARDUINO_AVR_BT)   || defined(ARDUINO_AVR_LILYPAD) || defined(ARDUINO_AVR_PRO)      || \
        defined(ARDUINO_AVR_NG) || defined(ARDUINO_AVR_UNO_WIFI_DEV_ED) || defined(ARDUINO_AVR_DUEMILANOVE) || defined(ARDUINO_AVR_FEATHER328P) || \
        defined(ARDUINO_AVR_METRO) || defined(ARDUINO_AVR_PROTRINKET5) || defined(ARDUINO_AVR_PROTRINKET3) || defined(ARDUINO_AVR_PROTRINKET5FTDI) || \
        defined(ARDUINO_AVR_PROTRINKET3FTDI) )
  #define USE_TIMER_2     false
  #warning Using Timer1, Timer2
#else          
  #define USE_TIMER_3     false
  #warning Using Timer1, Timer3
#endif

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "TimerInterrupt.h"

#if !defined(LED_BUILTIN)
  #define LED_BUILTIN     13
#endif

#if USE_TIMER_1

void TimerHandler1(unsigned int outputPin = LED_BUILTIN)
{
  static bool toggle1 = false;

#if (TIMER_INTERRUPT_DEBUG > 1)
  Serial.print("ITimer1 called, millis() = "); Serial.println(millis());
#endif

  //timer interrupt toggles pin LED_BUILTIN
  digitalWrite(outputPin, toggle1);
  toggle1 = !toggle1;
}

#endif

#if (USE_TIMER_2 || USE_TIMER_3)

void TimerHandler(unsigned int outputPin = LED_BUILTIN)
{
  static bool toggle = false;

#if (TIMER_INTERRUPT_DEBUG > 1)
  #if USE_TIMER_2
    Serial.print("ITimer2 called, millis() = ");
  #elif USE_TIMER_3
    Serial.print("ITimer3 called, millis() = ");
  #endif
  
  Serial.println(millis());
#endif

  //timer interrupt toggles outputPin
  digitalWrite(outputPin, toggle);
  toggle = !toggle;
}

#endif

unsigned int outputPin1 = LED_BUILTIN;
unsigned int outputPin  = A0;

#define USING_LOOP_TEST       false

#define TIMER1_INTERVAL_MS    1000
#define TIMER1_FREQUENCY      (float) (1000.0f / TIMER1_INTERVAL_MS)

#define TIMER_INTERVAL_MS     2000
#define TIMER_FREQUENCY       (float) (1000.0f / TIMER_INTERVAL_MS)


#if USING_LOOP_TEST
  #define TIMER1_DURATION_MS    (10UL * TIMER1_INTERVAL_MS)
  #define TIMER_DURATION_MS     (20UL * TIMER_INTERVAL_MS)
#else
  #define TIMER1_DURATION_MS    0
  #define TIMER_DURATION_MS     0
#endif




#include <LiquidCrystal_I2C.h>
#include <TimerInterrupt.h>


#define INTERRUPT_INTERVAL_MS 500 
LiquidCrystal_I2C lcd(0x27, 16,2);
short volatile year=0, month=0, day=0, hours=0, minutes=0, seconds=0, mill_seconds=0;
bool volatile reading_time = false, lcd_outdated;
short volatile month_lens[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char* months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

void setup()
{
  Serial.begin(9600);
  Serial.println("Running setup()");
  lcd.init();
  delay(500);
  ITimer1.init();
  if(ITimer1.attachInterruptInterval(INTERRUPT_INTERVAL_MS, on_timer_interrupt))
  {
    Serial.println("Timer interrupt attached successfully");
  }
  else
    Serial.println("Timer interrupt attachment failed");

}

void loop()
{
  //Check if data is arriving from serial to set the time
  //We expect 19 characters as the time format
  if(Serial.available() >= 19)
  {
    Serial.println("Found some data");
    reading_time = true;
    read_time();
    reading_time = false;
  }
  if(lcd_outdated) 
  {
    update_lcd();
    lcd_outdated = false;
  }

}

void read_time()
{
  year = 0; month = 0; day = 0; hours = 0; minutes = 0; seconds = 0; mill_seconds = 0;
  year = Serial.parseInt();
  month = Serial.parseInt() - 1;
  day = Serial.parseInt() - 1;
  hours = Serial.parseInt();
  minutes = Serial.parseInt();
  seconds = Serial.parseInt();
  Serial.println("Just read the time and this is what I have:");
  Serial.println(year);
  Serial.println(month);
  Serial.println(day);
  Serial.println(hours);
  Serial.println(minutes);
  Serial.println(seconds);
  Serial.println();
}

void on_timer_interrupt()
{
  if (reading_time) return;
  mill_seconds += INTERRUPT_INTERVAL_MS;
  if(mill_seconds >= 1000)
  {
    lcd_outdated = true;
    update_time();
  }
}

void update_time()
{

  //Update LCD time
  seconds += mill_seconds / 1000;
  mill_seconds %= 1000;
  if(seconds >= 60) Serial.print("Increamenting mintues | ");
  minutes += seconds / 60;
  seconds %= 60;
  if(minutes >= 60) Serial.print("Increamenting hours | ");
  hours += minutes / 60;
  minutes %= 60;
  if(hours >= 24) Serial.print("Increamenting day | ");
  day += hours / 24;
  hours %= 24;
  //Incrementing month
  short month_len;
  if(month == 1 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)))//If it's February and a leap year
    month_len = 29;
  else month_len = month_lens[month];
  if(day >= month_len) Serial.print("Increamenting month | ");
  month += day / month_len;
  day %= month_len;
  if(month >= 12) Serial.print("Increamenting year\n");
  year += month / 12;
  month %= 12;
}

void update_lcd()
{
  char date[17];
  char time[17];
  sprintf(date, "%04d-%s-%02d", year, months[month], day+1);
  sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);
  lcd.setCursor(2,0);
  lcd.print(date);
  lcd.setCursor(4,1);
  lcd.print(time);
}