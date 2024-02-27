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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include "config.h"
#include "ov7670.h"


/* USER CODE BEGIN PV */
#define PREAMBLE "\r\n!START!\r\n"
#define DELTA_PREAMBLE "\r\n!DELTA!\r\n"
#define SUFFIX "!END!\r\n"

extern DCMI_HandleTypeDef hdcmi;

uint16_t snapshot_buff[IMG_ROWS * IMG_COLS];
uint8_t old_snapshot_buff[IMG_ROWS * IMG_COLS];
uint8_t packed_buff[(IMG_COLS*IMG_ROWS)/2];

uint8_t tx_buff[sizeof(PREAMBLE) + 2 * IMG_ROWS * IMG_COLS + sizeof(SUFFIX)];//bcuz every pixel has 2 bytes (this is a uint8_t array)
size_t tx_buff_len = 0;//compile time constant

uint8_t dma_flag = 0; //for interrupt

// Your function definitions here
void print_buf(void);


int main(void)
{
  /* Reset of all peripherals */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_DCMI_Init();
  MX_USART3_UART_Init();
  MX_USB_OTG_FS_PCD_Init();
  MX_I2C2_Init();
  MX_TIM1_Init(); //for external clock/PWM
  MX_TIM6_Init();

  char msg[100];

  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  ov7670_init();//returns an integer though???
  HAL_Delay(100);
  ov7670_capture(snapshot_buff); //did I add this?

  // Your startup code here
	
	uint8_t colour =0xFF;
	/*uint16_t i;
	uint16_t j;
	for(i=0;i<sizeof(PREAMBLE);i++){
		tx_buff[i]=(uint8_t)PREAMBLE[i];
  }
	j=i-1;
	for (i=j;i<(IMG_COLS*IMG_ROWS)+j;i++){
		tx_buff[i]=colour;
	}j=i;
	for(i=j;i<sizeof(SUFFIX)+j;i++){
		tx_buff[i]=(uint8_t)SUFFIX[i];
  }
	
	uart_send_bin(tx_buff,sizeof(tx_buff));*/
	/*uint16_t i;
	uint16_t j;
	
	print_msg(PREAMBLE);
	HAL_Delay(1);
	
	for (int i=0;i<(IMG_COLS*IMG_ROWS);i++){
		old_snapshot_buff[i]=colour;
	}
	HAL_StatusTypeDef status;
	status=HAL_UART_Transmit_DMA(&huart3,old_snapshot_buff,IMG_ROWS * IMG_COLS);
	if(status!=HAL_OK){
		print_msg("UART Error\n");
	}
	while(HAL_UART_GetState(&huart3)!=HAL_UART_STATE_READY){
	}
	
	HAL_Delay(1);
	print_msg(SUFFIX);*/
	
	//sprintf(msg,"0x%x in main\n",ov7670_read(0x70));
	//print_herc(msg);
	
	
	while (1)
  {
    HAL_GPIO_TogglePin(LD2_GPIO_Port,LD2_Pin);
		//print_herc("init_test\n"); //how do i get this to print?
		//HAL_Delay(0);
		
		// Your code here
    if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin)) {
      HAL_Delay(100);  // debounce
			ov7670_snapshot(snapshot_buff);
			while(!dma_flag){
				HAL_Delay(0);
			}
			HAL_Delay(1);
			print_buf();
			HAL_Delay(1);
      dma_flag=0;
			print_msg("Snap!\r\n"); //retuns status instead?
			HAL_Delay(1000);
    }
		
		//continuous stream
		ov7670_capture(snapshot_buff);//why continuous if i'm just going to loop it?
		while(!dma_flag){
		}dma_flag=0;
		HAL_DCMI_Suspend(&hdcmi);
		HAL_Delay(1);
		print_buf();
		HAL_Delay(1);
		HAL_DCMI_Resume(&hdcmi);
  }
}


void print_buf() {
  // Send image data through serial port.
  // Your code here
	uint16_t i;
	uint16_t j;
	
	
	print_msg(PREAMBLE);
	HAL_Delay(1);
	
	for (int i=0;i<(IMG_COLS*IMG_ROWS);i++){
		old_snapshot_buff[i]=(uint8_t)(snapshot_buff[i]>>8); //12 for clipped
	}
	/*for (int i=1;i<((IMG_COLS*IMG_ROWS)/2);i++){
		packed_buff[i]=(old_snapshot_buff[i-1])&(old_snapshot_buff[i]<<4);
	}*/
	
	HAL_StatusTypeDef status;
	status=HAL_UART_Transmit_DMA(&huart3,old_snapshot_buff,IMG_ROWS * IMG_COLS);
	//status=HAL_UART_Transmit_DMA(&huart3,packed_buff,(IMG_ROWS * IMG_COLS)/2);
	
	//status=HAL_UART_Transmit(&huart3,old_snapshot_buff,IMG_ROWS*IMG_COLS,100); //got array shaping error
	
	/*if(status!=HAL_OK){
		print_msg("UART Transmit Error\n");
	}*/
	
	while(HAL_UART_GetState(&huart3)!=HAL_UART_STATE_READY){ //put this AFTER DMA UART transmit occurs
	}
	
	HAL_Delay(10);
	print_msg(SUFFIX);
	
	/*for(i=0;i<sizeof(PREAMBLE);i++){
		tx_buff[i]=(uint8_t)PREAMBLE[i];
  }
	j=i-1;;
	for (i=j;i<(IMG_COLS*IMG_ROWS)+j;i++){
		tx_buff[i]=old_snapshot_buff[i-j];//write this to every 2 tx buffs//this is the problem
	}j=i;
	
	for(i=j;i<sizeof(SUFFIX)+j;i++){
		tx_buff[i]=(uint8_t)SUFFIX[i];
  }
	uart_send_bin(tx_buff,sizeof(tx_buff)/sizeof(tx_buff[0])); //Size is Amount of data elements (u8 or u16) to be sent//sizeofuint8_t gives 1 anyways
	*/
}