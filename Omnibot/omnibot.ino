#include<math.h>
#define c PI/180
int f1, b1, f2, b2, f3, b3;
int m1, m2, m3;
void process();
float m, a;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  while (Serial.available())
  {
    char getData = Serial.read();
    if (getData == 'M')
    {
      m = Serial.parseFloat();

    }
    if (getData == 'A')
    {
      a = Serial.parseFloat();
    }
    if (getData == '#')
    {
      process();
    }
  }
}
void process()
{
  Serial.print("M");
  Serial.print(m);
  Serial.print("A");
  Serial.print(a);
  Serial.print("\n");

  m1 = (int)sin(c * (90 - a)) * m;
  m2 = (int)sin(c * (210 - a)) * m;
  m3 = (int)sin(c * (330 - a)) * m;

  m1 =  map(m1, -500, 500, -255, 255);
  m2 =  map(m2, -500, 500, -255, 255);
  m3 =  map(m3, -500, 500, -255, 255);

  //condition check

  if ( m1 >= 0) {
    analogWrite(f1, m1);
    analogWrite(b1, 0);
  }
  else {
    analogWrite(b1, -m1);
    analogWrite(f1, 0);
  }


  if ( m2 >= 0) {
    analogWrite(f2, m2);
    analogWrite(b2, 0);
  }
  else {
    analogWrite(b2, -m2);
    analogWrite(f2, 0);

    
  }
  if ( m3 >= 0) {
    analogWrite(f3, m3);
    analogWrite(b3, 0);
  }
  else {
    analogWrite(b3, -m3);
    analogWrite(f3, 0);
  }


}



