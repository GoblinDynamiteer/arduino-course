#include <Button.h>

const byte motorForward = 3;
const byte motorReverse = 5;
const byte motor2Forward = 11;
const byte motor2Reverse = 10;
const byte enablePin = 9;
const byte buttonPin = 13;
const byte potPin = A0;
int speed;
bool direction = 1;

Button btnDirection(buttonPin);

void setup(){
	pinMode(motorForward, OUTPUT);
	pinMode(motorReverse, OUTPUT);
	pinMode(enablePin, OUTPUT);
	//pinMode(potPin, INPUT);
	digitalWrite(enablePin, HIGH);
	btnDirection.begin();
}

void loop(){
	speed = map(analogRead(potPin), 0, 1023, 0, 255);
    if (btnDirection.pressed()) {
		if(direction){
			direction = 0;
		}
		else {
			direction = 1;
		}
    }
	if(direction){
		digitalWrite(motorForward, 0);
		analogWrite(motorReverse, speed);
		analogWrite(motor2Forward, speed);
		digitalWrite(motor2Reverse, 0);
		}
	else{
		analogWrite(motorForward, speed);
		digitalWrite(motorReverse, 0);
		digitalWrite(motor2Forward, 0);
		analogWrite(motor2Reverse, speed);
		}
	delay(20);
}