#include <Button.h>

const byte motor1Forward = 3;
const byte motor1Reverse = 5;
const byte motor2Forward = 11;
const byte motor2Reverse = 10;
const byte enablePin = 9;
const byte buttonPin = 13;
const byte potPin = A0;
int speed;
bool direction = 1;

Button btnDirection(buttonPin);

void setup(){
	pinMode(motor1Forward, OUTPUT);
	pinMode(motor1Reverse, OUTPUT);
	pinMode(motor2Forward, OUTPUT);
	pinMode(motor2Reverse, OUTPUT);
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
		digitalWrite(motor1Forward, 0);
		analogWrite(motor1Reverse, speed);
		
		analogWrite(motor2Forward, 0);
		digitalWrite(motor2Reverse, speed);
		}
	else{
		analogWrite(motor1Forward, speed);
		digitalWrite(motor1Reverse, 0);
		
		digitalWrite(motor2Forward, speed);
		analogWrite(motor2Reverse, 0);
		}
	delay(10);
}