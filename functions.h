#ifndef functions_h
#define functions_h
#include "DisplayNumber.h"
#include <usbhid.h>
#include <usbhub.h>
#include <hiduniversal.h>
#include <hidboot.h>

// Written by Brandon Ritchie
// At SJSU, 1/23/25
USB Usb;
USBHub Hub(&Usb);
HIDUniversal Hid(&Usb);
volatile int button = 0;
uint8_t *buf;
bool turn = true;
bool walkUpTime = false;
class CustomHIDParser : public HIDReportParser
{
protected:
    void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf)
    {
        button = buf[2];
        Serial.print(button);
        Serial.println();
    }
};

CustomHIDParser HidParser;
int ab = 22; // ab pin set to digital pin 22
int cd = 23; // cd line set to digi pin 23
// Stop go Lights
int red = 45;
int green = 46;
int dot = 47; //don't need dots when in seconds mode
int buzzer = 48; //don't currently have a buzzer
bool abLine = false;
bool cdLine = false;
DisplayNumber seconds(38, 39, 40, 41, 42, 43, 44);
DisplayNumber tens(31, 32, 33, 34, 35, 36, 37);
DisplayNumber minutes(24, 25, 26, 27, 28, 29, 30);

void doubleDisplay(bool val){
    if(val == true){ //display 4es 
        minutes.outputNum(4);
        tens.outputNum(-1);
        seconds.outputNum(5);
      }else if(val == false){ //display n0
        minutes.outputNum(-2);
        digitalWrite(31, HIGH); //a
        digitalWrite(32, HIGH); //b
        digitalWrite(33, HIGH); //c
        digitalWrite(34, LOW); //d
        digitalWrite(35, HIGH); //e
        digitalWrite(36, HIGH); //f
        digitalWrite(37, LOW); //g
        seconds.outputNum(0);
      }
}

void displayTime(int m, int t, int s)
{
    if(m == 0){
        minutes.outputNum(-2);
    }else{
        minutes.outputNum(m);
    }
    if(t == 0 && m == 0){
        tens.outputNum(-2);
    }else{
        tens.outputNum(t);
    }
    seconds.outputNum(s);
}

void turnLight(bool i)
{
    if (i == true)
    {
        digitalWrite(ab, HIGH);
        digitalWrite(cd, LOW);
    }
    else if (i == false)
    {
        digitalWrite(ab, LOW);
        digitalWrite(cd, HIGH);
    }
}

void emergen()
{
    int emergency = 1;
    displayTime(-2,-2,-2);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    while (emergency == 1)
    {
        Usb.Task();
        if (button == 40 || button == 43)
        { //resume current time
            emergency = 0;
            if(!walkUpTime){
                displayTime(0,1,0);
                delay(1000);
                for(int i = 9; i >= 0; i--){
                    displayTime(0,0,i);
                    delay(1000);
                }
                digitalWrite(red, LOW);
                digitalWrite(green, HIGH);
            }
            break;
        }
    }
}

void timer(int m, int t, int s)
{
      while (m != -1) // loop for rest of time
      {
          while (t != -1) // once seconds < 0, subtract one tens of seconds.
          {
              while (s != -1) // output the number of minutes and seconds. Wait 1 second then suzbtract seconds by 1. break loop and repeat
              {
                  Usb.Task();
                  if (button == 75 || button == 78) // emergency
                  {
                    button = 0;
                    emergen();
                  }else if (button == 43 || button == 40){ //end early
                    button = 0;
                    m = 0;
                    t = 0;
                    s = 0;
                  }
                  Serial.println();
                  displayTime(m,t,s);
                  s--;
                  delay(1000);
              }
              t--;
              s = 9; // reset seconds
          }
          m--;
          t = 9; // reset tens
      }
      digitalWrite(red,HIGH);
      digitalWrite(green,LOW);
}

void singleTimer(int m, int t, int s){
    delay(10);              // delay for hardware
    displayTime(m, t, s);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    walkUpTime = true;
    timer(0, 1, 0);         //10 seconds to switch lines
    walkUpTime = false;
    digitalWrite(green,HIGH);
    digitalWrite(red, LOW);
    timer(m, t, s);
}

void doubleTimer(int m, int t, int s) // time set to m minutes
{
    delay(10);              // delay for hardware
    turnLight(turn);        // display shooting line
    displayTime(m, t, s);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    walkUpTime = true;
    timer(0, 1, 0);         // 10 seconds to switch lines
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    walkUpTime = false;
    timer(m, t, s);
    turn = !turn;           // flip shooting line
    walkUpTime = true;
    turnLight(turn);
    timer(0, 1, 0);         // 10 seconds to switch lines
    walkUpTime = false;
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    timer(m, t, s);
}

void startClk(int m, int t, int s, bool dl){
    if(dl == true){
        doubleTimer(m,t,s);
    }else{
        singleTimer(m,t,s);
    }
}
#endif
