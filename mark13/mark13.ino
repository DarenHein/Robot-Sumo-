
// mark 13
// mark final espero yo 
int pinTri = A4 ; 
int pinEcho = A5 ; 
int recibe ; 
int motor1 = 2;
int motor2 = 3;
int motor3 = 4;
int motor4 = 5;
int infra = 10 ; 
int recibe2 ; 
void setup() {
  // put your setup code here, to run once:
  pinMode(infra,INPUT); 
  pinMode(pinTri,OUTPUT);
  pinMode(pinEcho,INPUT); 
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  recibe2 = digitalRead(infra);
  Serial.println(infra); 
  if (recibe2 == HIGH){
    digitalWrite(pinTri,HIGH); 
  delayMicroseconds(25); 
  recibe = pulseIn(pinEcho,HIGH); 
  delay(10);
  digitalWrite(pinTri,LOW); 
  Serial.println(recibe); 
  if (recibe <= 3000){ // ataca 
    digitalWrite(motor1,HIGH); 
    digitalWrite(motor2,LOW); 
    digitalWrite(motor3,HIGH); 
    digitalWrite(motor4,LOW); 
  }
  else if (recibe > 3000){ // psea que no hay nadie en la arena y se detiene y busca 
    // Girar hacia la derecha para buscar
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(1000); // Tiempo suficiente para que el robot gire
  
  // Detener el robot
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  delay(500); // Pequeña pausa antes de girar hacia la izquierda
  
  // Girar hacia la izquierda para buscar
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  delay(1000); // Tiempo suficiente para que el robot gire
  
  // Detener el robot
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  delay(25);  
    
  }
  }else {
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(1000); 
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  delay(500); 
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(7000);
  }

  
}
