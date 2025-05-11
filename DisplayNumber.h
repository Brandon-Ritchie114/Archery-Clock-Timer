#ifndef DisplayNumber_h
#define DisplayNumber_h
// Written by Brandon Ritchie
// At SJSU, 1/23/25
class DisplayNumber
{
private:
  int a, b, c, d, e, f, g; // pins
public:
  DisplayNumber(int aa, int ba, int ca, int da, int ea, int fa, int ga); // takes in pins, added a to variable to differentiate
  void outputNum(int num);                                               // Updates pin values to show correct number
};

DisplayNumber::DisplayNumber(int aa, int ba, int ca, int da, int ea, int fa, int ga)
{ // setting pins to variables to be used in outputNum
  a = aa;
  b = ba;
  c = ca;
  d = da;
  e = ea;
  f = fa;
  g = ga;
}

void DisplayNumber::outputNum(int num)
{
  if (num == 0)
  {
    Serial.print(0);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
  }
  else if (num == 1)
  {
    Serial.print(1);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  else if (num == 2)
  {
    Serial.print(2);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
  }
  else if (num == 3)
  {
    Serial.print(3);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(e, LOW);
  }
  else if (num == 4)
  {
    Serial.print(4);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(a, LOW);
    digitalWrite(d, LOW);
  }
  else if (num == 5)
  {
    Serial.print(5);
    digitalWrite(a, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(e, LOW);
  }
  else if (num == 6)
  {
    Serial.print(6);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
  }
  else if (num == 7)
  {
    Serial.print(7);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
  else if (num == 8)
  {
    Serial.print(8);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else if (num == 9)
  {
    Serial.print(9);
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else if(-1)
  {
   Serial.println(-1);  //spell E if broken
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else{
      digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
  }
}


#endif
