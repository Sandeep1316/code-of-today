#include<Servo.h>
const int Knocksensor=A0;
const int thresholdHIGH=30;
const int thresholdLOW=10;
const int SecretKnockLength=4;
const int SecretKnock[SecretKnockLength]={0,1,1,0};
int Secretcounter=0;
int Sensorreading=0;
int counter=0;
int angle1=0;
int angle2=90;
Servo servo1;
Servo servo2;
void setup() {
pinMode(13,OUTPUT);
Serial.begin(9600);
}
void loop() {
Sensorreading=analogRead(Knocksensor);
if(Sensorreading>=thresholdHIGH)
{
if(SecretKnock[Secretcounter]==1)
{To
Secretcounter++;
Serial.println("correct");
}
else
{
Secretcounter=0;
Serial.println("false");
}}
else if(Sensorreading>=thresholdLOW)
{
if(SecretKnock[Secretcounter]==0)
{
Secretcounter++;
Serial.println("correct");
}
else
{
Secretcounter=0;
Serial.println("fail");
}
delay(100);
}
if(Secretcounter==(SecretKnockLength))
{
digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000);
servo1.attach(9);
servo2.attach(10);
for (angle1=0;angle1<=90;angle1+=1)
{
servo1.write(angle1);
delay(20);
}
delay(2000);
for (angle2=90;angle2>=0;angle2-=1)
{
servo2.write(angle2);
delay(20);
}
delay(10000);
for (angle2=0;angle2<=90;angle2+=1)
{
servo2.write(angle2);
delay(20);
}
delay(2000);
for(angle1=90;angle1>=0;angle1-=1)
{
servo1.write(angle1);
delay(20);
}
Secretcounter=0;
}
}
