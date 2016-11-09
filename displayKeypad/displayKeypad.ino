#include "U8glib.h"
#include "Keypad.h"

U8GLIB_SSD1306_128X64 screen(U8G_I2C_OPT_NONE);


const byte ROWS = 4;
const byte COLS = 3;

char keys[ROWS][COLS] ={
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'},
	{'*','0','#'}
};

//byte rowPins[ROWS] = {1, 2, 3, 4};
//byte colPins[COLS] = {5, 6, 7};

byte rowPins[ROWS] = {5, 6, 7, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 3, 4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
	
}

void loop(){
	char key = keypad.getKey();
	char string[4];
	if(key != NO_KEY){
		sprintf(string, "%c", key);
		screen.firstPage();
		do{
			screen.setFont(u8g_font_gdr14);
			screen.drawStr(0,16, string);
			//screen.drawStr(0,32, "PRESIDENT!");
			}while(screen.nextPage());
	}
	delay(20);
}