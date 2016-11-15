const byte carRed = 12;
const byte carYellow = 11;
const byte carGreen = 10;
const byte walkRed = 9;
const byte walkGreen = 8;
const byte button = 2;
bool buttonPressed = 0;
bool isRed = 0;
int buttonCounter = 0;

void delayCheckButton(int wait){
	while(wait--){
		if(digitalRead(button)){
			buttonPressed = 1;
			do{
				;
			}while(digitalRead(button));
			buttonCounter++;
		}
		delay(1);
		if(buttonCounter > 2){
			break;
		}
	}
}


void blinkGreen(){
	for(int i=0; i<10;i++){
	delay(300);
	digitalWrite(walkGreen, LOW);
	delay(300);
	digitalWrite(walkGreen, HIGH);
	}
}
void carRedToGreen(){
	digitalWrite(carYellow, HIGH);
	delayCheckButton(1500);
	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, LOW);
	digitalWrite(carGreen, HIGH);
	isRed = 0;
}

void carGreenToRed(){
	digitalWrite(carGreen, LOW);
	digitalWrite(carYellow, HIGH);
	delayCheckButton(1500);
	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, HIGH);
	isRed = 1;
}

void setup(){
	pinMode(walkRed, OUTPUT);
	pinMode(walkGreen, OUTPUT);
	pinMode(carGreen, OUTPUT);
	pinMode(carYellow, OUTPUT);
	pinMode(carRed, OUTPUT);
	pinMode(button, INPUT);
	//Utgångsläge trafikljus rött
	digitalWrite(carGreen, HIGH);
	digitalWrite(walkRed, HIGH);
	Serial.begin(9600);
}

void loop(){
	if(isRed && buttonCounter < 3){
		carRedToGreen();
		}
	else{
		carGreenToRed();
		}
	if(buttonPressed){
		Serial.println(buttonCounter);
		if(!isRed){
			if(buttonCounter>2){
				delay(500);
			}
			else{
				delay(8000);
				}
			carGreenToRed();
			}
		delay(1000);
		digitalWrite(walkGreen, HIGH);
		digitalWrite(walkRed, LOW);
		delay(10000);
		blinkGreen();
		digitalWrite(walkGreen, LOW);
		digitalWrite(walkRed, HIGH);
		buttonPressed = 0;
		delay(1000);
		carRedToGreen();
		buttonCounter = 0;
	}
	delayCheckButton(8000);
}


