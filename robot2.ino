#include <Servo.h>
const int antsx=1700,antdx=1685,orarsx=1300,orardx=1360,fermo=1500;
const int pinsx=12,pindx=13;
Servo servoRight;
Servo servoLeft;

void setup() {

  pinMode(CNY, INPUT);
  pinMode(CNY, INPUT);
  pinMode(CNY, INPUT);
  

  servoRight.attach(pindx);
  servoLeft.attach(pinsx);

  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 
  delay(3000);


}

void loop() {


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