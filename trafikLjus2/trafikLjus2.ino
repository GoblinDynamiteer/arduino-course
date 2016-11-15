/*
Inl�mningsuppgift 1: Trafikljus
Datalogi

Johan K�mpe och Dylan Saleh

Funktion: 
Trafikljuset med tre LEDar skiftar kontinuerligt mellan gr�nt och r�tt,
med cirka �tta sekunders intervall.

Om knappen trycks ned indikeras att en g�ngtrafikant vill passera.
G�ngsignalen kommer g� fr�n r�tt till gr�nt, n�r trafikljuset skiftar till r�tt.

Den gr�na g�ngljus-LEDen kommer b�rja blinka efter tio sekunder
f�r att indikera att g�ngljuset kommer sl� �ver till r�tt.
*/

//Pins f�r LEDar
const byte carRed = 12;
const byte carYellow = 11;
const byte carGreen = 10;
const byte walkRed = 9;
const byte walkGreen = 8;

//Pin f�r knapp
const byte button = 2;

/* bool-variabler f�r indikering om knappen 
ha tryckts p�, och om trafikljuset st�r p� r�tt*/
bool buttonPressed = 0;
bool isRed = 1;

/* Funktion som v�ntar 'wait' antal millisekunder 
och samtidigt kontrollerar om knappen aktiveras. */
void delayCheckButton(int wait){
	//While-loopen k�rs medan 'wait' inte �r 0, f�r varje varv minskar 'wait' med 1
	while(wait--){
		if(digitalRead(button)){
			//Om knappen aktiveras s�tts variabel buttonPressed till 1
			buttonPressed = 1;
		}
		delay(1);
	}
}

//Funktion som blinkar gr�n LED f�r g�ngljus
void blinkGreen(){
	for(int i=0; i<10;i++){
	delay(300);
	digitalWrite(walkGreen, LOW);
	delay(300);
	digitalWrite(walkGreen, HIGH);
	}
}

//Funktion som skiftar trafikljus fr�n r�tt till gr�nt
void carRedToGreen(){
	digitalWrite(carYellow, HIGH);
	delayCheckButton(1500);
	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, LOW);
	digitalWrite(carGreen, HIGH);
	//S�tter isRed till 0 f�r att indikera att gr�n LED �r aktiverad
	isRed = 0;
}

//Funktion som skiftar trafikljus fr�n gr�nt till r�tt
void carGreenToRed(){
	digitalWrite(carGreen, LOW);
	digitalWrite(carYellow, HIGH);
	delayCheckButton(1500);
	digitalWrite(carYellow, LOW);
	digitalWrite(carRed, HIGH);
	//S�tter isRed till 0 f�r att indikera att r�d LED �r aktiverad
	isRed = 1;
}

void setup(){
	//Startar pins
	pinMode(walkRed, OUTPUT);
	pinMode(walkGreen, OUTPUT);
	pinMode(carGreen, OUTPUT);
	pinMode(carYellow, OUTPUT);
	pinMode(carRed, OUTPUT);
	//Utg�ngsl�ge f�r trafikljus �r r�tt
	digitalWrite(carRed, HIGH);
	digitalWrite(walkRed, HIGH);
	pinMode(button, INPUT);
}

void loop(){
	//Om trafikljus �r r�tt skiftar det till gr�nt, och vice versa
	if(isRed){
		carRedToGreen();
		}
	else{
		carGreenToRed();
		}
	//Om knappen har aktiverats triggar if-satsen
	if(buttonPressed){
		/* Om trafikljuset st�r p� gr�nt skiftas det till r�tt 
		efter ca �tta sekunder */
		if(!isRed){
			delay(8000);
			carGreenToRed();
			}
		delay(1000);
		//G�ngsignal skiftar till gr�nt och v�ntar ca 10 sekunder
		digitalWrite(walkGreen, HIGH);
		digitalWrite(walkRed, LOW);
		delay(10000);
		//Blinkar gr�n LED f�r g�ngljus
		blinkGreen();
		digitalWrite(walkGreen, LOW);
		digitalWrite(walkRed, HIGH);
		//S�tter buttonPressed till 0 igen, och sl�r om trafikljus till gr�n.
		buttonPressed = 0;
		delay(1000);
		carRedToGreen();
	}
	//V�nta ca �tta sekunder mellan trafikljus-byte
	delayCheckButton(8000);
}
