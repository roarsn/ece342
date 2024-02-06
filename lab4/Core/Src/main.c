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

#include "dfr0151.h"
#include "config.h"

#include <stdio.h>
#include <string.h>

//globals
uint8_t hour, min, sec, flag;


int main(void)
{
  /* Reset of all peripherals. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();  
  rtc_init();

  char msg[100];

  // Your start up code here
	rtc_retrieve_time(&hour,&min,&sec);
	rtc_get_time(&hour,&min,&sec);
	sprintf(msg,"INIThour,min,sec: %d : %d : %d \n\n\n",hour, min, sec);
	print_msg(msg);
	
  while (1)
  {
    // Your code here
    rtc_get_time(&hour,&min,&sec);
		sprintf(msg,"hour,min,sec: %d : %d : %d",hour, min, sec);
		print_msg(msg);
		print_msg("\n");
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    HAL_Delay(500);
    print_msg("\b\b\b\btick");

    HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    HAL_Delay(500);
    print_msg("\b\b\b\btock");
		print_msg("\n");
		if(flag){ //
			//rtc_set_time(hour,min,sec);
			rtc_store_time(hour,min,sec);
			HAL_Delay(10);
			flag=0;
		}
  }
}//need to add get date, try impossible