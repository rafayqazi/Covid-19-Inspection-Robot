#include <Adafruit_MLX90614.h>
#include <Wire.h> 

Adafruit_MLX90614 mlx = Adafruit_MLX90614();


const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
     mlx.begin();  
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   Serial.print("Inches:");
   Serial.print(inches);

   if(inches<=2){
    Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF()); 
    Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");
    
    }
   

   
   Serial.println();
   delay(1000);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
