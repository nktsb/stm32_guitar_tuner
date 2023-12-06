/*
 * Author: Subbotin N.Y.
 *  2022
 */

#include "screens.h"

void lowBatScreen(void){
	matrixTransmit(BRIGHT_ADDR, 0x0505); //brightness
	for(uint8_t b = 0; b < 3; b++){
		matrixDisplayNote(LOW_BAT, 0);
		delay(350);
		matrixClear();
		delay(350);
	}
}

void criticalBatScreen(void){
	matrixTransmit(0x0A,0x0202); //brightness
	for(uint8_t b = 0; b < 3; b++){
		matrixDisplayNote(CRIT_BAT, 0);
		delay(350);
		matrixClear();
		delay(350);
	}
	matrixDisplayNote(SAD, 0);
	delay(6000);
	matrixClear();
}

void helloWorldScreen(void){
	matrixDisplayNote(SMILE, 0);
	delay(500);
	matrixDisplayNote(WINK, 0);
	delay(500);
	matrixDisplayNote(SMILE,0);
	delay(500);
	matrixClear();
}
