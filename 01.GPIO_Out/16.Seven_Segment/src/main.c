#include<stm32f4xx.h>
void Delay(volatile uint32_t nCount)
{
	for (; nCount != 0; nCount--);
}
void GPIO_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	GPIOx->ODR ^= GPIO_Pin;
}
int i,count;
int main(void)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);  //Enable Peripheral clock for GPIOA
	GPIO_InitTypeDef GPIO_InitStructure;   // Structure definition
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;   // Enable All GPIO Pins  (of GPIOA)
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  // Pinmode to OuTPUT
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //// Push pull
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;  // // Pull Down model
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  // Speed to Fast speed
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	 while(1)
	 {
		 //for displaying 0
		 GPIOA->ODR = 0x0007;
		 GPIOC->ODR = 0x0007;
		 Delay(0xFFFFFF);
		 //for displaying 1
		 GPIOA->ODR = 0x0001;
		 GPIOC->ODR = 0x0004;
		 Delay(0xFFFFFF);
		 //for displaying 2
		 GPIOA->ODR = 0x000B;
		 GPIOC->ODR = 0x0003;
		 Delay(0xFFFFFF);
		 //for displaying 3
		 GPIOA->ODR = 0x000B;
		 GPIOC->ODR = 0x0006;
		 Delay(0xFFFFFF);
		 //for displaying 4
		 GPIOA->ODR = 0x000D;
		 GPIOC->ODR = 0x0004;
		 Delay(0xFFFFFF);
		 //for displaying 5
		 GPIOA->ODR = 0x000E;
		 GPIOC->ODR = 0x0006;
		 Delay(0xFFFFFF);
		 //for displaying 6
		 GPIOA->ODR = 0x000E;
		 GPIOC->ODR = 0x0007;
		 Delay(0xFFFFFF);
		 //for displaying 7
		 GPIOA->ODR = 0x0003;
		 GPIOC->ODR = 0x0004;
		 Delay(0xFFFFFF);
		 //for displaying 8
		 GPIOA->ODR = 0x000F;
		 GPIOC->ODR = 0x0007;
		 Delay(0xFFFFFF);
		 //for displaying 9
		 GPIOA->ODR = 0x000F;
		 GPIOC->ODR = 0x0006;
		 Delay(0xFFFFFF);
	 }
	  return 0;
}

