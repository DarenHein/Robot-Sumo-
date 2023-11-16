#include <Arduino.h>
// mark 8 sin sensor infra solo ultrasonico 
const int pinmotor1 = 2;
const int pinmotor2 = 3;
const int pinmotor3 = 4;
const int pinmotor4 = 5;
const int pinUltrasonicSensor = 9;
const int trigPin = A4;
const int echoPin = A5;

long duration;
int distance;

void setup() {
  pinMode(pinmotor1, OUTPUT);
  pinMode(pinmotor2, OUTPUT);
  pinMode(pinmotor3, OUTPUT);
  pinMode(pinmotor4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Retraso de 5 segundos
  delay(5000);
}

void loop() {
  // Activar el sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Leer el sensor ultrasónico
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Comprobar si hay un obstáculo detectado por el sensor ultrasónico
  if (distance < 20) {
    // Seguir avanzando
    digitalWrite(pinmotor1, HIGH);
    digitalWrite(pinmotor2, LOW);
    digitalWrite(pinmotor3, HIGH);
    digitalWrite(pinmotor4, LOW);
  } else {
    // No hacer nada
  }

  delay(100);
}

