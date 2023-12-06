/*
 * Author: Subbotin N.Y.
 *  2022
 */

#ifndef __SCREENS_H__
#define __SCREENS_H__

#include "main.h"

typedef enum{
	LOW_BAT = 13,
	CRIT_BAT,
	SAD,
	SMILE,
	WINK
}icons;

void lowBatScreen(void);
void criticalBatScreen(void);
void helloWorldScreen(void);

#endif /* __SCREENS_H__ */
