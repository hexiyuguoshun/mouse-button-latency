unsigned long startMillis;
int currentState, lastState = HIGH;

void setup() {
  Mouse.begin();
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  currentState = digitalRead(2);
  if(currentState == LOW && lastState == HIGH) {
    startMillis = millis();
    Mouse.press();
    while(!(Serial.available() > 0) );
    while(Serial.available() > 0)
      Serial.read();
    Mouse.release();
    Serial.println(millis() - startMillis);
  }
  lastState = currentState;
}
