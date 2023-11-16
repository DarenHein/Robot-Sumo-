#include <Arduino.h>

const int pinsensor = 10;
const int pinmotor1 = 2;
const int pinmotor2 = 3;
const int pinmotor3 = 4;
const int pinmotor4 = 5;
const int trigPin = 6;
const int echoPin = 7;

long duration;
int distance;

void setup() {
  pinMode(pinsensor, INPUT);
  pinMode(pinmotor1, OUTPUT);
  pinMode(pinmotor2, OUTPUT);
  pinMode(pinmotor3, OUTPUT);
  pinMode(pinmotor4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int digitalDistance = digitalRead(pinsensor);

  // Comprobar si el sensor infrarrojo detecta negro
  if (digitalDistance == HIGH) {
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
      // Avanzar
      digitalWrite(pinmotor1, HIGH);
      digitalWrite(pinmotor2, LOW);
      digitalWrite(pinmotor3, HIGH);
      digitalWrite(pinmotor4, LOW);
    }
  } else {
    // Retroceder
    digitalWrite(pinmotor1, LOW);
    digitalWrite(pinmotor2, HIGH);
    digitalWrite(pinmotor3, LOW);
    digitalWrite(pinmotor4, HIGH);

    // Girar una vuelta completa
    digitalWrite(pinmotor1, HIGH);
    digitalWrite(pinmotor2, LOW);
    delay(1000);
    digitalWrite(pinmotor1, LOW);
    digitalWrite(pinmotor2, HIGH);
    delay(1000);
  }

  delay(100);
}
