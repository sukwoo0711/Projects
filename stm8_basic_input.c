#include "stm8s.h"

void myDelay(void);
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
		 GPIOB->DDR = 0x55;
		 GPIOB->CR1 = 0x55;
		 GPIOE->DDR |=~(1<<7);
		 GPIOE->CR1 |=(1<<7);
		 while (1)
     {
			 if(!(GPIOE->IDR &(1<<7)))
			 {
				 GPIOB->ODR |=(1<<0)|(1<<2)|(1<<4)|(1<<6);
				 delay_us(200);
			 }
			 else
			 {
				 GPIOB->ODR &= ~((1<<0)|(1<<2)|(1<<4)|(1<<6));
				 delay_us(200);
			 }
			 /*
				if(!((GPIOE->IDR)&(1<<7)))
				{
				 while(!((GPIOE->IDR)&(1<<7)));
				 GPIOB->ODR |=(1<<0)|(1<<2)|(1<<4)|(1<<6);
				 delay_us(10000);
				}
				else
				GPIOB->ODR &= ~((1<<2)|(1<<4)|(1<<6)|(1<<0));
				delay_us(5000);
			*/
		}
}
