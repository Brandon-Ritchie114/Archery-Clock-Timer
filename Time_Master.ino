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
    while (1) { // error code of E10
      Serial.print("Not work \n");
      seconds.outputNum(-1);
      tens.outputNum(1);
      minutes.outputNum(0);
      delay(100);
      if(Usb.Init() == -1){
        break;
      }
    }
  }
  // Attach parser
  Hid.SetReportParser(0, &HidParser);
  // ab cd light pins 
  pinMode(22, OUTPUT); //ab
  pinMode(23, OUTPUT); //cd
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
  digitalWrite(38, LOW); //a 
  digitalWrite(39, LOW); //b
  digitalWrite(40, LOW); //c
  digitalWrite(41, LOW); //d
  digitalWrite(42, LOW); //e
  digitalWrite(43, LOW); //f 
  digitalWrite(44, LOW); //g
  // lights and dots
  digitalWrite(45, LOW); //green
  digitalWrite(46, LOW); //red
  digitalWrite(47, LOW); //dots
  digitalWrite(48, LOW); //buzzer
}

void loop(){
  Usb.Task();
  digitalWrite(45, LOW); //green
  digitalWrite(46, LOW); //red
  digitalWrite(22, LOW); //ab
  digitalWrite(23, LOW); //cd
  turn = true;
  Serial.println(button);
  bool doubleLine = true;
  int m = 0, t = 2, s = 0; //set default time at shoot of time. 
  
  //78 bottom 75 middle 43/40 top. Time is in seconds not minutes 
  //controller used can output either 43 or 40, varies.
  while(1){ //setting display time loop
  
    displayTime(m,t,s);
    Usb.Task();
    if(button == 75){ //addition code
      button = 0;
      t+=1;
      if(t > 9){
        m+=1;
        t=0;
        if(m > 9){
          m = 0;
        }
      }
      delay(10);
    }else if(button == 78){ //reverse addition code for subtraction.
      button = 0;
      t-=1;
      if(t < 0){
        m-=1;
        t=9;
        if(m < 0){
          m = 9;
        }
      }
      delay(10);
    }else if(button == 43|| button == 40){
      button = 0;
      break;
    }
  }
  
  while(1){ // double or single timer loop
    doubleDisplay(doubleLine);
    Usb.Task();
    if(button == 75 || button == 78){
      button = 0;
      doubleLine = !doubleLine;
    }else if(button == 43 || button == 40){
      button = 0;
      break;
    }
    delay(10);
  }

  while(1){ //timer control loop}
    displayTime(m,t,s);
    digitalWrite(red, HIGH);
    Usb.Task();
    if(button == 43 || button == 40){
      button = 0;
      startClk(m,t,s,doubleLine);
    }else if(button == 75 || button == 78){
      button = 0;
      break;
    }
  }
}