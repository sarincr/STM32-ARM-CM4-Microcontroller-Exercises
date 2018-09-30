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

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  //Enable Peripheral clock for GPIOA
	GPIO_InitTypeDef GPIO_InitStructure1;   // Structure definition
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_1;   // Enable GPIO Pin 1 (of GPIOA)
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IN;  // Pinmode to INPUT
	GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOA,&GPIO_InitStructure1);

	EXTI_InitTypeDef EXTI_InitStruct; // Structure definition
	NVIC_InitTypeDef NVIC_InitStruct; // Structure definition
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource1);  // Clock source for GPIOA EXTI0
	EXTI_InitStruct.EXTI_Line = EXTI_Line1;    // Line for interrupt
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;  // Enable interrupt
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;  // Mode of interrupt/event
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising;//Type of interrupt
	EXTI_Init(&EXTI_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel = EXTI1_IRQn;   // Channel for Priority
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x00;  // Primary Priority
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x00;  // Secondary Priority
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;  // Enable Priority and Que
	NVIC_Init(&NVIC_InitStruct);

	 while(1)
	 {

	 }
	  return 0;

}

void EXTI1_IRQHandler(void)  // Execute during Interrupt 0
{

    if (EXTI_GetITStatus(EXTI_Line1)) // Interrupt available
    {
        GPIO_ToggleBits(GPIOA, GPIO_Pin_5);    //Toggle during   Interrupt 0
        EXTI_ClearITPendingBit(EXTI_Line1);   // Exit  Interrupt 0
    }
}
