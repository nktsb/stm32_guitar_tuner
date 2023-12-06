/*
 * Author: Subbotin N.Y.
 *  2022
 */

#include "battery.h"

#define BATTERY_CHECK_PERIOD 20000

static bool low_bat_flag = 0;
static struct timer battery_check_timer = {0};

bool getLowBatFlag(void){
	return low_bat_flag;
}

void batteryCheckInit(){
	adcInit();
	timer_set(&battery_check_timer, 0);
}

uint8_t batteryCheckTask(void){
	if(timer_expired(&battery_check_timer)){
		timer_set(&battery_check_timer, BATTERY_CHECK_PERIOD);
		adcEnable();
		uint16_t res = adcRead();
		adcDisable();

		res = (res*9900)/4095;

		if(5700 <= res && res < 7000){
			low_bat_flag = 1;
			return 0;
		}else if(res < 5700){
			criticalBatScreen();
			__disable_irq();
			while(1);
		}
		return 1;
	}
	return 1;
}
