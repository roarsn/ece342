/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"
#include <stdio.h>
#include "config.h"

typedef enum {
LED_RED, // A0
LED_BLUE, //A2
LED_GREEN //A4
} LED_Colour;


typedef struct State{
LED_Colour activeLight;
uint16_t time;
struct State* next_state;
} State;

//define states
State redState = {LED_RED, (uint16_t)3000, NULL};
State blueState = {LED_BLUE, (uint16_t)1000, NULL};
State greenState = {LED_GREEN, (uint16_t)3000, NULL};


int main(void)
{
  /* Reset of all peripherals. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();


  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();


// ink states into a loop
redState.next_state = &blueState;
blueState.next_state = &greenState;
greenState.next_state = &redState;

//Set initial state
State* current_state = &redState;

  /* Infinite loop */
  while (1)
  {

/*switch(current_state->activeLight){

case LED_RED:
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);   // Red ON
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_4, GPIO_PIN_RESET); // Blue & Green OFF
break;
case LED_BLUE:
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);   // Red ON
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_4, GPIO_PIN_RESET); // Blue & Green OFF
break;
case LED_GREEN:
HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);   // Red ON
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_0, GPIO_PIN_RESET); // Blue & Green OFF
break;
}
*/

switch(current_state->activeLight){

case LED_RED:
HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);   // Red ON
        HAL_GPIO_WritePin(GPIOB, LD2_Pin | LD3_Pin, GPIO_PIN_RESET); // Blue & Green OFF
break;
case LED_BLUE:
HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET);   // Red ON
        HAL_GPIO_WritePin(GPIOB, LD1_Pin | LD3_Pin, GPIO_PIN_RESET); // Blue & Green OFF
break;
case LED_GREEN:
HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);   // Red ON
        HAL_GPIO_WritePin(GPIOB, LD2_Pin | LD1_Pin, GPIO_PIN_RESET); // Blue & Green OFF
break;
}
HAL_Delay(current_state -> time);
current_state = current_state -> next_state;



//test pins
//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0); // Toggle A0 LED
    //HAL_Delay(1000); // 1-second delay

//For blinking board
    //HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
//HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
 //HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
    //HAL_Delay(500);

  }
}

//For blinking board
    //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    //HAL_Delay(500);
