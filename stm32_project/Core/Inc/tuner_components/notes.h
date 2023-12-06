/*
 * Author: Subbotin N.Y.
 *  2022
 */

#ifndef __NOTES_H__
#define __NOTES_H__

#include "main.h"

typedef enum{
	NONE,
	A,
	A_DIES,
	B,
	C,
	C_DIES,
	D,
	D_DIES,
	E,
	F,
	F_DIES,
	G,
	G_DIES
}notes_t;

void noteCalculationInit(void);
void noteCalculationTask(void);
uint8_t collectNote(uint8_t note, uint16_t ideal, uint16_t down_board, uint32_t freq);

#endif /* __NOTES_H__ */
