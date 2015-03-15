unsigned long startMicros;
int currentState, lastState = HIGH;

void setup() {
  Mouse.begin();
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  currentState = digitalRead(2);
  if(currentState == LOW && lastState == HIGH) {
    startMicros = micros();
    Mouse.click();
    while(!(Serial.available() > 0) ) {
      if(micros() - startMicros > 1000000)
        break;
    }
    Serial.println(micros() - startMicros);
    delay(10);
  }
  lastState = currentState;
}
