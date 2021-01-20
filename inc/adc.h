
#ifndef __ADC_H__
#define __ADC_H__


extern void ADCInit(uint8_t speed);

extern uint8_t ADC_ChannelSelect(uint8_t ch);

extern uint8_t VoltageCMPModeInit(uint8_t fo,uint8_t re);

#endif
