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
#include "config.h"
#include <stdio.h>
#include "operations.h"


int8_t current_row = -1, current_col = -1;

int8_t ans=-1, num1=-1, num2=-1;


int main(void)
{
  /* Reset of all peripherals. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();

  char message[100];
  sprintf(message, "Printing test\n");
  print_msg(message); //UART transmit
	
	//int8_t key_pressed;
	char key_pressed_c;

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  
  /* Initialize ROW outputs */
  HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_SET);//initally they set row0 to one
  HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_RESET);

  /* Infinite loop */
  while (1)
  {
    //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    //HAL_Delay(500);
		
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_SET);
		HAL_Delay(10);
		if (current_col>-1){
			current_row=0;
			print_key(message);
			
			current_col=-1;
		}
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, GPIO_PIN_RESET);
		//HAL_Delay(10);
		
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_SET);
		if (current_col>-1){
			current_row=1;
			print_key(message);
			
			current_col=-1;
		}
		HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, GPIO_PIN_RESET);
		
		
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_SET);
		if (current_col>-1){
			current_row=2;
			print_key(message);
			
			current_col=-1;
		}
		HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, GPIO_PIN_RESET);
		
		
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_SET);
		if (current_col>-1){
			current_row=3;
			print_key(message);
			
			current_col=-1;
		}
		HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, GPIO_PIN_RESET);
		HAL_Delay(100);
			
		
		
		
		
		
		//sprintf(message, "Answer is %d \n", ans);
		//print_msg(message);
		
		//row1 not showing up, row1 keypad is row2 and row2 keypad is row3 and row3 keypad is nothing
		current_row=-1;
		current_col=-1;
  }
}