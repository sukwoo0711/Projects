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
//GPIOB->0,2,4,8 OUTPUT
//01010101 =>0x55;
main()   
{            
			// GPIOD->DDR |= 0x01;  // PD.0 as Output
			// GPIOD->CR1 |= 0x01;  // PD.0 as Push Pull Type Output
			// GPIOA->DDR |= 0x08;
			// GPIOA->CR1 |= 0x08;
			GPIOB->DDR |=0x55;
			GPIOB->CR1 |=0x55;
		 while (1)
     {
			 GPIOD->ODR |=1<<0;
				GPIOB->ODR |=(1<<0);
				delay_us(1000);
			 GPIOB->ODR |=(1<<2);
				delay_us(1000);
			 GPIOB->ODR |=(1<<4);
				delay_us(1000);
			 GPIOB->ODR |=(1<<6);
				delay_us(5000);
			 GPIOB->ODR &= ~(1<<0);
			 delay_us(1000);
			 GPIOB->ODR &= ~(1<<2);
			 delay_us(1000);
			 GPIOB->ODR &= ~(1<<4);
			 delay_us(1000);
			 GPIOB->ODR &= ~(1<<6);
			 delay_us(1000);
			 
     }
}
