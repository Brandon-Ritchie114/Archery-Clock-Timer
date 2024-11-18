#ifndef DisplayNumber_h
#define DisplayNumber_h
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
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
  }
  else
  {
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
