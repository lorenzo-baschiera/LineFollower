/*
Baschiera Lorenzo
Floreano Ian
Sebastianutti Elias
  
CLASSE 4 TEL A - I.S.I.S. ARTURO MALIGNANI

DATA INIZIO: 28 ott 2025
*/


//pin sensore HC
const int pinTrig=3;     
const int pinEcho=2;
const int usTocm=29;
long duration;           

//pin sensore IR
const int sensorIR=A5;
float ultimaDistanza = 60.0;

//variabili distanze ostacoli
float distanceHC,distanceIR;



//DICHIARAZIONI--------------------------------------------------------------------


void setup() {

  Serial.begin(9600);
 
  pinMode(pinTrig,OUTPUT);                  
  pinMode(pinEcho,INPUT);
  
 
  
}

void loop() {

  distanceIR = distanceIRmisura();  //lettura distanza ostacolo sensore Infrarossi
  distanceHC = distanceHCmisura();

  Serial.print("distanza IR: ");
  Serial.println(distanceIR);
  
  Serial.println("-----------------");
  
  Serial.print("distanza HC: ");
  Serial.println(distanceHC);

  delay(1000);
  
}


//FUNZIONI--------------------------------------------------------------------


//misura distanza con IR
float distanceIRmisura() {
  analogRead(sensorIR); // LETTURA A VUOTO: pulisce il convertitore
  delayMicroseconds(100);
  int raw = analogRead(sensorIR);
  float volts = raw * 0.004887585;
  
  // Se i volt sono bassissimi, siamo in campo libero
  if (volts < 0.4) {
    ultimaDistanza = 60.0;
    return 60.0;
  }

  float distanzaCalcolata = 30.0 / volts;
  float diff = ultimaDistanza - distanzaCalcolata;

  // LOGICA DI BLOCCO
  // Se la distanza aumenta improvvisamente (diff < -2) mentre eravamo vicini
  // OPPURE se siamo già bloccati (ultimaDistanza <= 3.0) 
  // MA i volt confermano che c'è qualcosa (volts > 1.2)
  if ((diff < -2.0 && ultimaDistanza < 15.0) || (ultimaDistanza <= 3.0 && volts > 1.2)) {
    distanzaCalcolata = 3.0; 
  }

  ultimaDistanza = distanzaCalcolata;
  return distanzaCalcolata;
}

//distanza con HC
float distanceHCmisura(){
  digitalWrite(pinTrig, LOW);               
  delayMicroseconds(5);                     
  digitalWrite(pinTrig, HIGH);              
  delayMicroseconds(10);                    
  digitalWrite(pinTrig, LOW);              
  duration = pulseIn(pinEcho, HIGH, 25000); 
  float distance=duration/usTocm/2;               
  delay(50);
  return distance;
}

