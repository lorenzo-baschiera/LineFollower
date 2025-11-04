/*
Baschiera Lorenzo
Floreano Ian
Sebastianutti Elias

CLASSE 4 TEL A - I.S.I.S. ARTURO MALIGNANI

DATA INIZIO: 
*/

#include <Servo.h>

const int antsx=1700,antdx=1685,orarsx=1300,orardx=1360,fermo=1500;
const int pinsx=12,pindx=13;

Servo servoRight;
Servo servoLeft;

void setup() {
  Serial.begin(9600);

  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  

  servoRight.attach(pindx);
  servoLeft.attach(pinsx);

  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 
  delay(3000);


}

void loop() {
  int sx2=digitalRead(6);
  int sx=digitalRead(5);
  int ce=digitalRead(4);
  int dx=digitalRead(3);
  int dx2=digitalRead(2);

  if((sx==1 && ce==0 && dx==1)|| (sx==0 && ce==0 && dx==0 )){
    forward();
  }
   if((sx==1 && ce==0 && dx==0) || (sx==1 && ce==1 && dx==0) || (sx==0 && ce==0 && dx==0 && dx2==0 && sx2==1)){
    turnright();
  }
  if((sx==0 && ce==0 && dx==1) || (sx==0 && ce==1 && dx==1) || (sx==0 && ce==0 && dx==0 && dx2==1 && sx2==0)){
    turnleft();
  }
  if(sx==0 && ce==0 && dx==0 && dx2==0 && sx2==0){
    servoRight.writeMicroseconds(fermo); 
    servoLeft.writeMicroseconds(fermo);
  }

}
void forward(){
  servoRight.writeMicroseconds(orardx); 
  servoLeft.writeMicroseconds(antsx); 
}
void backward(){
  servoRight.writeMicroseconds(antdx); 
  servoLeft.writeMicroseconds(orarsx); 
}
void turnleft(){
  servoRight.writeMicroseconds(orardx); 
  servoLeft.writeMicroseconds(orarsx);
}
void turnright(){
  servoRight.writeMicroseconds(antdx); 
  servoLeft.writeMicroseconds(antsx);
}
