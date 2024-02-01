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

//Globals
float* sin_LUT;
float *square_LUT;
float *saw_LUT;
float *triangle_LUT;

double produceSin(double x);

int8_t fs_terms=1; //make sure this works with xx_it extern var

double squareWave(int max, double x){
  double fX = 0.5;
  for(double n = 0 ; n < max ; n += 1.0){
    fX += (2.0 / PI) * (1.0 / ((2.0 * n) + 1.0)) * sin(((2.0 * n)+1.0)*x);
  }
  return fX;
}
double produceSquare(double x) {
return 1000 * squareWave(10, x) + 1100;
}

double sawTooth(int max, double x){
  double fX = 0.5;
  for(double n = 1 ; n < max ; n++){
    fX -= (1.0 / PI) * (1.0 / n) * sin(n * x);
  }
  return fX;
}
double produceSaw(double x) {
return 1000 * sawTooth(10, x) + 1100;
}

double triangleWave(int max, double x){
  double fX = 0.5;
  for(double n = 0 ; n < max ; n++){
    fX += (4.0 / pow(PI, 2)) * (pow(-1, n) / pow(((2*n) + 1), 2)) * sin((2*n + 1)* x);
  }
  return fX;
}
double produceTriangle(double x) {
return 1000 * triangleWave(10, x) + 1100;
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


HAL_DAC_Init(&hdac);
  HAL_DAC_Start(&hdac, DAC_CHANNEL_1);
  HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 255);

uint32_t sinoutput;

//part 2.2 fill
/*sin_LUT = malloc(sizeof(float) * 100);
int i = 0;
for (double rads = 2*3.14; rads < 4*3.14; rads += (2.0*3.14/100.0)) {
sin_LUT[i] = produceSin(rads);
i++;
}*/

//part 3 - square
/*square_LUT = malloc(sizeof(float) * 100);
int i = 0;
for (double rads = 2*3.14; rads < 4*3.14; rads += (2.0*3.14/100.0)) {
square_LUT[i] = produceSquare(rads);
i++;
}*/

//part 3 - saw
/*saw_LUT = malloc(sizeof(float) * 100);
int i = 0;
for (double rads = 2*3.14; rads < 4*3.14; rads += (2.0*3.14/100.0)) {
saw_LUT[i] = produceSaw(rads);
i++;
}*/

//part 3 - triangle
triangle_LUT = malloc(sizeof(float) * 100);
int i = 0;
for (double rads = 2*3.14; rads < 4*3.14; rads += (2.0*3.14/100.0)) {
triangle_LUT[i] = produceTriangle(rads);
i++;
}


  while (1)
  {
//for part 1
/*for (double x = 2*3.14; x < 4*3.14; x += 0.01) {
double val = produceSin(x);
HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, val);
}*/

//for 2.2
/*for (int i = 0; i < 100; i++) {
HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sin_LUT[i]);
}*/

//for 3 square
/*for (int i = 0; i < 100; i++) {
HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, square_LUT[i]);
}*/

//for 3 saw
/*for (int i = 0; i < 100; i++) {
HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, saw_LUT[i]);
}*/

//for 3 triangle
for (int i = 0; i < 100; i++) {
HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1, DAC_ALIGN_12B_R, triangle_LUT[i]);
}
  }
}
#pragma GCC pop_options

double produceSin(double x) {
return 1000 * sin(x) + 1100;
}






