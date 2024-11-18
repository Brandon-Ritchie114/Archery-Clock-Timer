#ifndef functions_h
#define functions_h
#include "DisplayNumber.h"
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
bool emegency = false;

DisplayNumber seconds(38, 39, 40, 41, 42, 43, 44);
DisplayNumber tens(31, 32, 33, 34, 35, 36, 37);
DisplayNumber minutes(24, 25, 26, 27, 28, 29, 30);

// test all connections
void startUp()
{
    delay(100);
    // turn on and off red, green, numbers, and dots.
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(dot, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(dot, LOW);
    // test AB & CD
    delay(500);
    digitalWrite(ab, HIGH);
    delay(500);
    digitalWrite(ab, LOW);
    delay(500);
    digitalWrite(cd, HIGH);
    delay(500);
    digitalWrite(cd, LOW);
    delay(500);
    // minutes test
    digitalWrite(24, HIGH);
    digitalWrite(25, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(27, HIGH);
    digitalWrite(28, HIGH);
    digitalWrite(29, HIGH);
    digitalWrite(30, HIGH);
    delay(500);
    digitalWrite(24, LOW);
    digitalWrite(25, LOW);
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);
    digitalWrite(28, LOW);
    digitalWrite(29, LOW);
    digitalWrite(30, LOW);
    delay(500);
    minutes.outputNum(5);
    delay(500);
    minutes.outputNum(10);
    delay(500);
    // tens tests
    digitalWrite(31, HIGH);
    digitalWrite(32, HIGH);
    digitalWrite(33, HIGH);
    digitalWrite(34, HIGH);
    digitalWrite(35, HIGH);
    digitalWrite(36, HIGH);
    digitalWrite(37, HIGH);
    delay(500);
    digitalWrite(31, LOW);
    digitalWrite(32, LOW);
    digitalWrite(33, LOW);
    digitalWrite(34, LOW);
    digitalWrite(35, LOW);
    digitalWrite(36, LOW);
    digitalWrite(37, LOW);
    delay(500);
    tens.outputNum(5);
    delay(500);
    tens.outputNum(10);
    delay(500);
    // seconds test
    digitalWrite(38, HIGH);
    digitalWrite(39, HIGH);
    digitalWrite(40, HIGH);
    digitalWrite(41, HIGH);
    digitalWrite(42, HIGH);
    digitalWrite(43, HIGH);
    digitalWrite(44, HIGH);
    delay(500);
    digitalWrite(38, LOW);
    digitalWrite(39, LOW);
    digitalWrite(40, LOW);
    digitalWrite(41, LOW);
    digitalWrite(42, LOW);
    digitalWrite(43, LOW);
    digitalWrite(44, LOW);
    delay(500);
    seconds.outputNum(5);
    delay(500);
    seconds.outputNum(10);
    delay(500);
}

void timer(int m, int t, int s)
{
    while (m != -1) // loop for rest of time
    {
        while (t != -1)
        {
            while (s != -1)
            {
                minutes.outputNum(m);
                tens.outputNum(t);
                seconds.outputNum(s);
                s--;
                delay(1050);
            }
            t--;
            s = 9; // reset seconds
        }
        m--;
        t = 5; // reset tens
    }
}
void buzz(int num)
{ // 1 -to the line, 2 - clear to shoot, 3 - grab arrwows, 4 - emergency
    if (num == 1)
    {
        digitalWrite(red, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
    }
    else if (num == 2)
    {
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
    }
    else if (num == 3)
    {
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
    }
    else
    {
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        delay(100);
        digitalWrite(buzzer, LOW);
    }
}
void indoor()
{ // time set to 2 minutes
    delay(100);
    digitalWrite(ab, HIGH);
    digitalWrite(red, HIGH);
    minutes.outputNum(2);
    tens.outputNum(0);
    seconds.outputNum(0);
    buzz(1);
    delay(5000);
    buzz(2);
    digitalWrite(red, LOW);
    delay(100);
    digitalWrite(green, HIGH);
    timer(0, 0, 5);
    digitalWrite(red, HIGH);
    delay(100);
    digitalWrite(green, LOW);
    digitalWrite(ab, LOW);
    delay(100);
    digitalWrite(cd, HIGH);
    delay(10000); // wait 20 seconds to switch lines
    buzz(1);
    delay(5000);
    buzz(2);
    digitalWrite(red, LOW);
    delay(100);
    digitalWrite(green, HIGH);
    timer(0, 0, 5);
    digitalWrite(green, LOW);
    delay(100);
    digitalWrite(red, HIGH);

    delay(3000);
    buzz(3);
}
void outdoor()
{ // time set to 2 minutes
    delay(100);
    digitalWrite(ab, HIGH);
    minutes.outputNum(4);
    tens.outputNum(0);
    seconds.outputNum(0);
    delay(5000);
    buzz(2);
    timer(4, 0, 0);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(ab, LOW);
    delay(10000); // wait 20 seconds to switch lines
    digitalWrite(cd, HIGH);
    buzz(1);
    delay(5000);
    buzz(2);
    timer(4, 0, 0);
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(cd, LOW);
    delay(3000);
    buzz(3);
}

#endif
