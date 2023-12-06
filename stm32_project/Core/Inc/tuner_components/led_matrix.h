/*
 * Author: Subbotin N.Y.
 *  2022
 */

#ifndef __LED_MATRIX_H__
#define __LED_MATRIX_H__

#include "main.h"

#define	POWER_ADDR		0x0C
#define DECODING_ADDR	0x09
#define	BRIGHT_ADDR		0x0A
#define	SCAN_LIM_ADDR	0x0B
#define	TEST_ADDR		0x0F

#define CLEAR_PERIOD 1000

void matrixTask(void);
void matrixTransmit(uint8_t address, uint16_t data);
void matrixInit(void);
void matrixDisplayNote(uint8_t note, uint8_t shift);
void matrixClear(void);

#endif /* __LED_MATRIX_H__ */
