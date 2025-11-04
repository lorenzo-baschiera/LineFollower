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

  int sens1=digitalRead(5);
  int sens2=digitalRead(4);
  int sens3=digitalRead(3);
  delay(250);
  if(sens1)  Serial.println("Sensore 1");
  if(sens2)  Serial.println("Sensore 2");
  if(sens3)  Serial.println("Sensore 3");
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
