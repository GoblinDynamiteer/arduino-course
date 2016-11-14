
const byte carRed = 12;
const byte carYellow = 11;
const byte carGreen = 10;
const byte walkRed = 9;
const byte walkGreen = 8;
const byte button = 2;

void carRedToGreen(){
	digitalWrite(carYellow, HIGH);
	delay(1500);
	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, LOW);
	digitalWrite(carGreen, HIGH);
}

void carGreenToRed(){
	digitalWrite(carGreen, LOW);
	digitalWrite(carYellow, HIGH);
	delay(1500);
	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, HIGH);
}

void setup(){
	pinMode(walkRed, OUTPUT);
	pinMode(walkGreen, OUTPUT);
	pinMode(carGreen, OUTPUT);
	pinMode(carYellow, OUTPUT);
	pinMode(carRed, OUTPUT);
	pinMode(button, INPUT);
	//Utgångsläge trafikljus grönt, gångljus rött
	digitalWrite(carGreen, HIGH);
	digitalWrite(walkRed, HIGH);
	Serial.begin(9600);
}

void loop(){
	if(digitalRead(button)){
		carGreenToRed();
		delay(1000);
		digitalWrite(walkGreen, HIGH);
		digitalWrite(walkRed, LOW);
		delay(10000);
		for(int i=0; i<10;i++){
			delay(300);
			digitalWrite(walkGreen, LOW);
			delay(300);
			digitalWrite(walkGreen, HIGH);
		}
		digitalWrite(walkGreen, LOW);
		digitalWrite(walkRed, HIGH);
		delay(1000);
		carRedToGreen();
	}
}

