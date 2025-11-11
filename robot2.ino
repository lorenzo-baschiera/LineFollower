/*
Baschiera Lorenzo
Floreano Ian
Sebastianutti Elias

CLASSE 4 TEL A - I.S.I.S. ARTURO MALIGNANI

DATA INIZIO: 28 ott 2025
*/

#include <Servo.h>

const int antSx=1700, antDx=1685, orarSx=1300, orarDx=1360, fermo=1500;	//definizione sensi di rotazione delle ruote

const int pinSx=12,pinDx=13;													                  //definizione pin dei servomotori

const int sogliaSensore = 400;                                          //Soglia lettura analogica oltre la quale il valore è considerato 1

Servo servoRight;
Servo servoLeft;

void setup() {

  Serial.begin(9600);

  servoRight.attach(pinDx);
  servoLeft.attach(pinSx);

  servoRight.writeMicroseconds(fermo); 
  servoLeft.writeMicroseconds(fermo); 
  delay(3000);

}

void loop() {

  int sx2 = analogRead(A0);
  int sx  = analogRead(A1);
  int ce  = analogRead(A2);
  int dx  = analogRead(A3);
  int dx2 = analogRead(A4);

  if(sx2 > sogliaSensore) sx2 = 1; else sx2 = 0;
  if(sx  > sogliaSensore) sx =  1; else sx  = 0;
  if(dx2 > sogliaSensore) dx2 = 1; else dx2 = 0;
  if(dx  > sogliaSensore) dx =  1; else dx  = 0;
  if(ce  > sogliaSensore) ce =  1; else ce  = 0;

  if((sx==1 && ce==0 && dx==1)|| (sx==0 && ce==0 && dx==0 )) forward();

   if((sx==1 && ce==0 && dx==0) || (sx==1 && ce==1 && dx==0) || (sx==0 && ce==0 && dx==0 && dx2==0 && sx2==1)) turnright();
  
  if((sx==0 && ce==0 && dx==1) || (sx==0 && ce==1 && dx==1) || (sx==0 && ce==0 && dx==0 && dx2==1 && sx2==0)) turnleft();
  
  if(sx==0 && ce==0 && dx==0 && dx2==0 && sx2==0){
    servoRight.detach();
    servoLeft.detach();
  }
  
}

//funzioni di movimento
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
