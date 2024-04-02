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
#include <stdint.h>


/* USER CODE BEGIN PV */
#define PREAMBLE "\r\n!START!\r\n"
#define DELTA_PREAMBLE "\r\n!DELTA!\r\n"
#define SUFFIX "!END!\r\n"

uint16_t snapshot_buff[IMG_ROWS * IMG_COLS];
uint8_t old_snapshot_buff[IMG_ROWS * IMG_COLS];

uint8_t tx_buff[sizeof(PREAMBLE) + 2 * IMG_ROWS * IMG_COLS + sizeof(SUFFIX)];
size_t tx_buff_len = 0;

uint8_t dma_flag = 0;

// Your function definitions here
void print_buf(void);

#define UART_TX_CHUNK_SIZE 64


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
  MX_TIM1_Init();
  MX_TIM6_Init();

  char msg[100];

  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
  ov7670_init();
  HAL_Delay(100);
  ov7670_capture(snapshot_buff);

  // Your startup code here
  sprintf(msg, "System initialized and ready for capturing.\r\n");
  HAL_UART_Transmit(&huart3, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

  while (1)
  {
    // Your code here
    if (HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin)) {
      HAL_Delay(100);  // debounce
    

      print_msg("Snap!\r\n"); //shown at button press

      // Capture an image and store it in snapshot_buff
      ov7670_capture(snapshot_buff);
      print_buf(); //to be implemented

    }
  }
}


void print_buf() {
  // Send image data through serial port.
  // Your code here

  // assuming UART buffer is large enough to handle the data

  const uint8_t *dataPtr = (const uint8_t *)snapshot_buff;
  size_t dataLen = sizeof(snapshot_buff);

  HAL_UART_Transmit(&huart3, (uint8_t *)PREAMBLE, strlen(PREAMBLE), HAL_MAX_DELAY);

  // Transmit the image data in chunks
  for (size_t i = 0; i < dataLen; i += UART_TX_CHUNK_SIZE) {
    size_t chunkSize = ((dataLen - i) < UART_TX_CHUNK_SIZE) ? (dataLen - i) : UART_TX_CHUNK_SIZE;
    HAL_UART_Transmit(&huart3, &dataPtr[i], chunkSize, HAL_MAX_DELAY);
  }

  // Transmit the suffix
  HAL_UART_Transmit(&huart3, (uint8_t *)SUFFIX, strlen(SUFFIX), HAL_MAX_DELAY);


}