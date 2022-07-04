/*
 * ADC.h
 *
 *  Created on: May 29, 2022
 *      Author: soudy
 */

#ifndef INC_ADC_H_
#define INC_ADC_H_

#define USE_POLLING 1

struct ADCConfigType
{
	enum {resolution_6 = 3, resolution_8 = 2, resolution_10 = 1, resolution_12 = 0} Resolution;
	enum {Single = 0 , Continues = 1} Mode;
	float Vref;
};


unsigned short int dataPtr;
unsigned char Conversion_Flag;
unsigned char Vref;
unsigned char valid_adc_value;

unsigned char ADC_ReadData(unsigned short int* DataPtr);
void ADC_Init(struct ADCConfigType* ConfigParamPtrS);
void ADC_GetConversionState(unsigned char* ConversionStatePtr);
void ADC_StartConv(unsigned char ChannelNum);

#endif /* INC_ADC_H_ */
