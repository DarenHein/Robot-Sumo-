// Segunda prueba de robot 
// mark 2

//  MATERIALES 
// LEDS 
int led = 10 ; 
int led2 = 11 ; 
// sensor ultrasonico 
int pinTri = 9 ; 
int pinEcho = 8 ; 
int recibe ; 
// PRIMER MODULO H 
// motor 1 
int pinM11 = 7 ;   
int pinM12 = 6 ; 
// motor 2 
int pinM21 = 5 ;   
int pinM22 = 4 ;   
// SEGUNDO MODULO H 
// SENSORES INFRAROJOS 

void setup() {
  pinMode(pinM11,OUTPUT); 
  pinMode(pinM12,OUTPUT); 
  pinMode(pinM21,OUTPUT); 
  pinMode(pinM22,OUTPUT); 
  pinMode(pinTri,OUTPUT); 
  pinMode(pinEcho,INPUT); 
  pinMode(led,OUTPUT); 
  pinMode(led2,OUTPUT); 
  Serial.begin(9600); 
  digitalWrite(led,HIGH); 
  delay(500); 
  digitalWrite(led,LOW); 
  delay(1000);
  digitalWrite(led2,HIGH);
  delay(1000);  
  digitalWrite(led2,LOW); 
  delay(500); 
  digitalWrite(led,HIGH); 
  delay(500);
  digitalWrite(led,LOW); 
  delay(500); 
  digitalWrite(led,HIGH); 
  digitalWrite(led2,HIGH); 
  delay(500); 
  digitalWrite(led,LOW); 
  digitalWrite(led2,LOW); 
  delay(2000);


}

void loop() {
  digitalWrite(pinTri,OUTPUT); 
  delayMicroseconds(25); 
  recibe = pulseIn(pinEcho,HIGH); 
  delay(10); 
  digitalWrite(pinTri,LOW); 
  Serial.println(recibe);
  if (recibe >= 800){
 digitalWrite(pinM11,LOW); 
  digitalWrite(pinM12,LOW); 
  digitalWrite(pinM21,LOW); 
  digitalWrite(pinM22,LOW);
  }
  else {
   digitalWrite(pinM11,HIGH); 
  digitalWrite(pinM12,LOW); 
  digitalWrite(pinM21,HIGH); 
  digitalWrite(pinM22,LOW);
  }
  


}
