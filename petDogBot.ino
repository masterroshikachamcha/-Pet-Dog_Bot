#include<Servo.h>
int mot1=7;//left
int mot2=8;//left
int mot3=11;//right
int mot4=12;//right
int trigpin = 32;
int echopin = 33;
long duration;
int distance;
int touch=53;
int touch1=52;
int led1=39;
int led2=40;
long touchread;
long touchread1;
int angle=0;
int servopin=10;
Servo Servo1;




int left=45;//left IR Sensor
int right=9;//Right IR Sensor

int Left=0; //Variable
int Right=0;//Variabe

void FORWARD ();
void LEFT ();
void RIGHT ();
void STOP ();

void setup()
{
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);
  pinMode(touch,INPUT);
  pinMode(touch1,INPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(left,INPUT);//ir sensor
  pinMode(right,INPUT); // ir sensor
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
 Servo1.attach(servopin);
  Serial.println("LINE FOLLOWING ROBOT \n");
  Serial.begin(9600);
  
  
}

void loop() 
{ 
touchread= digitalRead(touch);
Serial.println(touchread);

touchread1 = digitalRead(touch1);
Serial.println(touchread1);
if((touchread==1)&&(touchread1==1)==1)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
//code for servomotor

for(angle=0;angle<180;angle+=1){

  Servo1.write(angle);
  delay(5);
  
}

delay(1000);
for(angle=180;angle>=1;angle-=5){


  Servo1.write(angle);
  delay(5);
}
delay(1000);
  
}
else{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  Servo1.write(0);
  
}
if((touchread==1) && (touchread1==0)==1)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
}
else{
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  Servo1.write(0);
}

if((touchread1==1) && (touchread==0)==1)
{
  
//code for servomotor

for(angle=0;angle<180;angle+=1){

  Servo1.write(angle);
  delay(5);
  
}

delay(1000);
for(angle=180;angle>=1;angle-=5){


  Servo1.write(angle);
  delay(5);
}
delay(1000);
  
}
else{

  Servo1.write(0);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  
}














   
digitalWrite(trigpin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration= pulseIn(echopin, HIGH);
distance = duration*0.034/2;
if (distance<=7){
  STOP();
}
else{
  FORWARD();
}
Serial.print("Distance:  ");
Serial.println(distance);

  
  Left=digitalRead(left);
  Right=digitalRead(right);
  Serial.println(Left);
  Serial.println(Right);
  
  if((Left==0 && Right==1)==1)
    LEFT();
  if((Right==0 && Left==1)==1)
    RIGHT();
  if((Right==0 && Left==0)==1)
    STOP();
  if((Right==1 && Left==1)==1)
    FORWARD();
}

void FORWARD ()
{
   Serial.println("FORWARD");
   analogWrite(mot1,200);
   analogWrite(mot2,0);
   analogWrite(mot3,200);
   analogWrite(mot4,0);
}

void LEFT ()
{
   Serial.println("LEFT");
   analogWrite(mot1,200);
   analogWrite(mot2,0);
   analogWrite(mot3,0);
   analogWrite(mot4,200);
}

void RIGHT ()
{
   Serial.println("RIGHT");
   analogWrite(mot1,0);
   analogWrite(mot2,200);
   analogWrite(mot3,200);
   analogWrite(mot4,0);
}
void STOP ()
{
  Serial.println("STOP");
  analogWrite(mot1,0);
  analogWrite(mot2,0);
  analogWrite(mot3,0);
  analogWrite(mot4,0);
}



