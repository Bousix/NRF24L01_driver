#include "wif_drv.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_exti.h"

void NRF_PinConfigure()
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  
  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz;
  
  GPIO_Init(GPIOD, &GPIO_InitStruct);
  GPIO_WriteBit(GPIOD,GPIO_Pin_15, Bit_SET);
}

void NRF_InterruptConfigure()
{
  GPIO_InitTypeDef GPIO_InitStruct;
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  
  GPIO_StructInit(&GPIO_InitStruct);
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_25MHz;
  
  GPIO_Init(GPIOA, &GPIO_InitStruct);
  
  //Configuring EXTI 
  EXTI_InitTypeDef EXTI_Struct;
  EXTI_Struct.EXTI_Line = EXTI_Line0;
  EXTI_Struct.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_Struct.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_Struct.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_Struct);
  
  //Enabling EXTI interrupt in the NVIC
  NVIC_InitTypeDef NVIC_InitStructure;
   
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}