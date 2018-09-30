#include<stm32f4xx.h>
int inA,inB;
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
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_7;   // Enable GPIO Pin 13 (of GPIOC)
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IN;  // Pinmode to INPUT
	GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOC,&GPIO_InitStructure1);

	GPIO_InitTypeDef GPIO_InitStructure2;   // Structure definition
	GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_9;   // Enable GPIO Pin 9 (of GPIOA)
	GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_IN;  // Pinmode to OuTPUT
	GPIO_InitStructure2.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure2.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOA,&GPIO_InitStructure2);
	 while(1)
	 {
		 inA = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7);
		 inB = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_9);
		 if(inA ==1 && inB ==1 )
		 {
			 GPIO_SetBits(GPIOA,GPIO_Pin_5);
		 }
		 if(inA ==0 && inB ==0 )
		 {
			 GPIO_ResetBits(GPIOA,GPIO_Pin_5);
		 }
		 if(inA ==1 && inB ==0 )
		 {
			 GPIO_SetBits(GPIOA,GPIO_Pin_5);
		 }
		 if(inA ==0 && inB == 1 )
		 {
			 GPIO_SetBits(GPIOA,GPIO_Pin_5);
		 }
	 }
	  return 0;
}
