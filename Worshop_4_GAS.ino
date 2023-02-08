int Gas_analog = 4;    // used for ESP32

void setup() {
  Serial.begin(115200);
}

void loop() {
  int gassensorAnalog = analogRead(Gas_analog);
  Serial.println(gassensorAnalog);
  delay(100);
}
