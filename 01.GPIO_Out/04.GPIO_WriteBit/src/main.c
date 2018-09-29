#include<stm32f4xx.h>
int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  //Enable Peripheral clock for GPIOA
	GPIO_InitTypeDef GPIO_InitStructure;   // Structure definition
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;   // Enable GPIO Pin 5 (of GPIOA)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  // Pinmode to OuTPUT
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	 while(1)
	 {
		 GPIO_WriteBit(GPIOA,GPIO_Pin_5,1); // Set PORTA Pin 5 to High
	     for(int i=0;i<1000000;i++);
	     GPIO_WriteBit(GPIOA,GPIO_Pin_5,0);// Set PORTA Pin 5 to Low
	     for(int i=0;i<1000000;i++);
	 }
	  return 0;

}
