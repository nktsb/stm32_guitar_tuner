/*
 * Author: Subbotin N.Y.
 *  2022
 */

#include "notes.h"

#define START_BOARD (666)
#define END_BOARD (37453)

#define GD_A_BOARD_1 (2670)
#define A_FREQ (2750)

#define A_AD_BOARD (2830)
#define AD_FREQ (2913)

#define AD_B_BOARD (2990)
#define B_FREQ (3087)

#define B_C_BOARD (3180)
#define C_FREQ (3270)

#define C_CD_BOARD (3360)
#define CD_FREQ (3465)

#define CD_D_BOARD (3560)
#define D_FREQ (3671)

#define D_DD_BOARD (3780)
#define DD_FREQ (3889)

#define DD_E_BOARD (4010)
#define E_FREQ (4121)

#define E_F_BOARD (4240)
#define F_FREQ (4365)

#define F_FD_BOARD (4490)
#define FD_FREQ (4625)

#define FD_G_BOARD (4760)
#define G_FREQ (4900)

#define G_GD_BOARD (5040)
#define GD_FREQ (5190)

#define GD_A_BOARD_2 (5340)

#define BUF_SIZE (12)

static const uint16_t boards_set[13][3] = {
	{GD_A_BOARD_1, 	A_FREQ,  A},
	{A_AD_BOARD,   	AD_FREQ, A_DIES},
	{AD_B_BOARD,	B_FREQ,  B},
	{B_C_BOARD, 	C_FREQ,  C},
	{C_CD_BOARD, 	CD_FREQ, C_DIES},
	{CD_D_BOARD, 	D_FREQ,  D},
	{D_DD_BOARD, 	DD_FREQ, D_DIES},
	{DD_E_BOARD, 	E_FREQ,  E},
	{E_F_BOARD, 	F_FREQ,  F},
	{F_FD_BOARD, 	FD_FREQ, F_DIES},
	{FD_G_BOARD, 	G_FREQ,  G},
	{G_GD_BOARD, 	GD_FREQ,  G_DIES},
	{GD_A_BOARD_2, 	A_FREQ,  A}
};

#define	NOTE_BOARD	boards_set[12-i][0]
#define NOTE_FREQ	boards_set[12-i][1]
#define NOTE		boards_set[12-i][2]

void noteCalculationInit(void){
	initTIM1();
}

uint32_t period = 0;
uint8_t prev_note = 0;

void noteCalculationTask(void){
	if(period){
		if(START_BOARD < period && period <= END_BOARD){

			uint32_t freq = 100000000/period; //Hz * 10^-2
			period = 0;

			while(freq >= GD_A_BOARD_2)
				freq >>= 1;		//instead of freq /= 2

			for(uint8_t i = 0; i <= 12; i++){	//searching note in list
				if(freq > NOTE_BOARD){
					collectNote(NOTE, NOTE_FREQ, NOTE_BOARD, freq);
					break;
				}
			}

		}else{
			prev_note = NONE; //error
		}
	}
}

uint8_t collectNote(uint8_t note, uint16_t ideal, uint16_t down_board, uint32_t freq){
	static uint32_t freq_sum = 0;
	static uint8_t note_counter = 0;
	if((note != prev_note) && note_counter){
		prev_note = NONE;
		note_counter = 0;
		freq_sum = 0;
		return 0;
	}else{
		freq_sum += freq;
		note_counter++;
	}

	if(note_counter == BUF_SIZE){

		float shift = 0;

		shift = ((freq_sum/BUF_SIZE) - down_board)/((float)(ideal - (down_board))/7);
		uint8_t trig = (uint8_t)rint((double)shift);

		note_counter = 0;
		prev_note = 0;
		freq_sum = 0;

		setNewNoteAndTrig((notes_t)note, trig);

		return 1;
	}
	prev_note = note;
	return 1;
}


