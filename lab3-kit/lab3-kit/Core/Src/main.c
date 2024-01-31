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
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "config.h"
#include "fixedpt.h"

#pragma GCC push_options
#pragma GCC optimize ("O0")
/**
  * @brief  The application entry point.
  * @retval int
  */

extern int *sin_LUT; 

#define PI = 3.1415926;



int main(void)
{
	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DAC_Init();
  MX_TIM6_Init();
  MX_USART3_Init();
	HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	
	char message[100];
  sprintf(message, "Printing test\n");
  print_msg(message); //UART transmit
	
	//part 2.2
	int max_count=(int) nearbyint((2*3.1415926/0.01) +1.0);
	int count=0;
	int *sin_LUT=malloc(max_count*sizeof(double));
	for(double theta=0; theta<=(2*3.1415926); theta+=0.01){
			sin_LUT[count]=sin(theta);
			
			sprintf(message,"max count: %d \n count: %d sintheta: %lf\n",max_count, count, sin(theta));
			print_msg(message);
			count++;
	}
	
	
	
	uint32_t timer=0;
	HAL_TIM_Base_Start(&htim6); //adjust the prescalar for TIM6 in config
	
	//if(status==HAL_OK)
	timer = __HAL_TIM_GET_COUNTER(&htim6); //returns TIMx_CNT a 16 or 32 bit int register value
	//sprintf(message,"timer: %d\n",timer);
	//print_msg(message);
	
	/*//part 1
	count=0;
	for(int i=1;i<100;i++)
		count+=(i-1);
	HAL_TIM_Base_Start(&htim6);//REPEATING THIS HERE MAKES 4 TO 14 COUNT
	timer= __HAL_TIM_GET_COUNTER(&htim6) - timer;
	
	sprintf(message,"count: %d timer: %d\n",count,timer);
	print_msg(message);
	*/
	
	HAL_DAC_Init(&hdac);
  HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
  HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 255);
	
	uint32_t sinoutput;
	
  while (1)
  {
	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    HAL_Delay(50);
		HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
		timer= __HAL_TIM_GET_COUNTER(&htim6);
    //I'm sorry the way you had your for loops setup was confusing me
		for(double theta=0; theta<=(2*3.1415926); theta+=0.01){
		  HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sin(theta)); //uint32_t data
    }
    // for (int i=0;i<max_count;i++){
    // 	HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sin_LUT[i]);
		// }
    timer= __HAL_TIM_GET_COUNTER(&htim6) - timer;
		sprintf(message, "time: %d \n", timer);
		print_msg(message); //UART transmit	
		
	
  }
	free(sin_LUT);
}
#pragma GCC pop_options



double squareWave(int max, double x){
  double fX = 0.5;
  for(int n = 0 ; n < max ; n++){
    fX += (2 / PI) * (1 / ((2 * n) + 1)) * sin(((2 * n)+1)*x);
  }
  return fX;
}

