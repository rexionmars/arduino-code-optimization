#include <VarSpeedServo.h> 
 
VarSpeedServo myservo1;
VarSpeedServo myservo2;
 
const int servoPin1 = 9;
const int servoPin2 = 10;
 
void setup() { 
    myservo1.attach(servoPin1);
    myservo1.write(0,255,false);
    myservo2.attach(servoPin2);
    myservo2.write(0,255,true);
} 

void loop() {
    myservo1.write(180,127,false);
    myservo2.write(180,127,true);
  
    myservo1.write(0,30,false);
    myservo2.write(0,30,true);
} 
