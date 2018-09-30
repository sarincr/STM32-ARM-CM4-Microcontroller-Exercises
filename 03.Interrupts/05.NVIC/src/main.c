#include "stm32f4xx.h"
volatile uint32_t timer_ms = 0;


void EXTI15_10_IRQHandler()
{
   if (EXTI_GetITStatus(EXTI_Line13))
   {
     GPIO_SetBits(GPIOA,GPIO_Pin_5);
     EXTI_ClearITPendingBit(EXTI_Line13);
   }
}

void EXTI9_5_IRQHandler()
{
   if (EXTI_GetITStatus(EXTI_Line8))
   {
     GPIO_ResetBits(GPIOA,GPIO_Pin_5);
     EXTI_ClearITPendingBit(EXTI_Line8);
   }
}

int main(void)
{
    EXTI_InitTypeDef External_Int;
    NVIC_InitTypeDef NVIC_Int;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    SysTick_Config(SystemCoreClock / 1000);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  //Enable Peripheral clock for GPIOA
	GPIO_InitTypeDef GPIO_InitStructure;   // Structure definition
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;   // Enable GPIO Pin 5 (of GPIOA)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  // Pinmode to OuTPUT
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);  //Enable Peripheral clock for GPIOA
	GPIO_InitTypeDef GPIO_InitStructure1;   // Structure definition
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_13| GPIO_Pin_8;   // Enable GPIO Pin 13 (of GPIOC)
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_IN;  // Pinmode to INPUT
	GPIO_InitStructure1.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure1.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOC,&GPIO_InitStructure1);



	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource13);
	External_Int.EXTI_Line = EXTI_Line13;
    External_Int.EXTI_Mode = EXTI_Mode_Interrupt;
    External_Int.EXTI_Trigger = EXTI_Trigger_Falling;
    External_Int.EXTI_LineCmd = ENABLE;
    EXTI_Init(&External_Int);
    NVIC_Int.NVIC_IRQChannel = EXTI15_10_IRQn;
    NVIC_Int.NVIC_IRQChannelPreemptionPriority = 0x00;
    NVIC_Int.NVIC_IRQChannelSubPriority = 0x00;
    NVIC_Int.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_Int);


    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource8);
    External_Int.EXTI_Line = EXTI_Line8;
    External_Int.EXTI_Mode = EXTI_Mode_Interrupt;
    External_Int.EXTI_Trigger = EXTI_Trigger_Falling;
    External_Int.EXTI_LineCmd = ENABLE;
    EXTI_Init(&External_Int);
    NVIC_Int.NVIC_IRQChannel = EXTI9_5_IRQn;
    NVIC_Int.NVIC_IRQChannelPreemptionPriority = 0x01;
    NVIC_Int.NVIC_IRQChannelSubPriority = 0x01;
    NVIC_Int.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_Int);


   while (1)
   {

   }
}
