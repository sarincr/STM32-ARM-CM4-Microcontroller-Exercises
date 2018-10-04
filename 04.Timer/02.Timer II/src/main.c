#include<stm32f4xx.h>

void TIM_INT_Init()
{
    // Enable clock for TIM2
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    // TIM2 initialization overflow every 200ms/ 5 Hz
    // Update Event (Hz) = timer_clock / ((TIM_Prescaler + 1) * (TIM_Period + 1))
    // Update Event (Hz) = 84MHz / ((4199 + 1) * (4000 + 1)) = 5 Hz
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
    TIM_TimeBaseInitStruct.TIM_Prescaler = 4199;
    TIM_TimeBaseInitStruct.TIM_Period = 4000;
    TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;

    // TIM2 initialize
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStruct);
    // Enable TIM2 interrupt
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    // Start TIM2
    TIM_Cmd(TIM2, ENABLE);

    // Nested vectored interrupt settings
    NVIC_InitTypeDef NVIC_InitStruct;
    NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;  //Highest Priority
    NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0;  //Highest Priority
    NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStruct);
}

int main(void)
{

    // Timer interrupt initialization
    TIM_INT_Init();

    // Clock for GPIOA
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT; // GPIO as OUTPUT
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;  // Push Pull Mode
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5; // Pin Number
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;  // GPIO Speed to 50MHZ
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    while (1)
    {
    }
}


void TIM2_IRQHandler()
{
    // Checks whether the TIM2 interrupt has occurred or not
    if (TIM_GetITStatus(TIM2, TIM_IT_Update))
    {
        GPIO_ToggleBits(GPIOA, GPIO_Pin_5);  // Toggle LED on GPIO Port B Pin 5

        // Clears the TIM2 interrupt pending bit
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
    }
}
