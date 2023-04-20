#include <VarSpeedServo.h> 

VarSpeedServo myservo1;

const int servoPin1 = 9;

servoSequencePoint slow[] = {{100,20},{20,20},{60,50}};
servoSequencePoint twitchy[] = {{0,255},{180,40},{90,127},{120,60}};

const int analogPin = A0;

void setup() {
  myservo1.attach(servoPin1);
}

void loop() {
    int sensorValue = analogRead(analogPin);
    if (sensorValue > 200) {
        myservo1.sequencePlay(slow, 3);
    } else {
        myservo1.sequencePlay(twitchy, 4, true, 2);
    }
    delay(2);
}

