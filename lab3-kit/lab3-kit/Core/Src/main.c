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
	
#define PI 3.1415926
#define MAXIMUM 100000

extern double *sin_LUT; 
extern double *square_LUT; 
extern double *saw_LUT; 
extern double *triangle_LUT; 

int8_t fs_terms=1; //make sure this works with xx_it extern var

double squareWave(int max, double x){
  double fX = 0.5;
  for(int n = 0 ; n < max ; n++){
    fX += (2 / PI) * (1 / ((2 * n) + 1)) * sin(((2 * n)+1)*x);
  }
  return fX;
}

double sawTooth(int max, double x){
  double fX = 0.5;
  for(int n = 1 ; n < max ; n++){
    fX -= (1 / PI) * (1 / n) * sin(n * x)
  }
  return fX;
}

double triangularWave(int max, double x){
  double fX = 0.5;
  for(int n = 0 ; n < max ; n++){
    fX += (4 / pow(PI, 2)) * (pow(-1, n) / pow(((2*n) + 1), 2)) * sin((2*n + 1)* x);
  }
  return fX;
}

void squareLUT(int max, double x){
  int max_count=(int) nearbyint((2*3.1415926/0.01) +1.0);
	int count=0;
	double *square_LUT=malloc(max_count*sizeof(double));
	for(double theta=0; theta<=(2*3.1415926); theta+=0.01){
			square_LUT[count]=squareWave(0, theta);
			count++;
	}
  //we have LUT filled for smallest freq values of each
  for(int n = 3 ; n <= max_count ; i++){
    for (int i = 0; i < max_count; i++) {
      double square_nx = square_LUT[i] + cos((n - 1) * 0.01) + cos((n - 1) * 0.01) * square_LUT[i];
      printf("square(%dx) at index %d: %f\n", n, i, square_nx);
    }
  }
  free(square_LUT);
}

void sawLUT(int max, double x){
  int max_count=(int) nearbyint((2*3.1415926/0.01) +1.0);
	int count=0;
	double *saw_LUT=malloc(max_count*sizeof(double));
	for(double theta=0; theta<=(2*3.1415926); theta+=0.01){
			saw_LUT[count]=sawWave(0, theta);
			count++;
	}
  //we have LUT filled for smallest freq values of each
  for(int n = 3 ; n <= max_count ; i++){
    for (int i = 0; i < max_count; i++) {
      double saw_nx = saw_LUT[i] + cos((n - 1) * 0.01) + cos((n - 1) * 0.01) * saw_LUT[i];
      printf("saw(%dx) at index %d: %f\n", n, i, saw_nx);
    }
  }
  free(saw_LUT);
}

void triangleLUT(int max, double x){
  int max_count=(int) nearbyint((2*3.1415926/0.01) +1.0);
	int count=0;
	double *triangle_LUT=malloc(max_count*sizeof(double));
	for(double theta=0; theta<=(2*3.1415926); theta+=0.01){
			triangle_LUT[count]=triangleWave(0, theta);
			count++;
	}
  //we have LUT filled for smallest freq values of each
  for(int n = 3 ; n <= max_count ; i++){
    for (int i = 0; i < max_count; i++) {
      double triangle_nx = triangle_LUT[i] + cos((n - 1) * 0.01) + cos((n - 1) * 0.01) * triangle_LUT[i];
      printf("triangle(%dx) at index %d: %f\n", n, i, triangle_nx);
    }
  }
  free(triangle_LUT);
}






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
	fs_terms=1;
	
	char message[100];
  sprintf(message, "Printing test\n");
  print_msg(message); //UART transmit
	
	//part 2.2
	int max_count=(int) nearbyint((2*3.1415926/0.01) +1.0);
	int count=0;
	double *sin_LUT=malloc(max_count*sizeof(double));
	for(double theta=0; theta<=(2*3.1415926); theta+=0.01){
			sin_LUT[count]=sin(theta);
			
			sprintf(message,"max count: %d \n count: %d sintheta: %lf\n",max_count, count, sin_LUT[count]);
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
	  //HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
    HAL_Delay(50);
		
		timer= __HAL_TIM_GET_COUNTER(&htim6);
    //part 2.1
		/*for(double theta=0; theta<=(2*3.1415926); theta+=0.1){
		  //HAL_Delay(10);
			HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
			HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sin(theta)); //uint32_t data
    }*/
		/*for(int i=0;i<1;i+=0.01){	
			HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
			HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, squareWave(fs_terms,i));
			HAL_Delay(1);
		}*/
		//part 2.2
    for (int i=0;i<max_count;i++){
     	HAL_Delay(10);////mod this
			HAL_DAC_Start(&hdac, DAC_CHANNEL_1); //non-blocking, confirm placement 
			HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sin_LUT[i]);
			
		}
    timer= __HAL_TIM_GET_COUNTER(&htim6) - timer;//time to send all of one sine wave
		//sprintf(message, "time: %d \n", timer);
		//
		sprintf(message, "num_terms %d \n", fs_terms);
		//print_msg(message); //UART transmit	
		
	
  }
	free(sin_LUT);
}
#pragma GCC pop_options





