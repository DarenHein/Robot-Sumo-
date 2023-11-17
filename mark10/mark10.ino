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
// sensor infra 
int infra = 10 ; 
int recibe2; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(infra,INPUT); 
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
  recibe2 = digitalRead(infra); 
  if(recibe2 == HIGH){
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
  }
 
  }
  else {
  digitalWrite(buz,HIGH);
  delay(500); 
  digitalWrite(buz,LOW);w
  digitalWrite(motor1,LOW); 
  digitalWrite(motor2,LOW); 
  digitalWrite(motor3,LOW); 
  digitalWrite(motor4,LOW); 
  // retrocede 
  digitalWrite(motor1,LOW); 
  digitalWrite(motor2,HIGH); 
  digitalWrite(motor3,LOW); 
  digitalWrite(motor4,HIGH);

  }
}
