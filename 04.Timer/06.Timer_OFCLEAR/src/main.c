#include "stm32f4xx.h"
volatile uint32_t timer_tick;

void GPIO_INIT_EXAMPLE(void)
{
  GPIO_InitTypeDef  GPIO_InitStructure;

  /* GPIOA Periph clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  /* Configure PA5 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void TIMER_INIT_EXAMPLE(void)
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;


  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInitStructure.TIM_Prescaler = 10000-1;
  TIM_TimeBaseInitStructure.TIM_Period = 8400 - 1;
  TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

  TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE);

  TIM_Cmd(TIM2,ENABLE);
}

void NVIC_INIT_EXAMPLE(uint16_t IRQ)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  NVIC_InitStructure.NVIC_IRQChannel = IRQ;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_Init(&NVIC_InitStructure);
}

void TIM2_IRQHandler(void)
{
  while( (TIM2->SR & (1<<0)) > 0 )
  {
  TIM2->SR &= ~(1<<0); // Clear UIF flag
  GPIOA->ODR ^= GPIO_Pin_5; // Toggle LED
  }
}


int main(void)
{

  SystemInit();

  TIMER_INIT_EXAMPLE();

  NVIC_INIT_EXAMPLE(TIM2_IRQn);

  GPIO_INIT_EXAMPLE();


  while(1)
    {

    if (timer_tick >= 1)
    {

      timer_tick = 0;
    }
    }
}
