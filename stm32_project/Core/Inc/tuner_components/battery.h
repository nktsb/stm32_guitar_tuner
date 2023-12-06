/*
 * Author: Subbotin N.Y.
 *  2022
 */

#ifndef __BATTERY_H__
#define __BATTERY_H__

#include "main.h"

bool getLowBatFlag(void);
void batteryCheckInit(void);
uint8_t batteryCheckTask(void);

#endif /* __BATTERY_H__ */
