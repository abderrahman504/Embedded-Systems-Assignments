int button_pin = 2, green_led = 12, red_led = 13, green_state = LOW, red_state = HIGH;
boolean button_held = false;

void setup() {
  	pinMode(button_pin, INPUT);
    pinMode(green_led, OUTPUT);
    pinMode(red_led, OUTPUT);
    digitalWrite(red_led, red_state);
  	digitalWrite(green_led, green_state);
}

void loop() {
  int button_state = debounce(button_pin);
  //just pressed
  if(!button_held && button_state == HIGH){
    toggleLED();
    button_held = true;
  }
  //just released
  else if(button_held && button_state == LOW) button_held = false;
  
}

void toggleLED(){
  red_state = !red_state;
  green_state = !green_state;
  
  digitalWrite(red_led, red_state);
  digitalWrite(green_led, green_state);
}


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
