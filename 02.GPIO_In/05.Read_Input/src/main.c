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

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);  //Enable Peripheral clock for GPIOC
	GPIO_InitTypeDef GPIO_InitStructure1;   // Structure definition
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_13;   // Enable GPIO Pin 3 (of GPIOA)
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IN;  // Pinmode to OuTPUT
	GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOC,&GPIO_InitStructure1);
	 while(1)
	 {
		 int inval = GPIO_ReadInputData(GPIOC)>>13;
		 if (inval == 0)
		 {
			 GPIO_SetBits(GPIOA, GPIO_Pin_5);
		 }
		 else
		 {
			 GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		 }
	 }
	  return 0;

}
