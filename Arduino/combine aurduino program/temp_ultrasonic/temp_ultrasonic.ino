#include <Adafruit_MLX90614.h>
#include <Wire.h> 
#include <Servo.h>

Servo servo;

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

//................Temperature Sensor Wiring..............

const int trigPin = 7; // Trigger Pin of Ultrasonic Sensor Temp
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor Temp

//........ Senitization Sensor Wiring.................

const int trigPin2 = 9; // Trigger Pin of Ultrasonic Sensor senitization
const int echoPin2 = 8; // Echo Pin of Ultrasonic Sensor  senitization


void setup() {
   Serial.begin(9600); // Starting Serial Terminal
     mlx.begin();   // Mlx temp sensor Setup
     //.....Temperature sensor Wiring...........
     pinMode(trigPin, OUTPUT);
     pinMode(echoPin, INPUT);      

     ///// sentization Wiring

     pinMode(trigPin2, OUTPUT);
     pinMode(echoPin2, INPUT);
     servo.attach(3);
     servo.write(0);
}


void loop() {
   long duration, inches;
   digitalWrite(trigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);


   if(inches<=2){
   Serial.print("Inches:");
   Serial.print(inches);
   Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
    
    }
  
   delay(1000);

   //. Temperature End Senitization start

    Senitization();
    }



long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}



void Senitization(){
  
  long duration2, inches2;

digitalWrite(trigPin2, LOW);

delayMicroseconds(2);

digitalWrite(trigPin2, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin2, LOW);

duration2 = pulseIn(echoPin2, HIGH);

inches2 = microsecondsToInches(duration2);

  
if (inches2 <= 3) {


servo.write(180);

}

else{


servo.write(0); 
}
  
delay(500);
  }
