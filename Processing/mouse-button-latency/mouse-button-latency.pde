import processing.serial.*;

Serial myPort;

void setup() {
  size(480, 120);
  myPort = new Serial(this, Serial.list()[2], 115200);
}

void draw() {
  if(mousePressed) {
    myPort.write(65);
  }
  while(myPort.available() > 0)
    print(char(myPort.read()));
}

