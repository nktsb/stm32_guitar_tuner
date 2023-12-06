#ifndef __ADC_H__
#define __ADC_H__

#include "main.h"

void adcInit(void);
uint16_t adcRead(void);
void adcEnable(void);
void adcDisable(void);

#endif /* __ADC_H__ */
