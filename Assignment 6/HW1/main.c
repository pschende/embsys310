#include "stm32l475xx.h"
#include "system_stm32l4xx.h"

#define DELAY_CONST 100000

void delay(unsigned int pause_units);

int main()
{
  //Enable port A clock
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  
  //Set A5 as output
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1 ;
  GPIOA->MODER |= GPIO_MODER_MODE5_0 ;
  
  while(1){
    GPIOA->ODR ^= GPIO_ODR_OD5;
    delay(2);
  }  
  return 0;
}

void delay(unsigned int pause_units){
	pause_units *= DELAY_CONST;
	while (pause_units > 0){
		pause_units--;
	}
}