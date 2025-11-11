/*
Baschiera Lorenzo
Floreano Ian
Sebastianutti Elias

CLASSE 4 TEL A - I.S.I.S. ARTURO MALIGNANI

DATA INIZIO: 28 ott 2025
*/

#include <Servo.h>

const int antSx=1700, antDx=1685, orarSx=1300, orarDx=1360, fermo=1500;	//definizione sensi di rotazione delle ruote

const int pinSx=12,pinDx=13;													//definizione pin dei servomotori

Servo servoRight;
Servo servoLeft;

void setup() {

  Serial.begin(9600);

  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(3, INPUT);
  

  servoRight.attach(pinDx);
  servoLeft.attach(pinSx);

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
  servoRight.writeMicroseconds(orarDx); 
  servoLeft.writeMicroseconds(antSx); 
}
void backward(){
  servoRight.writeMicroseconds(antDx); 
  servoLeft.writeMicroseconds(orarSx); 
}
void turnleft(){
  servoRight.writeMicroseconds(orarDx); 
  servoLeft.writeMicroseconds(orarSx);
}
void turnright(){
  servoRight.writeMicroseconds(antDx); 
  servoLeft.writeMicroseconds(antSx);
}
