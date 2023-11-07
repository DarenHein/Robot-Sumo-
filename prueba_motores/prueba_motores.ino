// prueba de motores 4 motores con puente h 
int motor1 = 2 ;
int motor2 = 3 ;
int motor3 = 4 ;
int motor4 = 5 ;
int motor5 = 6 ; 
int motor6 = 7 ; 
int motor7 = 8 ; 
int motor8 = 9 ; 
void setup() {
  // put your setup code here, to run once:
  pinMode(motor1,OUTPUT); 
  pinMode(motor2,OUTPUT); 
  pinMode(motor3,OUTPUT); 
  pinMode(motor4,OUTPUT); 
  pinMode(motor5,OUTPUT); 
  pinMode(motor6,OUTPUT); 
  pinMode(motor7,OUTPUT); 
  pinMode(motor8,OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,HIGH);

  digitalWrite(motor3,LOW);
  digitalWrite(motor4,HIGH);

  digitalWrite(motor5,LOW);
  digitalWrite(motor6,HIGH);

  digitalWrite(motor7,LOW);
  digitalWrite(motor8,HIGH);

}
