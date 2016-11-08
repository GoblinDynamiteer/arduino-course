#include <Button.h>

Button buttonAdd(13);
Button buttonSub(12);
byte counter;


void setup(){
	Serial.begin(9600);
	buttonAdd.begin();
	buttonSub.begin();
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
}

void loop(){
if(buttonAdd.pressed()){
	Serial.println("Add!");
	Serial.println(counter);
	counter++;
}
if(buttonSub.pressed()){
	Serial.println("Sub!");
	Serial.println(counter);
	counter--;
}

for(int i=0;i<4;i++){
	digitalWrite(i+2, LOW);
}

for(int i=0;i<counter;i++){
	digitalWrite(i+2, HIGH);
}

//delay(10);

}