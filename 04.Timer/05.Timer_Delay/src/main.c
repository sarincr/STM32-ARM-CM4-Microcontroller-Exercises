#include "stm32f4xx.h"

void InitializeLEDs()
{
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
GPIO_InitTypeDef gpioStructure;
gpioStructure.GPIO_Pin = GPIO_Pin_5 ;
gpioStructure.GPIO_Mode = GPIO_Mode_OUT;
gpioStructure.GPIO_OType = GPIO_OType_PP;
gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;
gpioStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
GPIO_Init(GPIOA, &gpioStructure);
}

void InitializeTimer()
{
// Ftim2 = 84Mhz
TIM_TimeBaseInitTypeDef timerInitStructure;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
timerInitStructure.TIM_Prescaler = 168000;
timerInitStructure.TIM_Period = 1000;
timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
timerInitStructure.TIM_ClockDivision = 0;
timerInitStructure.TIM_RepetitionCounter = 0;
TIM_TimeBaseInit(TIM2, &timerInitStructure);
}

void delay_ms(uint16_t ms)
{
TIM_SetCounter(TIM2, 0);    // Make sure TIM2 Counter start from zero
TIM_Cmd(TIM2, ENABLE);              // Enalbe TIM2
while(TIM_GetCounter(TIM2) < ms);   // Wait ms Miliseconds
TIM_Cmd(TIM2, DISABLE);
}

int main(void)
{
InitializeLEDs();
InitializeTimer();
    while(1)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_5);
        delay_ms(1000);
        GPIO_ResetBits(GPIOA, GPIO_Pin_5);
        delay_ms(1000);
    }
}
