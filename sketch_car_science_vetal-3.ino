 // mark ruso 
#define Trig 8
#define Echo 9


const int in1 = 7;    // L298N-1 pin 7
const int in2 = 6;    // L298N-1 pin 8
const int ena = 11;    // L298N-1 pin 11

const int in3 = 5;    // L298N-1 pin 5
const int in4 = 4;    // L298N-1 pin 4
const int enb = 3;    // L298N-1 pin 3

const int analogPin1 = 13; // подключение датчика

void setup() 
{  
  Serial.begin(9600); // Задаем скорость работы монитор порта 
  pinMode(Trig, OUTPUT); // выход 
  pinMode(Echo, INPUT); // вход 
  pinMode(13, INPUT);
  
  pinMode(in1, OUTPUT);      // connection to L298n
  pinMode(in2, OUTPUT);      // connection to L298n
  pinMode(ena, OUTPUT);      // connection to L298n
    
  pinMode(in3, OUTPUT);      // connection to L298n
  pinMode(in4, OUTPUT);      // connection to L298n
  pinMode(ena, OUTPUT);      // connection to L298n

} 
unsigned int impulseTime=0; 
unsigned int distance_sm=0; 

void loop() 
{  
  digitalWrite(Trig, HIGH); 
  delayMicroseconds(10); // 10 микросекунд 
  digitalWrite(Trig, LOW);
  impulseTime=pulseIn(Echo, HIGH); // замеряем длину импульса 
  distance_sm=impulseTime/58; // переводим в сантиметры 



Serial.println(digitalRead(13)); // Выводим значение в порт 


if (digitalRead(13) == LOW) 
{
  

     if (distance_sm >15)  // если расстояние больше 15 сантиметров, то едем вперед
       //   if (distance_sm <15 && distance_sm >0)  // если расстояние от 0 до 15 сантиметров, то едем вперед
  {     
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(ena, 50);
      
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enb, 50);
  }  
  else  // в противном случае поворачиваемся 350 мс и ищем препятствие (соперника)
 {   
     digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(ena, 60);
      
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enb, 60);
      
    
      
  

  }  
  
  }

else 

{     

      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      analogWrite(ena, 65);
      
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enb, 65);
      
    
      delay(500);  
      
      
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(ena, 55);
      
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enb, 55);
      
    
      delay(800); 
      }



 

  delay(50); 
  
}
