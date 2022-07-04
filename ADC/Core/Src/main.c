#include "stm32f4xx.h"
#include "ADC.h"
#include "LCD.h"
#include "gpio.h"


int main(void)
{

    //   paramters={Resolution,mode,vref}
	// {Resolution if put {0=12 bits , 1= 10 bits ,2 = 8 bits,3= 6 bits}
	// {modes : Single =0 or Continues = 1}
	// {vref:voltage refrence of adc}

	struct ADCConfigType paramters={0,1,5};

	Conversion_Flag = 1;
	ADC_Init(&paramters);
	LCD_Init();

	LCD_DisplayString("Temp value = ");
	ADC_StartConv(0);
	for(int k=0;k<10000;k++); // delay


	while(1)
	{
		if (USE_POLLING){
			valid_adc_value = ADC_ReadData(&dataPtr);
		}
		if(!valid_adc_value){
			 LCD_MoveCursor(0,14);
			 LCD_IntToStr(dataPtr);
			 valid_adc_value = 1;
		 }

		 if(!(ADC1->CR2 & ADC_CR2_CONT)){
			  ADC1->CR2 |= (1 << 30);
		 }

		//       read the data
		// check of conversion is complete0
		//while(!(ADC->SR & EOC bit))
		// uint32_t  data = ADC1->DR;
	// for interrupt check EOCIE bit
	}

}


void ADC_IRQHandler(void)
{
	/* Check ADC1 EOC */

	valid_adc_value = ADC_ReadData(&dataPtr);

}
