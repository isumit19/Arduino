byte PWM_PIN1 = 3;
byte PWM_PIN2 = 2;
int f1;
int f2;
int m1=6;
int d1l=7;
int d1h=8;
int m2=11;
int d2h=10;
int d2l=9;
int t1;
int t2;
 
int pwm_value1;
int pwm_value2;
 
void setup() {
  pinMode(PWM_PIN1, INPUT);
  pinMode(PWM_PIN2,INPUT);
  pinMode(d1h,OUTPUT);
  pinMode(d1l,OUTPUT);
  pinMode(d2h,OUTPUT);
  pinMode(d2l,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(13,HIGH);
  pinMode(m1,OUTPUT);
  pinMode(m2,OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
 pwm_value1=pulseIn(PWM_PIN1,HIGH);
 pwm_value2=pulseIn(PWM_PIN2,HIGH);
 t1=constrain(pwm_value1,1350,1740);
 t2=constrain(pwm_value2,1140,1730);
  Serial.println(t1);
 
  
 
if(t2>1440)
  {
      digitalWrite(d2h,HIGH);
      digitalWrite(d2l,LOW);
      f1=map(t2,1440,1730,0,255);
  }
 else
  {
    digitalWrite(d2h,LOW);
    digitalWrite(d2l,HIGH);
    f1=map(t2,1140,1440,255,0);
  }
  analogWrite(m2,f1);

  
if(t1>1550)
{
  digitalWrite(d1h,HIGH);
  digitalWrite(d1l,LOW);
  f2=map(t1,1740,1550,255,0);
}
else
{
  digitalWrite(d1h,LOW);
  digitalWrite(d1l,HIGH);
  f2=map(t1,1350,1550,255,0);
}
analogWrite(m1,f2);
if(pwm_value1==0&&pwm_value2==0)
{
  analogWrite(m1,0);
  analogWrite(m2,0);
}
}
