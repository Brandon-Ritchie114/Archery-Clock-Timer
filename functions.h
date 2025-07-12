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
int button = 0;
uint8_t *buf;
bool turn = true;
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
// dots
int dot = 47;
int buzzer = 48;
bool abLine = false;
bool cdLine = false;
int m,t,s;
DisplayNumber seconds(38, 39, 40, 41, 42, 43, 44);
DisplayNumber tens(31, 32, 33, 34, 35, 36, 37);
DisplayNumber minutes(24, 25, 26, 27, 28, 29, 30);
void buzz(int num)
{ // 1 -to the line, 2 - clear to shoot, 3 - grab arrwows, 4 - emergency
    if (num == 1)
    {
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
    }
    else if (num == 2)
    {
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
        delay(500);
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
    }
    else if (num == 3)
    {
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
        delay(500);
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
        delay(500);
        digitalWrite(buzzer, HIGH);
        delay(300);
        digitalWrite(buzzer, LOW);
    }
    else
    {
        digitalWrite(buzzer, HIGH);
        delay(5000);
        digitalWrite(buzzer, LOW);
    }
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

void displayTime(int m, int t, int s)
{
    minutes.outputNum(m);
    tens.outputNum(t);
    seconds.outputNum(s);
}

void emergen(int g)
{
    int emergency = 1;
    minutes.outputNum(0);
    tens.outputNum(0);
    seconds.outputNum(0);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);
    buzz(4);
    while (emergency == 1)
    {
        displayTime(-1,-1,-1);
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        Usb.Task();
        if (button == 75)
        { // resume timer
            emergency = 0;
            digitalWrite(red, LOW);
            buzz(1);
            digitalWrite(green, HIGH);
            break;
        }
        else if (button == 40 || button == 43)
        { //reset timer fully
            emergency = 0;
            digitalWrite(red, LOW);            
            turn != turn;            
            m = 0;
            t = 0;
            s = 0;
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
                  if (button == 78) // emergency
                  {
                      emergen(a);
                  }else if (button == 75){ //end early
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
    delay(10);       // delay for hardware
    digitalWrite(ab,HIGH); // deciding what turn it is
    displayTime(m, t, s);
    buzz(2);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    timer(0, 1, 0); // 5 seconds to switch lines
    buzz(1);        // one to shoot
    digitalWrite(green,HIGH);
    digitalWrite(red, LOW);
    timer(m, t, s);
    buzz(3);
}

void doubleTimer(int m, int t, int s)
{                    // time set to m minutes
    delay(10);       // delay for hardware
    turnLight(turn); // deciding what turn it is
    displayTime(m, t, s);
    digitalWrite(green,LOW);
    digitalWrite(red, HIGH);
    buzz(2);
    timer(0, 1, 0); // 5 seconds to switch lines
    buzz(1);        // one to shoot
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    timer(m, t, s);
    turn = !turn; // flip to cd line
    buzz(2);
    turnLight(turn);        // display CD Line
    timer(0, 1, 0);         // 5 seconds to switch lines
    buzz(1);
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    timer(m, t, s);
    buzz(3);
}
#endif
