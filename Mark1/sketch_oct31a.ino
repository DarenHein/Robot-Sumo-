// primera prueba de robot 1 
// mark 1
// snesor ultrasonico 
int pinTri = 9 ; 
int pinEcho = 8 ; 
int recibe ; 
// motor 1 
int pinM11 = 7 ;   
int pinM12 = 6 ; 
// motor 2 
int pinM21 = 5 ;   
int pinM22 = 4 ;   

void setup() {
  // put your setup code here, to run once:
  pinMode(pinM11,OUTPUT); 
  pinMode(pinM12,OUTPUT); 
  pinMode(pinM21,OUTPUT); 
  pinMode(pinM22,OUTPUT); 
  pinMode(pinTri,OUTPUT); 
  pinMode(pinEcho,INPUT); 
  Serial.begin(9600); 


}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  digitalWrite(pinM11,HIGH); 
  digitalWrite(pinM12,LOW); 
  digitalWrite(pinM21,HIGH); 
  digitalWrite(pinM22,LOW); 
  */
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
