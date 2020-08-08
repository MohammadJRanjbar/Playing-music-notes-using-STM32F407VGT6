/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dac.h"
#include "tim.h"
#include "gpio.h"
#include "lm016.h"
/* Private includes ----------------------------------------------------------*/

/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
void play_note(int note_freq,uint32_t note_duration);
const int N = 50;
uint16_t SINE_WAVE[N] = 
{
	2048,2305,2557,2802,3035,3252,3450,3626,3777,3901,3996
	,4060,4092,4092,4060,3996,3901,3777,3626,3450,3252,3035
	,2802,2557,2305,2048,1791,1539,1294,1061,844,646,470,319
	,195,100,36,4,4,36,100,195,319,470,646,844,1061,1294,1539
	,1791

};
	int Note_Flag = 0 , Dac_Flag=0,Sine_Index = 0 ; 
	uint32_t Q_Duration = 0,H_Duration = 0;
	const int A0= 27 , AH0=29 , B0 = 31 ; 
	const int C1= 33 , CH1= 35 , D1 = 37 ,DH1=39 , E1=41 , F1 = 43 ,FH1=46,GH1=52 , A1 = 55 , AH1=58 ,B1=62;
	const int C2=65, CH2=70 ,D2=73,DH2=78,E2=82,F2=87,FH2=92,G2=98,GH2=104,A2=110 ,AH2=117,B2=123;
	const int C3=131,CH3=139,D3=147,DH3=156,E3=165,F3=175,FH3=185,G3=208 , A3=220 , AH3=233 ,B3=247;
	const int C4 = 262,CH4=277,D4 = 294, DH4=311 ,E4=330,  F4 = 349 , FH4=370 , G4=392	, A4 = 440  ,AH4=466, B4 =494;
	const int C5=523,CH5=554,D5=587,DH5=622,E5=660,F5=698,FH5=740,G5=384,GH5=831,A5=880,AH5=932,B5=988;
	const int C6=1046,CH6=1109,D6=1175,DH6=1244,E6=1318,F6=1307,FH6=1480,G6=1568,GH6=1661,A6=1760,AH6=1865,B6=1975;
	const int C7=2093,CH7=2217,D7=2349,DH7=2489,E7=2637,F7=2793,FH7=2960,G7=3136,GH7=3322,A7=3520,AH7=3729,B7=3951;
	const int C8=4186;
		
	
  
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  MX_TIM5_Init();
  MX_DAC_Init();
  /* USER CODE BEGIN 2 */
	uint32_t BpM = 120;
	Q_Duration = 60000/BpM;
	H_Duration = 2*60000/BpM;
	lcd_init();
	lcd_clear();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		//twinkle star
		lcd_puts("Twin");
		play_note(C4,Q_Duration);
		lcd_puts("kle ");
	
		play_note(C4,Q_Duration);;
		
		lcd_puts(" Twin");
		play_note(G4,Q_Duration);
		lcd_puts("kle");
		play_note(G4,Q_Duration);
		
		
		lcd_puts("lit");
		play_note(A4,Q_Duration);
		lcd_puts("tle");
		play_note(A4,Q_Duration);
		
		
		lcd_puts(" star");
		play_note(G4,H_Duration);
		
		lcd_clear();
		lcd_puts("How");
		play_note(F4,Q_Duration);
		lcd_puts(" I");
		play_note(F4,Q_Duration);
		lcd_puts(" won");
		play_note(E4,Q_Duration);
		lcd_puts("der");
		play_note(E4,Q_Duration);
		
		lcd_set_cursor(2,1);
		lcd_puts("What");
		play_note(D4,Q_Duration);
		lcd_puts(" you");
		play_note(D4,Q_Duration);
		lcd_puts(" are!");
		play_note(C4,H_Duration);
		lcd_clear();
		
		lcd_puts("Up");
		play_note(G4,Q_Duration);
		lcd_puts(" a");
		play_note(G4,Q_Duration);
		lcd_puts("bove");
		play_note(F4,Q_Duration);
		lcd_puts(" the");
		play_note(F4,Q_Duration);
		lcd_set_cursor(2,1);
		lcd_puts("world");
		play_note(E4,Q_Duration);
		
		lcd_puts(" so");
		play_note(E4,Q_Duration);
		lcd_puts(" high,");
		play_note(D4,H_Duration);
		
		lcd_clear();
		lcd_puts("like");
		play_note(G4,Q_Duration);
		lcd_puts(" a");
		play_note(G4,Q_Duration);
		lcd_puts(" dia");
		play_note(F4,Q_Duration);
		lcd_puts("mond");
		lcd_set_cursor(2,1);
		play_note(F4,Q_Duration);
		lcd_puts("in");
		play_note(E4,Q_Duration);
		lcd_puts(" the");
		play_note(E4,Q_Duration);
		lcd_puts(" sky.");
		play_note(D4,H_Duration);
		
		lcd_clear();
		
		lcd_puts("Twin");
		play_note(C4,Q_Duration);
		lcd_puts("kle ");
	
		play_note(C4,Q_Duration);;
		
		lcd_puts(" Twin");
		play_note(G4,Q_Duration);
		lcd_puts("kle");
		play_note(G4,Q_Duration);
		
		
		lcd_puts("lit");
		play_note(A4,Q_Duration);
		lcd_puts("tle");
		play_note(A4,Q_Duration);
		
		
		lcd_puts(" star");
		play_note(G4,H_Duration);
		
		lcd_clear();
		lcd_puts("How");
		play_note(F4,Q_Duration);
		lcd_puts(" I");
		play_note(F4,Q_Duration);
		lcd_puts(" won");
		play_note(E4,Q_Duration);
		lcd_puts("der");
		play_note(E4,Q_Duration);
		
		lcd_set_cursor(2,1);
		lcd_puts("What");
		play_note(D4,Q_Duration);
		lcd_puts(" you");
		play_note(D4,Q_Duration);
		lcd_puts(" are!");
		play_note(C4,H_Duration);
		lcd_clear();
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 168;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

