#include "defs.h"
#include "processor.h"
#include "main.h"
#include <task.h>

/*--------------------------------------------------------------------------*/

void SystemClock_Config(void);

/*--------------------------------------------------------------------------*/

void TesteTask( void* lpParam );

/*--------------------------------------------------------------------------*/

int main( void )
{
  
  BaseType_t bRet;
  TaskHandle_t handle;
  SystemInit();
  SystemClock_Config();

  bRet = xTaskCreate( TesteTask , 
                      "teste"   ,
                      128       ,
                      NULL      ,
                      4         ,
                      &handle   );
  
                      
  
  
  /* start the scheduler */
  vTaskStartScheduler();

  for ( ;; ) 
  {
      /*! se chegar aqui, tem boi na linha */
  }  
}

/*--------------------------------------------------------------------------*/

void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  __PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE|RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 20;
  RCC_OscInitStruct.PLL.PLLN = 268;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK|RCC_CLOCKTYPE_PCLK1
                              |RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

  return;
}

/*--------------------------------------------------------------------------*/

void TesteTask( void* lpParam )
{
  static DWORD dwCounter = 0;
  
  dwCounter++;
  
  return;
}

/*--------------------------------------------------------------------------*/

