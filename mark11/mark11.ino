int pinTri = A4 ; 
int pinEcho = A5 ; 
int recibe ; 
int motor1 = 2;
int motor2 = 3;
int motor3 = 4;
int motor4 = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinTri,OUTPUT);
  pinMode(pinEcho,INPUT); 
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  Serial.begin(9600);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(1000);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  delay(1000); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinTri,HIGH); 
  delayMicroseconds(25); 
  recibe = pulseIn(pinEcho,HIGH); 
  delay(10);
  digitalWrite(pinTri,LOW); 
  Serial.println(recibe); 
  if (recibe >= 700){
    digitalWrite(motor1,HIGH); 
    digitalWrite(motor2,LOW); 
    digitalWrite(motor3,HIGH); 
    digitalWrite(motor4,LOW); 
  }
  else {
    digitalWrite(motor1,LOW); 
    digitalWrite(motor2,LOW); 
    digitalWrite(motor3,LOW); 
    digitalWrite(motor4,LOW); 
  }
}
void buscar(){
  
}
