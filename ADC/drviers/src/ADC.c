/*
 * ADC.c
 *
 *  Created on: May 29, 2022
 *      Author: soudy
 */

//        initialization
	// Enable clock to GPIOA
#include "stm32f4xx.h"
#include "ADC.h"


void ADC_Init(struct ADCConfigType* ConfigParamPtr)
{
   // enable port A
	RCC->AHB1ENR |=(1u<<0);

	// pin 0 to analog mmode
	GPIOA->MODER |= (1u<<0);
	GPIOA->MODER |= (1u<<1);

	// Enable clock access to ADC1
	RCC->APB2ENR |= (1 << 8);

    // enable inturpt of adc
	NVIC->ISER[0] |=(1u<<(18));

	// Enable the ADC
	ADC1->CR2 |= (1 << 0);

	// adc scaler plck2 divided by 2
	ADC->CCR &= ~ADC_CCR_ADCPRE;

	// resolution
	ADC1->CR1 |=((ConfigParamPtr->Resolution)<< 24);

	/* Set Vref */
	Vref = ConfigParamPtr->Vref;

    // Right alignment
    ADC1->CR2 &=~(1<<11);

	// check the mode coninous or single
	// and if single set single bit else if contious mode set continous bit
	//enable single mode
	if(ConfigParamPtr->Mode == Single)
	{
		ADC1->CR2 &= ~(1u<<1);
	}
	//else enable continous mode
	else if(ConfigParamPtr->Mode == Continues)
	{
		ADC1->CR2 |= (1u<<1);
	}
}

void ADC_StartConv(unsigned char ChannelNum)
{
	  //select channel
      ADC1->SQR1 = ChannelNum;
	  ADC1->SQR3 = ChannelNum;

	  /* Setting interrupt for regular channels */
	  if(USE_POLLING){
			ADC1->CR1 &=~(1<<5);
	  }
	  else{
		  ADC1->CR1 |= (1<<5);
	  }

	  	//      start of conversion
	ADC1->CR2 |= (1 << 30);   //set swstart bit

}


void ADC_GetConversionState(unsigned char* ConversionStatePtr){

	  /* Check ADC1 EOC */
		  if((ADC1->SR & ADC_SR_EOC) == ADC_SR_EOC){
			  *ConversionStatePtr = 1;
		  }
		  else {
			  *ConversionStatePtr = 0;
		  }
}

unsigned char ADC_ReadData(unsigned short int* DataPtr)
{

	if (USE_POLLING){
		  ADC_GetConversionState(&Conversion_Flag);
	  }

	if (Conversion_Flag){

		      //	1.5 : max sensor voltage
			  //    150 : Max temp sensor can measure
			  // Read analog data and clear EOC flag

			  *DataPtr = (unsigned short int)(((unsigned short int)(ADC1->DR)*150*5)/(1.5f*4095.0f));
				  return 0;
			  }

		  else{
				  return 1;
			  }

}



