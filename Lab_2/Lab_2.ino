int in_pin = A5, led_pin = 9;


void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(9800);
}

void loop() {
  float in_percentage = analogRead(in_pin) / 1024.0;
  Serial.println(in_percentage);
  analogWrite(led_pin, 255*in_percentage);
}
