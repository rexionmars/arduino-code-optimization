#include <VarSpeedServo.h> 
 
VarSpeedServo myservo;
 
const int potPin = 0;
const int servoPin = 9;

int val;
 
 
void setup() {
    myservo.attach(servoPin); 
} 
 
void loop() {
    val = analogRead(potPin); 
    val = map(val, 0, 1023, 0, 180); 
    myservo.write(val); 
    delay(15); 
} 
