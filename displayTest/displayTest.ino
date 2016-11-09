#include "U8glib.h"

U8GLIB_SSD1306_128X64 screen(U8G_I2C_OPT_NONE);

void setup() {
	
}

void loop(){
	screen.firstPage();
	do{
		screen.setFont(u8g_font_gdr14);
		screen.drawStr(0,16, "TRUMP!");
		screen.drawStr(0,32, "PRESIDENT!");
		//screen.drawLine(1,1,126,62);
		//screen.drawLine(126,1,1,62);
		}while(screen.nextPage());
}