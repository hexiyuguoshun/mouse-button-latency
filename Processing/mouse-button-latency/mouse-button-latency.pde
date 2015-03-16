import processing.serial.*;

Serial myPort;
boolean receiving = false;

void setup() {
  size(480, 120);
  myPort = new Serial(this, Serial.list()[2], 115200);
}

void draw() {
  if(mousePressed && receiving == false) {
    myPort.write(65);
    receiving = true;
  }
  if(receiving == true) {
    if(myPort.available() > 0) {
      while(myPort.available() > 0)
        print(char(myPort.read()));
      receiving = false;
    }
  }
}

