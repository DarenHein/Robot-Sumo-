// mark 6 
// se agregan sensores ultra sonicos 
int motor1 = 2 ; 
int motor2 = 3 ; 
int motor3 = 4 ; 
int motor4 = 5 ;
// segundo puente h 
int motor5 = 6;   
int motor6 = 7;
int motor7 = 8; 
int motor8 = 9; 
// sensor untrasonico 
int pinTri = 10 ; 
int pinEcho = 11;
int recibe ; 
// sensores 
int sensor1 = A0; 
int sensor2 = A1; 
int recibe2 ; 
int recibe3 ; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(motor1,OUTPUT); 
  pinMode(motor2,OUTPUT); 
  pinMode(motor3,OUTPUT); 
  pinMode(motor4,OUTPUT); 
  pinMode(motor5,OUTPUT); 
  pinMode(motor6,OUTPUT); 
  pinMode(motor7,OUTPUT); 
  pinMode(motor8,OUTPUT); 
  pinMode(pinTri,OUTPUT); 
  pinMode(pinEcho,INPUT); 
  pinMode(sensor1,INPUT); 
  pinMode(sensor2,INPUT); 
  delay(5000); // tiempo de espera de regla 
}

void loop() {
  recibe2 = digitalRead(sensor1); 
  recibe3 = digitalRead(sensor2);
  if (recibe2 == HIGH && recibe3 == HIGH){
  digitalWrite(pinTri,HIGH); 
  delayMicroseconds(10); 
  recibe = pulseIn(pinEcho,HIGH); 
  Serial.println(recibe); 
  delay(25); 
  digitalWrite(pinTri,LOW); 
  
  if (recibe >= 800){
    // put your main code here, to run repeatedly:
  digitalWrite(motor1,HIGH); 
  digitalWrite(motor2,LOW); 
  digitalWrite(motor3,HIGH); 
  digitalWrite(motor4,LOW); 

  // segundo puente h 
  digitalWrite(motor5,HIGH); 
  digitalWrite(motor6,LOW); 
  digitalWrite(motor7,HIGH); 
  digitalWrite(motor8,LOW); 
  }
 }
 else {
  digitalWrite(motor1,LOW); 
  digitalWrite(motor2,HIGH); 
  digitalWrite(motor3,LOW); 
  digitalWrite(motor4,HIGH); 

  // segundo puente h 
  digitalWrite(motor5,LOW); 
  digitalWrite(motor6,HIGH); 
  digitalWrite(motor7,LOW); 
  digitalWrite(motor8,HIGH);
 } 
  
}

