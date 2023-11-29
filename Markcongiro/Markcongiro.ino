int motor1 = 2;
int motor2 = 3;
int motor3 = 4;
int motor4 = 5;

// Pins para el sensor ultrasónico
int pinTri = A4;
int pinEcho = A5;
int recibe ; 

void setup() {
  Serial.begin(9600); 
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  // Configuración para el sensor ultrasónico
  pinMode(pinTri, OUTPUT);
  pinMode(pinEcho, INPUT);

  // Realizar dos medios giros para buscar oponente
  buscarOponente();
}

void loop() {
  // Verificar si se detecta un oponente
  digitalWrite(pinTri,HIGH); 
  delayMicroseconds(25); 
  recibe = pulseIn(pinEcho,HIGH); 
  delay(10);
  digitalWrite(pinTri,LOW); 
  Serial.println(recibe);  
  if (recibe > 700){
    digitalWrite(motor1,HIGH); 
    digitalWrite(motor2,LOW); 
    digitalWrite(motor3,HIGH); 
    digitalWrite(motor4,LOW); 
  }
  else {
    
  }
}

void buscarOponente() {
  // Giro a la izquierda
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(1000); // ajusta el tiempo según sea necesario

  // Giro a la derecha
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  delay(1000); // ajusta el tiempo según sea necesario
}

bool detectarOponente() {
  long duration, distance;
  
  // Generar un pulso de 10 microsegundos en el pin Trig para activar el sensor
  digitalWrite(pinTri, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTri, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTri, LOW);

  // Medir el tiempo que tarda en llegar el eco
  duration = pulseIn(pinEcho, HIGH);

  // Calcular la distancia en centímetros
  distance = duration * 0.034 / 2;

  // Si la distancia es menor a un cierto valor, se considera que hay un oponente cerca
  if (distance < 20) { // Puedes ajustar este valor según la distancia a la que detectas al oponente
    return true;
  } else {
    return false;
  }
}
