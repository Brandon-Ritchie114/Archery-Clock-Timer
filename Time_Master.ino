 #include "functions.h"
// Written by Brandon Ritchie
// At SJSU, 1/23/25
//buttons 40, 78,75
void setup()
{
  Serial.begin(115200);
  while (!Serial); // Wait for the serial monitor to connect

  // Initialize USB Host
  if (Usb.Init() == -1) {
    Serial.println("USB Initialization Failed");

    while (1) { // error code of E10
      seconds.outputNum(-1);
      tens.outputNum(1);
      minutes.outputNum(0);
    }
  }
  // Attach parser
    Hid.SetReportParser(0, &HidParser);
  // ab cd light pins
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  // minutes pins
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  // tens pin
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);
  // seconds pins
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  // lights and dots
  pinMode(45, OUTPUT);
  pinMode(46, OUTPUT);
  pinMode(47, OUTPUT);
  pinMode(48, OUTPUT);
  // ab cd light pins
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  // minutes pins
  digitalWrite(24, LOW);
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  digitalWrite(28, LOW);
  digitalWrite(29, LOW);
  digitalWrite(30, LOW);
  // tens pins
  digitalWrite(31, LOW);
  digitalWrite(32, LOW);
  digitalWrite(33, LOW);
  digitalWrite(34, LOW);
  digitalWrite(35, LOW);
  digitalWrite(36, LOW);
  digitalWrite(37, LOW);
  // seconds pins
  digitalWrite(38, LOW);
  digitalWrite(39, LOW);
  digitalWrite(40, LOW);
  digitalWrite(41, LOW);
  digitalWrite(42, LOW);
  digitalWrite(43, LOW);
  digitalWrite(44, LOW);
  // lights and dots
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(47, LOW); //dots
  digitalWrite(48, LOW); //buzzer
}

void loop(){
    // digitalWrite(47, HIGH);
    // displayTime(1,0,0);
    displayTime(0,0,0);
    digitalWrite(ab,LOW);
    digitalWrite(cd,LOW);
    Usb.Task(); //78 bottom 75 middle 43 top
    if(button == 78){
     button = 0;
     doubleTimer(2,4,0);
    }else if(button == 75){
      button = 0;
      doubleTimer(3,0,0);
    }else if(button == 43|| button == 40){
      button = 0;
      singleTimer(2,4,0);
    }
    //*/
}
