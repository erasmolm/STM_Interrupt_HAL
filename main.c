/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	if(GPIO_Pin == KEY_BUTTON_PIN)
		BSP_LED_Toggle(LED4);
	else if(GPIO_Pin == GPIO_PIN_1)
		BSP_LED_Toggle(LED5);
	else if(GPIO_Pin == GPIO_PIN_2)
		BSP_LED_Toggle(LED6);
}

void setup(){
	HAL_Init();
	BSP_LED_Init(LED6);
	BSP_LED_Init(LED5);
	BSP_LED_Init(LED4);
	BSP_LED_Init(LED3);
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);

	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.Pin       = GPIO_PIN_1;
	GPIO_InitStruct.Mode      = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	GPIO_InitStruct.Pin       = GPIO_PIN_2;
	GPIO_InitStruct.Mode      = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI2_IRQn);
}

void loop(){
	HAL_Delay(500);
	BSP_LED_Toggle(LED3);
}

int main(void)
{
	setup();
	for(;;)loop();
	return 1;
}
