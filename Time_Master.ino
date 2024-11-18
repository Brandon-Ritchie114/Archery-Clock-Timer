#include "functions.h"
const byte interruptPin = 2;

void setup()
{
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), emergency, CHANGE);
  // ab cd light pins
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  // minutes pin
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
  // ab cd light pins
  digitalWrite(22, LOW);
  digitalWrite(23, LOW);
  // minutes pin
  digitalWrite(24, LOW);
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  digitalWrite(28, LOW);
  digitalWrite(29, LOW);
  digitalWrite(30, LOW);
  // tens pin
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
  digitalWrite(47, LOW);
  startUp();
}
void emergency() {


}
void loop()
{
  indoor();
  // put your main code here, to run repeatedly
}
