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
		int i;
		for(i=0;i<8;i++)
		{
			if(i%2==0){
				GPIOB->DDR |=(1<<i);
				GPIOB->CR1 |=(1<<i);
			}
		}
		GPIOB->CR1 |=((1<<0)||(1<<2)||(1<<4)||(1<<6));
		 while (1)
     {
		 GPIOB->ODR =(1<<0)|(1<<4);
		 delay_us(5000);
		 GPIOB->ODR &=~((1<<2)|(1<<6));
		 delay_us(5000);
		 
		 GPIOB->ODR =(1<<2)|(1<<6);
		 delay_us(5000);
		 GPIOB->ODR &=~((1<<0)|(1<<4));
		 delay_us(5000);		 
     }
}
