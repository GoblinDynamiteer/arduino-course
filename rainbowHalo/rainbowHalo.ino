#include <Adafruit_NeoPixel.h>

const byte neoPin = 10;
const byte neoPixels = 24;
byte neoBright = 100;

Adafruit_NeoPixel ring = Adafruit_NeoPixel(neoPixels, neoPin, NEO_RBG);

void setup(){
	ring.begin();
	ring.setBrightness(neoBright);
	ring.show();
}

void loop(){
	for(int i = 0; i<neoPixels;i++){
		ring.setPixelColor(i, ring.Color(255,0,0));
		ring.show();
		//delay(42);
	}
	ring.setBrightness(neoBright--);
	delay(10);
	if(neoBright == 0){
		neoBright = 100;
	}

}
