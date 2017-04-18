//pd0 -> default LED
#include "stm8s.h"


unsigned int readADC1(unsigned int channel)
{
	unsigned int val = 0;
	ADC1->CSR |=((0x0f)&channel);
	ADC1->CR2 |=(1<<3);
	ADC1->CR1 |=(1<<0);
	ADC1->CR1 |=(1<<0);
	while((ADC1->CSR)&(1<<7));
	val|=(unsigned int)ADC1->DRL;
	val|=(unsigned int)ADC1->DRH<<8;
	ADC1->CR1 &=~(1<<0);
	val &=0x03ff;
	return (val);
}

void GPIO_Config(void);
void GPIO_Config(void)
{
	GPIOD->DDR = 0x01;
	GPIOD->CR1 = 0x01;
}
void myDelay(unsigned int value);
void myDelay(unsigned int value)
{
	unsigned int i,j;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<value;j++);
	}
}
void delay_us(uint32_t nCount);
void delay_us(uint32_t nCount)
{
		int i;
		for(;nCount!=0;nCount--){
			for(i=0;i<10;i++);	//asm("NOP");
		}
}
int loop = 0;
main()   
{ 
	 unsigned int stepNos;
	 GPIO_Config();
	 while (1)
	 {
		//stepNos = readADC1(3);
		stepNos = 1000;
		GPIOD->ODR |=(1<<0);
		myDelay(stepNos);
		GPIOD->ODR&=~(1<<0);
		myDelay(stepNos);
	 }
}
