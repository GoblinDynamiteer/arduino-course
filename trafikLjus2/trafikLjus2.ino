/*
Inlämningsuppgift 1: Trafikljus
Datalogi

Johan Kämpe och Dylan Saleh

Funktion: 
Trafikljuset med tre LEDar skiftar kontinuerligt mellan grönt och rött,
med cirka åtta sekunders intervall.

Om knappen trycks ned indikeras att en gångtrafikant vill passera.
Gångsignalen kommer gå från rött till grönt, när trafikljuset skiftar till rött.

Den gröna gångljus-LEDen kommer börja blinka efter tio sekunder
för att indikera att gångljuset kommer slå över till rött.
*/

//Pins för LEDar
const byte carRed = 12;
const byte carYellow = 11;
const byte carGreen = 10;
const byte walkRed = 9;
const byte walkGreen = 8;

//Pin för knapp
const byte button = 2;

/* bool-variabler för indikering om knappen 
ha tryckts på, och om trafikljuset står på rött*/
bool buttonPressed = 0;
bool isRed = 1;

/* Funktion som väntar 'wait' antal millisekunder 
och samtidigt kontrollerar om knappen aktiveras. */
void delayCheckButton(int wait){
	//While-loopen körs medan 'wait' inte är 0, för varje varv minskar 'wait' med 1
	while(wait--){
		if(digitalRead(button)){
			//Om knappen aktiveras sätts variabel buttonPressed till 1
			buttonPressed = 1;
		}
		delay(1);
	}
}

//Funktion som blinkar grön LED för gångljus
void blinkGreen(){
	for(int i=0; i<10;i++){
	delay(300);
	digitalWrite(walkGreen, LOW);
	delay(300);
	digitalWrite(walkGreen, HIGH);
	}
}

//Funktion som skiftar trafikljus från rött till grönt
void carRedToGreen(){
	digitalWrite(carYellow, HIGH);
	delayCheckButton(1500);
	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, LOW);
	digitalWrite(carGreen, HIGH);
	//Sätter isRed till 0 för att indikera att grön LED är aktiverad
	isRed = 0;
}

//Funktion som skiftar trafikljus från grönt till rött
void carGreenToRed(){
	digitalWrite(carGreen, LOW);
	digitalWrite(carYellow, HIGH);
	delayCheckButton(1500);
	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, HIGH);
	//Sätter isRed till 0 för att indikera att röd LED är aktiverad
	isRed = 1;
}

void setup(){
	//Startar pins
	pinMode(walkRed, OUTPUT);
	pinMode(walkGreen, OUTPUT);
	pinMode(carGreen, OUTPUT);
	pinMode(carYellow, OUTPUT);
	pinMode(carRed, OUTPUT);
	//Utgångsläge för trafikljus är rött
	digitalWrite(carRed, HIGH);
	digitalWrite(walkRed, HIGH);
	pinMode(button, INPUT);
}

void loop(){
	//Om trafikljus är rött skiftar det till grönt, och vice versa
	if(isRed){
		carRedToGreen();
		}
	else{
		carGreenToRed();
		}
	//Om knappen har aktiverats triggar if-satsen
	if(buttonPressed){
		/* Om trafikljuset står på grönt skiftas det till rött 
		efter ca åtta sekunder */
		if(!isRed){
			delay(8000);
			carGreenToRed();
			}
		delay(1000);
		//Gångsignal skiftar till grönt och väntar ca 10 sekunder
		digitalWrite(walkGreen, HIGH);
		digitalWrite(walkRed, LOW);
		delay(10000);
		//Blinkar grön LED för gångljus
		blinkGreen();
		digitalWrite(walkGreen, LOW);
		digitalWrite(walkRed, HIGH);
		//Sätter buttonPressed till 0 igen, och slår om trafikljus till grön.
		buttonPressed = 0;
		delay(1000);
		carRedToGreen();
	}
	//Vänta ca åtta sekunder mellan trafikljus-byte
	delayCheckButton(8000);
}
