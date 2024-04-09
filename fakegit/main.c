/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "arm_math.h"
#include "arm_const_structs.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TEST_LENGTH_SAMPLES 2048 //every even index of input is 0 (complex)
//#define ADC_CLOCKPRESCALER hadc3.Init.ClockPrescaler //see if this works
//#define ADC_SAMPLE_TIME hadc3.Init.Resolution/freq???
#define FFT_SIZE 1024 // Adjust the FFT size as needed
#define ADC_BUF_LEN 1024
#define C 300000000
#define fC 10525000000
#define NUM_TAPS 64
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc3;
DMA_HandleTypeDef hdma_adc3;

TIM_HandleTypeDef htim6;

UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
extern float32_t testInput_f32_10khz[TEST_LENGTH_SAMPLES];
//static float32_t testOutput[TEST_LENGTH_SAMPLES/2];
uint16_t adc_buf[ADC_BUF_LEN];
//uint8_t py_buff[ADC_BUF_LEN];

uint8_t dma_hflag=0;
uint8_t dma_flag=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC3_Init(void);
static void MX_TIM6_Init(void);
static void MX_USART3_UART_Init(void);
/* USER CODE BEGIN PFP */
float32_t do_my_fft(float32_t* fft_input);
void print_msg(char * msg);
void print_uart(uint16_t *msg, size_t size);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint32_t fftSize = 1024;
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;
arm_cfft_instance_f32 fft_instance;

float32_t fft_input[FFT_SIZE * 2];
static float32_t fft_output[FFT_SIZE];

//uint32_t adc_samples [FFT_SIZE];
//uint32_t adc_index=0;
float32_t freq;
arm_status math_status;
char message[100];


//float32_t fir_coeffs[NUM_TAPS];
const float fir_coeffs[NUM_TAPS] = {
    0.000766, 0.001011, 0.001636, 0.002622, 0.003941, 0.005553, 0.007402, 0.009419,
    0.011526, 0.013647, 0.015699, 0.017600, 0.019269, 0.020634, 0.021628, 0.022195,
    0.022292, 0.021891, 0.020974, 0.019542, 0.017617, 0.015234, 0.012443, 0.009306,
    0.005902, 0.002315, -0.001432, -0.005318, -0.009249, -0.013128, -0.016856, -0.020341,
    -0.023495, -0.026234, -0.028480, -0.030160, -0.031208, -0.031570, -0.031208, -0.030094,
    -0.028222, -0.025601, -0.022253, -0.018208, -0.013511, -0.008219, -0.002403, 0.003745,
    0.010124, 0.016734, 0.023512, 0.030385, 0.037278, 0.044112, 0.050802, 0.057263,
    0.063409, 0.069158, 0.074430, 0.079152, 0.083254, 0.086674, 0.089355, 0.091250
};
arm_fir_instance_f32 fir_inst;
uint16_t py_buff[ADC_BUF_LEN];

//create output_data from inst and taps
void filter_init() {
    // Initialize FIR filter coefficients (e.g., Hamming window coefficients)
    arm_fir_init_f32(&fir_inst, NUM_TAPS, (float32_t *)fir_coeffs, py_buff, ADC_BUF_LEN);
}

