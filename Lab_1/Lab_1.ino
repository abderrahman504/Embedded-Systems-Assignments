int button_pin = 2, green_led = 12, red_led = 13;


void setup() {
  	pinMode(button_pin, INPUT);
    pinMode(green_led, OUTPUT);
    pinMode(red_led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  int switch_state = debounce(button_pin);
  digitalWrite(green_led, switch_state);
  digitalWrite(red_led, !switch_state);
}

// void toggleLED(){
//   red_state = !red_state;
//   green_state = !green_state;
  
//   digitalWrite(red_led, red_state);
//   digitalWrite(green_led, green_state);
// }


boolean debounce(int pin){
  int state, prev_state;
  prev_state = digitalRead(pin);
  for(int i=0; i < 10; i++){
    delay(1);
    state = digitalRead(pin);
    if(state != prev_state) i = 0;
    prev_state = state;
  }
  return state;
}
