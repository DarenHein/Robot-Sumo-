// ROBOT SUMO 
// MARK 4
//  MATERIALES 
// LEDS 
int led = 2 ; 
int led2 = 3 ; 
// sensor ultrasonico 
int pinTri = 4 ; 
int pinEcho = 5 ; 
int recibe ; 
// PRIMER MODULO H 
// motor 1 
int pinM11 = 6 ;   
int pinM12 = 7 ; 
// motor 2 
int pinM21 = 8 ;   
int pinM22 = 9 ;   
// SEGUNDO MODULO H 
// motor 1 modulo h 2 
int pinMh21 = 10 ; 
int pinMh22 = 11 ; 
// motor2 modulo h 2 
int pinMh23 = 12 ; 
int pinMh24 = 13 ; 
// SENSORES INFRAROJOS 
int sensor1 = A0; 
int sensor2 = A1; 
int recibe2 ; 
int recibe3 ; 
void setup() {
  pinMode(sensor1,INPUT); 
  pinMode(sensor2,OUTPUT); 
  pinMode(pinM11,OUTPUT); 
  pinMode(pinM12,OUTPUT); 
  pinMode(pinM21,OUTPUT); 
  pinMode(pinM22,OUTPUT); 
  pinMode(pinMh21,OUTPUT); 
  pinMode(pinMh22,OUTPUT); 
  pinMode(pinMh23,OUTPUT); 
  pinMode(pinMh24,OUTPUT); 
  pinMode(pinTri,OUTPUT); 
  pinMode(pinEcho,INPUT); 
  pinMode(led,OUTPUT); 
  pinMode(led2,OUTPUT); 
  Serial.begin(9600); 
  digitalWrite(led,HIGH); 
  delay(300); 
  digitalWrite(led,LOW); 
  delay(300);
  digitalWrite(led2,HIGH);
  delay(300);  
  digitalWrite(led2,LOW); 
  delay(300); 
  digitalWrite(led,HIGH); 
  delay(300);
  digitalWrite(led,LOW); 
  delay(300); 
  digitalWrite(led,HIGH); 
  digitalWrite(led2,HIGH); 
  delay(300); 
  digitalWrite(led,LOW); 
  digitalWrite(led2,LOW); 
  delay(2000);


}

void loop() {
  recibe2 = digitalRead(sensor1); 
  recibe3 = digitalRead(sensor2); 
  if (recibe2 == HIGH && recibe3 == HIGH){
  digitalWrite(led,HIGH); 
  digitalWrite(pinTri,OUTPUT); 
  delayMicroseconds(25); 
  recibe = pulseIn(pinEcho,HIGH); 
  delay(10); 
  digitalWrite(pinTri,LOW); 
  Serial.println(recibe);
  if (recibe >= 2000){
  // motores 1 y 2 del modulo h 1 apagados 
  digitalWrite(pinM11,LOW); 
  digitalWrite(pinM12,LOW); 
  digitalWrite(pinM21,LOW); 
  digitalWrite(pinM22,LOW);
  // motores 3 y 4 del modulo h 2 apagados  
  digitalWrite(pinMh21,LOW); 
  digitalWrite(pinMh22,LOW); 
  digitalWrite(pinMh23,LOW); 
  digitalWrite(pinMh24,LOW); 
  }
  else {
    // motor 1 y2 del modulo h1 encendido 
  digitalWrite(pinM11,HIGH); 
  digitalWrite(pinM12,LOW); 
  digitalWrite(pinM21,HIGH); 
  digitalWrite(pinM22,LOW);
  // motores 3 y 4 del modulo h2 encendidos 
  digitalWrite(pinMh21,HIGH); 
  digitalWrite(pinMh22,LOW); 
  digitalWrite(pinMh23,HIGH); 
  digitalWrite(pinMh24,LOW);
    }
  }
  else {
    // motor 1 y2 del modulo h1 encendido 
    // reversa 
    digitalWrite(led2,HIGH); 
    digitalWrite(pinM11,LOW); 
    digitalWrite(pinM12,HIGH); 
    digitalWrite(pinM21,LOW); 
    digitalWrite(pinM22,HIGH);
  // motores 3 y 4 del modulo h2 encendidos 
  // reversa 
    digitalWrite(pinMh21,LOW); 
    digitalWrite(pinMh22,HIGH); 
    digitalWrite(pinMh23,LOW); 
    digitalWrite(pinMh24,HIGH);

  }
}

