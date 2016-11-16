#include <Servo.h>

Servo motor;

const byte potPin = A0;
const byte servoPin = 9;

int pos;

void setup(){
	motor.attach(servoPin);
	pinMode(potPin, INPUT);
	Serial.begin(9600);
}

void loop(){
	Serial.println(pos);
	pos = map(analogRead(potPin), 0, 1023, 0, 180);
	motor.write(pos);
	delay(15);
}