// Apply filter function
void apply_filter() {
    // Apply FIR filter to input_data and store result in output_data
    arm_fir_f32(&fir_inst, adc_buf, py_buff, ADC_BUF_LEN);
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	for (int i=0;i<FFT_SIZE*2;i++){
		fft_input[i]=0.0f;
	}

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  //if(status==HAL_OK)
  //timer = __HAL_TIM_GET_COUNTER(&htim6);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC3_Init();
  MX_TIM6_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  //  if(HAL_TIM_Base_Start(&htim6)!=HAL_OK){
  //	  Error_Handler(); //adjust the prescalar for TIM6 in config
  //  }
  sprintf(message, "PRinting test\n");
  print_msg(message); //UART transmit

  HAL_ADC_Start_DMA(&hadc3, (uint32_t*)adc_buf, ADC_BUF_LEN);
  int count=0;


  filter_init();
  apply_filter();
  //float32_to_byte(testInput_f32_10khz, py_buff, ADC_BUF_LEN);


    /* USER CODE END 2 */
    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
      while (1)
      {
  //  	  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
  //  	  HAL_Delay(10);
  //
  //  	  //print_msg("Printing\n");
    	  //print_msg("\nHi\n");
    	  //HAL_Delay(100);
  //  	  //timer= __HAL_TIM_GET_COUNTER(&htim6) - timer;

    	  if (dma_flag && count<50){
    		  //float32_to_byte(adc_buf, py_buff, ADC_BUF_LEN);
    		  print_uart(adc_buf, ADC_BUF_LEN); //sends adc_buf as a uint8_t array
    		  dma_flag=0;
    		  //count++;
    	  }

//    		  if (dma_hflag>=1){
//    			  dma_hflag=0;
//    			  i = FFT_SI
//    		  }
//    		  //HAL_ADC_Stop_DMA(&hadc3);
//    		  print_msg("  FULL  \n");
//	  	  	  dma_flag=0;
//	  	  	  for (uint16_t i=0; i<FFT_SIZE;i++){
//  				  fft_input[2*i]=adc_buf[i]; //do i stop dma to freeze adc_buf while I buffer in?
//	  	  	  }
//    	  	//freq=do_my_fft(testInput_f32_10khz);//on HALF the buffer
//			freq=do_my_fft(fft_input);
//			sprintf(message,"freq: %lf, velocity: %lf", freq, -freq*C/(fC*2));
//			print_msg(message);
//			//HAL_Delay(200);
//			count++;
//			//HAL_ADC_Start_DMA(&hadc3, (uint32_t*)adc_buf, ADC_BUF_LEN);
//    	  }
  //  	  dma_hflag=0;
  //  	  if(freq!=0){
  //  		sprintf(message,"freq: %lf", freq);
  //  		print_msg(message);
  //  	  }
  //   	}

      /* USER CODE END WHILE */

      /* USER CODE BEGIN 3 */
    }
    /* USER CODE END 3 */
  }


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC3_Init(void)
{

  /* USER CODE BEGIN ADC3_Init 0 */

  /* USER CODE END ADC3_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC3_Init 1 */

  /* USER CODE END ADC3_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc3.Instance = ADC3;
  hadc3.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc3.Init.Resolution = ADC_RESOLUTION_12B;
  hadc3.Init.ScanConvMode = DISABLE;
  hadc3.Init.ContinuousConvMode = ENABLE;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc3.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.NbrOfConversion = 1;
  hadc3.Init.DMAContinuousRequests = ENABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_15;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC3_Init 2 */

  /* USER CODE END ADC3_Init 2 */

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 0;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 65535;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(Btn_Push_GPIO_Port, Btn_Push_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : Btn_Push_Pin */
  GPIO_InitStruct.Pin = Btn_Push_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(Btn_Push_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LD1_Pin LD3_Pin LD2_Pin */
  GPIO_InitStruct.Pin = LD1_Pin|LD3_Pin|LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

//called when first half of buffer is full, now can use first LEN/2 samples
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc3){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	//HAL_Delay(1000);
	//print_msg("halfcallback\n");
	dma_hflag=1;
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc3){
	//print_msg("cbcomplete\n");
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	//HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
	//HAL_Delay(1000);
	//print_msg("cbcomplete\n");
	dma_flag=1;
}

float32_t do_my_fft(float32_t* fft_input){ //since fft_input is an array

	// Convert ADC value to float32 and prepare the input buffer for FFT
	//float32_t input_sample = (float32_t)adc_val; //should there be a loop here? num samples is in fft_input, so array can hold up to 1048 or whatever
	//fft_input[0] = input_sample;
	//fft_input[1] = 0.0f;
	uint32_t peak_index=0;
	float32_t maxValue;

	math_status=arm_cfft_init_1024_f32(&fft_instance);
	// Perform FFT
	arm_cfft_f32(&fft_instance, fft_input,ifftFlag,doBitReverse);//forward, no bit reversal

	// Calculate magnitude spectrum
	arm_cmplx_mag_f32(fft_input, fft_output, FFT_SIZE);

	// Find peak index (index of dominant freq)
	arm_max_f32(fft_output, FFT_SIZE, &maxValue, &peak_index); //index of max value of fft output
	sprintf(message,"peak Index = %ld \n", peak_index);
	print_msg(message);//should be 213 for test
	// Calculate frequency in Hz
	uint8_t prescale=1;
	if (hadc3.Init.ClockPrescaler==ADC_CLOCK_SYNC_PCLK_DIV2)
		prescale=2;
	else if (hadc3.Init.ClockPrescaler==ADC_CLOCK_SYNC_PCLK_DIV4)
		prescale=4;
	uint32_t adc_clock_frequency = 0xF42400/prescale;//16MHz / ADC clock prescaler=div4; but might be 3
	float32_t adc_conversions_per_second = 260.95;//this will be led frequency//15.3ms
	float32_t sampling_frequency = (float32_t)adc_clock_frequency / adc_conversions_per_second;

	//float32_t sampling_frequency = (float32_t)ADC_SAMPLETIME_3CYCLES/ (float32_t)ADC_CLOCKPRESCALER;  //clock freq/conversions per second
	return (float32_t)peak_index * sampling_frequency / FFT_SIZE; //freq = peak*freq resolution (bin width)


 }

void print_msg(char * msg) {
	HAL_UART_Transmit(&huart3, (uint8_t *)msg, strlen(msg), 100);
}

void print_uart(uint16_t *msg, size_t size){
	HAL_UART_Transmit(&huart3, (uint8_t *)msg, size*sizeof(uint16_t), HAL_MAX_DELAY);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
