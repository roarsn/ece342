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
  STATE_EAST_WEST_GREEN,
  STATE_EAST_WEST_TRANSITION,  // East-West turns from green to red (through orange), North-South remains red
  STATE_NORTH_SOUTH_GREEN,
  STATE_NORTH_SOUTH_TRANSITION // North-South turns from green to red (through orange), East-West remains red
} TrafficState;


typedef struct State{
  TrafficState trafficState;
  uint16_t time;
  struct State* next_state;
} State;

//define states
State east_west_green = {STATE_EAST_WEST_GREEN, 3000, NULL};
State east_west_transition = {STATE_EAST_WEST_TRANSITION, 1000, NULL};
State north_south_green = {STATE_NORTH_SOUTH_GREEN, 3000, NULL};
State north_south_transition = {STATE_NORTH_SOUTH_TRANSITION, 1000, NULL};


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
east_west_green.next_state = &east_west_transition;
east_west_transition.next_state = &north_south_green;
north_south_green.next_state = &north_south_transition;
north_south_transition.next_state = &east_west_green;

//Set initial state
State* current_state = &east_west_green;

  /* Infinite loop */
  while (1)
  {

  //for EW, pin A0 = Red, A1 = Orange, A2 = Green
  //for NS, pin A3 = Red, A4 = Orange, A5 = Green
  switch(current_state->trafficState) {
    case STATE_EAST_WEST_GREEN:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2 | GPIO_PIN_3, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_5, GPIO_PIN_RESET); 
      break;
    case STATE_EAST_WEST_TRANSITION:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_3, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_2 | GPIO_PIN_4 | GPIO_PIN_5, GPIO_PIN_RESET); 
      break;
    case STATE_NORTH_SOUTH_GREEN:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_5, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4, GPIO_PIN_RESET); 
      break;
    case STATE_NORTH_SOUTH_TRANSITION:
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_4, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_5, GPIO_PIN_RESET); 
      break;




  }
}

//test pins
//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0); // Toggle A0 LED
    //HAL_Delay(1000); // 1-second delay

//For blinking board
    //HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
//HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
 //HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
    //HAL_Delay(500);

//For blinking board
    //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    //HAL_Delay(500);


//for single traffic light on board
/* switch(current_state->activeLight){

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
current_state = current_state -> next_state; */

//     case LED_RED:
//       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);   // Red ON
//       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_4, GPIO_PIN_RESET); // Blue & Green OFF
//       break;
//     case LED_BLUE:
//       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);   // Red ON
//       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_4, GPIO_PIN_RESET); // Blue & Green OFF
//       break;
//     case LED_GREEN:
//       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);   // Red ON
//       HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_0, GPIO_PIN_RESET); // Blue & Green OFF
//       break;
// }