void play_note(int note_freq,uint32_t note_duration)
{
	//to turn on the leds
	if(note_freq==C4)
	{
		HAL_GPIO_WritePin(GPIOA,ledC4_Pin,GPIO_PIN_SET);
	}
	if(note_freq==G4)
	{
		HAL_GPIO_WritePin(GPIOC,ledG4_Pin,GPIO_PIN_SET);
	}
	if(note_freq==D4)
	{
		HAL_GPIO_WritePin(GPIOA,ledD4_Pin,GPIO_PIN_SET);
	}
	if(note_freq==A4)
	{
		HAL_GPIO_WritePin(GPIOC,ledA4_Pin,GPIO_PIN_SET);
	}
	if(note_freq==E4)
	{
		HAL_GPIO_WritePin(GPIOA,ledE4_Pin,GPIO_PIN_SET);
	}
	if(note_freq==F4)
	{
		HAL_GPIO_WritePin(GPIOA,ledF4_Pin,GPIO_PIN_SET);
	}
	
	Note_Flag =0;	
	Sine_Index = 0;
	uint32_t Time_Comparator2 = (uint32_t) 84000000/(note_freq*N); // 200 * t_sample = 1/212   f_Sample = 212*200
	uint32_t Time_Comparator5 = (uint32_t) (84000000  / 1000) * note_duration ;
	//starting timers
	HAL_TIM_OC_Start_IT(&htim2,TIM_CHANNEL_2); 
	HAL_TIM_OC_Start_IT(&htim5,TIM_CHANNEL_1);
	//so we can compare whne to stop
	__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,Time_Comparator2); 
	__HAL_TIM_SET_COMPARE(&htim5,TIM_CHANNEL_1,Time_Comparator5);
	//counter is zero in start
	__HAL_TIM_SET_COUNTER(&htim2,0);
	__HAL_TIM_SET_COUNTER(&htim5,0);
	//starting the dac
	HAL_DAC_Start(&hdac,DAC_CHANNEL_1); 
	
	
	while(Note_Flag==0) 
	{
		if(Dac_Flag==1) 
		{
			HAL_DAC_SetValue(&hdac,DAC_CHANNEL_1,DAC_ALIGN_12B_R,SINE_WAVE[Sine_Index]);
			__HAL_TIM_SET_COUNTER(&htim2,0);
			Sine_Index++;
			if(Sine_Index==N)
				Sine_Index = 0;
			Dac_Flag = 0; //so we can use the interupt again
		}
	}
	
	//setting the counter to zero and stoping the two timers
	__HAL_TIM_SetCounter(&htim5,0);
	HAL_TIM_OC_Stop_IT(&htim2,TIM_CHANNEL_2);
	HAL_TIM_OC_Stop_IT(&htim5,TIM_CHANNEL_1);
	HAL_DAC_Stop(&hdac,DAC_CHANNEL_1);
	//to turn off the leds 
	if(note_freq==C4)
	{
		HAL_GPIO_WritePin(GPIOA,ledC4_Pin,GPIO_PIN_RESET);
	}
	if(note_freq==G4)
	{
		HAL_GPIO_WritePin(GPIOC,ledG4_Pin,GPIO_PIN_RESET);
	}
	if(note_freq==D4)
	{
		HAL_GPIO_WritePin(GPIOA,ledD4_Pin,GPIO_PIN_RESET);
	}
	if(note_freq==A4)
	{
		HAL_GPIO_WritePin(GPIOC,ledA4_Pin,GPIO_PIN_RESET);
	}
	if(note_freq==E4)
	{
		HAL_GPIO_WritePin(GPIOA,ledE4_Pin,GPIO_PIN_RESET);
	}
	if(note_freq==F4)
	{
		HAL_GPIO_WritePin(GPIOA,ledF4_Pin,GPIO_PIN_RESET);
	}
	
}

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
{
	
	if(htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2)
	{
		Dac_Flag = 1;	
	}
	else if (htim->Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		Note_Flag = 1;	
	}
	
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
