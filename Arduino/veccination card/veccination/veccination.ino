#include <Servo.h>

#define echoPin 8
#define trigPin 9



Servo servo;


void setup() {

Serial.begin (9600);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

servo.attach(3);
servo.write(0);

}

void loop() {
Senitization();

}


//inches function

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}


void Senitization(){
  
  long duration, inches;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

inches = microsecondsToInches(duration);

  
if (inches<= 3) {


servo.write(180);

}

else{

servo.write(0); 
}
  
delay(500);
  }
