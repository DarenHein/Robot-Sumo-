#include <Arduino.h>
// mark 8 sin sensor infra solo ultrasonico 
const int pinmotor1 = 2;
const int pinmotor2 = 3;
const int pinmotor3 = 4;
const int pinmotor4 = 5;
const int trigPin = A4;
const int echoPin = A5;
const buzzer = 10 ; 
long duration;
int distance;
void setup() {
  pinMode(buzzer,OUTPUT); 
  pinMode(pinmotor1, OUTPUT);
  pinMode(pinmotor2, OUTPUT);
  pinMode(pinmotor3, OUTPUT);
  pinMode(pinmotor4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(buzzer,HIGH); 
  delay(1000); 
  digitalWrite(buzzer,LOW);   
  delay(4000);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  if (distance < 20) {
    digitalWrite(pinmotor1, HIGH);
    digitalWrite(pinmotor2, LOW);
    digitalWrite(pinmotor3, HIGH);
    digitalWrite(pinmotor4, LOW);
  } else {
  }

  delay(100);
}

