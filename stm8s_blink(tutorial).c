#include "stm8s.h"
 
 
void myDelay(void);
void myDelay()
{
   int i,j;
   for(i=0;i<1000;i++)
   {
       for(j=0;j<100;j++);    
       }  
}   
int loop = 0;
main()   
{
//PA3 LED
			 GPIOD->DDR |= 0x01;  // PD.0 as Output
			 GPIOD->CR1 |= 0x01;  // PD.0 as Push Pull Type Output
			 GPIOA->DDR |= 0x08;  
			 GPIOA->CR1 |= 0x08;
		 while (1)
     {
			 GPIOD->ODR |=1<<0;
			 GPIOA->ODR |=1<<3;
			 myDelay();
			 GPIOD->ODR &= ~(1<<0);
			 GPIOA->ODR &= ~(1<<3);
			 myDelay();
     }
}
