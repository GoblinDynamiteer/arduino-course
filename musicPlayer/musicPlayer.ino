#include "pitches.h"
#include "melody.h"

const byte buzzerPin = 10;

void setup(){
	playTone(melody, noteDurations, sizeof(melody)/sizeof(int));
}

void loop(){
}

void playTone(int melody[], int noteDurations[], int length){
	for(int thisNote = 0; thisNote < length; thisNote++){
		int noteDuration = 1000 / noteDurations[thisNote];
		tone(buzzerPin, melody[thisNote], noteDuration);
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		noTone(buzzerPin);
	}
}