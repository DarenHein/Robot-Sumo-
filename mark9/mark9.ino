// robot sumo mark 9 
// version arduino nano 
// tuve que quitar los leds de forma provisional 
int motor1 = 2 ; 
int motor2 = 3 ; 
int motor3 = 4 ; 
int motor4 = 5 ;

// sensor untrasonico 
int pinTri = A4 ; 
int pinEcho = A5;
int recibe ; 
// buzzer 
int buz = 7 ; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(buz,OUTPUT); 
  pinMode(motor1,OUTPUT); 
  pinMode(motor2,OUTPUT); 
  pinMode(motor3,OUTPUT); 
  pinMode(motor4,OUTPUT); 
  pinMode(pinTri,OUTPUT); 
  pinMode(pinEcho,INPUT); 
  digitalWrite(buz,HIGH); 
  delay(5000); 
  digitalWrite(buz,LOW); 
}

void loop() {
  digitalWrite(pinTri,HIGH); 
  delayMicroseconds(10); 
  recibe = pulseIn(pinEcho,HIGH); 
  Serial.println(recibe); 
  delay(25); 
  digitalWrite(pinTri,LOW); 
  
  if (recibe < 1200){
    // put your main code here, to run repeatedly:
  digitalWrite(motor1,HIGH); 
  digitalWrite(motor2,LOW); 
  digitalWrite(motor3,HIGH); 
  digitalWrite(motor4,LOW); 
  }
  else {
  //delay(500); 
  digitalWrite(motor1,LOW); 
  digitalWrite(motor2,LOW); 
  digitalWrite(motor3,LOW); 
  digitalWrite(motor4,LOW); 

  }
}
