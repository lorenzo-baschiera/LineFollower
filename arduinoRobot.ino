#include <Servo.h>
const int antsx=1700,antdx=1685,orarsx=1300,orardx=1360,fermo=1500;
const int angiro=1600,angpiat=865;
const int pindx=12,pinsx=13;
Servo servoRight;
Servo servoLeft;

void setup() {
  
  servoRight.attach(pindx);
  servoLeft.attach(pinsx);


  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 
  delay(3000);


  turnleft360();
  turnright360();
  forward(7000);
  turnright180();
  forward(7000);
  
}
void loop() {
 
}

void turnleft180(){
  servoRight.writeMicroseconds(orardx); 
  servoLeft.writeMicroseconds(orarsx);
  delay(angpiat);
  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 

}
void turnright180(){
  servoRight.writeMicroseconds(antdx); 
  servoLeft.writeMicroseconds(antsx);
  delay(angpiat);
  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 

}
void turnleft360(){
  servoRight.writeMicroseconds(orardx); 
  servoLeft.writeMicroseconds(orarsx);
  delay(angiro);
  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 

}
void turnright360(){
  servoRight.writeMicroseconds(antdx); 
  servoLeft.writeMicroseconds(antsx);
  delay(angiro);
  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 

}
void forward(int time){
  servoRight.writeMicroseconds(orardx); 
  servoLeft.writeMicroseconds(antsx); 
  delay(time);
  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 

}