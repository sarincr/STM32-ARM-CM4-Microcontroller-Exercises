#include<stm32f4xx.h>
int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);  //Enable Peripheral clock for GPIOB
	GPIO_InitTypeDef GPIO_InitStructure;   // Structure definition
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;   // Enable GPIO Pin 3 (of GPIOB)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  // Pinmode to OuTPUT
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	 while(1)
	 {
		 GPIO_SetBits(GPIOB, GPIO_Pin_3);  // Set PORTB Pin 3 to High
	     for(int i=0;i<10000000;i++);
	     GPIO_ResetBits(GPIOB, GPIO_Pin_3); // Set PORTB Pin 3 to Low
	     for(int i=0;i<10000000;i++);
	 }
	  return 0;

}
