/**
 ******************************************************************************
 * @file    stm32h7xx_ll_rcc.h
 * @author  MCD Application Team
 * @brief   Header file of RCC LL module.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2017 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 *in the root directory of this software component. If no LICENSE file comes
 *with this software, it is provided AS-IS.
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32H7xx_LL_RCC_H
#define STM32H7xx_LL_RCC_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx.h"
#include <math.h>

/** @addtogroup STM32H7xx_LL_Driver
 * @{
 */

#if defined(RCC)

/** @defgroup RCC_LL RCC
 * @{
 */

/* Private types -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/** @defgroup RCC_LL_Private_Variables RCC Private Variables
 * @{
 */
extern const uint8_t LL_RCC_PrescTable[16];

/**
 * @}
 */
/* Private constants ---------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/** @defgroup RCC_LL_Private_Macros RCC Private Macros
 * @{
 */
#if !defined(UNUSED)
#define UNUSED(x) ((void)(x))
#endif

/* 32            24           16            8             0
   --------------------------------------------------------
   | Mask        | ClkSource   |  Bit       | Register    |
   |             |  Config     | Position   | Offset      |
   --------------------------------------------------------*/

#if defined(RCC_VER_2_0)
/* Clock source register offset Vs CDCCIPR register */
#define CDCCIP 0x0UL
#define CDCCIP1 0x4UL
#define CDCCIP2 0x8UL
#define SRDCCIP 0xCUL
#else
/* Clock source register offset Vs D1CCIPR register */
#define D1CCIP 0x0UL
#define D2CCIP1 0x4UL
#define D2CCIP2 0x8UL
#define D3CCIP 0xCUL
#endif /* RCC_VER_2_0 */

#define LL_RCC_REG_SHIFT 0U
#define LL_RCC_POS_SHIFT 8U
#define LL_RCC_CONFIG_SHIFT 16U
#define LL_RCC_MASK_SHIFT 24U

#define LL_CLKSOURCE_SHIFT(__CLKSOURCE__)                                      \
  (((__CLKSOURCE__) >> LL_RCC_POS_SHIFT) & 0x1FUL)

#define LL_CLKSOURCE_MASK(__CLKSOURCE__)                                       \
  ((((__CLKSOURCE__) >> LL_RCC_MASK_SHIFT) & 0xFFUL)                           \
   << LL_CLKSOURCE_SHIFT(__CLKSOURCE__))

#define LL_CLKSOURCE_CONFIG(__CLKSOURCE__)                                     \
  ((((__CLKSOURCE__) >> LL_RCC_CONFIG_SHIFT) & 0xFFUL)                         \
   << LL_CLKSOURCE_SHIFT(__CLKSOURCE__))

#define LL_CLKSOURCE_REG(__CLKSOURCE__)                                        \
  (((__CLKSOURCE__) >> LL_RCC_REG_SHIFT) & 0xFFUL)

#define LL_CLKSOURCE(__REG__, __MSK__, __POS__, __CLK__)                       \
  ((uint32_t)((((__MSK__) >> (__POS__)) << LL_RCC_MASK_SHIFT) |                \
              ((__POS__) << LL_RCC_POS_SHIFT) |                                \
              ((__REG__) << LL_RCC_REG_SHIFT) |                                \
              (((__CLK__) >> (__POS__)) << LL_RCC_CONFIG_SHIFT)))
/**
 * @}
 */
/* Exported types ------------------------------------------------------------*/
#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_Exported_Types RCC Exported Types
 * @{
 */

/** @defgroup LL_ES_CLOCK_FREQ Clocks Frequency Structure
 * @{
 */

/**
 * @brief  RCC Clocks Frequency Structure
 */
typedef struct {
  uint32_t SYSCLK_Frequency;
  uint32_t CPUCLK_Frequency;
  uint32_t HCLK_Frequency;
  uint32_t PCLK1_Frequency;
  uint32_t PCLK2_Frequency;
  uint32_t PCLK3_Frequency;
  uint32_t PCLK4_Frequency;
} LL_RCC_ClocksTypeDef;

/**
 * @}
 */

/**
 * @brief  PLL Clocks Frequency Structure
 */
typedef struct {
  uint32_t PLL_P_Frequency;
  uint32_t PLL_Q_Frequency;
  uint32_t PLL_R_Frequency;
} LL_PLL_ClocksTypeDef;

/**
 * @}
 */

#endif /* USE_FULL_LL_DRIVER */

/* Exported constants --------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Constants RCC Exported Constants
 * @{
 */

/** @defgroup RCC_LL_EC_OSC_VALUES Oscillator Values adaptation
 * @brief    Defines used to adapt values of different oscillators
 * @note     These values could be modified in the user environment according to
 *           HW set-up.
 * @{
 */
#if !defined(HSE_VALUE)
#if defined(RCC_VER_X) || defined(RCC_VER_3_0)
#define HSE_VALUE 25000000U /*!< Value of the HSE oscillator in Hz */
#else
#define HSE_VALUE 24000000U /*!< Value of the HSE oscillator in Hz */
#endif                      /* RCC_VER_X || RCC_VER_3_0 */
#endif                      /* HSE_VALUE */

#if !defined(HSI_VALUE)
#define HSI_VALUE 64000000U /*!< Value of the HSI oscillator in Hz */
#endif                      /* HSI_VALUE */

#if !defined(CSI_VALUE)
#define CSI_VALUE 4000000U /*!< Value of the CSI oscillator in Hz */
#endif                     /* CSI_VALUE */

#if !defined(LSE_VALUE)
#define LSE_VALUE 32768U /*!< Value of the LSE oscillator in Hz */
#endif                   /* LSE_VALUE */

#if !defined(LSI_VALUE)
#define LSI_VALUE 32000U /*!< Value of the LSI oscillator in Hz */
#endif                   /* LSI_VALUE */

#if !defined(EXTERNAL_CLOCK_VALUE)
#define EXTERNAL_CLOCK_VALUE                                                   \
  12288000U /*!< Value of the I2S_CKIN external oscillator in Hz */
#endif      /* EXTERNAL_CLOCK_VALUE */

#if !defined(HSI48_VALUE)
#define HSI48_VALUE 48000000U /*!< Value of the HSI48 oscillator in Hz */
#endif                        /* HSI48_VALUE */

/**
 * @}
 */

/** @defgroup RCC_LL_EC_HSIDIV  HSI oscillator divider
 * @{
 */
#define LL_RCC_HSI_DIV1 RCC_CR_HSIDIV_1
#define LL_RCC_HSI_DIV2 RCC_CR_HSIDIV_2
#define LL_RCC_HSI_DIV4 RCC_CR_HSIDIV_4
#define LL_RCC_HSI_DIV8 RCC_CR_HSIDIV_8
/**
 * @}
 */

/** @defgroup RCC_LL_EC_LSEDRIVE  LSE oscillator drive capability
 * @{
 */
#define LL_RCC_LSEDRIVE_LOW (uint32_t)(0x00000000U)
#define LL_RCC_LSEDRIVE_MEDIUMLOW (uint32_t)(RCC_BDCR_LSEDRV_0)
#define LL_RCC_LSEDRIVE_MEDIUMHIGH (uint32_t)(RCC_BDCR_LSEDRV_1)
#define LL_RCC_LSEDRIVE_HIGH (uint32_t)(RCC_BDCR_LSEDRV)
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SYS_CLKSOURCE  System clock switch
 * @{
 */
#define LL_RCC_SYS_CLKSOURCE_HSI RCC_CFGR_SW_HSI
#define LL_RCC_SYS_CLKSOURCE_CSI RCC_CFGR_SW_CSI
#define LL_RCC_SYS_CLKSOURCE_HSE RCC_CFGR_SW_HSE
#define LL_RCC_SYS_CLKSOURCE_PLL1 RCC_CFGR_SW_PLL1
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SYS_CLKSOURCE_STATUS  System clock switch status
 * @{
 */
#define LL_RCC_SYS_CLKSOURCE_STATUS_HSI                                        \
  RCC_CFGR_SWS_HSI /*!< HSI used as system clock */
#define LL_RCC_SYS_CLKSOURCE_STATUS_CSI                                        \
  RCC_CFGR_SWS_CSI /*!< CSI used as system clock */
#define LL_RCC_SYS_CLKSOURCE_STATUS_HSE                                        \
  RCC_CFGR_SWS_HSE /*!< HSE used as system clock */
#define LL_RCC_SYS_CLKSOURCE_STATUS_PLL1                                       \
  RCC_CFGR_SWS_PLL1 /*!< PLL1 used as system clock */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SYSWAKEUP_CLKSOURCE  System wakeup clock source
 * @{
 */
#define LL_RCC_SYSWAKEUP_CLKSOURCE_HSI (uint32_t)(0x00000000U)
#define LL_RCC_SYSWAKEUP_CLKSOURCE_CSI (uint32_t)(RCC_CFGR_STOPWUCK)
/**
 * @}
 */

/** @defgroup RCC_LL_EC_KERWAKEUP_CLKSOURCE  Kernel wakeup clock source
 * @{
 */
#define LL_RCC_KERWAKEUP_CLKSOURCE_HSI (uint32_t)(0x00000000U)
#define LL_RCC_KERWAKEUP_CLKSOURCE_CSI (uint32_t)(RCC_CFGR_STOPKERWUCK)
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SYSCLK_DIV  System prescaler
 * @{
 */
#if defined(RCC_D1CFGR_D1CPRE_DIV1)
#define LL_RCC_SYSCLK_DIV_1 RCC_D1CFGR_D1CPRE_DIV1
#define LL_RCC_SYSCLK_DIV_2 RCC_D1CFGR_D1CPRE_DIV2
#define LL_RCC_SYSCLK_DIV_4 RCC_D1CFGR_D1CPRE_DIV4
#define LL_RCC_SYSCLK_DIV_8 RCC_D1CFGR_D1CPRE_DIV8
#define LL_RCC_SYSCLK_DIV_16 RCC_D1CFGR_D1CPRE_DIV16
#define LL_RCC_SYSCLK_DIV_64 RCC_D1CFGR_D1CPRE_DIV64
#define LL_RCC_SYSCLK_DIV_128 RCC_D1CFGR_D1CPRE_DIV128
#define LL_RCC_SYSCLK_DIV_256 RCC_D1CFGR_D1CPRE_DIV256
#define LL_RCC_SYSCLK_DIV_512 RCC_D1CFGR_D1CPRE_DIV512
#else
#define LL_RCC_SYSCLK_DIV_1 RCC_CDCFGR1_CDCPRE_DIV1
#define LL_RCC_SYSCLK_DIV_2 RCC_CDCFGR1_CDCPRE_DIV2
#define LL_RCC_SYSCLK_DIV_4 RCC_CDCFGR1_CDCPRE_DIV4
#define LL_RCC_SYSCLK_DIV_8 RCC_CDCFGR1_CDCPRE_DIV8
#define LL_RCC_SYSCLK_DIV_16 RCC_CDCFGR1_CDCPRE_DIV16
#define LL_RCC_SYSCLK_DIV_64 RCC_CDCFGR1_CDCPRE_DIV64
#define LL_RCC_SYSCLK_DIV_128 RCC_CDCFGR1_CDCPRE_DIV128
#define LL_RCC_SYSCLK_DIV_256 RCC_CDCFGR1_CDCPRE_DIV256
#define LL_RCC_SYSCLK_DIV_512 RCC_CDCFGR1_CDCPRE_DIV512
#endif /* RCC_D1CFGR_D1CPRE_DIV1 */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_AHB_DIV  AHB prescaler
 * @{
 */
#if defined(RCC_D1CFGR_HPRE_DIV1)
#define LL_RCC_AHB_DIV_1 RCC_D1CFGR_HPRE_DIV1
#define LL_RCC_AHB_DIV_2 RCC_D1CFGR_HPRE_DIV2
#define LL_RCC_AHB_DIV_4 RCC_D1CFGR_HPRE_DIV4
#define LL_RCC_AHB_DIV_8 RCC_D1CFGR_HPRE_DIV8
#define LL_RCC_AHB_DIV_16 RCC_D1CFGR_HPRE_DIV16
#define LL_RCC_AHB_DIV_64 RCC_D1CFGR_HPRE_DIV64
#define LL_RCC_AHB_DIV_128 RCC_D1CFGR_HPRE_DIV128
#define LL_RCC_AHB_DIV_256 RCC_D1CFGR_HPRE_DIV256
#define LL_RCC_AHB_DIV_512 RCC_D1CFGR_HPRE_DIV512
#else
#define LL_RCC_AHB_DIV_1 RCC_CDCFGR1_HPRE_DIV1
#define LL_RCC_AHB_DIV_2 RCC_CDCFGR1_HPRE_DIV2
#define LL_RCC_AHB_DIV_4 RCC_CDCFGR1_HPRE_DIV4
#define LL_RCC_AHB_DIV_8 RCC_CDCFGR1_HPRE_DIV8
#define LL_RCC_AHB_DIV_16 RCC_CDCFGR1_HPRE_DIV16
#define LL_RCC_AHB_DIV_64 RCC_CDCFGR1_HPRE_DIV64
#define LL_RCC_AHB_DIV_128 RCC_CDCFGR1_HPRE_DIV128
#define LL_RCC_AHB_DIV_256 RCC_CDCFGR1_HPRE_DIV256
#define LL_RCC_AHB_DIV_512 RCC_CDCFGR1_HPRE_DIV512
#endif /* RCC_D1CFGR_HPRE_DIV1 */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_APB1_DIV  APB low-speed prescaler (APB1)
 * @{
 */
#if defined(RCC_D2CFGR_D2PPRE1_DIV1)
#define LL_RCC_APB1_DIV_1 RCC_D2CFGR_D2PPRE1_DIV1
#define LL_RCC_APB1_DIV_2 RCC_D2CFGR_D2PPRE1_DIV2
#define LL_RCC_APB1_DIV_4 RCC_D2CFGR_D2PPRE1_DIV4
#define LL_RCC_APB1_DIV_8 RCC_D2CFGR_D2PPRE1_DIV8
#define LL_RCC_APB1_DIV_16 RCC_D2CFGR_D2PPRE1_DIV16
#else
#define LL_RCC_APB1_DIV_1 RCC_CDCFGR2_CDPPRE1_DIV1
#define LL_RCC_APB1_DIV_2 RCC_CDCFGR2_CDPPRE1_DIV2
#define LL_RCC_APB1_DIV_4 RCC_CDCFGR2_CDPPRE1_DIV4
#define LL_RCC_APB1_DIV_8 RCC_CDCFGR2_CDPPRE1_DIV8
#define LL_RCC_APB1_DIV_16 RCC_CDCFGR2_CDPPRE1_DIV16
#endif /* RCC_D2CFGR_D2PPRE1_DIV1 */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_APB2_DIV  APB low-speed prescaler (APB2)
 * @{
 */
#if defined(RCC_D2CFGR_D2PPRE2_DIV1)
#define LL_RCC_APB2_DIV_1 RCC_D2CFGR_D2PPRE2_DIV1
#define LL_RCC_APB2_DIV_2 RCC_D2CFGR_D2PPRE2_DIV2
#define LL_RCC_APB2_DIV_4 RCC_D2CFGR_D2PPRE2_DIV4
#define LL_RCC_APB2_DIV_8 RCC_D2CFGR_D2PPRE2_DIV8
#define LL_RCC_APB2_DIV_16 RCC_D2CFGR_D2PPRE2_DIV16
#else
#define LL_RCC_APB2_DIV_1 RCC_CDCFGR2_CDPPRE2_DIV1
#define LL_RCC_APB2_DIV_2 RCC_CDCFGR2_CDPPRE2_DIV2
#define LL_RCC_APB2_DIV_4 RCC_CDCFGR2_CDPPRE2_DIV4
#define LL_RCC_APB2_DIV_8 RCC_CDCFGR2_CDPPRE2_DIV8
#define LL_RCC_APB2_DIV_16 RCC_CDCFGR2_CDPPRE2_DIV16
#endif /* RCC_D2CFGR_D2PPRE2_DIV1 */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_APB3_DIV  APB low-speed prescaler (APB3)
 * @{
 */
#if defined(RCC_D1CFGR_D1PPRE_DIV1)
#define LL_RCC_APB3_DIV_1 RCC_D1CFGR_D1PPRE_DIV1
#define LL_RCC_APB3_DIV_2 RCC_D1CFGR_D1PPRE_DIV2
#define LL_RCC_APB3_DIV_4 RCC_D1CFGR_D1PPRE_DIV4
#define LL_RCC_APB3_DIV_8 RCC_D1CFGR_D1PPRE_DIV8
#define LL_RCC_APB3_DIV_16 RCC_D1CFGR_D1PPRE_DIV16
#else
#define LL_RCC_APB3_DIV_1 RCC_CDCFGR1_CDPPRE_DIV1
#define LL_RCC_APB3_DIV_2 RCC_CDCFGR1_CDPPRE_DIV2
#define LL_RCC_APB3_DIV_4 RCC_CDCFGR1_CDPPRE_DIV4
#define LL_RCC_APB3_DIV_8 RCC_CDCFGR1_CDPPRE_DIV8
#define LL_RCC_APB3_DIV_16 RCC_CDCFGR1_CDPPRE_DIV16
#endif /* RCC_D1CFGR_D1PPRE_DIV1 */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_APB4_DIV  APB low-speed prescaler (APB4)
 * @{
 */
#if defined(RCC_D3CFGR_D3PPRE_DIV1)
#define LL_RCC_APB4_DIV_1 RCC_D3CFGR_D3PPRE_DIV1
#define LL_RCC_APB4_DIV_2 RCC_D3CFGR_D3PPRE_DIV2
#define LL_RCC_APB4_DIV_4 RCC_D3CFGR_D3PPRE_DIV4
#define LL_RCC_APB4_DIV_8 RCC_D3CFGR_D3PPRE_DIV8
#define LL_RCC_APB4_DIV_16 RCC_D3CFGR_D3PPRE_DIV16
#else
#define LL_RCC_APB4_DIV_1 RCC_SRDCFGR_SRDPPRE_DIV1
#define LL_RCC_APB4_DIV_2 RCC_SRDCFGR_SRDPPRE_DIV2
#define LL_RCC_APB4_DIV_4 RCC_SRDCFGR_SRDPPRE_DIV4
#define LL_RCC_APB4_DIV_8 RCC_SRDCFGR_SRDPPRE_DIV8
#define LL_RCC_APB4_DIV_16 RCC_SRDCFGR_SRDPPRE_DIV16
#endif /* RCC_D3CFGR_D3PPRE_DIV1 */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_MCOxSOURCE  MCO source selection
 * @{
 */
#define LL_RCC_MCO1SOURCE_HSI (uint32_t)((RCC_CFGR_MCO1 >> 16U) | 0x00000000U)
#define LL_RCC_MCO1SOURCE_LSE                                                  \
  (uint32_t)((RCC_CFGR_MCO1 >> 16U) | RCC_CFGR_MCO1_0)
#define LL_RCC_MCO1SOURCE_HSE                                                  \
  (uint32_t)((RCC_CFGR_MCO1 >> 16U) | RCC_CFGR_MCO1_1)
#define LL_RCC_MCO1SOURCE_PLL1QCLK                                             \
  (uint32_t)((RCC_CFGR_MCO1 >> 16U) | RCC_CFGR_MCO1_1 | RCC_CFGR_MCO1_0)
#define LL_RCC_MCO1SOURCE_HSI48                                                \
  (uint32_t)((RCC_CFGR_MCO1 >> 16U) | RCC_CFGR_MCO1_2)
#define LL_RCC_MCO2SOURCE_SYSCLK                                               \
  (uint32_t)((RCC_CFGR_MCO2 >> 16U) | 0x00000000U)
#define LL_RCC_MCO2SOURCE_PLL2PCLK                                             \
  (uint32_t)((RCC_CFGR_MCO2 >> 16U) | RCC_CFGR_MCO2_0)
#define LL_RCC_MCO2SOURCE_HSE                                                  \
  (uint32_t)((RCC_CFGR_MCO2 >> 16U) | RCC_CFGR_MCO2_1)
#define LL_RCC_MCO2SOURCE_PLL1PCLK                                             \
  (uint32_t)((RCC_CFGR_MCO2 >> 16U) | RCC_CFGR_MCO2_1 | RCC_CFGR_MCO2_0)
#define LL_RCC_MCO2SOURCE_CSI                                                  \
  (uint32_t)((RCC_CFGR_MCO2 >> 16U) | RCC_CFGR_MCO2_2)
#define LL_RCC_MCO2SOURCE_LSI                                                  \
  (uint32_t)((RCC_CFGR_MCO2 >> 16U) | RCC_CFGR_MCO2_2 | RCC_CFGR_MCO2_0)
/**
 * @}
 */

/** @defgroup RCC_LL_EC_MCOx_DIV  MCO prescaler
 * @{
 */
#define LL_RCC_MCO1_DIV_1                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_0)
#define LL_RCC_MCO1_DIV_2                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_1)
#define LL_RCC_MCO1_DIV_3                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_0 |                  \
             RCC_CFGR_MCO1PRE_1)
#define LL_RCC_MCO1_DIV_4                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_2)
#define LL_RCC_MCO1_DIV_5                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_0 |                  \
             RCC_CFGR_MCO1PRE_2)
#define LL_RCC_MCO1_DIV_6                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_1 |                  \
             RCC_CFGR_MCO1PRE_2)
#define LL_RCC_MCO1_DIV_7                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_0 |                  \
             RCC_CFGR_MCO1PRE_1 | RCC_CFGR_MCO1PRE_2)
#define LL_RCC_MCO1_DIV_8                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_3)
#define LL_RCC_MCO1_DIV_9                                                      \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_0 |                  \
             RCC_CFGR_MCO1PRE_3)
#define LL_RCC_MCO1_DIV_10                                                     \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_1 |                  \
             RCC_CFGR_MCO1PRE_3)
#define LL_RCC_MCO1_DIV_11                                                     \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_0 |                  \
             RCC_CFGR_MCO1PRE_1 | RCC_CFGR_MCO1PRE_3)
#define LL_RCC_MCO1_DIV_12                                                     \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_2 |                  \
             RCC_CFGR_MCO1PRE_3)
#define LL_RCC_MCO1_DIV_13                                                     \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_0 |                  \
             RCC_CFGR_MCO1PRE_2 | RCC_CFGR_MCO1PRE_3)
#define LL_RCC_MCO1_DIV_14                                                     \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE_1 |                  \
             RCC_CFGR_MCO1PRE_2 | RCC_CFGR_MCO1PRE_3)
#define LL_RCC_MCO1_DIV_15                                                     \
  (uint32_t)((RCC_CFGR_MCO1PRE >> 16U) | RCC_CFGR_MCO1PRE)
#define LL_RCC_MCO2_DIV_1                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_0)
#define LL_RCC_MCO2_DIV_2                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_1)
#define LL_RCC_MCO2_DIV_3                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_0 |                  \
             RCC_CFGR_MCO2PRE_1)
#define LL_RCC_MCO2_DIV_4                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_2)
#define LL_RCC_MCO2_DIV_5                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_0 |                  \
             RCC_CFGR_MCO2PRE_2)
#define LL_RCC_MCO2_DIV_6                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_1 |                  \
             RCC_CFGR_MCO2PRE_2)
#define LL_RCC_MCO2_DIV_7                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_0 |                  \
             RCC_CFGR_MCO2PRE_1 | RCC_CFGR_MCO2PRE_2)
#define LL_RCC_MCO2_DIV_8                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_3)
#define LL_RCC_MCO2_DIV_9                                                      \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_0 |                  \
             RCC_CFGR_MCO2PRE_3)
#define LL_RCC_MCO2_DIV_10                                                     \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_1 |                  \
             RCC_CFGR_MCO2PRE_3)
#define LL_RCC_MCO2_DIV_11                                                     \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_0 |                  \
             RCC_CFGR_MCO2PRE_1 | RCC_CFGR_MCO2PRE_3)
#define LL_RCC_MCO2_DIV_12                                                     \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_2 |                  \
             RCC_CFGR_MCO2PRE_3)
#define LL_RCC_MCO2_DIV_13                                                     \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_0 |                  \
             RCC_CFGR_MCO2PRE_2 | RCC_CFGR_MCO2PRE_3)
#define LL_RCC_MCO2_DIV_14                                                     \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE_1 |                  \
             RCC_CFGR_MCO2PRE_2 | RCC_CFGR_MCO2PRE_3)
#define LL_RCC_MCO2_DIV_15                                                     \
  (uint32_t)((RCC_CFGR_MCO2PRE >> 16U) | RCC_CFGR_MCO2PRE)

/**
 * @}
 */

/** @defgroup RCC_LL_EC_RTC_HSEDIV  HSE prescaler for RTC clock
 * @{
 */
#define LL_RCC_RTC_NOCLOCK (uint32_t)(0x00000000U)
#define LL_RCC_RTC_HSE_DIV_2 (uint32_t)(RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_3 (uint32_t)(RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_4 (uint32_t)(RCC_CFGR_RTCPRE_2)
#define LL_RCC_RTC_HSE_DIV_5 (uint32_t)(RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_6 (uint32_t)(RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_7                                                   \
  (uint32_t)(RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_8 (uint32_t)(RCC_CFGR_RTCPRE_3)
#define LL_RCC_RTC_HSE_DIV_9 (uint32_t)(RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_10 (uint32_t)(RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_11                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_12 (uint32_t)(RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2)
#define LL_RCC_RTC_HSE_DIV_13                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_14                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_15                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_16 (uint32_t)(RCC_CFGR_RTCPRE_4)
#define LL_RCC_RTC_HSE_DIV_17 (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_18 (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_19                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_20 (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_2)
#define LL_RCC_RTC_HSE_DIV_21                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_22                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_23                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_24 (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3)
#define LL_RCC_RTC_HSE_DIV_25                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_26                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_27                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_1 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_28                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2)
#define LL_RCC_RTC_HSE_DIV_29                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_30                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_31                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_32 (uint32_t)(RCC_CFGR_RTCPRE_5)
#define LL_RCC_RTC_HSE_DIV_33 (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_34 (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_35                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_36 (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_2)
#define LL_RCC_RTC_HSE_DIV_37                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_38                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_39                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_40 (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_3)
#define LL_RCC_RTC_HSE_DIV_41                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_42                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_43                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_1 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_44                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2)
#define LL_RCC_RTC_HSE_DIV_45                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_46                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_47                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_3 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_48 (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4)
#define LL_RCC_RTC_HSE_DIV_49                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_50                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_51                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_1 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_52                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_2)
#define LL_RCC_RTC_HSE_DIV_53                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_54                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_55                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_2 |       \
             RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_56                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3)
#define LL_RCC_RTC_HSE_DIV_57                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 |       \
             RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_58                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 |       \
             RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_59                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 |       \
             RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_60                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 |       \
             RCC_CFGR_RTCPRE_2)
#define LL_RCC_RTC_HSE_DIV_61                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 |       \
             RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_0)
#define LL_RCC_RTC_HSE_DIV_62                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 |       \
             RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1)
#define LL_RCC_RTC_HSE_DIV_63                                                  \
  (uint32_t)(RCC_CFGR_RTCPRE_5 | RCC_CFGR_RTCPRE_4 | RCC_CFGR_RTCPRE_3 |       \
             RCC_CFGR_RTCPRE_2 | RCC_CFGR_RTCPRE_1 | RCC_CFGR_RTCPRE_0)
/**
 * @}
 */

/** @defgroup RCC_LL_EC_USARTx_CLKSOURCE  Peripheral USART clock source
 * selection
 * @{
 */
#if defined(RCC_D2CCIP2R_USART16SEL)
#define LL_RCC_USART16_CLKSOURCE_PCLK2                                         \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16SEL, RCC_D2CCIP2R_USART16SEL_Pos,  \
               0x00000000U)
#define LL_RCC_USART16_CLKSOURCE_PLL2Q                                         \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16SEL, RCC_D2CCIP2R_USART16SEL_Pos,  \
               RCC_D2CCIP2R_USART16SEL_0)
#define LL_RCC_USART16_CLKSOURCE_PLL3Q                                         \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16SEL, RCC_D2CCIP2R_USART16SEL_Pos,  \
               RCC_D2CCIP2R_USART16SEL_1)
#define LL_RCC_USART16_CLKSOURCE_HSI                                           \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16SEL, RCC_D2CCIP2R_USART16SEL_Pos,  \
               RCC_D2CCIP2R_USART16SEL_0 | RCC_D2CCIP2R_USART16SEL_1)
#define LL_RCC_USART16_CLKSOURCE_CSI                                           \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16SEL, RCC_D2CCIP2R_USART16SEL_Pos,  \
               RCC_D2CCIP2R_USART16SEL_2)
#define LL_RCC_USART16_CLKSOURCE_LSE                                           \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16SEL, RCC_D2CCIP2R_USART16SEL_Pos,  \
               RCC_D2CCIP2R_USART16SEL_0 | RCC_D2CCIP2R_USART16SEL_2)
/*  Aliases */
#define LL_RCC_USART16910_CLKSOURCE_PCLK2 LL_RCC_USART16_CLKSOURCE_PCLK2
#define LL_RCC_USART16910_CLKSOURCE_PLL2Q LL_RCC_USART16_CLKSOURCE_PLL2Q
#define LL_RCC_USART16910_CLKSOURCE_PLL3Q LL_RCC_USART16_CLKSOURCE_PLL3Q
#define LL_RCC_USART16910_CLKSOURCE_HSI LL_RCC_USART16_CLKSOURCE_HSI
#define LL_RCC_USART16910_CLKSOURCE_CSI LL_RCC_USART16_CLKSOURCE_CSI
#define LL_RCC_USART16910_CLKSOURCE_LSE LL_RCC_USART16_CLKSOURCE_LSE

#elif defined(RCC_D2CCIP2R_USART16910SEL)
#define LL_RCC_USART16910_CLKSOURCE_PCLK2                                      \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16910SEL,                            \
               RCC_D2CCIP2R_USART16910SEL_Pos, 0x00000000U)
#define LL_RCC_USART16910_CLKSOURCE_PLL2Q                                      \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16910SEL,                            \
               RCC_D2CCIP2R_USART16910SEL_Pos, RCC_D2CCIP2R_USART16910SEL_0)
#define LL_RCC_USART16910_CLKSOURCE_PLL3Q                                      \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16910SEL,                            \
               RCC_D2CCIP2R_USART16910SEL_Pos, RCC_D2CCIP2R_USART16910SEL_1)
#define LL_RCC_USART16910_CLKSOURCE_HSI                                        \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16910SEL,                            \
               RCC_D2CCIP2R_USART16910SEL_Pos,                                 \
               RCC_D2CCIP2R_USART16910SEL_0 | RCC_D2CCIP2R_USART16910SEL_1)
#define LL_RCC_USART16910_CLKSOURCE_CSI                                        \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16910SEL,                            \
               RCC_D2CCIP2R_USART16910SEL_Pos, RCC_D2CCIP2R_USART16910SEL_2)
#define LL_RCC_USART16910_CLKSOURCE_LSE                                        \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16910SEL,                            \
               RCC_D2CCIP2R_USART16910SEL_Pos,                                 \
               RCC_D2CCIP2R_USART16910SEL_0 | RCC_D2CCIP2R_USART16910SEL_2)
/*  Aliases */
#define LL_RCC_USART16_CLKSOURCE_PCLK2 LL_RCC_USART16910_CLKSOURCE_PCLK2
#define LL_RCC_USART16_CLKSOURCE_PLL2Q LL_RCC_USART16910_CLKSOURCE_PLL2Q
#define LL_RCC_USART16_CLKSOURCE_PLL3Q LL_RCC_USART16910_CLKSOURCE_PLL3Q
#define LL_RCC_USART16_CLKSOURCE_HSI LL_RCC_USART16910_CLKSOURCE_HSI
#define LL_RCC_USART16_CLKSOURCE_CSI LL_RCC_USART16910_CLKSOURCE_CSI
#define LL_RCC_USART16_CLKSOURCE_LSE LL_RCC_USART16910_CLKSOURCE_LSE

#else
#define LL_RCC_USART16910_CLKSOURCE_PCLK2                                      \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART16910SEL,                            \
               RCC_CDCCIP2R_USART16910SEL_Pos, 0x00000000U)
#define LL_RCC_USART16910_CLKSOURCE_PLL2Q                                      \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART16910SEL,                            \
               RCC_CDCCIP2R_USART16910SEL_Pos, RCC_CDCCIP2R_USART16910SEL_0)
#define LL_RCC_USART16910_CLKSOURCE_PLL3Q                                      \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART16910SEL,                            \
               RCC_CDCCIP2R_USART16910SEL_Pos, RCC_CDCCIP2R_USART16910SEL_1)
#define LL_RCC_USART16910_CLKSOURCE_HSI                                        \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART16910SEL,                            \
               RCC_CDCCIP2R_USART16910SEL_Pos,                                 \
               RCC_CDCCIP2R_USART16910SEL_0 | RCC_CDCCIP2R_USART16910SEL_1)
#define LL_RCC_USART16910_CLKSOURCE_CSI                                        \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART16910SEL,                            \
               RCC_CDCCIP2R_USART16910SEL_Pos, RCC_CDCCIP2R_USART16910SEL_2)
#define LL_RCC_USART16910_CLKSOURCE_LSE                                        \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART16910SEL,                            \
               RCC_CDCCIP2R_USART16910SEL_Pos,                                 \
               RCC_CDCCIP2R_USART16910SEL_0 | RCC_CDCCIP2R_USART16910SEL_2)
/*  Aliases */
#define LL_RCC_USART16_CLKSOURCE_PCLK2 LL_RCC_USART16910_CLKSOURCE_PCLK2
#define LL_RCC_USART16_CLKSOURCE_PLL2Q LL_RCC_USART16910_CLKSOURCE_PLL2Q
#define LL_RCC_USART16_CLKSOURCE_PLL3Q LL_RCC_USART16910_CLKSOURCE_PLL3Q
#define LL_RCC_USART16_CLKSOURCE_HSI LL_RCC_USART16910_CLKSOURCE_HSI
#define LL_RCC_USART16_CLKSOURCE_CSI LL_RCC_USART16910_CLKSOURCE_CSI
#define LL_RCC_USART16_CLKSOURCE_LSE LL_RCC_USART16910_CLKSOURCE_LSE
#endif /* RCC_D2CCIP2R_USART16SEL */
#if defined(RCC_D2CCIP2R_USART28SEL)
#define LL_RCC_USART234578_CLKSOURCE_PCLK1                                     \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART28SEL, RCC_D2CCIP2R_USART28SEL_Pos,  \
               0x00000000U)
#define LL_RCC_USART234578_CLKSOURCE_PLL2Q                                     \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART28SEL, RCC_D2CCIP2R_USART28SEL_Pos,  \
               RCC_D2CCIP2R_USART28SEL_0)
#define LL_RCC_USART234578_CLKSOURCE_PLL3Q                                     \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART28SEL, RCC_D2CCIP2R_USART28SEL_Pos,  \
               RCC_D2CCIP2R_USART28SEL_1)
#define LL_RCC_USART234578_CLKSOURCE_HSI                                       \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART28SEL, RCC_D2CCIP2R_USART28SEL_Pos,  \
               RCC_D2CCIP2R_USART28SEL_0 | RCC_D2CCIP2R_USART28SEL_1)
#define LL_RCC_USART234578_CLKSOURCE_CSI                                       \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART28SEL, RCC_D2CCIP2R_USART28SEL_Pos,  \
               RCC_D2CCIP2R_USART28SEL_2)
#define LL_RCC_USART234578_CLKSOURCE_LSE                                       \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART28SEL, RCC_D2CCIP2R_USART28SEL_Pos,  \
               RCC_D2CCIP2R_USART28SEL_0 | RCC_D2CCIP2R_USART28SEL_2)
#else
#define LL_RCC_USART234578_CLKSOURCE_PCLK1                                     \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART234578SEL,                           \
               RCC_CDCCIP2R_USART234578SEL_Pos, 0x00000000U)
#define LL_RCC_USART234578_CLKSOURCE_PLL2Q                                     \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART234578SEL,                           \
               RCC_CDCCIP2R_USART234578SEL_Pos, RCC_CDCCIP2R_USART234578SEL_0)
#define LL_RCC_USART234578_CLKSOURCE_PLL3Q                                     \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART234578SEL,                           \
               RCC_CDCCIP2R_USART234578SEL_Pos, RCC_CDCCIP2R_USART234578SEL_1)
#define LL_RCC_USART234578_CLKSOURCE_HSI                                       \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART234578SEL,                           \
               RCC_CDCCIP2R_USART234578SEL_Pos,                                \
               RCC_CDCCIP2R_USART234578SEL_0 | RCC_CDCCIP2R_USART234578SEL_1)
#define LL_RCC_USART234578_CLKSOURCE_CSI                                       \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART234578SEL,                           \
               RCC_CDCCIP2R_USART234578SEL_Pos, RCC_CDCCIP2R_USART234578SEL_2)
#define LL_RCC_USART234578_CLKSOURCE_LSE                                       \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART234578SEL,                           \
               RCC_CDCCIP2R_USART234578SEL_Pos,                                \
               RCC_CDCCIP2R_USART234578SEL_0 | RCC_CDCCIP2R_USART234578SEL_2)
#endif /* RCC_D2CCIP2R_USART28SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_LPUARTx_CLKSOURCE  Peripheral LPUART clock source
 * selection
 * @{
 */
#if defined(RCC_D3CCIPR_LPUART1SEL)
#define LL_RCC_LPUART1_CLKSOURCE_PCLK4 (0x00000000U)
#define LL_RCC_LPUART1_CLKSOURCE_PLL2Q (RCC_D3CCIPR_LPUART1SEL_0)
#define LL_RCC_LPUART1_CLKSOURCE_PLL3Q (RCC_D3CCIPR_LPUART1SEL_1)
#define LL_RCC_LPUART1_CLKSOURCE_HSI                                           \
  (RCC_D3CCIPR_LPUART1SEL_0 | RCC_D3CCIPR_LPUART1SEL_1)
#define LL_RCC_LPUART1_CLKSOURCE_CSI (RCC_D3CCIPR_LPUART1SEL_2)
#define LL_RCC_LPUART1_CLKSOURCE_LSE                                           \
  (RCC_D3CCIPR_LPUART1SEL_0 | RCC_D3CCIPR_LPUART1SEL_2)
#else
#define LL_RCC_LPUART1_CLKSOURCE_PCLK4 (0x00000000U)
#define LL_RCC_LPUART1_CLKSOURCE_PLL2Q (RCC_SRDCCIPR_LPUART1SEL_0)
#define LL_RCC_LPUART1_CLKSOURCE_PLL3Q (RCC_SRDCCIPR_LPUART1SEL_1)
#define LL_RCC_LPUART1_CLKSOURCE_HSI                                           \
  (RCC_SRDCCIPR_LPUART1SEL_0 | RCC_SRDCCIPR_LPUART1SEL_1)
#define LL_RCC_LPUART1_CLKSOURCE_CSI (RCC_SRDCCIPR_LPUART1SEL_2)
#define LL_RCC_LPUART1_CLKSOURCE_LSE                                           \
  (RCC_SRDCCIPR_LPUART1SEL_0 | RCC_SRDCCIPR_LPUART1SEL_2)
#endif /* RCC_D3CCIPR_LPUART1SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_I2Cx_CLKSOURCE  Peripheral I2C clock source selection
 * @{
 */
#if defined(RCC_D2CCIP2R_I2C123SEL)
#define LL_RCC_I2C123_CLKSOURCE_PCLK1                                          \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C123SEL, RCC_D2CCIP2R_I2C123SEL_Pos,    \
               0x00000000U)
#define LL_RCC_I2C123_CLKSOURCE_PLL3R                                          \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C123SEL, RCC_D2CCIP2R_I2C123SEL_Pos,    \
               RCC_D2CCIP2R_I2C123SEL_0)
#define LL_RCC_I2C123_CLKSOURCE_HSI                                            \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C123SEL, RCC_D2CCIP2R_I2C123SEL_Pos,    \
               RCC_D2CCIP2R_I2C123SEL_1)
#define LL_RCC_I2C123_CLKSOURCE_CSI                                            \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C123SEL, RCC_D2CCIP2R_I2C123SEL_Pos,    \
               RCC_D2CCIP2R_I2C123SEL_0 | RCC_D2CCIP2R_I2C123SEL_1)
/*  Aliases */
#define LL_RCC_I2C1235_CLKSOURCE_PCLK1 LL_RCC_I2C123_CLKSOURCE_PCLK1
#define LL_RCC_I2C1235_CLKSOURCE_PLL3R LL_RCC_I2C123_CLKSOURCE_PLL3R
#define LL_RCC_I2C1235_CLKSOURCE_HSI LL_RCC_I2C123_CLKSOURCE_HSI
#define LL_RCC_I2C1235_CLKSOURCE_CSI LL_RCC_I2C123_CLKSOURCE_CSI

#elif defined(RCC_D2CCIP2R_I2C1235SEL)
#define LL_RCC_I2C1235_CLKSOURCE_PCLK1                                         \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C1235SEL, RCC_D2CCIP2R_I2C1235SEL_Pos,  \
               0x00000000U)
#define LL_RCC_I2C1235_CLKSOURCE_PLL3R                                         \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C1235SEL, RCC_D2CCIP2R_I2C1235SEL_Pos,  \
               RCC_D2CCIP2R_I2C1235SEL_0)
#define LL_RCC_I2C1235_CLKSOURCE_HSI                                           \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C1235SEL, RCC_D2CCIP2R_I2C1235SEL_Pos,  \
               RCC_D2CCIP2R_I2C1235SEL_1)
#define LL_RCC_I2C1235_CLKSOURCE_CSI                                           \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C1235SEL, RCC_D2CCIP2R_I2C1235SEL_Pos,  \
               RCC_D2CCIP2R_I2C1235SEL_0 | RCC_D2CCIP2R_I2C1235SEL_1)
/*  Aliases */
#define LL_RCC_I2C123_CLKSOURCE_PCLK1 LL_RCC_I2C1235_CLKSOURCE_PCLK1
#define LL_RCC_I2C123_CLKSOURCE_PLL3R LL_RCC_I2C1235_CLKSOURCE_PLL3R
#define LL_RCC_I2C123_CLKSOURCE_HSI LL_RCC_I2C1235_CLKSOURCE_HSI
#define LL_RCC_I2C123_CLKSOURCE_CSI LL_RCC_I2C1235_CLKSOURCE_CSI

#else
#define LL_RCC_I2C123_CLKSOURCE_PCLK1                                          \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_I2C123SEL, RCC_CDCCIP2R_I2C123SEL_Pos,    \
               0x00000000U)
#define LL_RCC_I2C123_CLKSOURCE_PLL3R                                          \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_I2C123SEL, RCC_CDCCIP2R_I2C123SEL_Pos,    \
               RCC_CDCCIP2R_I2C123SEL_0)
#define LL_RCC_I2C123_CLKSOURCE_HSI                                            \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_I2C123SEL, RCC_CDCCIP2R_I2C123SEL_Pos,    \
               RCC_CDCCIP2R_I2C123SEL_1)
#define LL_RCC_I2C123_CLKSOURCE_CSI                                            \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_I2C123SEL, RCC_CDCCIP2R_I2C123SEL_Pos,    \
               RCC_CDCCIP2R_I2C123SEL_0 | RCC_CDCCIP2R_I2C123SEL_1)
#endif /* RCC_D2CCIP2R_I2C123SEL */
#if defined(RCC_D3CCIPR_I2C4SEL)
#define LL_RCC_I2C4_CLKSOURCE_PCLK4                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_I2C4SEL, RCC_D3CCIPR_I2C4SEL_Pos,           \
               0x00000000U)
#define LL_RCC_I2C4_CLKSOURCE_PLL3R                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_I2C4SEL, RCC_D3CCIPR_I2C4SEL_Pos,           \
               RCC_D3CCIPR_I2C4SEL_0)
#define LL_RCC_I2C4_CLKSOURCE_HSI                                              \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_I2C4SEL, RCC_D3CCIPR_I2C4SEL_Pos,           \
               RCC_D3CCIPR_I2C4SEL_1)
#define LL_RCC_I2C4_CLKSOURCE_CSI                                              \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_I2C4SEL, RCC_D3CCIPR_I2C4SEL_Pos,           \
               RCC_D3CCIPR_I2C4SEL_0 | RCC_D3CCIPR_I2C4SEL_1)
#else
#define LL_RCC_I2C4_CLKSOURCE_PCLK4                                            \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_I2C4SEL, RCC_SRDCCIPR_I2C4SEL_Pos,        \
               0x00000000U)
#define LL_RCC_I2C4_CLKSOURCE_PLL3R                                            \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_I2C4SEL, RCC_SRDCCIPR_I2C4SEL_Pos,        \
               RCC_SRDCCIPR_I2C4SEL_0)
#define LL_RCC_I2C4_CLKSOURCE_HSI                                              \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_I2C4SEL, RCC_SRDCCIPR_I2C4SEL_Pos,        \
               RCC_SRDCCIPR_I2C4SEL_1)
#define LL_RCC_I2C4_CLKSOURCE_CSI                                              \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_I2C4SEL, RCC_SRDCCIPR_I2C4SEL_Pos,        \
               RCC_SRDCCIPR_I2C4SEL_0 | RCC_SRDCCIPR_I2C4SEL_1)
#endif /* RCC_D3CCIPR_I2C4SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_LPTIMx_CLKSOURCE  Peripheral LPTIM clock source
 * selection
 * @{
 */
#if defined(RCC_D2CCIP2R_LPTIM1SEL)
#define LL_RCC_LPTIM1_CLKSOURCE_PCLK1                                          \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_LPTIM1SEL, RCC_D2CCIP2R_LPTIM1SEL_Pos,    \
               0x00000000U)
#define LL_RCC_LPTIM1_CLKSOURCE_PLL2P                                          \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_LPTIM1SEL, RCC_D2CCIP2R_LPTIM1SEL_Pos,    \
               RCC_D2CCIP2R_LPTIM1SEL_0)
#define LL_RCC_LPTIM1_CLKSOURCE_PLL3R                                          \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_LPTIM1SEL, RCC_D2CCIP2R_LPTIM1SEL_Pos,    \
               RCC_D2CCIP2R_LPTIM1SEL_1)
#define LL_RCC_LPTIM1_CLKSOURCE_LSE                                            \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_LPTIM1SEL, RCC_D2CCIP2R_LPTIM1SEL_Pos,    \
               RCC_D2CCIP2R_LPTIM1SEL_0 | RCC_D2CCIP2R_LPTIM1SEL_1)
#define LL_RCC_LPTIM1_CLKSOURCE_LSI                                            \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_LPTIM1SEL, RCC_D2CCIP2R_LPTIM1SEL_Pos,    \
               RCC_D2CCIP2R_LPTIM1SEL_2)
#define LL_RCC_LPTIM1_CLKSOURCE_CLKP                                           \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_LPTIM1SEL, RCC_D2CCIP2R_LPTIM1SEL_Pos,    \
               RCC_D2CCIP2R_LPTIM1SEL_0 | RCC_D2CCIP2R_LPTIM1SEL_2)
#else
#define LL_RCC_LPTIM1_CLKSOURCE_PCLK1                                          \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_LPTIM1SEL, RCC_CDCCIP2R_LPTIM1SEL_Pos,    \
               0x00000000U)
#define LL_RCC_LPTIM1_CLKSOURCE_PLL2P                                          \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_LPTIM1SEL, RCC_CDCCIP2R_LPTIM1SEL_Pos,    \
               RCC_CDCCIP2R_LPTIM1SEL_0)
#define LL_RCC_LPTIM1_CLKSOURCE_PLL3R                                          \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_LPTIM1SEL, RCC_CDCCIP2R_LPTIM1SEL_Pos,    \
               RCC_CDCCIP2R_LPTIM1SEL_1)
#define LL_RCC_LPTIM1_CLKSOURCE_LSE                                            \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_LPTIM1SEL, RCC_CDCCIP2R_LPTIM1SEL_Pos,    \
               RCC_CDCCIP2R_LPTIM1SEL_0 | RCC_CDCCIP2R_LPTIM1SEL_1)
#define LL_RCC_LPTIM1_CLKSOURCE_LSI                                            \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_LPTIM1SEL, RCC_CDCCIP2R_LPTIM1SEL_Pos,    \
               RCC_CDCCIP2R_LPTIM1SEL_2)
#define LL_RCC_LPTIM1_CLKSOURCE_CLKP                                           \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_LPTIM1SEL, RCC_CDCCIP2R_LPTIM1SEL_Pos,    \
               RCC_CDCCIP2R_LPTIM1SEL_0 | RCC_CDCCIP2R_LPTIM1SEL_2)
#endif /* RCC_D2CCIP2R_LPTIM1SEL */
#if defined(RCC_D3CCIPR_LPTIM2SEL)
#define LL_RCC_LPTIM2_CLKSOURCE_PCLK4                                          \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM2SEL, RCC_D3CCIPR_LPTIM2SEL_Pos,       \
               0x00000000U)
#define LL_RCC_LPTIM2_CLKSOURCE_PLL2P                                          \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM2SEL, RCC_D3CCIPR_LPTIM2SEL_Pos,       \
               RCC_D3CCIPR_LPTIM2SEL_0)
#define LL_RCC_LPTIM2_CLKSOURCE_PLL3R                                          \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM2SEL, RCC_D3CCIPR_LPTIM2SEL_Pos,       \
               RCC_D3CCIPR_LPTIM2SEL_1)
#define LL_RCC_LPTIM2_CLKSOURCE_LSE                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM2SEL, RCC_D3CCIPR_LPTIM2SEL_Pos,       \
               RCC_D3CCIPR_LPTIM2SEL_0 | RCC_D3CCIPR_LPTIM2SEL_1)
#define LL_RCC_LPTIM2_CLKSOURCE_LSI                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM2SEL, RCC_D3CCIPR_LPTIM2SEL_Pos,       \
               RCC_D3CCIPR_LPTIM2SEL_2)
#define LL_RCC_LPTIM2_CLKSOURCE_CLKP                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM2SEL, RCC_D3CCIPR_LPTIM2SEL_Pos,       \
               RCC_D3CCIPR_LPTIM2SEL_0 | RCC_D3CCIPR_LPTIM2SEL_2)
#else
#define LL_RCC_LPTIM2_CLKSOURCE_PCLK4                                          \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM2SEL, RCC_SRDCCIPR_LPTIM2SEL_Pos,    \
               0x00000000U)
#define LL_RCC_LPTIM2_CLKSOURCE_PLL2P                                          \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM2SEL, RCC_SRDCCIPR_LPTIM2SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM2SEL_0)
#define LL_RCC_LPTIM2_CLKSOURCE_PLL3R                                          \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM2SEL, RCC_SRDCCIPR_LPTIM2SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM2SEL_1)
#define LL_RCC_LPTIM2_CLKSOURCE_LSE                                            \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM2SEL, RCC_SRDCCIPR_LPTIM2SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM2SEL_0 | RCC_SRDCCIPR_LPTIM2SEL_1)
#define LL_RCC_LPTIM2_CLKSOURCE_LSI                                            \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM2SEL, RCC_SRDCCIPR_LPTIM2SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM2SEL_2)
#define LL_RCC_LPTIM2_CLKSOURCE_CLKP                                           \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM2SEL, RCC_SRDCCIPR_LPTIM2SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM2SEL_0 | RCC_SRDCCIPR_LPTIM2SEL_2)
#endif /* RCC_D3CCIPR_LPTIM2SEL */
#if defined(RCC_D3CCIPR_LPTIM345SEL)
#define LL_RCC_LPTIM345_CLKSOURCE_PCLK4                                        \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM345SEL, RCC_D3CCIPR_LPTIM345SEL_Pos,   \
               0x00000000U)
#define LL_RCC_LPTIM345_CLKSOURCE_PLL2P                                        \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM345SEL, RCC_D3CCIPR_LPTIM345SEL_Pos,   \
               RCC_D3CCIPR_LPTIM345SEL_0)
#define LL_RCC_LPTIM345_CLKSOURCE_PLL3R                                        \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM345SEL, RCC_D3CCIPR_LPTIM345SEL_Pos,   \
               RCC_D3CCIPR_LPTIM345SEL_1)
#define LL_RCC_LPTIM345_CLKSOURCE_LSE                                          \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM345SEL, RCC_D3CCIPR_LPTIM345SEL_Pos,   \
               RCC_D3CCIPR_LPTIM345SEL_0 | RCC_D3CCIPR_LPTIM345SEL_1)
#define LL_RCC_LPTIM345_CLKSOURCE_LSI                                          \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM345SEL, RCC_D3CCIPR_LPTIM345SEL_Pos,   \
               RCC_D3CCIPR_LPTIM345SEL_2)
#define LL_RCC_LPTIM345_CLKSOURCE_CLKP                                         \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM345SEL, RCC_D3CCIPR_LPTIM345SEL_Pos,   \
               RCC_D3CCIPR_LPTIM345SEL_0 | RCC_D3CCIPR_LPTIM345SEL_2)
#else
#define LL_RCC_LPTIM345_CLKSOURCE_PCLK4                                        \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM3SEL, RCC_SRDCCIPR_LPTIM3SEL_Pos,    \
               0x00000000U)
#define LL_RCC_LPTIM345_CLKSOURCE_PLL2P                                        \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM3SEL, RCC_SRDCCIPR_LPTIM3SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM3SEL_0)
#define LL_RCC_LPTIM345_CLKSOURCE_PLL3R                                        \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM3SEL, RCC_SRDCCIPR_LPTIM3SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM3SEL_1)
#define LL_RCC_LPTIM345_CLKSOURCE_LSE                                          \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM3SEL, RCC_SRDCCIPR_LPTIM3SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM3SEL_0 | RCC_SRDCCIPR_LPTIM3SEL_1)
#define LL_RCC_LPTIM345_CLKSOURCE_LSI                                          \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM3SEL, RCC_SRDCCIPR_LPTIM3SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM3SEL_2)
#define LL_RCC_LPTIM345_CLKSOURCE_CLKP                                         \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM3SEL, RCC_SRDCCIPR_LPTIM3SEL_Pos,    \
               RCC_SRDCCIPR_LPTIM3SEL_0 | RCC_SRDCCIPR_LPTIM3SEL_2)
/* aliases*/
#define LL_RCC_LPTIM3_CLKSOURCE_PCLK4 LL_RCC_LPTIM345_CLKSOURCE_PCLK4
#define LL_RCC_LPTIM3_CLKSOURCE_PLL2P LL_RCC_LPTIM345_CLKSOURCE_PLL2P
#define LL_RCC_LPTIM3_CLKSOURCE_PLL3R LL_RCC_LPTIM345_CLKSOURCE_PLL3R
#define LL_RCC_LPTIM3_CLKSOURCE_LSE LL_RCC_LPTIM345_CLKSOURCE_LSE
#define LL_RCC_LPTIM3_CLKSOURCE_LSI LL_RCC_LPTIM345_CLKSOURCE_LSI
#define LL_RCC_LPTIM3_CLKSOURCE_CLKP LL_RCC_LPTIM345_CLKSOURCE_CLKP
#endif /* RCC_D3CCIPR_LPTIM345SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SAIx_CLKSOURCE  Peripheral SAI clock source selection
 * @{
 */
#if defined(RCC_D2CCIP1R_SAI1SEL)
#define LL_RCC_SAI1_CLKSOURCE_PLL1Q                                            \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI1SEL, RCC_D2CCIP1R_SAI1SEL_Pos,        \
               0x00000000U)
#define LL_RCC_SAI1_CLKSOURCE_PLL2P                                            \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI1SEL, RCC_D2CCIP1R_SAI1SEL_Pos,        \
               RCC_D2CCIP1R_SAI1SEL_0)
#define LL_RCC_SAI1_CLKSOURCE_PLL3P                                            \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI1SEL, RCC_D2CCIP1R_SAI1SEL_Pos,        \
               RCC_D2CCIP1R_SAI1SEL_1)
#define LL_RCC_SAI1_CLKSOURCE_I2S_CKIN                                         \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI1SEL, RCC_D2CCIP1R_SAI1SEL_Pos,        \
               RCC_D2CCIP1R_SAI1SEL_0 | RCC_D2CCIP1R_SAI1SEL_1)
#define LL_RCC_SAI1_CLKSOURCE_CLKP                                             \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI1SEL, RCC_D2CCIP1R_SAI1SEL_Pos,        \
               RCC_D2CCIP1R_SAI1SEL_2)
#else
#define LL_RCC_SAI1_CLKSOURCE_PLL1Q                                            \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI1SEL, RCC_CDCCIP1R_SAI1SEL_Pos,        \
               0x00000000U)
#define LL_RCC_SAI1_CLKSOURCE_PLL2P                                            \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI1SEL, RCC_CDCCIP1R_SAI1SEL_Pos,        \
               RCC_CDCCIP1R_SAI1SEL_0)
#define LL_RCC_SAI1_CLKSOURCE_PLL3P                                            \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI1SEL, RCC_CDCCIP1R_SAI1SEL_Pos,        \
               RCC_CDCCIP1R_SAI1SEL_1)
#define LL_RCC_SAI1_CLKSOURCE_I2S_CKIN                                         \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI1SEL, RCC_CDCCIP1R_SAI1SEL_Pos,        \
               RCC_CDCCIP1R_SAI1SEL_0 | RCC_CDCCIP1R_SAI1SEL_1)
#define LL_RCC_SAI1_CLKSOURCE_CLKP                                             \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI1SEL, RCC_CDCCIP1R_SAI1SEL_Pos,        \
               RCC_CDCCIP1R_SAI1SEL_2)
#endif
#if defined(SAI3)
#define LL_RCC_SAI23_CLKSOURCE_PLL1Q                                           \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI23SEL, RCC_D2CCIP1R_SAI23SEL_Pos,      \
               0x00000000U)
#define LL_RCC_SAI23_CLKSOURCE_PLL2P                                           \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI23SEL, RCC_D2CCIP1R_SAI23SEL_Pos,      \
               RCC_D2CCIP1R_SAI23SEL_0)
#define LL_RCC_SAI23_CLKSOURCE_PLL3P                                           \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI23SEL, RCC_D2CCIP1R_SAI23SEL_Pos,      \
               RCC_D2CCIP1R_SAI23SEL_1)
#define LL_RCC_SAI23_CLKSOURCE_I2S_CKIN                                        \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI23SEL, RCC_D2CCIP1R_SAI23SEL_Pos,      \
               RCC_D2CCIP1R_SAI23SEL_0 | RCC_D2CCIP1R_SAI23SEL_1)
#define LL_RCC_SAI23_CLKSOURCE_CLKP                                            \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI23SEL, RCC_D2CCIP1R_SAI23SEL_Pos,      \
               RCC_D2CCIP1R_SAI23SEL_2)
#endif /* SAI3 */
#if defined(RCC_CDCCIP1R_SAI2ASEL)
#define LL_RCC_SAI2A_CLKSOURCE_PLL1Q                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2ASEL, RCC_CDCCIP1R_SAI2ASEL_Pos,      \
               0x00000000U)
#define LL_RCC_SAI2A_CLKSOURCE_PLL2P                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2ASEL, RCC_CDCCIP1R_SAI2ASEL_Pos,      \
               RCC_CDCCIP1R_SAI2ASEL_0)
#define LL_RCC_SAI2A_CLKSOURCE_PLL3P                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2ASEL, RCC_CDCCIP1R_SAI2ASEL_Pos,      \
               RCC_CDCCIP1R_SAI2ASEL_1)
#define LL_RCC_SAI2A_CLKSOURCE_I2S_CKIN                                        \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2ASEL, RCC_CDCCIP1R_SAI2ASEL_Pos,      \
               RCC_CDCCIP1R_SAI2ASEL_0 | RCC_CDCCIP1R_SAI2ASEL_1)
#define LL_RCC_SAI2A_CLKSOURCE_CLKP                                            \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2ASEL, RCC_CDCCIP1R_SAI2ASEL_Pos,      \
               RCC_CDCCIP1R_SAI2ASEL_2)
#define LL_RCC_SAI2A_CLKSOURCE_SPDIF                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2ASEL, RCC_CDCCIP1R_SAI2ASEL_Pos,      \
               RCC_CDCCIP1R_SAI2ASEL_0 | RCC_CDCCIP1R_SAI2ASEL_2)
#endif /* RCC_CDCCIP1R_SAI2ASEL */
#if defined(RCC_CDCCIP1R_SAI2BSEL)
#define LL_RCC_SAI2B_CLKSOURCE_PLL1Q                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2BSEL, RCC_CDCCIP1R_SAI2BSEL_Pos,      \
               0x00000000U)
#define LL_RCC_SAI2B_CLKSOURCE_PLL2P                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2BSEL, RCC_CDCCIP1R_SAI2BSEL_Pos,      \
               RCC_CDCCIP1R_SAI2BSEL_0)
#define LL_RCC_SAI2B_CLKSOURCE_PLL3P                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2BSEL, RCC_CDCCIP1R_SAI2BSEL_Pos,      \
               RCC_CDCCIP1R_SAI2BSEL_1)
#define LL_RCC_SAI2B_CLKSOURCE_I2S_CKIN                                        \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2BSEL, RCC_CDCCIP1R_SAI2BSEL_Pos,      \
               RCC_CDCCIP1R_SAI2BSEL_0 | RCC_CDCCIP1R_SAI2BSEL_1)
#define LL_RCC_SAI2B_CLKSOURCE_CLKP                                            \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2BSEL, RCC_CDCCIP1R_SAI2BSEL_Pos,      \
               RCC_CDCCIP1R_SAI2BSEL_2)
#define LL_RCC_SAI2B_CLKSOURCE_SPDIF                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2BSEL, RCC_CDCCIP1R_SAI2BSEL_Pos,      \
               RCC_CDCCIP1R_SAI2BSEL_0 | RCC_CDCCIP1R_SAI2BSEL_2)
#endif /* RCC_CDCCIP1R_SAI2BSEL */
#if defined(SAI4_Block_A)
#define LL_RCC_SAI4A_CLKSOURCE_PLL1Q                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4ASEL, RCC_D3CCIPR_SAI4ASEL_Pos,         \
               0x00000000U)
#define LL_RCC_SAI4A_CLKSOURCE_PLL2P                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4ASEL, RCC_D3CCIPR_SAI4ASEL_Pos,         \
               RCC_D3CCIPR_SAI4ASEL_0)
#define LL_RCC_SAI4A_CLKSOURCE_PLL3P                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4ASEL, RCC_D3CCIPR_SAI4ASEL_Pos,         \
               RCC_D3CCIPR_SAI4ASEL_1)
#define LL_RCC_SAI4A_CLKSOURCE_I2S_CKIN                                        \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4ASEL, RCC_D3CCIPR_SAI4ASEL_Pos,         \
               RCC_D3CCIPR_SAI4ASEL_0 | RCC_D3CCIPR_SAI4ASEL_1)
#define LL_RCC_SAI4A_CLKSOURCE_CLKP                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4ASEL, RCC_D3CCIPR_SAI4ASEL_Pos,         \
               RCC_D3CCIPR_SAI4ASEL_2)
#if defined(RCC_VER_3_0)
#define LL_RCC_SAI4A_CLKSOURCE_SPDIF                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4ASEL, RCC_D3CCIPR_SAI4ASEL_Pos,         \
               RCC_D3CCIPR_SAI4ASEL_2 | RCC_D3CCIPR_SAI4ASEL_0)
#endif /* RCC_VER_3_0 */
#endif /* SAI4_Block_A */
#if defined(SAI4_Block_B)
#define LL_RCC_SAI4B_CLKSOURCE_PLL1Q                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4BSEL, RCC_D3CCIPR_SAI4BSEL_Pos,         \
               0x00000000U)
#define LL_RCC_SAI4B_CLKSOURCE_PLL2P                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4BSEL, RCC_D3CCIPR_SAI4BSEL_Pos,         \
               RCC_D3CCIPR_SAI4BSEL_0)
#define LL_RCC_SAI4B_CLKSOURCE_PLL3P                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4BSEL, RCC_D3CCIPR_SAI4BSEL_Pos,         \
               RCC_D3CCIPR_SAI4BSEL_1)
#define LL_RCC_SAI4B_CLKSOURCE_I2S_CKIN                                        \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4BSEL, RCC_D3CCIPR_SAI4BSEL_Pos,         \
               RCC_D3CCIPR_SAI4BSEL_0 | RCC_D3CCIPR_SAI4BSEL_1)
#define LL_RCC_SAI4B_CLKSOURCE_CLKP                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4BSEL, RCC_D3CCIPR_SAI4BSEL_Pos,         \
               RCC_D3CCIPR_SAI4BSEL_2)
#if defined(RCC_VER_3_0)
#define LL_RCC_SAI4B_CLKSOURCE_SPDIF                                           \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4BSEL, RCC_D3CCIPR_SAI4BSEL_Pos,         \
               RCC_D3CCIPR_SAI4BSEL_2 | RCC_D3CCIPR_SAI4BSEL_0)
#endif /* RCC_VER_3_0 */
#endif /* SAI4_Block_B */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SDMMC_CLKSOURCE  Peripheral SDMMC clock source selection
 * @{
 */
#if defined(RCC_D1CCIPR_SDMMCSEL)
#define LL_RCC_SDMMC_CLKSOURCE_PLL1Q (0x00000000U)
#define LL_RCC_SDMMC_CLKSOURCE_PLL2R (RCC_D1CCIPR_SDMMCSEL)
#else
#define LL_RCC_SDMMC_CLKSOURCE_PLL1Q (0x00000000U)
#define LL_RCC_SDMMC_CLKSOURCE_PLL2R (RCC_CDCCIPR_SDMMCSEL)
#endif /* RCC_D1CCIPR_SDMMCSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_RNG_CLKSOURCE  Peripheral RNG clock source selection
 * @{
 */
#if defined(RCC_D2CCIP2R_RNGSEL)
#define LL_RCC_RNG_CLKSOURCE_HSI48 (0x00000000U)
#define LL_RCC_RNG_CLKSOURCE_PLL1Q (RCC_D2CCIP2R_RNGSEL_0)
#define LL_RCC_RNG_CLKSOURCE_LSE (RCC_D2CCIP2R_RNGSEL_1)
#define LL_RCC_RNG_CLKSOURCE_LSI (RCC_D2CCIP2R_RNGSEL_1 | RCC_D2CCIP2R_RNGSEL_0)
#else
#define LL_RCC_RNG_CLKSOURCE_HSI48 (0x00000000U)
#define LL_RCC_RNG_CLKSOURCE_PLL1Q (RCC_CDCCIP2R_RNGSEL_0)
#define LL_RCC_RNG_CLKSOURCE_LSE (RCC_CDCCIP2R_RNGSEL_1)
#define LL_RCC_RNG_CLKSOURCE_LSI (RCC_CDCCIP2R_RNGSEL_1 | RCC_CDCCIP2R_RNGSEL_0)
#endif /* RCC_D2CCIP2R_RNGSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_USB_CLKSOURCE  Peripheral USB clock source selection
 * @{
 */
#if defined(RCC_D2CCIP2R_USBSEL)
#define LL_RCC_USB_CLKSOURCE_DISABLE (0x00000000U)
#define LL_RCC_USB_CLKSOURCE_PLL1Q (RCC_D2CCIP2R_USBSEL_0)
#define LL_RCC_USB_CLKSOURCE_PLL3Q (RCC_D2CCIP2R_USBSEL_1)
#define LL_RCC_USB_CLKSOURCE_HSI48                                             \
  (RCC_D2CCIP2R_USBSEL_1 | RCC_D2CCIP2R_USBSEL_0)
#else
#define LL_RCC_USB_CLKSOURCE_DISABLE (0x00000000U)
#define LL_RCC_USB_CLKSOURCE_PLL1Q (RCC_CDCCIP2R_USBSEL_0)
#define LL_RCC_USB_CLKSOURCE_PLL3Q (RCC_CDCCIP2R_USBSEL_1)
#define LL_RCC_USB_CLKSOURCE_HSI48                                             \
  (RCC_CDCCIP2R_USBSEL_1 | RCC_CDCCIP2R_USBSEL_0)
#endif /* RCC_D2CCIP2R_USBSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_CEC_CLKSOURCE  Peripheral CEC clock source selection
 * @{
 */
#if defined(RCC_D2CCIP2R_CECSEL)
#define LL_RCC_CEC_CLKSOURCE_LSE (0x00000000U)
#define LL_RCC_CEC_CLKSOURCE_LSI (RCC_D2CCIP2R_CECSEL_0)
#define LL_RCC_CEC_CLKSOURCE_CSI_DIV122 (RCC_D2CCIP2R_CECSEL_1)
#else
#define LL_RCC_CEC_CLKSOURCE_LSE (0x00000000U)
#define LL_RCC_CEC_CLKSOURCE_LSI (RCC_CDCCIP2R_CECSEL_0)
#define LL_RCC_CEC_CLKSOURCE_CSI_DIV122 (RCC_CDCCIP2R_CECSEL_1)
#endif
/**
 * @}
 */

#if defined(DSI)
/** @defgroup RCC_LL_EC_DSI_CLKSOURCE  Peripheral DSI clock source selection
 * @{
 */
#define LL_RCC_DSI_CLKSOURCE_PHY (0x00000000U)
#define LL_RCC_DSI_CLKSOURCE_PLL2Q (RCC_D1CCIPR_DSISEL)
/**
 * @}
 */
#endif /* DSI */

/** @defgroup RCC_LL_EC_DFSDM_CLKSOURCE  Peripheral DFSDM clock source selection
 * @{
 */
#if defined(RCC_D2CCIP1R_DFSDM1SEL)
#define LL_RCC_DFSDM1_CLKSOURCE_PCLK2 (0x00000000U)
#define LL_RCC_DFSDM1_CLKSOURCE_SYSCLK (RCC_D2CCIP1R_DFSDM1SEL)
#else
#define LL_RCC_DFSDM1_CLKSOURCE_PCLK2 (0x00000000U)
#define LL_RCC_DFSDM1_CLKSOURCE_SYSCLK (RCC_CDCCIP1R_DFSDM1SEL)
#endif /* RCC_D2CCIP1R_DFSDM1SEL */
/**
 * @}
 */

#if defined(DFSDM2_BASE)
/** @defgroup RCC_LL_EC_DFSDM2_CLKSOURCE  Peripheral DFSDM2 clock source
 * selection
 * @{
 */
#define LL_RCC_DFSDM2_CLKSOURCE_PCLK4 (0x00000000U)
#define LL_RCC_DFSDM2_CLKSOURCE_SYSCLK (RCC_SRDCCIPR_DFSDM2SEL)
/**
 * @}
 */
#endif /* DFSDM2_BASE */

/** @defgroup RCC_LL_EC_FMC_CLKSOURCE  Peripheral FMC clock source selection
 * @{
 */
#if defined(RCC_D1CCIPR_FMCSEL)
#define LL_RCC_FMC_CLKSOURCE_HCLK (0x00000000U)
#define LL_RCC_FMC_CLKSOURCE_PLL1Q (RCC_D1CCIPR_FMCSEL_0)
#define LL_RCC_FMC_CLKSOURCE_PLL2R (RCC_D1CCIPR_FMCSEL_1)
#define LL_RCC_FMC_CLKSOURCE_CLKP (RCC_D1CCIPR_FMCSEL_0 | RCC_D1CCIPR_FMCSEL_1)
#else
#define LL_RCC_FMC_CLKSOURCE_HCLK (0x00000000U)
#define LL_RCC_FMC_CLKSOURCE_PLL1Q (RCC_CDCCIPR_FMCSEL_0)
#define LL_RCC_FMC_CLKSOURCE_PLL2R (RCC_CDCCIPR_FMCSEL_1)
#define LL_RCC_FMC_CLKSOURCE_CLKP (RCC_CDCCIPR_FMCSEL_0 | RCC_CDCCIPR_FMCSEL_1)
#endif /* RCC_D1CCIPR_FMCSEL */
/**
 * @}
 */

#if defined(QUADSPI)
/** @defgroup RCC_LL_EC_QSPI_CLKSOURCE  Peripheral QSPI clock source selection
 * @{
 */
#define LL_RCC_QSPI_CLKSOURCE_HCLK (0x00000000U)
#define LL_RCC_QSPI_CLKSOURCE_PLL1Q (RCC_D1CCIPR_QSPISEL_0)
#define LL_RCC_QSPI_CLKSOURCE_PLL2R (RCC_D1CCIPR_QSPISEL_1)
#define LL_RCC_QSPI_CLKSOURCE_CLKP                                             \
  (RCC_D1CCIPR_QSPISEL_0 | RCC_D1CCIPR_QSPISEL_1)
/**
 * @}
 */
#endif /* QUADSPI */

#if defined(OCTOSPI1) || defined(OCTOSPI2)
/** @defgroup RCC_LL_EC_OSPI_CLKSOURCE  Peripheral OSPI clock source selection
 * @{
 */
#if defined(RCC_D1CCIPR_OCTOSPISEL)
#define LL_RCC_OSPI_CLKSOURCE_HCLK (0x00000000U)
#define LL_RCC_OSPI_CLKSOURCE_PLL1Q (RCC_D1CCIPR_OCTOSPISEL_0)
#define LL_RCC_OSPI_CLKSOURCE_PLL2R (RCC_D1CCIPR_OCTOSPISEL_1)
#define LL_RCC_OSPI_CLKSOURCE_CLKP                                             \
  (RCC_D1CCIPR_OCTOSPISEL_0 | RCC_D1CCIPR_OCTOSPISEL_1)
#else
#define LL_RCC_OSPI_CLKSOURCE_HCLK (0x00000000U)
#define LL_RCC_OSPI_CLKSOURCE_PLL1Q (RCC_CDCCIPR_OCTOSPISEL_0)
#define LL_RCC_OSPI_CLKSOURCE_PLL2R (RCC_CDCCIPR_OCTOSPISEL_1)
#define LL_RCC_OSPI_CLKSOURCE_CLKP                                             \
  (RCC_CDCCIPR_OCTOSPISEL_0 | RCC_CDCCIPR_OCTOSPISEL_1)
#endif /* RCC_D1CCIPR_OCTOSPISEL */
/**
 * @}
 */
#endif /* defined(OCTOSPI1) || defined(OCTOSPI2) */

/** @defgroup RCC_LL_EC_CLKP_CLKSOURCE  Peripheral CLKP clock source selection
 * @{
 */
#if defined(RCC_D1CCIPR_CKPERSEL)
#define LL_RCC_CLKP_CLKSOURCE_HSI (0x00000000U)
#define LL_RCC_CLKP_CLKSOURCE_CSI (RCC_D1CCIPR_CKPERSEL_0)
#define LL_RCC_CLKP_CLKSOURCE_HSE (RCC_D1CCIPR_CKPERSEL_1)
#else
#define LL_RCC_CLKP_CLKSOURCE_HSI (0x00000000U)
#define LL_RCC_CLKP_CLKSOURCE_CSI (RCC_CDCCIPR_CKPERSEL_0)
#define LL_RCC_CLKP_CLKSOURCE_HSE (RCC_CDCCIPR_CKPERSEL_1)
#endif /* RCC_D1CCIPR_CKPERSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SPIx_CLKSOURCE  Peripheral SPI clock source selection
 * @{
 */
#if defined(RCC_D2CCIP1R_SPI123SEL)
#define LL_RCC_SPI123_CLKSOURCE_PLL1Q                                          \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI123SEL, RCC_D2CCIP1R_SPI123SEL_Pos,    \
               0x00000000U)
#define LL_RCC_SPI123_CLKSOURCE_PLL2P                                          \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI123SEL, RCC_D2CCIP1R_SPI123SEL_Pos,    \
               RCC_D2CCIP1R_SPI123SEL_0)
#define LL_RCC_SPI123_CLKSOURCE_PLL3P                                          \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI123SEL, RCC_D2CCIP1R_SPI123SEL_Pos,    \
               RCC_D2CCIP1R_SPI123SEL_1)
#define LL_RCC_SPI123_CLKSOURCE_I2S_CKIN                                       \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI123SEL, RCC_D2CCIP1R_SPI123SEL_Pos,    \
               RCC_D2CCIP1R_SPI123SEL_0 | RCC_D2CCIP1R_SPI123SEL_1)
#define LL_RCC_SPI123_CLKSOURCE_CLKP                                           \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI123SEL, RCC_D2CCIP1R_SPI123SEL_Pos,    \
               RCC_D2CCIP1R_SPI123SEL_2)
#else
#define LL_RCC_SPI123_CLKSOURCE_PLL1Q                                          \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI123SEL, RCC_CDCCIP1R_SPI123SEL_Pos,    \
               0x00000000U)
#define LL_RCC_SPI123_CLKSOURCE_PLL2P                                          \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI123SEL, RCC_CDCCIP1R_SPI123SEL_Pos,    \
               RCC_CDCCIP1R_SPI123SEL_0)
#define LL_RCC_SPI123_CLKSOURCE_PLL3P                                          \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI123SEL, RCC_CDCCIP1R_SPI123SEL_Pos,    \
               RCC_CDCCIP1R_SPI123SEL_1)
#define LL_RCC_SPI123_CLKSOURCE_I2S_CKIN                                       \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI123SEL, RCC_CDCCIP1R_SPI123SEL_Pos,    \
               RCC_CDCCIP1R_SPI123SEL_0 | RCC_CDCCIP1R_SPI123SEL_1)
#define LL_RCC_SPI123_CLKSOURCE_CLKP                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI123SEL, RCC_CDCCIP1R_SPI123SEL_Pos,    \
               RCC_CDCCIP1R_SPI123SEL_2)
#endif /* RCC_D2CCIP1R_SPI123SEL */
#if defined(RCC_D2CCIP1R_SPI45SEL)
#define LL_RCC_SPI45_CLKSOURCE_PCLK2                                           \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI45SEL, RCC_D2CCIP1R_SPI45SEL_Pos,      \
               0x00000000U)
#define LL_RCC_SPI45_CLKSOURCE_PLL2Q                                           \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI45SEL, RCC_D2CCIP1R_SPI45SEL_Pos,      \
               RCC_D2CCIP1R_SPI45SEL_0)
#define LL_RCC_SPI45_CLKSOURCE_PLL3Q                                           \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI45SEL, RCC_D2CCIP1R_SPI45SEL_Pos,      \
               RCC_D2CCIP1R_SPI45SEL_1)
#define LL_RCC_SPI45_CLKSOURCE_HSI                                             \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI45SEL, RCC_D2CCIP1R_SPI45SEL_Pos,      \
               RCC_D2CCIP1R_SPI45SEL_0 | RCC_D2CCIP1R_SPI45SEL_1)
#define LL_RCC_SPI45_CLKSOURCE_CSI                                             \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI45SEL, RCC_D2CCIP1R_SPI45SEL_Pos,      \
               RCC_D2CCIP1R_SPI45SEL_2)
#define LL_RCC_SPI45_CLKSOURCE_HSE                                             \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI45SEL, RCC_D2CCIP1R_SPI45SEL_Pos,      \
               RCC_D2CCIP1R_SPI45SEL_0 | RCC_D2CCIP1R_SPI45SEL_2)
#else
#define LL_RCC_SPI45_CLKSOURCE_PCLK2                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI45SEL, RCC_CDCCIP1R_SPI45SEL_Pos,      \
               0x00000000U)
#define LL_RCC_SPI45_CLKSOURCE_PLL2Q                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI45SEL, RCC_CDCCIP1R_SPI45SEL_Pos,      \
               RCC_CDCCIP1R_SPI45SEL_0)
#define LL_RCC_SPI45_CLKSOURCE_PLL3Q                                           \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI45SEL, RCC_CDCCIP1R_SPI45SEL_Pos,      \
               RCC_CDCCIP1R_SPI45SEL_1)
#define LL_RCC_SPI45_CLKSOURCE_HSI                                             \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI45SEL, RCC_CDCCIP1R_SPI45SEL_Pos,      \
               RCC_CDCCIP1R_SPI45SEL_0 | RCC_CDCCIP1R_SPI45SEL_1)
#define LL_RCC_SPI45_CLKSOURCE_CSI                                             \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI45SEL, RCC_CDCCIP1R_SPI45SEL_Pos,      \
               RCC_CDCCIP1R_SPI45SEL_2)
#define LL_RCC_SPI45_CLKSOURCE_HSE                                             \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI45SEL, RCC_CDCCIP1R_SPI45SEL_Pos,      \
               RCC_CDCCIP1R_SPI45SEL_0 | RCC_CDCCIP1R_SPI45SEL_2)
#endif /* (RCC_D2CCIP1R_SPI45SEL */
#if defined(RCC_D3CCIPR_SPI6SEL)
#define LL_RCC_SPI6_CLKSOURCE_PCLK4                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SPI6SEL, RCC_D3CCIPR_SPI6SEL_Pos,           \
               0x00000000U)
#define LL_RCC_SPI6_CLKSOURCE_PLL2Q                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SPI6SEL, RCC_D3CCIPR_SPI6SEL_Pos,           \
               RCC_D3CCIPR_SPI6SEL_0)
#define LL_RCC_SPI6_CLKSOURCE_PLL3Q                                            \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SPI6SEL, RCC_D3CCIPR_SPI6SEL_Pos,           \
               RCC_D3CCIPR_SPI6SEL_1)
#define LL_RCC_SPI6_CLKSOURCE_HSI                                              \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SPI6SEL, RCC_D3CCIPR_SPI6SEL_Pos,           \
               RCC_D3CCIPR_SPI6SEL_0 | RCC_D3CCIPR_SPI6SEL_1)
#define LL_RCC_SPI6_CLKSOURCE_CSI                                              \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SPI6SEL, RCC_D3CCIPR_SPI6SEL_Pos,           \
               RCC_D3CCIPR_SPI6SEL_2)
#define LL_RCC_SPI6_CLKSOURCE_HSE                                              \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SPI6SEL, RCC_D3CCIPR_SPI6SEL_Pos,           \
               RCC_D3CCIPR_SPI6SEL_0 | RCC_D3CCIPR_SPI6SEL_2)
#else
#define LL_RCC_SPI6_CLKSOURCE_PCLK4                                            \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_SPI6SEL, RCC_SRDCCIPR_SPI6SEL_Pos,        \
               0x00000000U)
#define LL_RCC_SPI6_CLKSOURCE_PLL2Q                                            \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_SPI6SEL, RCC_SRDCCIPR_SPI6SEL_Pos,        \
               RCC_SRDCCIPR_SPI6SEL_0)
#define LL_RCC_SPI6_CLKSOURCE_PLL3Q                                            \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_SPI6SEL, RCC_SRDCCIPR_SPI6SEL_Pos,        \
               RCC_SRDCCIPR_SPI6SEL_1)
#define LL_RCC_SPI6_CLKSOURCE_HSI                                              \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_SPI6SEL, RCC_SRDCCIPR_SPI6SEL_Pos,        \
               RCC_SRDCCIPR_SPI6SEL_0 | RCC_SRDCCIPR_SPI6SEL_1)
#define LL_RCC_SPI6_CLKSOURCE_CSI                                              \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_SPI6SEL, RCC_SRDCCIPR_SPI6SEL_Pos,        \
               RCC_SRDCCIPR_SPI6SEL_2)
#define LL_RCC_SPI6_CLKSOURCE_HSE                                              \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_SPI6SEL, RCC_SRDCCIPR_SPI6SEL_Pos,        \
               RCC_SRDCCIPR_SPI6SEL_0 | RCC_SRDCCIPR_SPI6SEL_2)
#define LL_RCC_SPI6_CLKSOURCE_I2S_CKIN                                         \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_SPI6SEL, RCC_SRDCCIPR_SPI6SEL_Pos,        \
               RCC_SRDCCIPR_SPI6SEL_1 | RCC_SRDCCIPR_SPI6SEL_2)
#endif /* RCC_D3CCIPR_SPI6SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SPDIF_CLKSOURCE  Peripheral SPDIF clock source selection
 * @{
 */
#if defined(RCC_D2CCIP1R_SPDIFSEL)
#define LL_RCC_SPDIF_CLKSOURCE_PLL1Q (0x00000000U)
#define LL_RCC_SPDIF_CLKSOURCE_PLL2R (RCC_D2CCIP1R_SPDIFSEL_0)
#define LL_RCC_SPDIF_CLKSOURCE_PLL3R (RCC_D2CCIP1R_SPDIFSEL_1)
#define LL_RCC_SPDIF_CLKSOURCE_HSI                                             \
  (RCC_D2CCIP1R_SPDIFSEL_0 | RCC_D2CCIP1R_SPDIFSEL_1)
#else
#define LL_RCC_SPDIF_CLKSOURCE_PLL1Q (0x00000000U)
#define LL_RCC_SPDIF_CLKSOURCE_PLL2R (RCC_CDCCIP1R_SPDIFSEL_0)
#define LL_RCC_SPDIF_CLKSOURCE_PLL3R (RCC_CDCCIP1R_SPDIFSEL_1)
#define LL_RCC_SPDIF_CLKSOURCE_HSI                                             \
  (RCC_CDCCIP1R_SPDIFSEL_0 | RCC_CDCCIP1R_SPDIFSEL_1)
#endif /* RCC_D2CCIP1R_SPDIFSEL */
/**
 * @}
 */

#if defined(FDCAN1) || defined(FDCAN2)
/** @defgroup RCC_LL_EC_FDCAN_CLKSOURCE  Peripheral FDCAN clock source selection
 * @{
 */
#if defined(RCC_D2CCIP1R_FDCANSEL)
#define LL_RCC_FDCAN_CLKSOURCE_HSE (0x00000000U)
#define LL_RCC_FDCAN_CLKSOURCE_PLL1Q (RCC_D2CCIP1R_FDCANSEL_0)
#define LL_RCC_FDCAN_CLKSOURCE_PLL2Q (RCC_D2CCIP1R_FDCANSEL_1)
#else
#define LL_RCC_FDCAN_CLKSOURCE_HSE (0x00000000U)
#define LL_RCC_FDCAN_CLKSOURCE_PLL1Q (RCC_CDCCIP1R_FDCANSEL_0)
#define LL_RCC_FDCAN_CLKSOURCE_PLL2Q (RCC_CDCCIP1R_FDCANSEL_1)
#endif /* RCC_D2CCIP1R_FDCANSEL */
/**
 * @}
 */
#endif /*FDCAN1 || FDCAN2*/

/** @defgroup RCC_LL_EC_SWP_CLKSOURCE  Peripheral SWP clock source selection
 * @{
 */
#if defined(RCC_D2CCIP1R_SWPSEL)
#define LL_RCC_SWP_CLKSOURCE_PCLK1 (0x00000000U)
#define LL_RCC_SWP_CLKSOURCE_HSI (RCC_D2CCIP1R_SWPSEL)
#else
#define LL_RCC_SWP_CLKSOURCE_PCLK1 (0x00000000U)
#define LL_RCC_SWP_CLKSOURCE_HSI (RCC_CDCCIP1R_SWPSEL)
#endif /* RCC_D2CCIP1R_SWPSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_ADC_CLKSOURCE  Peripheral ADC clock source selection
 * @{
 */
#if defined(RCC_D3CCIPR_ADCSEL)
#define LL_RCC_ADC_CLKSOURCE_PLL2P (0x00000000U)
#define LL_RCC_ADC_CLKSOURCE_PLL3R (RCC_D3CCIPR_ADCSEL_0)
#define LL_RCC_ADC_CLKSOURCE_CLKP (RCC_D3CCIPR_ADCSEL_1)
#else
#define LL_RCC_ADC_CLKSOURCE_PLL2P (0x00000000U)
#define LL_RCC_ADC_CLKSOURCE_PLL3R (RCC_SRDCCIPR_ADCSEL_0)
#define LL_RCC_ADC_CLKSOURCE_CLKP (RCC_SRDCCIPR_ADCSEL_1)
#endif /* RCC_D3CCIPR_ADCSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_USARTx  Peripheral USART get clock source
 * @{
 */
#if defined(RCC_D2CCIP2R_USART16SEL)
#define LL_RCC_USART16_CLKSOURCE                                               \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16SEL, RCC_D2CCIP2R_USART16SEL_Pos,  \
               0x00000000U)
#elif defined(RCC_D2CCIP2R_USART16910SEL)
#define LL_RCC_USART16_CLKSOURCE                                               \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART16910SEL,                            \
               RCC_D2CCIP2R_USART16910SEL_Pos, 0x00000000U)
/* alias*/
#define LL_RCC_USART16910_CLKSOURCE LL_RCC_USART16_CLKSOURCE
#else
#define LL_RCC_USART16_CLKSOURCE                                               \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART16910SEL,                            \
               RCC_CDCCIP2R_USART16910SEL_Pos, 0x00000000U)
/* alias*/
#define LL_RCC_USART16910_CLKSOURCE LL_RCC_USART16_CLKSOURCE
#endif /* RCC_D2CCIP2R_USART16SEL */
#if defined(RCC_D2CCIP2R_USART28SEL)
#define LL_RCC_USART234578_CLKSOURCE                                           \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_USART28SEL, RCC_D2CCIP2R_USART28SEL_Pos,  \
               0x00000000U)
#else
#define LL_RCC_USART234578_CLKSOURCE                                           \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_USART234578SEL,                           \
               RCC_CDCCIP2R_USART234578SEL_Pos, 0x00000000U)
#endif /* RCC_D2CCIP2R_USART28SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_LPUARTx  Peripheral LPUART get clock source
 * @{
 */
#if defined(RCC_D3CCIPR_LPUART1SEL)
#define LL_RCC_LPUART1_CLKSOURCE RCC_D3CCIPR_LPUART1SEL
#else
#define LL_RCC_LPUART1_CLKSOURCE RCC_SRDCCIPR_LPUART1SEL
#endif /* RCC_D3CCIPR_LPUART1SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_I2Cx  Peripheral I2C get clock source
 * @{
 */
#if defined(RCC_D2CCIP2R_I2C123SEL)
#define LL_RCC_I2C123_CLKSOURCE                                                \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C123SEL, RCC_D2CCIP2R_I2C123SEL_Pos,    \
               0x00000000U)
/* alias */
#define LL_RCC_I2C1235_CLKSOURCE LL_RCC_I2C123_CLKSOURCE
#elif defined(RCC_D2CCIP2R_I2C1235SEL)
#define LL_RCC_I2C1235_CLKSOURCE                                               \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_I2C1235SEL, RCC_D2CCIP2R_I2C1235SEL_Pos,  \
               0x00000000U)
/* alias */
#define LL_RCC_I2C123_CLKSOURCE LL_RCC_I2C1235_CLKSOURCE
#else
#define LL_RCC_I2C123_CLKSOURCE                                                \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_I2C123SEL, RCC_CDCCIP2R_I2C123SEL_Pos,    \
               0x00000000U)
/* alias */
#define LL_RCC_I2C1235_CLKSOURCE LL_RCC_I2C123_CLKSOURCE
#endif /* RCC_D2CCIP2R_I2C123SEL */
#if defined(RCC_D3CCIPR_I2C4SEL)
#define LL_RCC_I2C4_CLKSOURCE                                                  \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_I2C4SEL, RCC_D3CCIPR_I2C4SEL_Pos,           \
               0x00000000U)
#else
#define LL_RCC_I2C4_CLKSOURCE                                                  \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_I2C4SEL, RCC_SRDCCIPR_I2C4SEL_Pos,        \
               0x00000000U)
#endif /* RCC_D3CCIPR_I2C4SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_LPTIMx  Peripheral LPTIM get clock source
 * @{
 */
#if defined(RCC_D2CCIP2R_LPTIM1SEL)
#define LL_RCC_LPTIM1_CLKSOURCE                                                \
  LL_CLKSOURCE(D2CCIP2, RCC_D2CCIP2R_LPTIM1SEL, RCC_D2CCIP2R_LPTIM1SEL_Pos,    \
               0x00000000U)
#else
#define LL_RCC_LPTIM1_CLKSOURCE                                                \
  LL_CLKSOURCE(CDCCIP2, RCC_CDCCIP2R_LPTIM1SEL, RCC_CDCCIP2R_LPTIM1SEL_Pos,    \
               0x00000000U)
#endif /* RCC_D2CCIP2R_LPTIM1SEL) */
#if defined(RCC_D3CCIPR_LPTIM2SEL)
#define LL_RCC_LPTIM2_CLKSOURCE                                                \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM2SEL, RCC_D3CCIPR_LPTIM2SEL_Pos,       \
               0x00000000U)
#else
#define LL_RCC_LPTIM2_CLKSOURCE                                                \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM2SEL, RCC_SRDCCIPR_LPTIM2SEL_Pos,    \
               0x00000000U)
#endif /* RCC_D3CCIPR_LPTIM2SEL */
#if defined(RCC_D3CCIPR_LPTIM345SEL)
#define LL_RCC_LPTIM345_CLKSOURCE                                              \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_LPTIM345SEL, RCC_D3CCIPR_LPTIM345SEL_Pos,   \
               0x00000000U)
#else
#define LL_RCC_LPTIM345_CLKSOURCE                                              \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_LPTIM3SEL, RCC_SRDCCIPR_LPTIM3SEL_Pos,    \
               0x00000000U)
#define LL_RCC_LPTIM3_CLKSOURCE LL_RCC_LPTIM345_CLKSOURCE /* alias */
#endif /* RCC_D3CCIPR_LPTIM345SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SAIx  Peripheral SAI get clock source
 * @{
 */
#if defined(RCC_D2CCIP1R_SAI1SEL)
#define LL_RCC_SAI1_CLKSOURCE                                                  \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI1SEL, RCC_D2CCIP1R_SAI1SEL_Pos,        \
               0x00000000U)
#else
#define LL_RCC_SAI1_CLKSOURCE                                                  \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI1SEL, RCC_CDCCIP1R_SAI1SEL_Pos,        \
               0x00000000U)
#endif /* RCC_D2CCIP1R_SAI1SEL */
#if defined(RCC_D2CCIP1R_SAI23SEL)
#define LL_RCC_SAI23_CLKSOURCE                                                 \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SAI23SEL, RCC_D2CCIP1R_SAI23SEL_Pos,      \
               0x00000000U)
#endif /* RCC_D2CCIP1R_SAI23SEL */
#if defined(RCC_CDCCIP1R_SAI2ASEL)
#define LL_RCC_SAI2A_CLKSOURCE                                                 \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2ASEL, RCC_CDCCIP1R_SAI2ASEL_Pos,      \
               0x00000000U)
#endif /* RCC_CDCCIP1R_SAI2ASEL */
#if defined(RCC_CDCCIP1R_SAI2BSEL)
#define LL_RCC_SAI2B_CLKSOURCE                                                 \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SAI2BSEL, RCC_CDCCIP1R_SAI2BSEL_Pos,      \
               0x00000000U)
#endif /*  RCC_CDCCIP1R_SAI2BSEL */
#if defined(RCC_D3CCIPR_SAI4ASEL)
#define LL_RCC_SAI4A_CLKSOURCE                                                 \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4ASEL, RCC_D3CCIPR_SAI4ASEL_Pos,         \
               0x00000000U)
#endif /* RCC_D3CCIPR_SAI4ASEL */
#if defined(RCC_D3CCIPR_SAI4BSEL)
#define LL_RCC_SAI4B_CLKSOURCE                                                 \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SAI4BSEL, RCC_D3CCIPR_SAI4BSEL_Pos,         \
               0x00000000U)
#endif /*  RCC_D3CCIPR_SAI4BSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SDMMC  Peripheral SDMMC get clock source
 * @{
 */
#if defined(RCC_D1CCIPR_SDMMCSEL)
#define LL_RCC_SDMMC_CLKSOURCE RCC_D1CCIPR_SDMMCSEL
#else
#define LL_RCC_SDMMC_CLKSOURCE RCC_CDCCIPR_SDMMCSEL
#endif /* RCC_D1CCIPR_SDMMCSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_RNG Peripheral RNG get clock source
 * @{
 */
#if (RCC_D2CCIP2R_RNGSEL)
#define LL_RCC_RNG_CLKSOURCE RCC_D2CCIP2R_RNGSEL
#else
#define LL_RCC_RNG_CLKSOURCE RCC_CDCCIP2R_RNGSEL
#endif /* RCC_D2CCIP2R_RNGSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_USB  Peripheral USB get clock source
 * @{
 */
#if (RCC_D2CCIP2R_USBSEL)
#define LL_RCC_USB_CLKSOURCE RCC_D2CCIP2R_USBSEL
#else
#define LL_RCC_USB_CLKSOURCE RCC_CDCCIP2R_USBSEL
#endif /* RCC_D2CCIP2R_USBSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_CEC  Peripheral CEC get clock source
 * @{
 */
#if (RCC_D2CCIP2R_CECSEL)
#define LL_RCC_CEC_CLKSOURCE RCC_D2CCIP2R_CECSEL
#else
#define LL_RCC_CEC_CLKSOURCE RCC_CDCCIP2R_CECSEL
#endif /* RCC_D2CCIP2R_CECSEL */
/**
 * @}
 */

#if defined(DSI)
/** @defgroup RCC_LL_EC_DSI  Peripheral DSI get clock source
 * @{
 */
#define LL_RCC_DSI_CLKSOURCE RCC_D1CCIPR_DSISEL
/**
 * @}
 */
#endif /* DSI */

/** @defgroup RCC_LL_EC_DFSDM  Peripheral DFSDM get clock source
 * @{
 */
#if defined(RCC_D2CCIP1R_DFSDM1SEL)
#define LL_RCC_DFSDM1_CLKSOURCE RCC_D2CCIP1R_DFSDM1SEL
#else
#define LL_RCC_DFSDM1_CLKSOURCE RCC_CDCCIP1R_DFSDM1SEL
#endif /* RCC_D2CCIP1R_DFSDM1SEL */
/**
 * @}
 */

#if defined(DFSDM2_BASE)
/** @defgroup RCC_LL_EC_DFSDM2  Peripheral DFSDM2 get clock source
 * @{
 */
#define LL_RCC_DFSDM2_CLKSOURCE RCC_SRDCCIPR_DFSDM2SEL
/**
 * @}
 */
#endif /* DFSDM2_BASE */

/** @defgroup RCC_LL_EC_FMC  Peripheral FMC get clock source
 * @{
 */
#if defined(RCC_D1CCIPR_FMCSEL)
#define LL_RCC_FMC_CLKSOURCE RCC_D1CCIPR_FMCSEL
#else
#define LL_RCC_FMC_CLKSOURCE RCC_CDCCIPR_FMCSEL
#endif
/**
 * @}
 */

#if defined(QUADSPI)
/** @defgroup RCC_LL_EC_QSPI  Peripheral QSPI get clock source
 * @{
 */
#define LL_RCC_QSPI_CLKSOURCE RCC_D1CCIPR_QSPISEL
/**
 * @}
 */
#endif /* QUADSPI */

#if defined(OCTOSPI1) || defined(OCTOSPI2)
/** @defgroup RCC_LL_EC_OSPI Peripheral OSPI get clock source
 * @{
 */
#if defined(RCC_CDCCIPR_OCTOSPISEL)
#define LL_RCC_OSPI_CLKSOURCE RCC_CDCCIPR_OCTOSPISEL
#else
#define LL_RCC_OSPI_CLKSOURCE RCC_D1CCIPR_OCTOSPISEL
#endif /* RCC_CDCCIPR_OCTOSPISEL */
/**
 * @}
 */
#endif /* OCTOSPI1 || OCTOSPI2 */

/** @defgroup RCC_LL_EC_CLKP Peripheral CLKP get clock source
 * @{
 */
#if defined(RCC_D1CCIPR_CKPERSEL)
#define LL_RCC_CLKP_CLKSOURCE RCC_D1CCIPR_CKPERSEL
#else
#define LL_RCC_CLKP_CLKSOURCE RCC_CDCCIPR_CKPERSEL
#endif /* RCC_D1CCIPR_CKPERSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SPIx  Peripheral SPI get clock source
 * @{
 */
#if defined(RCC_D2CCIP1R_SPI123SEL)
#define LL_RCC_SPI123_CLKSOURCE                                                \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI123SEL, RCC_D2CCIP1R_SPI123SEL_Pos,    \
               0x00000000U)
#else
#define LL_RCC_SPI123_CLKSOURCE                                                \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI123SEL, RCC_CDCCIP1R_SPI123SEL_Pos,    \
               0x00000000U)
#endif /* RCC_D2CCIP1R_SPI123SEL */
#if defined(RCC_D2CCIP1R_SPI45SEL)
#define LL_RCC_SPI45_CLKSOURCE                                                 \
  LL_CLKSOURCE(D2CCIP1, RCC_D2CCIP1R_SPI45SEL, RCC_D2CCIP1R_SPI45SEL_Pos,      \
               0x00000000U)
#else
#define LL_RCC_SPI45_CLKSOURCE                                                 \
  LL_CLKSOURCE(CDCCIP1, RCC_CDCCIP1R_SPI45SEL, RCC_CDCCIP1R_SPI45SEL_Pos,      \
               0x00000000U)
#endif /* RCC_D2CCIP1R_SPI45SEL */
#if defined(RCC_D3CCIPR_SPI6SEL)
#define LL_RCC_SPI6_CLKSOURCE                                                  \
  LL_CLKSOURCE(D3CCIP, RCC_D3CCIPR_SPI6SEL, RCC_D3CCIPR_SPI6SEL_Pos,           \
               0x00000000U)
#else
#define LL_RCC_SPI6_CLKSOURCE                                                  \
  LL_CLKSOURCE(SRDCCIP, RCC_SRDCCIPR_SPI6SEL, RCC_SRDCCIPR_SPI6SEL_Pos,        \
               0x00000000U)
#endif /* RCC_D3CCIPR_SPI6SEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_SPDIF  Peripheral SPDIF get clock source
 * @{
 */
#if defined(RCC_D2CCIP1R_SPDIFSEL)
#define LL_RCC_SPDIF_CLKSOURCE RCC_D2CCIP1R_SPDIFSEL
#else
#define LL_RCC_SPDIF_CLKSOURCE RCC_CDCCIP1R_SPDIFSEL
#endif /* RCC_D2CCIP1R_SPDIFSEL */
/**
 * @}
 */

#if defined(FDCAN1) || defined(FDCAN2)
/** @defgroup RCC_LL_EC_FDCAN  Peripheral FDCAN get clock source
 * @{
 */
#if defined(RCC_D2CCIP1R_FDCANSEL)
#define LL_RCC_FDCAN_CLKSOURCE RCC_D2CCIP1R_FDCANSEL
#else
#define LL_RCC_FDCAN_CLKSOURCE RCC_CDCCIP1R_FDCANSEL
#endif
/**
 * @}
 */
#endif /*FDCAN1 || FDCAN2*/

/** @defgroup RCC_LL_EC_SWP  Peripheral SWP get clock source
 * @{
 */
#if defined(RCC_D2CCIP1R_SWPSEL)
#define LL_RCC_SWP_CLKSOURCE RCC_D2CCIP1R_SWPSEL
#else
#define LL_RCC_SWP_CLKSOURCE RCC_CDCCIP1R_SWPSEL
#endif /* RCC_D2CCIP1R_SWPSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_ADC  Peripheral ADC get clock source
 * @{
 */
#if defined(RCC_D3CCIPR_ADCSEL)
#define LL_RCC_ADC_CLKSOURCE RCC_D3CCIPR_ADCSEL
#else
#define LL_RCC_ADC_CLKSOURCE RCC_SRDCCIPR_ADCSEL
#endif /* RCC_D3CCIPR_ADCSEL */
/**
 * @}
 */

/** @defgroup RCC_LL_EC_RTC_CLKSOURCE  RTC clock source selection
 * @{
 */
#define LL_RCC_RTC_CLKSOURCE_NONE (uint32_t)(0x00000000U)
#define LL_RCC_RTC_CLKSOURCE_LSE (uint32_t)(RCC_BDCR_RTCSEL_0)
#define LL_RCC_RTC_CLKSOURCE_LSI (uint32_t)(RCC_BDCR_RTCSEL_1)
#define LL_RCC_RTC_CLKSOURCE_HSE                                               \
  (uint32_t)(RCC_BDCR_RTCSEL_0 | RCC_BDCR_RTCSEL_1)
/**
 * @}
 */

/** @defgroup RCC_LL_EC_TIM_CLKPRESCALER  Timers clocks prescalers selection
 * @{
 */
#define LL_RCC_TIM_PRESCALER_TWICE (uint32_t)(0x00000000U)
#define LL_RCC_TIM_PRESCALER_FOUR_TIMES (uint32_t)(RCC_CFGR_TIMPRE)
/**
 * @}
 */

#if defined(HRTIM1)
/** @defgroup RCC_LL_EC_HRTIM_CLKSOURCE  High Resolution Timers clock selection
 * @{
 */
#define LL_RCC_HRTIM_CLKSOURCE_TIM                                             \
  (uint32_t)(0x00000000U) /* HRTIM Clock source is same as other timers */
#define LL_RCC_HRTIM_CLKSOURCE_CPU                                             \
  (uint32_t)(RCC_CFGR_HRTIMSEL) /* HRTIM Clock source is the CPU clock */
/**
 * @}
 */
#endif /* HRTIM1 */

/** @defgroup RCC_LL_EC_PLLSOURCE   All PLLs entry clock source
 * @{
 */
#define LL_RCC_PLLSOURCE_HSI RCC_PLLCKSELR_PLLSRC_HSI
#define LL_RCC_PLLSOURCE_CSI RCC_PLLCKSELR_PLLSRC_CSI
#define LL_RCC_PLLSOURCE_HSE RCC_PLLCKSELR_PLLSRC_HSE
#define LL_RCC_PLLSOURCE_NONE RCC_PLLCKSELR_PLLSRC_NONE
/**
 * @}
 */

/** @defgroup RCC_LL_EC_PLLINPUTRANGE   All PLLs input range
 * @{
 */
#define LL_RCC_PLLINPUTRANGE_1_2 (uint32_t)(0x00000000U)
#define LL_RCC_PLLINPUTRANGE_2_4 (uint32_t)(0x00000001)
#define LL_RCC_PLLINPUTRANGE_4_8 (uint32_t)(0x00000002)
#define LL_RCC_PLLINPUTRANGE_8_16 (uint32_t)(0x00000003)
/**
 * @}
 */

/** @defgroup RCC_LL_EC_PLLVCORANGE   All PLLs VCO range
 * @{
 */
#define LL_RCC_PLLVCORANGE_WIDE                                                \
  (uint32_t)(0x00000000U) /* VCO output range: 192 to 836 MHz   OR  128 to 544 \
                             MHz (*) */
#define LL_RCC_PLLVCORANGE_MEDIUM                                              \
  (uint32_t)(0x00000001) /* VCO output range: 150 to 420 MHz */
/**
 * (*) : For stm32h7a3xx and stm32h7b3xx family lines.
 * @}
 */

/**
 * @}
 */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Macros RCC Exported Macros
 * @{
 */

/** @defgroup RCC_LL_EM_WRITE_READ Common Write and read registers Macros
 * @{
 */

/**
 * @brief  Write a value in RCC register
 * @param  __REG__ Register to be written
 * @param  __VALUE__ Value to be written in the register
 * @retval None
 */
#define LL_RCC_WriteReg(__REG__, __VALUE__) WRITE_REG(RCC->__REG__, (__VALUE__))

/**
 * @brief  Read a value in RCC register
 * @param  __REG__ Register to be read
 * @retval Register value
 */
#define LL_RCC_ReadReg(__REG__) READ_REG(RCC->__REG__)
/**
 * @}
 */

/** @defgroup RCC_LL_EM_CALC_FREQ Calculate frequencies
 * @{
 */

/**
 * @brief  Helper macro to calculate the SYSCLK frequency
 * @param  __SYSINPUTCLKFREQ__ Frequency of the input of sys_ck (based on
 * HSE/CSI/HSI/PLL1P)
 * @param  __SYSPRESCALER__ This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SYSCLK_DIV_1
 *         @arg @ref LL_RCC_SYSCLK_DIV_2
 *         @arg @ref LL_RCC_SYSCLK_DIV_4
 *         @arg @ref LL_RCC_SYSCLK_DIV_8
 *         @arg @ref LL_RCC_SYSCLK_DIV_16
 *         @arg @ref LL_RCC_SYSCLK_DIV_64
 *         @arg @ref LL_RCC_SYSCLK_DIV_128
 *         @arg @ref LL_RCC_SYSCLK_DIV_256
 *         @arg @ref LL_RCC_SYSCLK_DIV_512
 * @retval SYSCLK clock frequency (in Hz)
 */
#if defined(RCC_D1CFGR_D1CPRE)
#define LL_RCC_CALC_SYSCLK_FREQ(__SYSINPUTCLKFREQ__, __SYSPRESCALER__)         \
  ((__SYSINPUTCLKFREQ__) >>                                                    \
   ((LL_RCC_PrescTable[((__SYSPRESCALER__) & RCC_D1CFGR_D1CPRE) >>             \
                       RCC_D1CFGR_D1CPRE_Pos]) &                               \
    0x1FU))
#else
#define LL_RCC_CALC_SYSCLK_FREQ(__SYSINPUTCLKFREQ__, __SYSPRESCALER__)         \
  ((__SYSINPUTCLKFREQ__) >>                                                    \
   ((LL_RCC_PrescTable[((__SYSPRESCALER__) & RCC_CDCFGR1_CDCPRE) >>            \
                       RCC_CDCFGR1_CDCPRE_Pos]) &                              \
    0x1FU))
#endif /* RCC_D1CFGR_D1CPRE */

/**
 * @brief  Helper macro to calculate the HCLK frequency
 * @param  __SYSCLKFREQ__ SYSCLK frequency.
 * @param  __HPRESCALER__ This parameter can be one of the following values:
 *         @arg @ref LL_RCC_AHB_DIV_1
 *         @arg @ref LL_RCC_AHB_DIV_2
 *         @arg @ref LL_RCC_AHB_DIV_4
 *         @arg @ref LL_RCC_AHB_DIV_8
 *         @arg @ref LL_RCC_AHB_DIV_16
 *         @arg @ref LL_RCC_AHB_DIV_64
 *         @arg @ref LL_RCC_AHB_DIV_128
 *         @arg @ref LL_RCC_AHB_DIV_256
 *         @arg @ref LL_RCC_AHB_DIV_512
 * @retval HCLK clock frequency (in Hz)
 */
#if defined(RCC_D1CFGR_HPRE)
#define LL_RCC_CALC_HCLK_FREQ(__SYSCLKFREQ__, __HPRESCALER__)                  \
  ((__SYSCLKFREQ__) >>                                                         \
   ((LL_RCC_PrescTable[((__HPRESCALER__) & RCC_D1CFGR_HPRE) >>                 \
                       RCC_D1CFGR_HPRE_Pos]) &                                 \
    0x1FU))
#else
#define LL_RCC_CALC_HCLK_FREQ(__SYSCLKFREQ__, __HPRESCALER__)                  \
  ((__SYSCLKFREQ__) >>                                                         \
   ((LL_RCC_PrescTable[((__HPRESCALER__) & RCC_CDCFGR1_HPRE) >>                \
                       RCC_CDCFGR1_HPRE_Pos]) &                                \
    0x1FU))
#endif /* RCC_D1CFGR_HPRE */

/**
 * @brief  Helper macro to calculate the PCLK1 frequency (ABP1)
 * @param  __HCLKFREQ__ HCLK frequency
 * @param  __APB1PRESCALER__ This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB1_DIV_1
 *         @arg @ref LL_RCC_APB1_DIV_2
 *         @arg @ref LL_RCC_APB1_DIV_4
 *         @arg @ref LL_RCC_APB1_DIV_8
 *         @arg @ref LL_RCC_APB1_DIV_16
 * @retval PCLK1 clock frequency (in Hz)
 */
#if defined(RCC_D2CFGR_D2PPRE1)
#define LL_RCC_CALC_PCLK1_FREQ(__HCLKFREQ__, __APB1PRESCALER__)                \
  ((__HCLKFREQ__) >>                                                           \
   ((LL_RCC_PrescTable[((__APB1PRESCALER__) & RCC_D2CFGR_D2PPRE1) >>           \
                       RCC_D2CFGR_D2PPRE1_Pos]) &                              \
    0x1FU))
#else
#define LL_RCC_CALC_PCLK1_FREQ(__HCLKFREQ__, __APB1PRESCALER__)                \
  ((__HCLKFREQ__) >>                                                           \
   ((LL_RCC_PrescTable[((__APB1PRESCALER__) & RCC_CDCFGR2_CDPPRE1) >>          \
                       RCC_CDCFGR2_CDPPRE1_Pos]) &                             \
    0x1FU))
#endif /* RCC_D2CFGR_D2PPRE1 */

/**
 * @brief  Helper macro to calculate the PCLK2 frequency (ABP2)
 * @param  __HCLKFREQ__ HCLK frequency
 * @param  __APB2PRESCALER__ This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB2_DIV_1
 *         @arg @ref LL_RCC_APB2_DIV_2
 *         @arg @ref LL_RCC_APB2_DIV_4
 *         @arg @ref LL_RCC_APB2_DIV_8
 *         @arg @ref LL_RCC_APB2_DIV_16
 * @retval PCLK2 clock frequency (in Hz)
 */
#if defined(RCC_D2CFGR_D2PPRE2)
#define LL_RCC_CALC_PCLK2_FREQ(__HCLKFREQ__, __APB2PRESCALER__)                \
  ((__HCLKFREQ__) >>                                                           \
   ((LL_RCC_PrescTable[((__APB2PRESCALER__) & RCC_D2CFGR_D2PPRE2) >>           \
                       RCC_D2CFGR_D2PPRE2_Pos]) &                              \
    0x1FU))
#else
#define LL_RCC_CALC_PCLK2_FREQ(__HCLKFREQ__, __APB2PRESCALER__)                \
  ((__HCLKFREQ__) >>                                                           \
   ((LL_RCC_PrescTable[((__APB2PRESCALER__) & RCC_CDCFGR2_CDPPRE2) >>          \
                       RCC_CDCFGR2_CDPPRE2_Pos]) &                             \
    0x1FU))
#endif /* RCC_D2CFGR_D2PPRE2 */

/**
 * @brief  Helper macro to calculate the PCLK3 frequency (APB3)
 * @param  __HCLKFREQ__ HCLK frequency
 * @param  __APB3PRESCALER__ This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB3_DIV_1
 *         @arg @ref LL_RCC_APB3_DIV_2
 *         @arg @ref LL_RCC_APB3_DIV_4
 *         @arg @ref LL_RCC_APB3_DIV_8
 *         @arg @ref LL_RCC_APB3_DIV_16
 * @retval PCLK1 clock frequency (in Hz)
 */
#if defined(RCC_D1CFGR_D1PPRE)
#define LL_RCC_CALC_PCLK3_FREQ(__HCLKFREQ__, __APB3PRESCALER__)                \
  ((__HCLKFREQ__) >>                                                           \
   ((LL_RCC_PrescTable[((__APB3PRESCALER__) & RCC_D1CFGR_D1PPRE) >>            \
                       RCC_D1CFGR_D1PPRE_Pos]) &                               \
    0x1FU))
#else
#define LL_RCC_CALC_PCLK3_FREQ(__HCLKFREQ__, __APB3PRESCALER__)                \
  ((__HCLKFREQ__) >>                                                           \
   ((LL_RCC_PrescTable[((__APB3PRESCALER__) & RCC_CDCFGR1_CDPPRE) >>           \
                       RCC_CDCFGR1_CDPPRE_Pos]) &                              \
    0x1FU))
#endif /* RCC_D1CFGR_D1PPRE */

/**
 * @brief  Helper macro to calculate the PCLK4 frequency (ABP4)
 * @param  __HCLKFREQ__ HCLK frequency
 * @param  __APB4PRESCALER__ This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB4_DIV_1
 *         @arg @ref LL_RCC_APB4_DIV_2
 *         @arg @ref LL_RCC_APB4_DIV_4
 *         @arg @ref LL_RCC_APB4_DIV_8
 *         @arg @ref LL_RCC_APB4_DIV_16
 * @retval PCLK1 clock frequency (in Hz)
 */
#if defined(RCC_D3CFGR_D3PPRE)
#define LL_RCC_CALC_PCLK4_FREQ(__HCLKFREQ__, __APB4PRESCALER__)                \
  ((__HCLKFREQ__) >>                                                           \
   ((LL_RCC_PrescTable[((__APB4PRESCALER__) & RCC_D3CFGR_D3PPRE) >>            \
                       RCC_D3CFGR_D3PPRE_Pos]) &                               \
    0x1FU))
#else
#define LL_RCC_CALC_PCLK4_FREQ(__HCLKFREQ__, __APB4PRESCALER__)                \
  ((__HCLKFREQ__) >>                                                           \
   ((LL_RCC_PrescTable[((__APB4PRESCALER__) & RCC_SRDCFGR_SRDPPRE) >>          \
                       RCC_SRDCFGR_SRDPPRE_Pos]) &                             \
    0x1FU))
#endif /* RCC_D3CFGR_D3PPRE */

/**
 * @}
 */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_EC_PERIPH_FREQUENCY Peripheral clock frequency
 * @{
 */
#define LL_RCC_PERIPH_FREQUENCY_NO                                             \
  0x00000000U /*!< No clock enabled for the peripheral            */
#define LL_RCC_PERIPH_FREQUENCY_NA                                             \
  0xFFFFFFFFU /*!< Frequency cannot be provided as external clock */
/**
 * @}
 */
#endif /* USE_FULL_LL_DRIVER */

/**
 * @}
 */

/* Exported functions --------------------------------------------------------*/
/** @defgroup RCC_LL_Exported_Functions RCC Exported Functions
 * @{
 */

/** @defgroup RCC_LL_EF_HSE HSE
 * @{
 */

/**
 * @brief  Enable the Clock Security System.
 * @note Once HSE Clock Security System is enabled it cannot be changed anymore
 * unless a reset occurs or system enter in standby mode.
 * @rmtoll CR           CSSHSEON         LL_RCC_HSE_EnableCSS
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSE_EnableCSS(void) {
  SET_BIT(RCC->CR, RCC_CR_CSSHSEON);
}

/**
 * @brief  Enable HSE external oscillator (HSE Bypass)
 * @rmtoll CR           HSEBYP        LL_RCC_HSE_EnableBypass
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSE_EnableBypass(void) {
  SET_BIT(RCC->CR, RCC_CR_HSEBYP);
}

/**
 * @brief  Disable HSE external oscillator (HSE Bypass)
 * @rmtoll CR           HSEBYP        LL_RCC_HSE_DisableBypass
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSE_DisableBypass(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_HSEBYP);
}

#if defined(RCC_CR_HSEEXT)
/**
 * @brief  Select the Analog HSE external clock type in Bypass mode
 * @rmtoll CR           HSEEXT        LL_RCC_HSE_SelectAnalogClock
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSE_SelectAnalogClock(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_HSEEXT);
}

/**
 * @brief  Select the Digital HSE external clock type in Bypass mode
 * @rmtoll CR           HSEEXT        LL_RCC_HSE_SelectDigitalClock
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSE_SelectDigitalClock(void) {
  SET_BIT(RCC->CR, RCC_CR_HSEEXT);
}
#endif /* RCC_CR_HSEEXT */

/**
 * @brief  Enable HSE crystal oscillator (HSE ON)
 * @rmtoll CR           HSEON         LL_RCC_HSE_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSE_Enable(void) { SET_BIT(RCC->CR, RCC_CR_HSEON); }

/**
 * @brief  Disable HSE crystal oscillator (HSE ON)
 * @rmtoll CR           HSEON         LL_RCC_HSE_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSE_Disable(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_HSEON);
}

/**
 * @brief  Check if HSE oscillator Ready
 * @rmtoll CR           HSERDY        LL_RCC_HSE_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_HSE_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_HSERDY) == (RCC_CR_HSERDY)) ? 1UL : 0UL);
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_HSI HSI
 * @{
 */

/**
 * @brief  Enable HSI oscillator
 * @rmtoll CR           HSION         LL_RCC_HSI_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSI_Enable(void) { SET_BIT(RCC->CR, RCC_CR_HSION); }

/**
 * @brief  Disable HSI oscillator
 * @rmtoll CR           HSION         LL_RCC_HSI_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSI_Disable(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_HSION);
}

/**
 * @brief  Check if HSI clock is ready
 * @rmtoll CR           HSIRDY        LL_RCC_HSI_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_HSI_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_HSIRDY) == (RCC_CR_HSIRDY)) ? 1UL : 0UL);
}

/**
 * @brief  Check if HSI new divider applied and ready
 * @rmtoll CR           HSIDIVF        LL_RCC_HSI_IsDividerReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_HSI_IsDividerReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_HSIDIVF) == (RCC_CR_HSIDIVF)) ? 1UL : 0UL);
}

/**
 * @brief  Set HSI divider
 * @rmtoll CR           HSIDIV        LL_RCC_HSI_SetDivider
 * @param  Divider This parameter can be one of the following values:
 *         @arg @ref LL_RCC_HSI_DIV1
 *         @arg @ref LL_RCC_HSI_DIV2
 *         @arg @ref LL_RCC_HSI_DIV4
 *         @arg @ref LL_RCC_HSI_DIV8
 * @retval None.
 */
__STATIC_INLINE void LL_RCC_HSI_SetDivider(uint32_t Divider) {
  MODIFY_REG(RCC->CR, RCC_CR_HSIDIV, Divider);
}

/**
 * @brief  Get HSI divider
 * @rmtoll CR           HSIDIV        LL_RCC_HSI_GetDivider
 * @retval can be one of the following values:
 *         @arg @ref LL_RCC_HSI_DIV1
 *         @arg @ref LL_RCC_HSI_DIV2
 *         @arg @ref LL_RCC_HSI_DIV4
 *         @arg @ref LL_RCC_HSI_DIV8
 */
__STATIC_INLINE uint32_t LL_RCC_HSI_GetDivider(void) {
  return (READ_BIT(RCC->CR, RCC_CR_HSIDIV));
}

/**
 * @brief  Enable HSI oscillator in Stop mode
 * @rmtoll CR           HSIKERON         LL_RCC_HSI_EnableStopMode
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSI_EnableStopMode(void) {
  SET_BIT(RCC->CR, RCC_CR_HSIKERON);
}

/**
 * @brief  Disable HSI oscillator in Stop mode
 * @rmtoll CR           HSION         LL_RCC_HSI_DisableStopMode
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSI_DisableStopMode(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_HSIKERON);
}

/**
 * @brief  Get HSI Calibration value
 * @note When HSITRIM is written, HSICAL is updated with the sum of
 *       HSITRIM and the factory trim value
 * @rmtoll HSICFGR        HSICAL        LL_RCC_HSI_GetCalibration
 * @retval A value between 0 and 4095 (0xFFF)
 */
__STATIC_INLINE uint32_t LL_RCC_HSI_GetCalibration(void) {
  return (uint32_t)(READ_BIT(RCC->HSICFGR, RCC_HSICFGR_HSICAL) >>
                    RCC_HSICFGR_HSICAL_Pos);
}

/**
 * @brief  Set HSI Calibration trimming
 * @note user-programmable trimming value that is added to the HSICAL
 * @note Default value is 64 (32 for Cut1.x), which, when added to the HSICAL
 * value, should trim the HSI to 64 MHz +/- 1 %
 * @rmtoll HSICFGR        HSITRIM       LL_RCC_HSI_SetCalibTrimming
 * @param  Value can be a value between 0 and 127 (63 for Cut1.x)
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSI_SetCalibTrimming(uint32_t Value) {
#if defined(RCC_VER_X)
  if ((DBGMCU->IDCODE & 0xF0000000U) == 0x10000000U) {
    /* STM32H7 Rev.Y */
    MODIFY_REG(RCC->HSICFGR, 0x3F000U, Value << 12U);
  } else {
    /* STM32H7 Rev.V */
    MODIFY_REG(RCC->HSICFGR, RCC_HSICFGR_HSITRIM,
               Value << RCC_HSICFGR_HSITRIM_Pos);
  }
#else
  MODIFY_REG(RCC->HSICFGR, RCC_HSICFGR_HSITRIM,
             Value << RCC_HSICFGR_HSITRIM_Pos);
#endif /* RCC_VER_X */
}

/**
 * @brief  Get HSI Calibration trimming
 * @rmtoll HSICFGR        HSITRIM       LL_RCC_HSI_GetCalibTrimming
 * @retval A value between 0 and 127 (63 for Cut1.x)
 */
__STATIC_INLINE uint32_t LL_RCC_HSI_GetCalibTrimming(void) {
#if defined(RCC_VER_X)
  if ((DBGMCU->IDCODE & 0xF0000000U) == 0x10000000U) {
    /* STM32H7 Rev.Y */
    return (uint32_t)(READ_BIT(RCC->HSICFGR, 0x3F000U) >> 12U);
  } else {
    /* STM32H7 Rev.V */
    return (uint32_t)(READ_BIT(RCC->HSICFGR, RCC_HSICFGR_HSITRIM) >>
                      RCC_HSICFGR_HSITRIM_Pos);
  }
#else
  return (uint32_t)(READ_BIT(RCC->HSICFGR, RCC_HSICFGR_HSITRIM) >>
                    RCC_HSICFGR_HSITRIM_Pos);
#endif /* RCC_VER_X */
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_CSI CSI
 * @{
 */

/**
 * @brief  Enable CSI oscillator
 * @rmtoll CR           CSION         LL_RCC_CSI_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_CSI_Enable(void) { SET_BIT(RCC->CR, RCC_CR_CSION); }

/**
 * @brief  Disable CSI oscillator
 * @rmtoll CR           CSION         LL_RCC_CSI_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_CSI_Disable(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_CSION);
}

/**
 * @brief  Check if CSI clock is ready
 * @rmtoll CR           CSIRDY        LL_RCC_CSI_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_CSI_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_CSIRDY) == (RCC_CR_CSIRDY)) ? 1UL : 0UL);
}

/**
 * @brief  Enable CSI oscillator in Stop mode
 * @rmtoll CR           CSIKERON         LL_RCC_CSI_EnableStopMode
 * @retval None
 */
__STATIC_INLINE void LL_RCC_CSI_EnableStopMode(void) {
  SET_BIT(RCC->CR, RCC_CR_CSIKERON);
}

/**
 * @brief  Disable CSI oscillator in Stop mode
 * @rmtoll CR           CSIKERON         LL_RCC_CSI_DisableStopMode
 * @retval None
 */
__STATIC_INLINE void LL_RCC_CSI_DisableStopMode(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_CSIKERON);
}

/**
 * @brief  Get CSI Calibration value
 * @note When CSITRIM is written, CSICAL is updated with the sum of
 *       CSITRIM and the factory trim value
 * @rmtoll CSICFGR        CSICAL        LL_RCC_CSI_GetCalibration
 * @retval A value between 0 and 255 (0xFF)
 */
__STATIC_INLINE uint32_t LL_RCC_CSI_GetCalibration(void) {
#if defined(RCC_VER_X)
  if ((DBGMCU->IDCODE & 0xF0000000U) == 0x10000000U) {
    /* STM32H7 Rev.Y */
    return (uint32_t)(READ_BIT(RCC->HSICFGR, 0x3FC0000U) >> 18U);
  } else {
    /* STM32H7 Rev.V */
    return (uint32_t)(READ_BIT(RCC->CSICFGR, RCC_CSICFGR_CSICAL) >>
                      RCC_CSICFGR_CSICAL_Pos);
  }
#else
  return (uint32_t)(READ_BIT(RCC->CSICFGR, RCC_CSICFGR_CSICAL) >>
                    RCC_CSICFGR_CSICAL_Pos);
#endif /* RCC_VER_X */
}

/**
 * @brief  Set CSI Calibration trimming
 * @note user-programmable trimming value that is added to the CSICAL
 * @note Default value is 16, which, when added to the CSICAL value,
 *       should trim the CSI to 4 MHz +/- 1 %
 * @rmtoll CSICFGR        CSITRIM       LL_RCC_CSI_SetCalibTrimming
 * @param  Value can be a value between 0 and 31
 * @retval None
 */
__STATIC_INLINE void LL_RCC_CSI_SetCalibTrimming(uint32_t Value) {
#if defined(RCC_VER_X)
  if ((DBGMCU->IDCODE & 0xF0000000U) == 0x10000000U) {
    /* STM32H7 Rev.Y */
    MODIFY_REG(RCC->HSICFGR, 0x7C000000U, Value << 26U);
  } else {
    /* STM32H7 Rev.V */
    MODIFY_REG(RCC->CSICFGR, RCC_CSICFGR_CSITRIM,
               Value << RCC_CSICFGR_CSITRIM_Pos);
  }
#else
  MODIFY_REG(RCC->CSICFGR, RCC_CSICFGR_CSITRIM,
             Value << RCC_CSICFGR_CSITRIM_Pos);
#endif /* RCC_VER_X */
}

/**
 * @brief  Get CSI Calibration trimming
 * @rmtoll CSICFGR        CSITRIM       LL_RCC_CSI_GetCalibTrimming
 * @retval A value between 0 and 31
 */
__STATIC_INLINE uint32_t LL_RCC_CSI_GetCalibTrimming(void) {
#if defined(RCC_VER_X)
  if ((DBGMCU->IDCODE & 0xF0000000U) == 0x10000000U) {
    /* STM32H7 Rev.Y */
    return (uint32_t)(READ_BIT(RCC->HSICFGR, 0x7C000000U) >> 26U);
  } else {
    /* STM32H7 Rev.V */
    return (uint32_t)(READ_BIT(RCC->CSICFGR, RCC_CSICFGR_CSITRIM) >>
                      RCC_CSICFGR_CSITRIM_Pos);
  }
#else
  return (uint32_t)(READ_BIT(RCC->CSICFGR, RCC_CSICFGR_CSITRIM) >>
                    RCC_CSICFGR_CSITRIM_Pos);
#endif /* RCC_VER_X */
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_HSI48 HSI48
 * @{
 */

/**
 * @brief  Enable HSI48 oscillator
 * @rmtoll CR           HSI48ON         LL_RCC_HSI48_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSI48_Enable(void) {
  SET_BIT(RCC->CR, RCC_CR_HSI48ON);
}

/**
 * @brief  Disable HSI48 oscillator
 * @rmtoll CR           HSI48ON         LL_RCC_HSI48_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_HSI48_Disable(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_HSI48ON);
}

/**
 * @brief  Check if HSI48 clock is ready
 * @rmtoll CR           HSI48RDY        LL_RCC_HSI48_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_HSI48_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_HSI48RDY) == (RCC_CR_HSI48RDY)) ? 1UL
                                                                    : 0UL);
}

/**
 * @brief  Get HSI48 Calibration value
 * @note When HSI48TRIM is written, HSI48CAL is updated with the sum of
 *       HSI48TRIM and the factory trim value
 * @rmtoll CRRCR        HSI48CAL        LL_RCC_HSI48_GetCalibration
 * @retval A value between 0 and 1023 (0x3FF)
 */
__STATIC_INLINE uint32_t LL_RCC_HSI48_GetCalibration(void) {
  return (uint32_t)(READ_BIT(RCC->CRRCR, RCC_CRRCR_HSI48CAL) >>
                    RCC_CRRCR_HSI48CAL_Pos);
}
/**
 * @}
 */

#if defined(RCC_CR_D1CKRDY)

/** @defgroup RCC_LL_EF_D1CLK D1CKREADY
 * @{
 */

/**
 * @brief  Check if D1 clock is ready
 * @rmtoll CR           D1CKRDY        LL_RCC_D1CK_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_D1CK_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_D1CKRDY) == (RCC_CR_D1CKRDY)) ? 1UL : 0UL);
}

/**
 * @}
 */
#else

/** @defgroup RCC_LL_EF_CPUCLK CPUCKREADY
 * @{
 */

/**
 * @brief  Check if CPU clock is ready
 * @rmtoll CR           CPUCKRDY        LL_RCC_CPUCK_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_CPUCK_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_CPUCKRDY) == (RCC_CR_CPUCKRDY)) ? 1UL
                                                                    : 0UL);
}
/* alias */
#define LL_RCC_D1CK_IsReady LL_RCC_CPUCK_IsReady
/**
 * @}
 */
#endif /* RCC_CR_D1CKRDY */

#if defined(RCC_CR_D2CKRDY)

/** @defgroup RCC_LL_EF_D2CLK D2CKREADY
 * @{
 */

/**
 * @brief  Check if D2 clock is ready
 * @rmtoll CR           D2CKRDY        LL_RCC_D2CK_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_D2CK_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_D2CKRDY) == (RCC_CR_D2CKRDY)) ? 1UL : 0UL);
}
/**
 * @}
 */
#else

/** @defgroup RCC_LL_EF_CDCLK CDCKREADY
 * @{
 */

/**
 * @brief  Check if CD clock is ready
 * @rmtoll CR           CDCKRDY        LL_RCC_CDCK_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_CDCK_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_CDCKRDY) == (RCC_CR_CDCKRDY)) ? 1UL : 0UL);
}
#define LL_RCC_D2CK_IsReady LL_RCC_CDCK_IsReady
/**
 * @}
 */
#endif /* RCC_CR_D2CKRDY */

/** @defgroup RCC_LL_EF_SYSTEM_WIDE_RESET RESET
 * @{
 */
#if defined(RCC_GCR_WW1RSC)

/**
 * @brief  Enable system wide reset for Window Watch Dog 1
 * @rmtoll GCR          WW1RSC        LL_RCC_WWDG1_EnableSystemReset
 * @retval None.
 */
__STATIC_INLINE void LL_RCC_WWDG1_EnableSystemReset(void) {
  SET_BIT(RCC->GCR, RCC_GCR_WW1RSC);
}

/**
 * @brief  Check if Window Watch Dog 1 reset is system wide
 * @rmtoll GCR          WW1RSC        LL_RCC_WWDG1_IsSystemReset
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_WWDG1_IsSystemReset(void) {
  return ((READ_BIT(RCC->GCR, RCC_GCR_WW1RSC) == RCC_GCR_WW1RSC) ? 1UL : 0UL);
}
#endif /* RCC_GCR_WW1RSC */

#if defined(DUAL_CORE)
/**
 * @brief  Enable system wide reset for Window Watch Dog 2
 * @rmtoll GCR          WW1RSC        LL_RCC_WWDG2_EnableSystemReset
 * @retval None.
 */
__STATIC_INLINE void LL_RCC_WWDG2_EnableSystemReset(void) {
  SET_BIT(RCC->GCR, RCC_GCR_WW2RSC);
}

/**
 * @brief  Check if Window Watch Dog 2 reset is system wide
 * @rmtoll GCR          WW2RSC        LL_RCC_WWDG2_IsSystemReset
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_WWDG2_IsSystemReset(void) {
  return ((READ_BIT(RCC->GCR, RCC_GCR_WW2RSC) == RCC_GCR_WW2RSC) ? 1UL : 0UL);
}
#endif /*DUAL_CORE*/
/**
 * @}
 */

#if defined(DUAL_CORE)
/** @defgroup RCC_LL_EF_BOOT_CPU CPU
 * @{
 */

/**
 * @brief  Force CM4 boot (if hold by option byte BCM4 = 0)
 * @rmtoll GCR          BOOT_C2        LL_RCC_ForceCM4Boot
 * @retval None.
 */
__STATIC_INLINE void LL_RCC_ForceCM4Boot(void) {
  SET_BIT(RCC->GCR, RCC_GCR_BOOT_C2);
}

/**
 * @brief  Check if CM4 boot is forced
 * @rmtoll GCR          BOOT_C2        LL_RCC_IsCM4BootForced
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsCM4BootForced(void) {
  return ((READ_BIT(RCC->GCR, RCC_GCR_BOOT_C2) == RCC_GCR_BOOT_C2) ? 1UL : 0UL);
}

/**
 * @brief  Force CM7 boot (if hold by option byte BCM7 = 0)
 * @rmtoll GCR          BOOT_C1        LL_RCC_ForceCM7Boot
 * @retval None.
 */
__STATIC_INLINE void LL_RCC_ForceCM7Boot(void) {
  SET_BIT(RCC->GCR, RCC_GCR_BOOT_C1);
}

/**
 * @brief  Check if CM7 boot is forced
 * @rmtoll GCR          BOOT_C1        LL_RCC_IsCM7BootForced
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsCM7BootForced(void) {
  return ((READ_BIT(RCC->GCR, RCC_GCR_BOOT_C1) == RCC_GCR_BOOT_C1) ? 1UL : 0UL);
}

/**
 * @}
 */
#endif /*DUAL_CORE*/

/** @defgroup RCC_LL_EF_LSE LSE
 * @{
 */

/**
 * @brief  Enable the Clock Security System on LSE.
 * @note Once LSE Clock Security System is enabled it cannot be changed anymore
 * unless a clock failure is detected.
 * @rmtoll BDCR          LSECSSON         LL_RCC_LSE_EnableCSS
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSE_EnableCSS(void) {
  SET_BIT(RCC->BDCR, RCC_BDCR_LSECSSON);
}

/**
 * @brief  Check if LSE failure is detected by Clock Security System
 * @rmtoll BDCR         LSECSSD       LL_RCC_LSE_IsFailureDetected
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_LSE_IsFailureDetected(void) {
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_LSECSSD) == (RCC_BDCR_LSECSSD)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Enable  Low Speed External (LSE) crystal.
 * @rmtoll BDCR         LSEON         LL_RCC_LSE_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSE_Enable(void) {
  SET_BIT(RCC->BDCR, RCC_BDCR_LSEON);
}

/**
 * @brief  Disable  Low Speed External (LSE) crystal.
 * @rmtoll BDCR         LSEON         LL_RCC_LSE_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSE_Disable(void) {
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEON);
}

/**
 * @brief  Enable external clock source (LSE bypass).
 * @rmtoll BDCR         LSEBYP        LL_RCC_LSE_EnableBypass
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSE_EnableBypass(void) {
  SET_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
}

/**
 * @brief  Disable external clock source (LSE bypass).
 * @rmtoll BDCR         LSEBYP        LL_RCC_LSE_DisableBypass
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSE_DisableBypass(void) {
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEBYP);
}

#if defined(RCC_BDCR_LSEEXT)
/**
 * @brief  Enable Low-speed external DIGITAL clock type in Bypass mode (not to
 * be used if RTC is active).
 * @note   The external clock must be enabled with the LSEON bit, to be used by
 * the device. The LSEEXT bit can be written only if the LSE oscillator is
 * disabled.
 * @rmtoll BDCR         LSEEXT        LL_RCC_LSE_SelectDigitalClock
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSE_SelectDigitalClock(void) {
  SET_BIT(RCC->BDCR, RCC_BDCR_LSEEXT);
}

/**
 * @brief  Enable Low-speed external ANALOG clock type in Bypass mode (default
 * after Backup domain reset).
 * @note   The external clock must be enabled with the LSEON bit, to be used by
 * the device. The LSEEXT bit can be written only if the LSE oscillator is
 * disabled.
 * @rmtoll BDCR         LSEEXT        LL_RCC_LSE_SelectAnalogClock
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSE_SelectAnalogClock(void) {
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_LSEEXT);
}
#endif /* RCC_BDCR_LSEEXT */

/**
 * @brief  Set LSE oscillator drive capability
 * @note The oscillator is in Xtal mode when it is not in bypass mode.
 * @rmtoll BDCR         LSEDRV        LL_RCC_LSE_SetDriveCapability
 * @param  LSEDrive This parameter can be one of the following values:
 *         @arg @ref LL_RCC_LSEDRIVE_LOW
 *         @arg @ref LL_RCC_LSEDRIVE_MEDIUMLOW
 *         @arg @ref LL_RCC_LSEDRIVE_MEDIUMHIGH
 *         @arg @ref LL_RCC_LSEDRIVE_HIGH
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSE_SetDriveCapability(uint32_t LSEDrive) {
  MODIFY_REG(RCC->BDCR, RCC_BDCR_LSEDRV, LSEDrive);
}

/**
 * @brief  Get LSE oscillator drive capability
 * @rmtoll BDCR         LSEDRV        LL_RCC_LSE_GetDriveCapability
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_LSEDRIVE_LOW
 *         @arg @ref LL_RCC_LSEDRIVE_MEDIUMLOW
 *         @arg @ref LL_RCC_LSEDRIVE_MEDIUMHIGH
 *         @arg @ref LL_RCC_LSEDRIVE_HIGH
 */
__STATIC_INLINE uint32_t LL_RCC_LSE_GetDriveCapability(void) {
  return (uint32_t)(READ_BIT(RCC->BDCR, RCC_BDCR_LSEDRV));
}

/**
 * @brief  Check if LSE oscillator Ready
 * @rmtoll BDCR         LSERDY        LL_RCC_LSE_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_LSE_IsReady(void) {
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_LSERDY) == (RCC_BDCR_LSERDY)) ? 1UL
                                                                      : 0UL);
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_LSI LSI
 * @{
 */

/**
 * @brief  Enable LSI Oscillator
 * @rmtoll CSR          LSION         LL_RCC_LSI_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSI_Enable(void) {
  SET_BIT(RCC->CSR, RCC_CSR_LSION);
}

/**
 * @brief  Disable LSI Oscillator
 * @rmtoll CSR          LSION         LL_RCC_LSI_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_LSI_Disable(void) {
  CLEAR_BIT(RCC->CSR, RCC_CSR_LSION);
}

/**
 * @brief  Check if LSI is Ready
 * @rmtoll CSR          LSIRDY        LL_RCC_LSI_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_LSI_IsReady(void) {
  return ((READ_BIT(RCC->CSR, RCC_CSR_LSIRDY) == (RCC_CSR_LSIRDY)) ? 1UL : 0UL);
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_System System
 * @{
 */

/**
 * @brief  Configure the system clock source
 * @rmtoll CFGR         SW            LL_RCC_SetSysClkSource
 * @param  Source This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_PLL1
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetSysClkSource(uint32_t Source) {
  MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, Source);
}

/**
 * @brief  Get the system clock source
 * @rmtoll CFGR         SWS           LL_RCC_GetSysClkSource
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_HSI
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_CSI
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_HSE
 *         @arg @ref LL_RCC_SYS_CLKSOURCE_STATUS_PLL1
 */
__STATIC_INLINE uint32_t LL_RCC_GetSysClkSource(void) {
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_SWS));
}

/**
 * @brief  Configure the system wakeup clock source
 * @rmtoll CFGR         STOPWUCK       LL_RCC_SetSysWakeUpClkSource
 * @param  Source This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SYSWAKEUP_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SYSWAKEUP_CLKSOURCE_CSI
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetSysWakeUpClkSource(uint32_t Source) {
  MODIFY_REG(RCC->CFGR, RCC_CFGR_STOPWUCK, Source);
}

/**
 * @brief  Get the system wakeup clock source
 * @rmtoll CFGR         STOPWUCK           LL_RCC_GetSysWakeUpClkSource
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SYSWAKEUP_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SYSWAKEUP_CLKSOURCE_CSI
 */
__STATIC_INLINE uint32_t LL_RCC_GetSysWakeUpClkSource(void) {
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_STOPWUCK));
}

/**
 * @brief  Configure the kernel wakeup clock source
 * @rmtoll CFGR         STOPKERWUCK       LL_RCC_SetKerWakeUpClkSource
 * @param  Source This parameter can be one of the following values:
 *         @arg @ref LL_RCC_KERWAKEUP_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_KERWAKEUP_CLKSOURCE_CSI
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetKerWakeUpClkSource(uint32_t Source) {
  MODIFY_REG(RCC->CFGR, RCC_CFGR_STOPKERWUCK, Source);
}

/**
 * @brief  Get the kernel wakeup clock source
 * @rmtoll CFGR         STOPKERWUCK           LL_RCC_GetKerWakeUpClkSource
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_KERWAKEUP_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_KERWAKEUP_CLKSOURCE_CSI
 */
__STATIC_INLINE uint32_t LL_RCC_GetKerWakeUpClkSource(void) {
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_STOPKERWUCK));
}

/**
 * @brief  Set System prescaler
 * @rmtoll D1CFGR/CDCFGR1        D1CPRE/CDCPRE          LL_RCC_SetSysPrescaler
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SYSCLK_DIV_1
 *         @arg @ref LL_RCC_SYSCLK_DIV_2
 *         @arg @ref LL_RCC_SYSCLK_DIV_4
 *         @arg @ref LL_RCC_SYSCLK_DIV_8
 *         @arg @ref LL_RCC_SYSCLK_DIV_16
 *         @arg @ref LL_RCC_SYSCLK_DIV_64
 *         @arg @ref LL_RCC_SYSCLK_DIV_128
 *         @arg @ref LL_RCC_SYSCLK_DIV_256
 *         @arg @ref LL_RCC_SYSCLK_DIV_512
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetSysPrescaler(uint32_t Prescaler) {
#if defined(RCC_D1CFGR_D1CPRE)
  MODIFY_REG(RCC->D1CFGR, RCC_D1CFGR_D1CPRE, Prescaler);
#else
  MODIFY_REG(RCC->CDCFGR1, RCC_CDCFGR1_CDCPRE, Prescaler);
#endif /* RCC_D1CFGR_D1CPRE */
}

/**
 * @brief  Set AHB prescaler
 * @rmtoll D1CFGR/CDCFGR1        HPRE         LL_RCC_SetAHBPrescaler
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_AHB_DIV_1
 *         @arg @ref LL_RCC_AHB_DIV_2
 *         @arg @ref LL_RCC_AHB_DIV_4
 *         @arg @ref LL_RCC_AHB_DIV_8
 *         @arg @ref LL_RCC_AHB_DIV_16
 *         @arg @ref LL_RCC_AHB_DIV_64
 *         @arg @ref LL_RCC_AHB_DIV_128
 *         @arg @ref LL_RCC_AHB_DIV_256
 *         @arg @ref LL_RCC_AHB_DIV_512
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetAHBPrescaler(uint32_t Prescaler) {
#if defined(RCC_D1CFGR_HPRE)
  MODIFY_REG(RCC->D1CFGR, RCC_D1CFGR_HPRE, Prescaler);
#else
  MODIFY_REG(RCC->CDCFGR1, RCC_CDCFGR1_HPRE, Prescaler);
#endif /* RCC_D1CFGR_HPRE */
}

/**
 * @brief  Set APB1 prescaler
 * @rmtoll D2CFGR/CDCFGR2         D2PPRE1/CDPPRE1 LL_RCC_SetAPB1Prescaler
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB1_DIV_1
 *         @arg @ref LL_RCC_APB1_DIV_2
 *         @arg @ref LL_RCC_APB1_DIV_4
 *         @arg @ref LL_RCC_APB1_DIV_8
 *         @arg @ref LL_RCC_APB1_DIV_16
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetAPB1Prescaler(uint32_t Prescaler) {
#if defined(RCC_D2CFGR_D2PPRE1)
  MODIFY_REG(RCC->D2CFGR, RCC_D2CFGR_D2PPRE1, Prescaler);
#else
  MODIFY_REG(RCC->CDCFGR2, RCC_CDCFGR2_CDPPRE1, Prescaler);
#endif /* RCC_D2CFGR_D2PPRE1 */
}

/**
 * @brief  Set APB2 prescaler
 * @rmtoll D2CFGR/CDCFGR2         D2PPRE2/CDPPRE2 LL_RCC_SetAPB2Prescaler
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB2_DIV_1
 *         @arg @ref LL_RCC_APB2_DIV_2
 *         @arg @ref LL_RCC_APB2_DIV_4
 *         @arg @ref LL_RCC_APB2_DIV_8
 *         @arg @ref LL_RCC_APB2_DIV_16
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetAPB2Prescaler(uint32_t Prescaler) {
#if defined(RCC_D2CFGR_D2PPRE2)
  MODIFY_REG(RCC->D2CFGR, RCC_D2CFGR_D2PPRE2, Prescaler);
#else
  MODIFY_REG(RCC->CDCFGR2, RCC_CDCFGR2_CDPPRE2, Prescaler);
#endif /* RCC_D2CFGR_D2PPRE2 */
}

/**
 * @brief  Set APB3 prescaler
 * @rmtoll D1CFGR/CDCFGR1         D1PPRE/CDPPRE         LL_RCC_SetAPB3Prescaler
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB3_DIV_1
 *         @arg @ref LL_RCC_APB3_DIV_2
 *         @arg @ref LL_RCC_APB3_DIV_4
 *         @arg @ref LL_RCC_APB3_DIV_8
 *         @arg @ref LL_RCC_APB3_DIV_16
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetAPB3Prescaler(uint32_t Prescaler) {
#if defined(RCC_D1CFGR_D1PPRE)
  MODIFY_REG(RCC->D1CFGR, RCC_D1CFGR_D1PPRE, Prescaler);
#else
  MODIFY_REG(RCC->CDCFGR1, RCC_CDCFGR1_CDPPRE, Prescaler);
#endif /* RCC_D1CFGR_D1PPRE */
}

/**
 * @brief  Set APB4 prescaler
 * @rmtoll D3CFGR/SRDCFGR         D3PPRE/SRDPPRE         LL_RCC_SetAPB4Prescaler
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_APB4_DIV_1
 *         @arg @ref LL_RCC_APB4_DIV_2
 *         @arg @ref LL_RCC_APB4_DIV_4
 *         @arg @ref LL_RCC_APB4_DIV_8
 *         @arg @ref LL_RCC_APB4_DIV_16
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetAPB4Prescaler(uint32_t Prescaler) {
#if defined(RCC_D3CFGR_D3PPRE)
  MODIFY_REG(RCC->D3CFGR, RCC_D3CFGR_D3PPRE, Prescaler);
#else
  MODIFY_REG(RCC->SRDCFGR, RCC_SRDCFGR_SRDPPRE, Prescaler);
#endif /* RCC_D3CFGR_D3PPRE */
}

/**
 * @brief  Get System prescaler
 * @rmtoll D1CFGR/CDCFGR1        D1CPRE/CDCPRE          LL_RCC_GetSysPrescaler
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SYSCLK_DIV_1
 *         @arg @ref LL_RCC_SYSCLK_DIV_2
 *         @arg @ref LL_RCC_SYSCLK_DIV_4
 *         @arg @ref LL_RCC_SYSCLK_DIV_8
 *         @arg @ref LL_RCC_SYSCLK_DIV_16
 *         @arg @ref LL_RCC_SYSCLK_DIV_64
 *         @arg @ref LL_RCC_SYSCLK_DIV_128
 *         @arg @ref LL_RCC_SYSCLK_DIV_256
 *         @arg @ref LL_RCC_SYSCLK_DIV_512
 */
__STATIC_INLINE uint32_t LL_RCC_GetSysPrescaler(void) {
#if defined(RCC_D1CFGR_D1CPRE)
  return (uint32_t)(READ_BIT(RCC->D1CFGR, RCC_D1CFGR_D1CPRE));
#else
  return (uint32_t)(READ_BIT(RCC->CDCFGR1, RCC_CDCFGR1_CDCPRE));
#endif /* RCC_D1CFGR_D1CPRE */
}

/**
 * @brief  Get AHB prescaler
 * @rmtoll D1CFGR/ CDCFGR1       HPRE         LL_RCC_GetAHBPrescaler
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_AHB_DIV_1
 *         @arg @ref LL_RCC_AHB_DIV_2
 *         @arg @ref LL_RCC_AHB_DIV_4
 *         @arg @ref LL_RCC_AHB_DIV_8
 *         @arg @ref LL_RCC_AHB_DIV_16
 *         @arg @ref LL_RCC_AHB_DIV_64
 *         @arg @ref LL_RCC_AHB_DIV_128
 *         @arg @ref LL_RCC_AHB_DIV_256
 *         @arg @ref LL_RCC_AHB_DIV_512
 */
__STATIC_INLINE uint32_t LL_RCC_GetAHBPrescaler(void) {
#if defined(RCC_D1CFGR_HPRE)
  return (uint32_t)(READ_BIT(RCC->D1CFGR, RCC_D1CFGR_HPRE));
#else
  return (uint32_t)(READ_BIT(RCC->CDCFGR1, RCC_CDCFGR1_HPRE));
#endif /* RCC_D1CFGR_HPRE */
}

/**
 * @brief  Get APB1 prescaler
 * @rmtoll D2CFGR/CDCFGR2         D2PPRE1/CDPPRE1 LL_RCC_GetAPB1Prescaler
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_APB1_DIV_1
 *         @arg @ref LL_RCC_APB1_DIV_2
 *         @arg @ref LL_RCC_APB1_DIV_4
 *         @arg @ref LL_RCC_APB1_DIV_8
 *         @arg @ref LL_RCC_APB1_DIV_16
 */
__STATIC_INLINE uint32_t LL_RCC_GetAPB1Prescaler(void) {
#if defined(RCC_D2CFGR_D2PPRE1)
  return (uint32_t)(READ_BIT(RCC->D2CFGR, RCC_D2CFGR_D2PPRE1));
#else
  return (uint32_t)(READ_BIT(RCC->CDCFGR2, RCC_CDCFGR2_CDPPRE1));
#endif /* RCC_D2CFGR_D2PPRE1 */
}

/**
 * @brief  Get APB2 prescaler
 * @rmtoll D2CFGR/CDCFGR2         D2PPRE2/CDPPRE2 LL_RCC_GetAPB2Prescaler
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_APB2_DIV_1
 *         @arg @ref LL_RCC_APB2_DIV_2
 *         @arg @ref LL_RCC_APB2_DIV_4
 *         @arg @ref LL_RCC_APB2_DIV_8
 *         @arg @ref LL_RCC_APB2_DIV_16
 */
__STATIC_INLINE uint32_t LL_RCC_GetAPB2Prescaler(void) {
#if defined(RCC_D2CFGR_D2PPRE2)
  return (uint32_t)(READ_BIT(RCC->D2CFGR, RCC_D2CFGR_D2PPRE2));
#else
  return (uint32_t)(READ_BIT(RCC->CDCFGR2, RCC_CDCFGR2_CDPPRE2));
#endif /* RCC_D2CFGR_D2PPRE2 */
}

/**
 * @brief  Get APB3 prescaler
 * @rmtoll D1CFGR/CDCFGR1         D1PPRE/CDPPRE         LL_RCC_GetAPB3Prescaler
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_APB3_DIV_1
 *         @arg @ref LL_RCC_APB3_DIV_2
 *         @arg @ref LL_RCC_APB3_DIV_4
 *         @arg @ref LL_RCC_APB3_DIV_8
 *         @arg @ref LL_RCC_APB3_DIV_16
 */
__STATIC_INLINE uint32_t LL_RCC_GetAPB3Prescaler(void) {
#if defined(RCC_D1CFGR_D1PPRE)
  return (uint32_t)(READ_BIT(RCC->D1CFGR, RCC_D1CFGR_D1PPRE));
#else
  return (uint32_t)(READ_BIT(RCC->CDCFGR1, RCC_CDCFGR1_CDPPRE));
#endif /* RCC_D1CFGR_D1PPRE */
}

/**
 * @brief  Get APB4 prescaler
 * @rmtoll D3CFGR/SRDCFGR         D3PPRE/SRDPPRE         LL_RCC_GetAPB4Prescaler
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_APB4_DIV_1
 *         @arg @ref LL_RCC_APB4_DIV_2
 *         @arg @ref LL_RCC_APB4_DIV_4
 *         @arg @ref LL_RCC_APB4_DIV_8
 *         @arg @ref LL_RCC_APB4_DIV_16
 */
__STATIC_INLINE uint32_t LL_RCC_GetAPB4Prescaler(void) {
#if defined(RCC_D3CFGR_D3PPRE)
  return (uint32_t)(READ_BIT(RCC->D3CFGR, RCC_D3CFGR_D3PPRE));
#else
  return (uint32_t)(READ_BIT(RCC->SRDCFGR, RCC_SRDCFGR_SRDPPRE));
#endif /* RCC_D3CFGR_D3PPRE */
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_MCO MCO
 * @{
 */

/**
 * @brief  Configure MCOx
 * @rmtoll CFGR         MCO1          LL_RCC_ConfigMCO\n
 *         CFGR         MCO1PRE       LL_RCC_ConfigMCO\n
 *         CFGR         MCO2          LL_RCC_ConfigMCO\n
 *         CFGR         MCO2PRE       LL_RCC_ConfigMCO
 * @param  MCOxSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_MCO1SOURCE_HSI
 *         @arg @ref LL_RCC_MCO1SOURCE_LSE
 *         @arg @ref LL_RCC_MCO1SOURCE_HSE
 *         @arg @ref LL_RCC_MCO1SOURCE_PLL1QCLK
 *         @arg @ref LL_RCC_MCO1SOURCE_HSI48
 *         @arg @ref LL_RCC_MCO2SOURCE_SYSCLK
 *         @arg @ref LL_RCC_MCO2SOURCE_PLL2PCLK
 *         @arg @ref LL_RCC_MCO2SOURCE_HSE
 *         @arg @ref LL_RCC_MCO2SOURCE_PLL1PCLK
 *         @arg @ref LL_RCC_MCO2SOURCE_CSI
 *         @arg @ref LL_RCC_MCO2SOURCE_LSI
 * @param  MCOxPrescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_MCO1_DIV_1
 *         @arg @ref LL_RCC_MCO1_DIV_2
 *         @arg @ref LL_RCC_MCO1_DIV_3
 *         @arg @ref LL_RCC_MCO1_DIV_4
 *         @arg @ref LL_RCC_MCO1_DIV_5
 *         @arg @ref LL_RCC_MCO1_DIV_6
 *         @arg @ref LL_RCC_MCO1_DIV_7
 *         @arg @ref LL_RCC_MCO1_DIV_8
 *         @arg @ref LL_RCC_MCO1_DIV_9
 *         @arg @ref LL_RCC_MCO1_DIV_10
 *         @arg @ref LL_RCC_MCO1_DIV_11
 *         @arg @ref LL_RCC_MCO1_DIV_12
 *         @arg @ref LL_RCC_MCO1_DIV_13
 *         @arg @ref LL_RCC_MCO1_DIV_14
 *         @arg @ref LL_RCC_MCO1_DIV_15
 *         @arg @ref LL_RCC_MCO2_DIV_1
 *         @arg @ref LL_RCC_MCO2_DIV_2
 *         @arg @ref LL_RCC_MCO2_DIV_3
 *         @arg @ref LL_RCC_MCO2_DIV_4
 *         @arg @ref LL_RCC_MCO2_DIV_5
 *         @arg @ref LL_RCC_MCO2_DIV_6
 *         @arg @ref LL_RCC_MCO2_DIV_7
 *         @arg @ref LL_RCC_MCO2_DIV_8
 *         @arg @ref LL_RCC_MCO2_DIV_9
 *         @arg @ref LL_RCC_MCO2_DIV_10
 *         @arg @ref LL_RCC_MCO2_DIV_11
 *         @arg @ref LL_RCC_MCO2_DIV_12
 *         @arg @ref LL_RCC_MCO2_DIV_13
 *         @arg @ref LL_RCC_MCO2_DIV_14
 *         @arg @ref LL_RCC_MCO2_DIV_15
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ConfigMCO(uint32_t MCOxSource,
                                      uint32_t MCOxPrescaler) {
  MODIFY_REG(RCC->CFGR, (MCOxSource << 16U) | (MCOxPrescaler << 16U),
             (MCOxSource & 0xFFFF0000U) | (MCOxPrescaler & 0xFFFF0000U));
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_Peripheral_Clock_Source Peripheral Clock Source
 * @{
 */

/**
 * @brief  Configure periph clock source
 * @rmtoll D2CCIP1R/CDCCIP1R        *     LL_RCC_SetClockSource\n
 *         D2CCIP2R/CDCCIP2R        *     LL_RCC_SetClockSource\n
 *         D3CCIPR/SRDCCIPR         *     LL_RCC_SetClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL3P
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_I2S_CKIN
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL2P  (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL3P  (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_I2S_CKIN  (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_SPDIF  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL1Q  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL2P  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL3P  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_I2S_CKIN  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_CLKP  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_SPDIF  (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL1Q  (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_SPDIF (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_SPDIF  (*)
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL3P
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_I2S_CKIN
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_I2S_CKIN (*)
 *
 *         (*) value not defined in all devices.
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetClockSource(uint32_t ClkSource) {
#if defined(RCC_D1CCIPR_FMCSEL)
  uint32_t *pReg =
      (uint32_t *)((uint32_t)&RCC->D1CCIPR + LL_CLKSOURCE_REG(ClkSource));
#else
  uint32_t *pReg =
      (uint32_t *)((uint32_t)&RCC->CDCCIPR + LL_CLKSOURCE_REG(ClkSource));
#endif /*  */
  MODIFY_REG(*pReg, LL_CLKSOURCE_MASK(ClkSource),
             LL_CLKSOURCE_CONFIG(ClkSource));
}

/**
 * @brief  Configure USARTx clock source
 * @rmtoll D2CCIP2R / D2CCIP2R        USART16SEL LL_RCC_SetUSARTClockSource\n
 *         D2CCIP2R / D2CCIP2R        USART28SEL     LL_RCC_SetUSARTClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_LSE
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetUSARTClockSource(uint32_t ClkSource) {
  LL_RCC_SetClockSource(ClkSource);
}

/**
 * @brief  Configure LPUARTx clock source
 * @rmtoll D3CCIPR / SRDCCIPR        LPUART1SEL     LL_RCC_SetLPUARTClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_LSE
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetLPUARTClockSource(uint32_t ClkSource) {
#if defined(RCC_D3CCIPR_LPUART1SEL)
  MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_LPUART1SEL, ClkSource);
#else
  MODIFY_REG(RCC->SRDCCIPR, RCC_SRDCCIPR_LPUART1SEL, ClkSource);
#endif /* RCC_D3CCIPR_LPUART1SEL */
}

/**
 * @brief  Configure I2Cx clock source
 * @rmtoll D2CCIP2R / CDCCIP2R       I2C123SEL       LL_RCC_SetI2CClockSource\n
 *         D3CCIPR / SRDCCIPR        I2C4SEL         LL_RCC_SetI2CClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_CSI
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetI2CClockSource(uint32_t ClkSource) {
  LL_RCC_SetClockSource(ClkSource);
}

/**
 * @brief  Configure LPTIMx clock source
 * @rmtoll D2CCIP2R / CDCCIP2R      LPTIM1SEL     LL_RCC_SetLPTIMClockSource
 *         D3CCIPR  / SRDCCIPR      LPTIM2SEL     LL_RCC_SetLPTIMClockSource\n
 *         D3CCIPR  / SRDCCIPR      LPTIM345SEL   LL_RCC_SetLPTIMClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_CLKP
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetLPTIMClockSource(uint32_t ClkSource) {
  LL_RCC_SetClockSource(ClkSource);
}

/**
 * @brief  Configure SAIx clock source
 * @rmtoll D2CCIP1R / CDCCIP1R       SAI1SEL       LL_RCC_SetSAIClockSource\n
 *         D2CCIP1R / CDCCIP1R       SAI23SEL      LL_RCC_SetSAIClockSource
 *         D3CCIPR  / SRDCCIPR       SAI4ASEL      LL_RCC_SetSAI4xClockSource\n
 *         D3CCIPR  / SRDCCIPR       SAI4BSEL      LL_RCC_SetSAI4xClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL3P
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_I2S_CKIN
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL2P  (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL3P  (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_I2S_CKIN  (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_SPDIF  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL1Q  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL2P  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL3P  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_I2S_CKIN  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_CLKP  (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_SPDIF  (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL1Q  (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_SPDIF  (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_SPDIF  (*)
 *
 *         (*) value not defined in all devices.
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetSAIClockSource(uint32_t ClkSource) {
  LL_RCC_SetClockSource(ClkSource);
}

/**
 * @brief  Configure SDMMCx clock source
 * @rmtoll D1CCIPR / CDCCIPR       SDMMCSEL      LL_RCC_SetSDMMCClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SDMMC_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SDMMC_CLKSOURCE_PLL2R
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetSDMMCClockSource(uint32_t ClkSource) {
#if defined(RCC_D1CCIPR_SDMMCSEL)
  MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_SDMMCSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIPR, RCC_CDCCIPR_SDMMCSEL, ClkSource);
#endif /* RCC_D1CCIPR_SDMMCSEL */
}

/**
 * @brief  Configure RNGx clock source
 * @rmtoll D2CCIP2R / CDCCIP2R       RNGSEL      LL_RCC_SetRNGClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_RNG_CLKSOURCE_HSI48
 *         @arg @ref LL_RCC_RNG_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_RNG_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_RNG_CLKSOURCE_LSI
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetRNGClockSource(uint32_t ClkSource) {
#if defined(RCC_D2CCIP2R_RNGSEL)
  MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_RNGSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIP2R, RCC_CDCCIP2R_RNGSEL, ClkSource);
#endif /* RCC_D2CCIP2R_RNGSEL */
}

/**
 * @brief  Configure USBx clock source
 * @rmtoll D2CCIP2R / CDCCIP2R      USBSEL      LL_RCC_SetUSBClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_USB_CLKSOURCE_DISABLE
 *         @arg @ref LL_RCC_USB_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_USB_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USB_CLKSOURCE_HSI48
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetUSBClockSource(uint32_t ClkSource) {
#if defined(RCC_D2CCIP2R_USBSEL)
  MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_USBSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIP2R, RCC_CDCCIP2R_USBSEL, ClkSource);
#endif /* RCC_D2CCIP2R_USBSEL */
}

/**
 * @brief  Configure CECx clock source
 * @rmtoll D2CCIP2R / CDCCIP2R         CECSEL        LL_RCC_SetCECClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_CEC_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_CEC_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_CEC_CLKSOURCE_CSI_DIV122
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetCECClockSource(uint32_t ClkSource) {
#if defined(RCC_D2CCIP2R_CECSEL)
  MODIFY_REG(RCC->D2CCIP2R, RCC_D2CCIP2R_CECSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIP2R, RCC_CDCCIP2R_CECSEL, ClkSource);
#endif /* RCC_D2CCIP2R_CECSEL */
}

#if defined(DSI)
/**
 * @brief  Configure DSIx clock source
 * @rmtoll D1CCIPR         DSISEL        LL_RCC_SetDSIClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_DSI_CLKSOURCE_PHY
 *         @arg @ref LL_RCC_DSI_CLKSOURCE_PLL2Q
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetDSIClockSource(uint32_t ClkSource) {
  MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_DSISEL, ClkSource);
}
#endif /* DSI */

/**
 * @brief  Configure DFSDMx Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R         DFSDM1SEL LL_RCC_SetDFSDMClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_DFSDM1_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_DFSDM1_CLKSOURCE_SYSCLK
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetDFSDMClockSource(uint32_t ClkSource) {
#if defined(RCC_D2CCIP1R_DFSDM1SEL)
  MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_DFSDM1SEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIP1R, RCC_CDCCIP1R_DFSDM1SEL, ClkSource);
#endif /* RCC_D2CCIP1R_DFSDM1SEL */
}

#if defined(DFSDM2_BASE)
/**
 * @brief  Configure DFSDMx Kernel clock source
 * @rmtoll SRDCCIPR                   DFSDM2SEL LL_RCC_SetDFSDM2ClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_DFSDM2_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_DFSDM2_CLKSOURCE_SYSCLK
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetDFSDM2ClockSource(uint32_t ClkSource) {
  MODIFY_REG(RCC->SRDCCIPR, RCC_SRDCCIPR_DFSDM2SEL, ClkSource);
}
#endif /* DFSDM2_BASE */

/**
 * @brief  Configure FMCx Kernel clock source
 * @rmtoll D1CCIPR /  CDCCIPR        FMCSEL        LL_RCC_SetFMCClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_FMC_CLKSOURCE_HCLK
 *         @arg @ref LL_RCC_FMC_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_FMC_CLKSOURCE_PLL2R
 *         @arg @ref LL_RCC_FMC_CLKSOURCE_CLKP
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetFMCClockSource(uint32_t ClkSource) {
#if defined(RCC_D1CCIPR_FMCSEL)
  MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_FMCSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIPR, RCC_CDCCIPR_FMCSEL, ClkSource);
#endif /* RCC_D1CCIPR_FMCSEL */
}

#if defined(QUADSPI)
/**
 * @brief  Configure QSPIx Kernel clock source
 * @rmtoll D1CCIPR         QSPISEL        LL_RCC_SetQSPIClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE_HCLK
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE_PLL2R
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE_CLKP
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetQSPIClockSource(uint32_t ClkSource) {
  MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_QSPISEL, ClkSource);
}
#endif /* QUADSPI */

#if defined(OCTOSPI1) || defined(OCTOSPI2)
/**
 * @brief  Configure OSPIx Kernel clock source
 * @rmtoll D1CCIPR         OPISEL        LL_RCC_SetOSPIClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE_HCLK
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE_PLL2R
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE_CLKP
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetOSPIClockSource(uint32_t ClkSource) {
#if defined(RCC_D1CCIPR_OCTOSPISEL)
  MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_OCTOSPISEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIPR, RCC_CDCCIPR_OCTOSPISEL, ClkSource);
#endif /* RCC_D1CCIPR_OCTOSPISEL */
}
#endif /* OCTOSPI1 || OCTOSPI2 */

/**
 * @brief  Configure CLKP Kernel clock source
 * @rmtoll D1CCIPR / CDCCIPR         CKPERSEL        LL_RCC_SetCLKPClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_CLKP_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_CLKP_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_CLKP_CLKSOURCE_HSE
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetCLKPClockSource(uint32_t ClkSource) {
#if defined(RCC_D1CCIPR_CKPERSEL)
  MODIFY_REG(RCC->D1CCIPR, RCC_D1CCIPR_CKPERSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIPR, RCC_CDCCIPR_CKPERSEL, ClkSource);
#endif /* RCC_D1CCIPR_CKPERSEL */
}

/**
 * @brief  Configure SPIx Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R       SPI123SEL        LL_RCC_SetSPIClockSource\n
 *         D2CCIP1R / CDCCIP1R       SPI45SEL         LL_RCC_SetSPIClockSource\n
 *         D3CCIPR  / SRDCCIPR       SPI6SEL          LL_RCC_SetSPIClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL3P
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_I2S_CKIN
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_I2S_CKIN (*)
 *
 *         (*) value not defined in all devices.
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetSPIClockSource(uint32_t ClkSource) {
  LL_RCC_SetClockSource(ClkSource);
}

/**
 * @brief  Configure SPDIFx Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R       SPDIFSEL        LL_RCC_SetSPDIFClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE_PLL2R
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE_HSI
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetSPDIFClockSource(uint32_t ClkSource) {
#if defined(RCC_D2CCIP1R_SPDIFSEL)
  MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_SPDIFSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIP1R, RCC_CDCCIP1R_SPDIFSEL, ClkSource);
#endif /* RCC_D2CCIP1R_SPDIFSEL */
}

/**
 * @brief  Configure FDCANx Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R      FDCANSEL        LL_RCC_SetFDCANClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_FDCAN_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_FDCAN_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_FDCAN_CLKSOURCE_PLL2Q
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetFDCANClockSource(uint32_t ClkSource) {
#if defined(RCC_D2CCIP1R_FDCANSEL)
  MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_FDCANSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIP1R, RCC_CDCCIP1R_FDCANSEL, ClkSource);
#endif /* RCC_D2CCIP1R_FDCANSEL */
}

/**
 * @brief  Configure SWPx Kernel clock source
 * @rmtoll D2CCIP1R /  CDCCIP1R       SWPSEL        LL_RCC_SetSWPClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SWP_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_SWP_CLKSOURCE_HSI
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetSWPClockSource(uint32_t ClkSource) {
#if defined(RCC_D2CCIP1R_SWPSEL)
  MODIFY_REG(RCC->D2CCIP1R, RCC_D2CCIP1R_SWPSEL, ClkSource);
#else
  MODIFY_REG(RCC->CDCCIP1R, RCC_CDCCIP1R_SWPSEL, ClkSource);
#endif /* RCC_D2CCIP1R_SWPSEL */
}

/**
 * @brief  Configure ADCx Kernel clock source
 * @rmtoll D3CCIPR / SRDCCIPR        ADCSEL        LL_RCC_SetADCClockSource
 * @param  ClkSource This parameter can be one of the following values:
 *         @arg @ref LL_RCC_ADC_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_ADC_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_ADC_CLKSOURCE_CLKP
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetADCClockSource(uint32_t ClkSource) {
#if defined(RCC_D3CCIPR_ADCSEL)
  MODIFY_REG(RCC->D3CCIPR, RCC_D3CCIPR_ADCSEL, ClkSource);
#else
  MODIFY_REG(RCC->SRDCCIPR, RCC_SRDCCIPR_ADCSEL, ClkSource);
#endif /* RCC_D3CCIPR_ADCSEL */
}

/**
 * @brief  Get periph clock source
 * @rmtoll D1CCIPR  / CDCCIPR       *     LL_RCC_GetClockSource\n
 *         D2CCIP1R / CDCCIP1R      *     LL_RCC_GetClockSource\n
 *         D2CCIP2R / CDCCIP2R      *     LL_RCC_GetClockSource\n
 *         D3CCIPR  / SRDCCIPR      *     LL_RCC_GetClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_USART16_CLKSOURCE
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE (*)
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE (*)
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE (*)
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE (*)
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL3P
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_I2S_CKIN
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_SPDIF (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_SPDIF (*)
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL3P
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_I2S_CKIN
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_I2S_CKIN (*)
 *
 *         (*) value not defined in all devices.
 * @retval None
 */
__STATIC_INLINE uint32_t LL_RCC_GetClockSource(uint32_t Periph) {
#if defined(RCC_D1CCIPR_FMCSEL)
  const uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&RCC->D1CCIPR) +
                                                 LL_CLKSOURCE_REG(Periph)));
#else
  const uint32_t *pReg = (uint32_t *)((uint32_t)((uint32_t)(&RCC->CDCCIPR) +
                                                 LL_CLKSOURCE_REG(Periph)));
#endif /* RCC_D1CCIPR_FMCSEL */
  return (uint32_t)(Periph | (((READ_BIT(*pReg, LL_CLKSOURCE_MASK(Periph))) >>
                               LL_CLKSOURCE_SHIFT(Periph))
                              << LL_RCC_CONFIG_SHIFT));
}

/**
 * @brief  Get USARTx clock source
 * @rmtoll D2CCIP2R / CDCCIP2R      USART16SEL     LL_RCC_GetUSARTClockSource\n
 *         D2CCIP2R / CDCCIP2R      USART28SEL     LL_RCC_GetUSARTClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_USART16_CLKSOURCE
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_USART16_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_USART234578_CLKSOURCE_LSE
 */
__STATIC_INLINE uint32_t LL_RCC_GetUSARTClockSource(uint32_t Periph) {
  return LL_RCC_GetClockSource(Periph);
}

/**
 * @brief  Get LPUART clock source
 * @rmtoll D3CCIPR / SRDCCIPR       LPUART1SEL     LL_RCC_GetLPUARTClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_LPUART1_CLKSOURCE_LSE
 */
__STATIC_INLINE uint32_t LL_RCC_GetLPUARTClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D3CCIPR_LPUART1SEL)
  return (uint32_t)(READ_BIT(RCC->D3CCIPR, RCC_D3CCIPR_LPUART1SEL));
#else
  return (uint32_t)(READ_BIT(RCC->SRDCCIPR, RCC_SRDCCIPR_LPUART1SEL));
#endif /* RCC_D3CCIPR_LPUART1SEL */
}

/**
 * @brief  Get I2Cx clock source
 * @rmtoll D2CCIP2R / CDCCIP2R     I2C123SEL       LL_RCC_GetI2CClockSource\n
 *         D3CCIPR  / SRDCCIPR     I2C4SEL         LL_RCC_GetI2CClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_I2C123_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_I2C4_CLKSOURCE_CSI
 */
__STATIC_INLINE uint32_t LL_RCC_GetI2CClockSource(uint32_t Periph) {
  return LL_RCC_GetClockSource(Periph);
}

/**
 * @brief  Get LPTIM clock source
 * @rmtoll D2CCIP2R / CDCCIP2R      LPTIM1SEL     LL_RCC_GetLPTIMClockSource\n
 *         D3CCIPR  / SRDCCIPR      LPTIM2SEL     LL_RCC_GetLPTIMClockSource\n
 *         D3CCIPR  / SRDCCIPR      LPTIM345SEL   LL_RCC_GetLPTIMClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM1_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM2_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_LPTIM345_CLKSOURCE_CLKP
 * @retval None
 */
__STATIC_INLINE uint32_t LL_RCC_GetLPTIMClockSource(uint32_t Periph) {
  return LL_RCC_GetClockSource(Periph);
}

/**
 * @brief  Get SAIx clock source
 * @rmtoll D2CCIP1R / CDCCIP1R     SAI1SEL       LL_RCC_GetSAIClockSource\n
 *         D2CCIP1R / CDCCIP1R     SAI23SEL      LL_RCC_GetSAIClockSource
 *         D3CCIPR  / SRDCCIPR     SAI4ASEL      LL_RCC_GetSAIClockSource\n
 *         D3CCIPR  / SRDCCIPR     SAI4BSEL      LL_RCC_GetSAIClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE    (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE  (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE  (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE   (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE   (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE   (*)
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_PLL3P
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_I2S_CKIN
 *         @arg @ref LL_RCC_SAI1_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI23_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI2A_CLKSOURCE_SPDIF (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI2B_CLKSOURCE_SPDIF (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI4A_CLKSOURCE_CLKP (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL1Q (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL2P (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_PLL3P (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_I2S_CKIN (*)
 *         @arg @ref LL_RCC_SAI4B_CLKSOURCE_CLKP (*)
 *
 *  (*) value not defined in all devices.
 */
__STATIC_INLINE uint32_t LL_RCC_GetSAIClockSource(uint32_t Periph) {
  return LL_RCC_GetClockSource(Periph);
}

/**
 * @brief  Get SDMMC clock source
 * @rmtoll D1CCIPR / CDCCIPR      SDMMCSEL      LL_RCC_GetSDMMCClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SDMMC_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SDMMC_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SDMMC_CLKSOURCE_PLL2R
 */
__STATIC_INLINE uint32_t LL_RCC_GetSDMMCClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D1CCIPR_SDMMCSEL)
  return (uint32_t)(READ_BIT(RCC->D1CCIPR, RCC_D1CCIPR_SDMMCSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIPR, RCC_CDCCIPR_SDMMCSEL));
#endif /* RCC_D1CCIPR_SDMMCSEL */
}

/**
 * @brief  Get RNG clock source
 * @rmtoll D2CCIP2R        RNGSEL      LL_RCC_GetRNGClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_RNG_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_RNG_CLKSOURCE_HSI48
 *         @arg @ref LL_RCC_RNG_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_RNG_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_RNG_CLKSOURCE_LSI
 */
__STATIC_INLINE uint32_t LL_RCC_GetRNGClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D2CCIP2R_RNGSEL)
  return (uint32_t)(READ_BIT(RCC->D2CCIP2R, RCC_D2CCIP2R_RNGSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIP2R, RCC_CDCCIP2R_RNGSEL));
#endif /* RCC_D2CCIP2R_RNGSEL */
}

/**
 * @brief  Get USB clock source
 * @rmtoll D2CCIP2R / CDCCIP2R      USBSEL      LL_RCC_GetUSBClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_USB_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_USB_CLKSOURCE_DISABLE
 *         @arg @ref LL_RCC_USB_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_USB_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_USB_CLKSOURCE_HSI48
 */
__STATIC_INLINE uint32_t LL_RCC_GetUSBClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D2CCIP2R_USBSEL)
  return (uint32_t)(READ_BIT(RCC->D2CCIP2R, RCC_D2CCIP2R_USBSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIP2R, RCC_CDCCIP2R_USBSEL));
#endif /* RCC_D2CCIP2R_USBSEL */
}

/**
 * @brief  Get CEC clock source
 * @rmtoll D2CCIP2R / CDCCIP2R        CECSEL        LL_RCC_GetCECClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_CEC_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_CEC_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_CEC_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_CEC_CLKSOURCE_CSI_DIV122
 */
__STATIC_INLINE uint32_t LL_RCC_GetCECClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D2CCIP2R_CECSEL)
  return (uint32_t)(READ_BIT(RCC->D2CCIP2R, RCC_D2CCIP2R_CECSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIP2R, RCC_CDCCIP2R_CECSEL));
#endif /* RCC_D2CCIP2R_CECSEL */
}

#if defined(DSI)
/**
 * @brief  Get DSI clock source
 * @rmtoll D1CCIPR         DSISEL        LL_RCC_GetDSIClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_DSI_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_DSI_CLKSOURCE_PHY
 *         @arg @ref LL_RCC_DSI_CLKSOURCE_PLL2Q
 */
__STATIC_INLINE uint32_t LL_RCC_GetDSIClockSource(uint32_t Periph) {
  UNUSED(Periph);
  return (uint32_t)(READ_BIT(RCC->D1CCIPR, RCC_D1CCIPR_DSISEL));
}
#endif /* DSI */

/**
 * @brief  Get DFSDM Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R         DFSDM1SEL LL_RCC_GetDFSDMClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_DFSDM1_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_DFSDM1_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_DFSDM1_CLKSOURCE_SYSCLK
 */
__STATIC_INLINE uint32_t LL_RCC_GetDFSDMClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D2CCIP1R_DFSDM1SEL)
  return (uint32_t)(READ_BIT(RCC->D2CCIP1R, RCC_D2CCIP1R_DFSDM1SEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIP1R, RCC_CDCCIP1R_DFSDM1SEL));
#endif /* RCC_D2CCIP1R_DFSDM1SEL */
}

#if defined(DFSDM2_BASE)
/**
 * @brief  Get DFSDM2 Kernel clock source
 * @rmtoll SRDCCIPR         DFSDM2SEL        LL_RCC_GetDFSDM2ClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_DFSDM2_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_DFSDM2_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_DFSDM2_CLKSOURCE_SYSCLK
 */
__STATIC_INLINE uint32_t LL_RCC_GetDFSDM2ClockSource(uint32_t Periph) {
  UNUSED(Periph);
  return (uint32_t)(READ_BIT(RCC->SRDCCIPR, RCC_SRDCCIPR_DFSDM2SEL));
}
#endif /* DFSDM2_BASE */

/**
 * @brief  Get FMC Kernel clock source
 * @rmtoll D1CCIPR / D1CCIPR         FMCSEL        LL_RCC_GetFMCClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_FMC_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_FMC_CLKSOURCE_HCLK
 *         @arg @ref LL_RCC_FMC_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_FMC_CLKSOURCE_PLL2R
 *         @arg @ref LL_RCC_FMC_CLKSOURCE_CLKP
 */
__STATIC_INLINE uint32_t LL_RCC_GetFMCClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D1CCIPR_FMCSEL)
  return (uint32_t)(READ_BIT(RCC->D1CCIPR, RCC_D1CCIPR_FMCSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIPR, RCC_CDCCIPR_FMCSEL));
#endif /* RCC_D1CCIPR_FMCSEL */
}

#if defined(QUADSPI)
/**
 * @brief  Get QSPI Kernel clock source
 * @rmtoll D1CCIPR  /  CDCCIPR      QSPISEL        LL_RCC_GetQSPIClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE_HCLK
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE_PLL2R
 *         @arg @ref LL_RCC_QSPI_CLKSOURCE_CLKP
 */
__STATIC_INLINE uint32_t LL_RCC_GetQSPIClockSource(uint32_t Periph) {
  UNUSED(Periph);
  return (uint32_t)(READ_BIT(RCC->D1CCIPR, RCC_D1CCIPR_QSPISEL));
}
#endif /* QUADSPI */

#if defined(OCTOSPI1) || defined(OCTOSPI2)
/**
 * @brief  Get OSPI Kernel clock source
 * @rmtoll CDCCIPR      OSPISEL        LL_RCC_GetOSPIClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE_HCLK
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE_PLL2R
 *         @arg @ref LL_RCC_OSPI_CLKSOURCE_CLKP
 */
__STATIC_INLINE uint32_t LL_RCC_GetOSPIClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D1CCIPR_OCTOSPISEL)
  return (uint32_t)(READ_BIT(RCC->D1CCIPR, RCC_D1CCIPR_OCTOSPISEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIPR, RCC_CDCCIPR_OCTOSPISEL));
#endif /* RCC_D1CCIPR_OCTOSPISEL */
}
#endif /* defined(OCTOSPI1) || defined(OCTOSPI2) */

/**
 * @brief  Get CLKP Kernel clock source
 * @rmtoll D1CCIPR /  CDCCIPR       CKPERSEL        LL_RCC_GetCLKPClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_CLKP_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_CLKP_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_CLKP_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_CLKP_CLKSOURCE_HSE
 */
__STATIC_INLINE uint32_t LL_RCC_GetCLKPClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D1CCIPR_CKPERSEL)
  return (uint32_t)(READ_BIT(RCC->D1CCIPR, RCC_D1CCIPR_CKPERSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIPR, RCC_CDCCIPR_CKPERSEL));
#endif /* RCC_D1CCIPR_CKPERSEL */
}

/**
 * @brief  Get SPIx Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R     SPI123SEL       LL_RCC_GetSPIClockSource\n
 *         D2CCIP1R / CDCCIP1R     SPI45SEL        LL_RCC_GetSPIClockSource\n
 *         D3CCIPR  / SRDCCIPR     SPI6SEL         LL_RCC_GetSPIClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_PLL3P
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_I2S_CKIN
 *         @arg @ref LL_RCC_SPI123_CLKSOURCE_CLKP
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PCLK2
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SPI45_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PCLK4
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PLL2Q
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_PLL3Q
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_HSI
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_CSI
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_SPI6_CLKSOURCE_I2S_CKIN (*)
 *
 *         (*) value not defined in all stm32h7xx lines.
 */
__STATIC_INLINE uint32_t LL_RCC_GetSPIClockSource(uint32_t Periph) {
  return LL_RCC_GetClockSource(Periph);
}

/**
 * @brief  Get SPDIF Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R      SPDIFSEL        LL_RCC_GetSPDIFClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE_PLL2R
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_SPDIF_CLKSOURCE_HSI
 */
__STATIC_INLINE uint32_t LL_RCC_GetSPDIFClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D2CCIP1R_SPDIFSEL)
  return (uint32_t)(READ_BIT(RCC->D2CCIP1R, RCC_D2CCIP1R_SPDIFSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIP1R, RCC_CDCCIP1R_SPDIFSEL));
#endif /* RCC_D2CCIP1R_SPDIFSEL */
}

/**
 * @brief  Get FDCAN Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R       FDCANSEL        LL_RCC_GetFDCANClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_FDCAN_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_FDCAN_CLKSOURCE_HSE
 *         @arg @ref LL_RCC_FDCAN_CLKSOURCE_PLL1Q
 *         @arg @ref LL_RCC_FDCAN_CLKSOURCE_PLL2Q
 */
__STATIC_INLINE uint32_t LL_RCC_GetFDCANClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D2CCIP1R_FDCANSEL)
  return (uint32_t)(READ_BIT(RCC->D2CCIP1R, RCC_D2CCIP1R_FDCANSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIP1R, RCC_CDCCIP1R_FDCANSEL));
#endif /* RCC_D2CCIP1R_FDCANSEL */
}

/**
 * @brief  Get SWP Kernel clock source
 * @rmtoll D2CCIP1R / CDCCIP1R       SWPSEL        LL_RCC_GetSWPClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_SWP_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_SWP_CLKSOURCE_PCLK1
 *         @arg @ref LL_RCC_SWP_CLKSOURCE_HSI
 */
__STATIC_INLINE uint32_t LL_RCC_GetSWPClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D2CCIP1R_SWPSEL)
  return (uint32_t)(READ_BIT(RCC->D2CCIP1R, RCC_D2CCIP1R_SWPSEL));
#else
  return (uint32_t)(READ_BIT(RCC->CDCCIP1R, RCC_CDCCIP1R_SWPSEL));
#endif /* RCC_D2CCIP1R_SWPSEL */
}

/**
 * @brief  Get ADC Kernel clock source
 * @rmtoll D3CCIPR / SRDCCIPR       ADCSEL        LL_RCC_GetADCClockSource
 * @param  Periph This parameter can be one of the following values:
 *         @arg @ref LL_RCC_ADC_CLKSOURCE
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_ADC_CLKSOURCE_PLL2P
 *         @arg @ref LL_RCC_ADC_CLKSOURCE_PLL3R
 *         @arg @ref LL_RCC_ADC_CLKSOURCE_CLKP
 */
__STATIC_INLINE uint32_t LL_RCC_GetADCClockSource(uint32_t Periph) {
  UNUSED(Periph);
#if defined(RCC_D3CCIPR_ADCSEL)
  return (uint32_t)(READ_BIT(RCC->D3CCIPR, RCC_D3CCIPR_ADCSEL));
#else
  return (uint32_t)(READ_BIT(RCC->SRDCCIPR, RCC_SRDCCIPR_ADCSEL));
#endif /* RCC_D3CCIPR_ADCSEL */
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_RTC RTC
 * @{
 */

/**
 * @brief  Set RTC Clock Source
 * @note   Once the RTC clock source has been selected, it cannot be changed
 * anymore unless the Backup domain is reset, or unless a failure is detected on
 * LSE (LSECSSD is set). The BDRST bit can be used to reset them.
 * @rmtoll BDCR         RTCSEL        LL_RCC_SetRTCClockSource
 * @param  Source This parameter can be one of the following values:
 *         @arg @ref LL_RCC_RTC_CLKSOURCE_NONE
 *         @arg @ref LL_RCC_RTC_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_RTC_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_RTC_CLKSOURCE_HSE
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetRTCClockSource(uint32_t Source) {
  MODIFY_REG(RCC->BDCR, RCC_BDCR_RTCSEL, Source);
}

/**
 * @brief  Get RTC Clock Source
 * @rmtoll BDCR         RTCSEL        LL_RCC_GetRTCClockSource
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_RTC_CLKSOURCE_NONE
 *         @arg @ref LL_RCC_RTC_CLKSOURCE_LSE
 *         @arg @ref LL_RCC_RTC_CLKSOURCE_LSI
 *         @arg @ref LL_RCC_RTC_CLKSOURCE_HSE
 */
__STATIC_INLINE uint32_t LL_RCC_GetRTCClockSource(void) {
  return (uint32_t)(READ_BIT(RCC->BDCR, RCC_BDCR_RTCSEL));
}

/**
 * @brief  Enable RTC
 * @rmtoll BDCR         RTCEN         LL_RCC_EnableRTC
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableRTC(void) {
  SET_BIT(RCC->BDCR, RCC_BDCR_RTCEN);
}

/**
 * @brief  Disable RTC
 * @rmtoll BDCR         RTCEN         LL_RCC_DisableRTC
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableRTC(void) {
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_RTCEN);
}

/**
 * @brief  Check if RTC has been enabled or not
 * @rmtoll BDCR         RTCEN         LL_RCC_IsEnabledRTC
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnabledRTC(void) {
  return ((READ_BIT(RCC->BDCR, RCC_BDCR_RTCEN) == (RCC_BDCR_RTCEN)) ? 1UL
                                                                    : 0UL);
}

/**
 * @brief  Force the Backup domain reset
 * @rmtoll BDCR         BDRST / VSWRST         LL_RCC_ForceBackupDomainReset
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ForceBackupDomainReset(void) {
  SET_BIT(RCC->BDCR, RCC_BDCR_BDRST);
}

/**
 * @brief  Release the Backup domain reset
 * @rmtoll BDCR         BDRST / VSWRST          LL_RCC_ReleaseBackupDomainReset
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ReleaseBackupDomainReset(void) {
#if defined(RCC_BDCR_BDRST)
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_BDRST);
#else
  CLEAR_BIT(RCC->BDCR, RCC_BDCR_VSWRST);
#endif /* RCC_BDCR_BDRST */
}

/**
 * @brief  Set HSE Prescalers for RTC Clock
 * @rmtoll CFGR         RTCPRE        LL_RCC_SetRTC_HSEPrescaler
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_RTC_NOCLOCK
 *         @arg @ref LL_RCC_RTC_HSE_DIV_2
 *         @arg @ref LL_RCC_RTC_HSE_DIV_3
 *         @arg @ref LL_RCC_RTC_HSE_DIV_4
 *         @arg @ref LL_RCC_RTC_HSE_DIV_5
 *         @arg @ref LL_RCC_RTC_HSE_DIV_6
 *         @arg @ref LL_RCC_RTC_HSE_DIV_7
 *         @arg @ref LL_RCC_RTC_HSE_DIV_8
 *         @arg @ref LL_RCC_RTC_HSE_DIV_9
 *         @arg @ref LL_RCC_RTC_HSE_DIV_10
 *         @arg @ref LL_RCC_RTC_HSE_DIV_11
 *         @arg @ref LL_RCC_RTC_HSE_DIV_12
 *         @arg @ref LL_RCC_RTC_HSE_DIV_13
 *         @arg @ref LL_RCC_RTC_HSE_DIV_14
 *         @arg @ref LL_RCC_RTC_HSE_DIV_15
 *         @arg @ref LL_RCC_RTC_HSE_DIV_16
 *         @arg @ref LL_RCC_RTC_HSE_DIV_17
 *         @arg @ref LL_RCC_RTC_HSE_DIV_18
 *         @arg @ref LL_RCC_RTC_HSE_DIV_19
 *         @arg @ref LL_RCC_RTC_HSE_DIV_20
 *         @arg @ref LL_RCC_RTC_HSE_DIV_21
 *         @arg @ref LL_RCC_RTC_HSE_DIV_22
 *         @arg @ref LL_RCC_RTC_HSE_DIV_23
 *         @arg @ref LL_RCC_RTC_HSE_DIV_24
 *         @arg @ref LL_RCC_RTC_HSE_DIV_25
 *         @arg @ref LL_RCC_RTC_HSE_DIV_26
 *         @arg @ref LL_RCC_RTC_HSE_DIV_27
 *         @arg @ref LL_RCC_RTC_HSE_DIV_28
 *         @arg @ref LL_RCC_RTC_HSE_DIV_29
 *         @arg @ref LL_RCC_RTC_HSE_DIV_30
 *         @arg @ref LL_RCC_RTC_HSE_DIV_31
 *         @arg @ref LL_RCC_RTC_HSE_DIV_32
 *         @arg @ref LL_RCC_RTC_HSE_DIV_33
 *         @arg @ref LL_RCC_RTC_HSE_DIV_34
 *         @arg @ref LL_RCC_RTC_HSE_DIV_35
 *         @arg @ref LL_RCC_RTC_HSE_DIV_36
 *         @arg @ref LL_RCC_RTC_HSE_DIV_37
 *         @arg @ref LL_RCC_RTC_HSE_DIV_38
 *         @arg @ref LL_RCC_RTC_HSE_DIV_39
 *         @arg @ref LL_RCC_RTC_HSE_DIV_40
 *         @arg @ref LL_RCC_RTC_HSE_DIV_41
 *         @arg @ref LL_RCC_RTC_HSE_DIV_42
 *         @arg @ref LL_RCC_RTC_HSE_DIV_43
 *         @arg @ref LL_RCC_RTC_HSE_DIV_44
 *         @arg @ref LL_RCC_RTC_HSE_DIV_45
 *         @arg @ref LL_RCC_RTC_HSE_DIV_46
 *         @arg @ref LL_RCC_RTC_HSE_DIV_47
 *         @arg @ref LL_RCC_RTC_HSE_DIV_48
 *         @arg @ref LL_RCC_RTC_HSE_DIV_49
 *         @arg @ref LL_RCC_RTC_HSE_DIV_50
 *         @arg @ref LL_RCC_RTC_HSE_DIV_51
 *         @arg @ref LL_RCC_RTC_HSE_DIV_52
 *         @arg @ref LL_RCC_RTC_HSE_DIV_53
 *         @arg @ref LL_RCC_RTC_HSE_DIV_54
 *         @arg @ref LL_RCC_RTC_HSE_DIV_55
 *         @arg @ref LL_RCC_RTC_HSE_DIV_56
 *         @arg @ref LL_RCC_RTC_HSE_DIV_57
 *         @arg @ref LL_RCC_RTC_HSE_DIV_58
 *         @arg @ref LL_RCC_RTC_HSE_DIV_59
 *         @arg @ref LL_RCC_RTC_HSE_DIV_60
 *         @arg @ref LL_RCC_RTC_HSE_DIV_61
 *         @arg @ref LL_RCC_RTC_HSE_DIV_62
 *         @arg @ref LL_RCC_RTC_HSE_DIV_63
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetRTC_HSEPrescaler(uint32_t Prescaler) {
  MODIFY_REG(RCC->CFGR, RCC_CFGR_RTCPRE, Prescaler);
}

/**
 * @brief  Get HSE Prescalers for RTC Clock
 * @rmtoll CFGR         RTCPRE        LL_RCC_GetRTC_HSEPrescaler
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_RTC_NOCLOCK
 *         @arg @ref LL_RCC_RTC_HSE_DIV_2
 *         @arg @ref LL_RCC_RTC_HSE_DIV_3
 *         @arg @ref LL_RCC_RTC_HSE_DIV_4
 *         @arg @ref LL_RCC_RTC_HSE_DIV_5
 *         @arg @ref LL_RCC_RTC_HSE_DIV_6
 *         @arg @ref LL_RCC_RTC_HSE_DIV_7
 *         @arg @ref LL_RCC_RTC_HSE_DIV_8
 *         @arg @ref LL_RCC_RTC_HSE_DIV_9
 *         @arg @ref LL_RCC_RTC_HSE_DIV_10
 *         @arg @ref LL_RCC_RTC_HSE_DIV_11
 *         @arg @ref LL_RCC_RTC_HSE_DIV_12
 *         @arg @ref LL_RCC_RTC_HSE_DIV_13
 *         @arg @ref LL_RCC_RTC_HSE_DIV_14
 *         @arg @ref LL_RCC_RTC_HSE_DIV_15
 *         @arg @ref LL_RCC_RTC_HSE_DIV_16
 *         @arg @ref LL_RCC_RTC_HSE_DIV_17
 *         @arg @ref LL_RCC_RTC_HSE_DIV_18
 *         @arg @ref LL_RCC_RTC_HSE_DIV_19
 *         @arg @ref LL_RCC_RTC_HSE_DIV_20
 *         @arg @ref LL_RCC_RTC_HSE_DIV_21
 *         @arg @ref LL_RCC_RTC_HSE_DIV_22
 *         @arg @ref LL_RCC_RTC_HSE_DIV_23
 *         @arg @ref LL_RCC_RTC_HSE_DIV_24
 *         @arg @ref LL_RCC_RTC_HSE_DIV_25
 *         @arg @ref LL_RCC_RTC_HSE_DIV_26
 *         @arg @ref LL_RCC_RTC_HSE_DIV_27
 *         @arg @ref LL_RCC_RTC_HSE_DIV_28
 *         @arg @ref LL_RCC_RTC_HSE_DIV_29
 *         @arg @ref LL_RCC_RTC_HSE_DIV_30
 *         @arg @ref LL_RCC_RTC_HSE_DIV_31
 *         @arg @ref LL_RCC_RTC_HSE_DIV_32
 *         @arg @ref LL_RCC_RTC_HSE_DIV_33
 *         @arg @ref LL_RCC_RTC_HSE_DIV_34
 *         @arg @ref LL_RCC_RTC_HSE_DIV_35
 *         @arg @ref LL_RCC_RTC_HSE_DIV_36
 *         @arg @ref LL_RCC_RTC_HSE_DIV_37
 *         @arg @ref LL_RCC_RTC_HSE_DIV_38
 *         @arg @ref LL_RCC_RTC_HSE_DIV_39
 *         @arg @ref LL_RCC_RTC_HSE_DIV_40
 *         @arg @ref LL_RCC_RTC_HSE_DIV_41
 *         @arg @ref LL_RCC_RTC_HSE_DIV_42
 *         @arg @ref LL_RCC_RTC_HSE_DIV_43
 *         @arg @ref LL_RCC_RTC_HSE_DIV_44
 *         @arg @ref LL_RCC_RTC_HSE_DIV_45
 *         @arg @ref LL_RCC_RTC_HSE_DIV_46
 *         @arg @ref LL_RCC_RTC_HSE_DIV_47
 *         @arg @ref LL_RCC_RTC_HSE_DIV_48
 *         @arg @ref LL_RCC_RTC_HSE_DIV_49
 *         @arg @ref LL_RCC_RTC_HSE_DIV_50
 *         @arg @ref LL_RCC_RTC_HSE_DIV_51
 *         @arg @ref LL_RCC_RTC_HSE_DIV_52
 *         @arg @ref LL_RCC_RTC_HSE_DIV_53
 *         @arg @ref LL_RCC_RTC_HSE_DIV_54
 *         @arg @ref LL_RCC_RTC_HSE_DIV_55
 *         @arg @ref LL_RCC_RTC_HSE_DIV_56
 *         @arg @ref LL_RCC_RTC_HSE_DIV_57
 *         @arg @ref LL_RCC_RTC_HSE_DIV_58
 *         @arg @ref LL_RCC_RTC_HSE_DIV_59
 *         @arg @ref LL_RCC_RTC_HSE_DIV_60
 *         @arg @ref LL_RCC_RTC_HSE_DIV_61
 *         @arg @ref LL_RCC_RTC_HSE_DIV_62
 *         @arg @ref LL_RCC_RTC_HSE_DIV_63
 */
__STATIC_INLINE uint32_t LL_RCC_GetRTC_HSEPrescaler(void) {
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_RTCPRE));
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_TIM_CLOCK_PRESCALER TIM
 * @{
 */

/**
 * @brief  Set Timers Clock Prescalers
 * @rmtoll CFGR         TIMPRE        LL_RCC_SetTIMPrescaler
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_TIM_PRESCALER_TWICE
 *         @arg @ref LL_RCC_TIM_PRESCALER_FOUR_TIMES
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetTIMPrescaler(uint32_t Prescaler) {
  MODIFY_REG(RCC->CFGR, RCC_CFGR_TIMPRE, Prescaler);
}

/**
 * @brief  Get Timers Clock Prescalers
 * @rmtoll CFGR         TIMPRE        LL_RCC_GetTIMPrescaler
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_TIM_PRESCALER_TWICE
 *         @arg @ref LL_RCC_TIM_PRESCALER_FOUR_TIMES
 */
__STATIC_INLINE uint32_t LL_RCC_GetTIMPrescaler(void) {
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_TIMPRE));
}

/**
 * @}
 */

#if defined(HRTIM1)
/** @defgroup RCC_LL_EF_HRTIM_SET_CLOCK_SOURCE HRTIM
 * @{
 */

/**
 * @brief  Set High Resolution Timers Clock Source
 * @rmtoll CFGR         HRTIMSEL        LL_RCC_SetHRTIMClockSource
 * @param  Prescaler This parameter can be one of the following values:
 *         @arg @ref LL_RCC_HRTIM_CLKSOURCE_TIM
 *         @arg @ref LL_RCC_HRTIM_CLKSOURCE_CPU
 * @retval None
 */
__STATIC_INLINE void LL_RCC_SetHRTIMClockSource(uint32_t Prescaler) {
  MODIFY_REG(RCC->CFGR, RCC_CFGR_HRTIMSEL, Prescaler);
}
#endif /* HRTIM1 */

#if defined(HRTIM1)
/**
 * @brief  Get High Resolution Timers Clock Source
 * @rmtoll CFGR         HRTIMSEL        LL_RCC_GetHRTIMClockSource
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_HRTIM_CLKSOURCE_TIM
 *         @arg @ref LL_RCC_HRTIM_CLKSOURCE_CPU
 */
__STATIC_INLINE uint32_t LL_RCC_GetHRTIMClockSource(void) {
  return (uint32_t)(READ_BIT(RCC->CFGR, RCC_CFGR_HRTIMSEL));
}
/**
 * @}
 */
#endif /* HRTIM1 */

/** @defgroup RCC_LL_EF_PLL PLL
 * @{
 */

/**
 * @brief  Set the oscillator used as PLL clock source.
 * @note   PLLSRC can be written only when All PLLs are disabled.
 * @rmtoll PLLCKSELR      PLLSRC        LL_RCC_PLL_SetSource
 * @param  PLLSource parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLLSOURCE_HSI
 *         @arg @ref LL_RCC_PLLSOURCE_CSI
 *         @arg @ref LL_RCC_PLLSOURCE_HSE
 *         @arg @ref LL_RCC_PLLSOURCE_NONE
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL_SetSource(uint32_t PLLSource) {
  MODIFY_REG(RCC->PLLCKSELR, RCC_PLLCKSELR_PLLSRC, PLLSource);
}

/**
 * @brief  Get the oscillator used as PLL clock source.
 * @rmtoll PLLCKSELR      PLLSRC        LL_RCC_PLL_GetSource
 * @retval Returned value can be one of the following values:
 *         @arg @ref LL_RCC_PLLSOURCE_HSI
 *         @arg @ref LL_RCC_PLLSOURCE_CSI
 *         @arg @ref LL_RCC_PLLSOURCE_HSE
 *         @arg @ref LL_RCC_PLLSOURCE_NONE
 */
__STATIC_INLINE uint32_t LL_RCC_PLL_GetSource(void) {
  return (uint32_t)(READ_BIT(RCC->PLLCKSELR, RCC_PLLCKSELR_PLLSRC));
}

/**
 * @brief  Enable PLL1
 * @rmtoll CR           PLL1ON         LL_RCC_PLL1_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1_Enable(void) {
  SET_BIT(RCC->CR, RCC_CR_PLL1ON);
}

/**
 * @brief  Disable PLL1
 * @note Cannot be disabled if the PLL1 clock is used as the system clock
 * @rmtoll CR           PLL1ON         LL_RCC_PLL1_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1_Disable(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_PLL1ON);
}

/**
 * @brief  Check if PLL1 Ready
 * @rmtoll CR           PLL1RDY        LL_RCC_PLL1_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_PLL1RDY) == (RCC_CR_PLL1RDY)) ? 1UL : 0UL);
}

/**
 * @brief  Enable PLL1P
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCFGR           DIVP1EN         LL_RCC_PLL1P_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1P_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP1EN);
}

/**
 * @brief  Enable PLL1Q
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCFGR           DIVQ1EN         LL_RCC_PLL1Q_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1Q_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ1EN);
}

/**
 * @brief  Enable PLL1R
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCFGR           DIVR1EN         LL_RCC_PLL1R_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1R_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR1EN);
}

/**
 * @brief  Enable PLL1 FRACN
 * @rmtoll PLLCFGR           PLL1FRACEN         LL_RCC_PLL1FRACN_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1FRACN_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL1FRACEN);
}

/**
 * @brief  Check if PLL1 P is enabled
 * @rmtoll PLLCFGR           DIVP1EN         LL_RCC_PLL1P_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1P_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP1EN) == RCC_PLLCFGR_DIVP1EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL1 Q is enabled
 * @rmtoll PLLCFGR           DIVQ1EN         LL_RCC_PLL1Q_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1Q_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ1EN) == RCC_PLLCFGR_DIVQ1EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL1 R is enabled
 * @rmtoll PLLCFGR           DIVR1EN         LL_RCC_PLL1R_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1R_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR1EN) == RCC_PLLCFGR_DIVR1EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL1 FRACN is enabled
 * @rmtoll PLLCFGR           PLL1FRACEN         LL_RCC_PLL1FRACN_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1FRACN_IsEnabled(void) {
  return (
      (READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL1FRACEN) == RCC_PLLCFGR_PLL1FRACEN)
          ? 1UL
          : 0UL);
}

/**
 * @brief  Disable PLL1P
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCFGR           DIVP1EN         LL_RCC_PLL1P_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1P_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP1EN);
}

/**
 * @brief  Disable PLL1Q
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCFGR           DIVQ1EN         LL_RCC_PLL1Q_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1Q_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ1EN);
}

/**
 * @brief  Disable PLL1R
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCFGR           DIVR1EN         LL_RCC_PLL1R_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1R_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR1EN);
}

/**
 * @brief  Disable PLL1 FRACN
 * @rmtoll PLLCFGR           PLL1FRACEN         LL_RCC_PLL1FRACN_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1FRACN_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL1FRACEN);
}

/**
 * @brief  Set PLL1 VCO OutputRange
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCFGR        PLL1VCOSEL       LL_RCC_PLL1_SetVCOOuputRange
 * @param  VCORange This parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLLVCORANGE_WIDE
 *         @arg @ref LL_RCC_PLLVCORANGE_MEDIUM
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1_SetVCOOutputRange(uint32_t VCORange) {
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL1VCOSEL,
             VCORange << RCC_PLLCFGR_PLL1VCOSEL_Pos);
}

/**
 * @brief  Set PLL1 VCO Input Range
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCFGR        PLL1RGE       LL_RCC_PLL1_SetVCOInputRange
 * @param  InputRange This parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLLINPUTRANGE_1_2
 *         @arg @ref LL_RCC_PLLINPUTRANGE_2_4
 *         @arg @ref LL_RCC_PLLINPUTRANGE_4_8
 *         @arg @ref LL_RCC_PLLINPUTRANGE_8_16
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL1_SetVCOInputRange(uint32_t InputRange) {
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL1RGE,
             InputRange << RCC_PLLCFGR_PLL1RGE_Pos);
}

/**
 * @brief  Get PLL1 N Coefficient
 * @rmtoll PLL1DIVR        N1          LL_RCC_PLL1_GetN
 * @retval A value between 4 and 512
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1_GetN(void) {
  return (uint32_t)((READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_N1) >>
                     RCC_PLL1DIVR_N1_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL1 M Coefficient
 * @rmtoll PLLCKSELR       DIVM1          LL_RCC_PLL1_GetM
 * @retval A value between 0 and 63
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1_GetM(void) {
  return (uint32_t)(READ_BIT(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM1) >>
                    RCC_PLLCKSELR_DIVM1_Pos);
}

/**
 * @brief  Get PLL1 P Coefficient
 * @rmtoll PLL1DIVR        P1          LL_RCC_PLL1_GetP
 * @retval A value between 2 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1_GetP(void) {
  return (uint32_t)((READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_P1) >>
                     RCC_PLL1DIVR_P1_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL1 Q Coefficient
 * @rmtoll PLL1DIVR        Q1          LL_RCC_PLL1_GetQ
 * @retval A value between 1 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1_GetQ(void) {
  return (uint32_t)((READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_Q1) >>
                     RCC_PLL1DIVR_Q1_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL1 R Coefficient
 * @rmtoll PLL1DIVR        R1          LL_RCC_PLL1_GetR
 * @retval A value between 1 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1_GetR(void) {
  return (uint32_t)((READ_BIT(RCC->PLL1DIVR, RCC_PLL1DIVR_R1) >>
                     RCC_PLL1DIVR_R1_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL1 FRACN Coefficient
 * @rmtoll PLL1FRACR      FRACN1          LL_RCC_PLL1_GetFRACN
 * @retval A value between 0 and 8191 (0x1FFF)
 */
__STATIC_INLINE uint32_t LL_RCC_PLL1_GetFRACN(void) {
  return (uint32_t)(READ_BIT(RCC->PLL1FRACR, RCC_PLL1FRACR_FRACN1) >>
                    RCC_PLL1FRACR_FRACN1_Pos);
}

/**
 * @brief  Set PLL1 N Coefficient
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLL1DIVR        N1          LL_RCC_PLL1_SetN
 * @param  N parameter can be a value between 4 and 512
 */
__STATIC_INLINE void LL_RCC_PLL1_SetN(uint32_t N) {
  MODIFY_REG(RCC->PLL1DIVR, RCC_PLL1DIVR_N1, (N - 1UL) << RCC_PLL1DIVR_N1_Pos);
}

/**
 * @brief  Set PLL1 M Coefficient
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLLCKSELR       DIVM1          LL_RCC_PLL1_SetM
 * @param  M parameter can be a value between 0 and 63
 */
__STATIC_INLINE void LL_RCC_PLL1_SetM(uint32_t M) {
  MODIFY_REG(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM1, M << RCC_PLLCKSELR_DIVM1_Pos);
}

/**
 * @brief  Set PLL1 P Coefficient
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLL1DIVR        P1          LL_RCC_PLL1_SetP
 * @param  P parameter can be a value between 2 (or 1*) and 128 (ODD division
 * factor not supported)
 *
 * (*) : For stm32h72xxx and stm32h73xxx family lines.
 */
__STATIC_INLINE void LL_RCC_PLL1_SetP(uint32_t P) {
  MODIFY_REG(RCC->PLL1DIVR, RCC_PLL1DIVR_P1, (P - 1UL) << RCC_PLL1DIVR_P1_Pos);
}

/**
 * @brief  Set PLL1 Q Coefficient
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLL1DIVR        Q1          LL_RCC_PLL1_SetQ
 * @param  Q parameter can be a value between 1 and 128
 */
__STATIC_INLINE void LL_RCC_PLL1_SetQ(uint32_t Q) {
  MODIFY_REG(RCC->PLL1DIVR, RCC_PLL1DIVR_Q1, (Q - 1UL) << RCC_PLL1DIVR_Q1_Pos);
}

/**
 * @brief  Set PLL1 R Coefficient
 * @note   This API shall be called only when PLL1 is disabled.
 * @rmtoll PLL1DIVR        R1          LL_RCC_PLL1_SetR
 * @param  R parameter can be a value between 1 and 128
 */
__STATIC_INLINE void LL_RCC_PLL1_SetR(uint32_t R) {
  MODIFY_REG(RCC->PLL1DIVR, RCC_PLL1DIVR_R1, (R - 1UL) << RCC_PLL1DIVR_R1_Pos);
}

/**
 * @brief  Set PLL1 FRACN Coefficient
 * @rmtoll PLL1FRACR        FRACN1          LL_RCC_PLL1_SetFRACN
 * @param  FRACN parameter can be a value between 0 and 8191 (0x1FFF)
 */
__STATIC_INLINE void LL_RCC_PLL1_SetFRACN(uint32_t FRACN) {
  MODIFY_REG(RCC->PLL1FRACR, RCC_PLL1FRACR_FRACN1,
             FRACN << RCC_PLL1FRACR_FRACN1_Pos);
}

/**
 * @brief  Enable PLL2
 * @rmtoll CR           PLL2ON         LL_RCC_PLL2_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2_Enable(void) {
  SET_BIT(RCC->CR, RCC_CR_PLL2ON);
}

/**
 * @brief  Disable PLL2
 * @note Cannot be disabled if the PLL2 clock is used as the system clock
 * @rmtoll CR           PLL2ON         LL_RCC_PLL2_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2_Disable(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_PLL2ON);
}

/**
 * @brief  Check if PLL2 Ready
 * @rmtoll CR           PLL2RDY        LL_RCC_PLL2_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_PLL2RDY) == (RCC_CR_PLL2RDY)) ? 1UL : 0UL);
}

/**
 * @brief  Enable PLL2P
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCFGR           DIVP2EN         LL_RCC_PLL2P_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2P_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP2EN);
}

/**
 * @brief  Enable PLL2Q
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCFGR           DIVQ2EN         LL_RCC_PLL2Q_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2Q_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ2EN);
}

/**
 * @brief  Enable PLL2R
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCFGR           DIVR2EN         LL_RCC_PLL2R_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2R_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR2EN);
}

/**
 * @brief  Enable PLL2 FRACN
 * @rmtoll PLLCFGR           PLL2FRACEN         LL_RCC_PLL2FRACN_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2FRACN_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL2FRACEN);
}

/**
 * @brief  Check if PLL2 P is enabled
 * @rmtoll PLLCFGR           DIVP2EN         LL_RCC_PLL2P_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2P_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP2EN) == RCC_PLLCFGR_DIVP2EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL2 Q is enabled
 * @rmtoll PLLCFGR           DIVQ2EN         LL_RCC_PLL2Q_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2Q_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ2EN) == RCC_PLLCFGR_DIVQ2EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL2 R is enabled
 * @rmtoll PLLCFGR           DIVR2EN         LL_RCC_PLL2R_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2R_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR2EN) == RCC_PLLCFGR_DIVR2EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL2 FRACN is enabled
 * @rmtoll PLLCFGR           PLL2FRACEN         LL_RCC_PLL2FRACN_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2FRACN_IsEnabled(void) {
  return (
      (READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL2FRACEN) == RCC_PLLCFGR_PLL2FRACEN)
          ? 1UL
          : 0UL);
}

/**
 * @brief  Disable PLL2P
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCFGR           DIVP2EN         LL_RCC_PLL2P_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2P_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP2EN);
}

/**
 * @brief  Disable PLL2Q
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCFGR           DIVQ2EN         LL_RCC_PLL2Q_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2Q_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ2EN);
}

/**
 * @brief  Disable PLL2R
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCFGR           DIVR2EN         LL_RCC_PLL2R_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2R_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR2EN);
}

/**
 * @brief  Disable PLL2 FRACN
 * @rmtoll PLLCFGR           PLL2FRACEN         LL_RCC_PLL2FRACN_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2FRACN_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL2FRACEN);
}

/**
 * @brief  Set PLL2 VCO OutputRange
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCFGR        PLL2VCOSEL       LL_RCC_PLL2_SetVCOOuputRange
 * @param  VCORange This parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLLVCORANGE_WIDE
 *         @arg @ref LL_RCC_PLLVCORANGE_MEDIUM
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2_SetVCOOutputRange(uint32_t VCORange) {
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL2VCOSEL,
             VCORange << RCC_PLLCFGR_PLL2VCOSEL_Pos);
}

/**
 * @brief  Set PLL2 VCO Input Range
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCFGR        PLL2RGE       LL_RCC_PLL2_SetVCOInputRange
 * @param  InputRange This parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLLINPUTRANGE_1_2
 *         @arg @ref LL_RCC_PLLINPUTRANGE_2_4
 *         @arg @ref LL_RCC_PLLINPUTRANGE_4_8
 *         @arg @ref LL_RCC_PLLINPUTRANGE_8_16
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL2_SetVCOInputRange(uint32_t InputRange) {
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL2RGE,
             InputRange << RCC_PLLCFGR_PLL2RGE_Pos);
}

/**
 * @brief  Get PLL2 N Coefficient
 * @rmtoll PLL2DIVR        N2          LL_RCC_PLL2_GetN
 * @retval A value between 4 and 512
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2_GetN(void) {
  return (uint32_t)((READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_N2) >>
                     RCC_PLL2DIVR_N2_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL2 M Coefficient
 * @rmtoll PLLCKSELR       DIVM2          LL_RCC_PLL2_GetM
 * @retval A value between 0 and 63
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2_GetM(void) {
  return (uint32_t)(READ_BIT(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM2) >>
                    RCC_PLLCKSELR_DIVM2_Pos);
}

/**
 * @brief  Get PLL2 P Coefficient
 * @rmtoll PLL2DIVR        P2          LL_RCC_PLL2_GetP
 * @retval A value between 1 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2_GetP(void) {
  return (uint32_t)((READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_P2) >>
                     RCC_PLL2DIVR_P2_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL2 Q Coefficient
 * @rmtoll PLL2DIVR        Q2          LL_RCC_PLL2_GetQ
 * @retval A value between 1 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2_GetQ(void) {
  return (uint32_t)((READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_Q2) >>
                     RCC_PLL2DIVR_Q2_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL2 R Coefficient
 * @rmtoll PLL2DIVR        R2          LL_RCC_PLL2_GetR
 * @retval A value between 1 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2_GetR(void) {
  return (uint32_t)((READ_BIT(RCC->PLL2DIVR, RCC_PLL2DIVR_R2) >>
                     RCC_PLL2DIVR_R2_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL2 FRACN Coefficient
 * @rmtoll PLL2FRACR      FRACN2          LL_RCC_PLL2_GetFRACN
 * @retval A value between 0 and 8191 (0x1FFF)
 */
__STATIC_INLINE uint32_t LL_RCC_PLL2_GetFRACN(void) {
  return (uint32_t)(READ_BIT(RCC->PLL2FRACR, RCC_PLL2FRACR_FRACN2) >>
                    RCC_PLL2FRACR_FRACN2_Pos);
}

/**
 * @brief  Set PLL2 N Coefficient
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLL2DIVR        N2          LL_RCC_PLL2_SetN
 * @param  N parameter can be a value between 4 and 512
 */
__STATIC_INLINE void LL_RCC_PLL2_SetN(uint32_t N) {
  MODIFY_REG(RCC->PLL2DIVR, RCC_PLL2DIVR_N2, (N - 1UL) << RCC_PLL2DIVR_N2_Pos);
}

/**
 * @brief  Set PLL2 M Coefficient
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLLCKSELR       DIVM2          LL_RCC_PLL2_SetM
 * @param  M parameter can be a value between 0 and 63
 */
__STATIC_INLINE void LL_RCC_PLL2_SetM(uint32_t M) {
  MODIFY_REG(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM2, M << RCC_PLLCKSELR_DIVM2_Pos);
}

/**
 * @brief  Set PLL2 P Coefficient
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLL2DIVR        P2          LL_RCC_PLL2_SetP
 * @param  P parameter can be a value between 1 and 128
 */
__STATIC_INLINE void LL_RCC_PLL2_SetP(uint32_t P) {
  MODIFY_REG(RCC->PLL2DIVR, RCC_PLL2DIVR_P2, (P - 1UL) << RCC_PLL2DIVR_P2_Pos);
}

/**
 * @brief  Set PLL2 Q Coefficient
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLL2DIVR        Q2          LL_RCC_PLL2_SetQ
 * @param  Q parameter can be a value between 1 and 128
 */
__STATIC_INLINE void LL_RCC_PLL2_SetQ(uint32_t Q) {
  MODIFY_REG(RCC->PLL2DIVR, RCC_PLL2DIVR_Q2, (Q - 1UL) << RCC_PLL2DIVR_Q2_Pos);
}

/**
 * @brief  Set PLL2 R Coefficient
 * @note   This API shall be called only when PLL2 is disabled.
 * @rmtoll PLL2DIVR        R2          LL_RCC_PLL2_SetR
 * @param  R parameter can be a value between 1 and 128
 */
__STATIC_INLINE void LL_RCC_PLL2_SetR(uint32_t R) {
  MODIFY_REG(RCC->PLL2DIVR, RCC_PLL2DIVR_R2, (R - 1UL) << RCC_PLL2DIVR_R2_Pos);
}

/**
 * @brief  Set PLL2 FRACN Coefficient
 * @rmtoll PLL2FRACR        FRACN2          LL_RCC_PLL2_SetFRACN
 * @param  FRACN parameter can be a value between 0 and 8191 (0x1FFF)
 */
__STATIC_INLINE void LL_RCC_PLL2_SetFRACN(uint32_t FRACN) {
  MODIFY_REG(RCC->PLL2FRACR, RCC_PLL2FRACR_FRACN2,
             FRACN << RCC_PLL2FRACR_FRACN2_Pos);
}

/**
 * @brief  Enable PLL3
 * @rmtoll CR           PLL3ON         LL_RCC_PLL3_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3_Enable(void) {
  SET_BIT(RCC->CR, RCC_CR_PLL3ON);
}

/**
 * @brief  Disable PLL3
 * @note Cannot be disabled if the PLL3 clock is used as the system clock
 * @rmtoll CR           PLL3ON         LL_RCC_PLL3_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3_Disable(void) {
  CLEAR_BIT(RCC->CR, RCC_CR_PLL3ON);
}

/**
 * @brief  Check if PLL3 Ready
 * @rmtoll CR           PLL3RDY        LL_RCC_PLL3_IsReady
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3_IsReady(void) {
  return ((READ_BIT(RCC->CR, RCC_CR_PLL3RDY) == (RCC_CR_PLL3RDY)) ? 1UL : 0UL);
}

/**
 * @brief  Enable PLL3P
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCFGR           DIVP3EN         LL_RCC_PLL3P_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3P_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP3EN);
}

/**
 * @brief  Enable PLL3Q
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCFGR           DIVQ3EN         LL_RCC_PLL3Q_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3Q_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ3EN);
}

/**
 * @brief  Enable PLL3R
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCFGR           DIVR3EN         LL_RCC_PLL3R_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3R_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR3EN);
}

/**
 * @brief  Enable PLL3 FRACN
 * @rmtoll PLLCFGR           PLL3FRACEN         LL_RCC_PLL3FRACN_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3FRACN_Enable(void) {
  SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL3FRACEN);
}

/**
 * @brief  Check if PLL3 P is enabled
 * @rmtoll PLLCFGR           DIVP3EN         LL_RCC_PLL3P_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3P_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP3EN) == RCC_PLLCFGR_DIVP3EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL3 Q is enabled
 * @rmtoll PLLCFGR           DIVQ3EN         LL_RCC_PLL3Q_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3Q_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ3EN) == RCC_PLLCFGR_DIVQ3EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL3 R is enabled
 * @rmtoll PLLCFGR           DIVR3EN         LL_RCC_PLL3R_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3R_IsEnabled(void) {
  return ((READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR3EN) == RCC_PLLCFGR_DIVR3EN)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL3 FRACN is enabled
 * @rmtoll PLLCFGR           PLL3FRACEN         LL_RCC_PLL3FRACN_IsEnabled
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3FRACN_IsEnabled(void) {
  return (
      (READ_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL3FRACEN) == RCC_PLLCFGR_PLL3FRACEN)
          ? 1UL
          : 0UL);
}

/**
 * @brief  Disable PLL3P
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCFGR           DIVP2EN         LL_RCC_PLL3P_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3P_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVP3EN);
}

/**
 * @brief  Disable PLL3Q
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCFGR           DIVQ3EN         LL_RCC_PLL3Q_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3Q_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVQ3EN);
}

/**
 * @brief  Disable PLL3R
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCFGR           DIVR3EN         LL_RCC_PLL3R_Disable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3R_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_DIVR3EN);
}

/**
 * @brief  Disable PLL3 FRACN
 * @rmtoll PLLCFGR           PLL3FRACEN         LL_RCC_PLL3FRACN_Enable
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3FRACN_Disable(void) {
  CLEAR_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLL3FRACEN);
}

/**
 * @brief  Set PLL3 VCO OutputRange
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCFGR        PLL3VCOSEL       LL_RCC_PLL3_SetVCOOuputRange
 * @param  VCORange This parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLLVCORANGE_WIDE
 *         @arg @ref LL_RCC_PLLVCORANGE_MEDIUM
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3_SetVCOOutputRange(uint32_t VCORange) {
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL3VCOSEL,
             VCORange << RCC_PLLCFGR_PLL3VCOSEL_Pos);
}

/**
 * @brief  Set PLL3 VCO Input Range
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCFGR        PLL3RGE       LL_RCC_PLL3_SetVCOInputRange
 * @param  InputRange This parameter can be one of the following values:
 *         @arg @ref LL_RCC_PLLINPUTRANGE_1_2
 *         @arg @ref LL_RCC_PLLINPUTRANGE_2_4
 *         @arg @ref LL_RCC_PLLINPUTRANGE_4_8
 *         @arg @ref LL_RCC_PLLINPUTRANGE_8_16
 * @retval None
 */
__STATIC_INLINE void LL_RCC_PLL3_SetVCOInputRange(uint32_t InputRange) {
  MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLL3RGE,
             InputRange << RCC_PLLCFGR_PLL3RGE_Pos);
}

/**
 * @brief  Get PLL3 N Coefficient
 * @rmtoll PLL3DIVR        N3          LL_RCC_PLL3_GetN
 * @retval A value between 4 and 512
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3_GetN(void) {
  return (uint32_t)((READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_N3) >>
                     RCC_PLL3DIVR_N3_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL3 M Coefficient
 * @rmtoll PLLCKSELR       DIVM3          LL_RCC_PLL3_GetM
 * @retval A value between 0 and 63
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3_GetM(void) {
  return (uint32_t)(READ_BIT(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM3) >>
                    RCC_PLLCKSELR_DIVM3_Pos);
}

/**
 * @brief  Get PLL3 P Coefficient
 * @rmtoll PLL3DIVR        P3          LL_RCC_PLL3_GetP
 * @retval A value between 1 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3_GetP(void) {
  return (uint32_t)((READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_P3) >>
                     RCC_PLL3DIVR_P3_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL3 Q Coefficient
 * @rmtoll PLL3DIVR        Q3          LL_RCC_PLL3_GetQ
 * @retval A value between 1 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3_GetQ(void) {
  return (uint32_t)((READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_Q3) >>
                     RCC_PLL3DIVR_Q3_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL3 R Coefficient
 * @rmtoll PLL3DIVR        R3          LL_RCC_PLL3_GetR
 * @retval A value between 1 and 128
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3_GetR(void) {
  return (uint32_t)((READ_BIT(RCC->PLL3DIVR, RCC_PLL3DIVR_R3) >>
                     RCC_PLL3DIVR_R3_Pos) +
                    1UL);
}

/**
 * @brief  Get PLL3 FRACN Coefficient
 * @rmtoll PLL3FRACR      FRACN3          LL_RCC_PLL3_GetFRACN
 * @retval A value between 0 and 8191 (0x1FFF)
 */
__STATIC_INLINE uint32_t LL_RCC_PLL3_GetFRACN(void) {
  return (uint32_t)(READ_BIT(RCC->PLL3FRACR, RCC_PLL3FRACR_FRACN3) >>
                    RCC_PLL3FRACR_FRACN3_Pos);
}

/**
 * @brief  Set PLL3 N Coefficient
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLL3DIVR        N3          LL_RCC_PLL3_SetN
 * @param  N parameter can be a value between 4 and 512
 */
__STATIC_INLINE void LL_RCC_PLL3_SetN(uint32_t N) {
  MODIFY_REG(RCC->PLL3DIVR, RCC_PLL3DIVR_N3, (N - 1UL) << RCC_PLL3DIVR_N3_Pos);
}

/**
 * @brief  Set PLL3 M Coefficient
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLLCKSELR       DIVM3          LL_RCC_PLL3_SetM
 * @param  M parameter can be a value between 0 and 63
 */
__STATIC_INLINE void LL_RCC_PLL3_SetM(uint32_t M) {
  MODIFY_REG(RCC->PLLCKSELR, RCC_PLLCKSELR_DIVM3, M << RCC_PLLCKSELR_DIVM3_Pos);
}

/**
 * @brief  Set PLL3 P Coefficient
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLL3DIVR        P3          LL_RCC_PLL3_SetP
 * @param  P parameter can be a value between 1 and 128
 */
__STATIC_INLINE void LL_RCC_PLL3_SetP(uint32_t P) {
  MODIFY_REG(RCC->PLL3DIVR, RCC_PLL3DIVR_P3, (P - 1UL) << RCC_PLL3DIVR_P3_Pos);
}

/**
 * @brief  Set PLL3 Q Coefficient
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLL3DIVR        Q3          LL_RCC_PLL3_SetQ
 * @param  Q parameter can be a value between 1 and 128
 */
__STATIC_INLINE void LL_RCC_PLL3_SetQ(uint32_t Q) {
  MODIFY_REG(RCC->PLL3DIVR, RCC_PLL3DIVR_Q3, (Q - 1UL) << RCC_PLL3DIVR_Q3_Pos);
}

/**
 * @brief  Set PLL3 R Coefficient
 * @note   This API shall be called only when PLL3 is disabled.
 * @rmtoll PLL3DIVR        R3          LL_RCC_PLL3_SetR
 * @param  R parameter can be a value between 1 and 128
 */
__STATIC_INLINE void LL_RCC_PLL3_SetR(uint32_t R) {
  MODIFY_REG(RCC->PLL3DIVR, RCC_PLL3DIVR_R3, (R - 1UL) << RCC_PLL3DIVR_R3_Pos);
}

/**
 * @brief  Set PLL3 FRACN Coefficient
 * @rmtoll PLL3FRACR        FRACN3          LL_RCC_PLL3_SetFRACN
 * @param  FRACN parameter can be a value between 0 and 8191 (0x1FFF)
 */
__STATIC_INLINE void LL_RCC_PLL3_SetFRACN(uint32_t FRACN) {
  MODIFY_REG(RCC->PLL3FRACR, RCC_PLL3FRACR_FRACN3,
             FRACN << RCC_PLL3FRACR_FRACN3_Pos);
}

/**
 * @}
 */

/** @defgroup RCC_LL_EF_FLAG_Management FLAG Management
 * @{
 */

/**
 * @brief  Clear LSI ready interrupt flag
 * @rmtoll CICR         LSIRDYC       LL_RCC_ClearFlag_LSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_LSIRDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_LSIRDYC);
}

/**
 * @brief  Clear LSE ready interrupt flag
 * @rmtoll CICR         LSERDYC       LL_RCC_ClearFlag_LSERDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_LSERDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_LSERDYC);
}

/**
 * @brief  Clear HSI ready interrupt flag
 * @rmtoll CICR         HSIRDYC       LL_RCC_ClearFlag_HSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_HSIRDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_HSIRDYC);
}

/**
 * @brief  Clear HSE ready interrupt flag
 * @rmtoll CICR         HSERDYC       LL_RCC_ClearFlag_HSERDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_HSERDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_HSERDYC);
}

/**
 * @brief  Clear CSI ready interrupt flag
 * @rmtoll CICR         CSIRDYC       LL_RCC_ClearFlag_CSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_CSIRDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_CSIRDYC);
}

/**
 * @brief  Clear HSI48 ready interrupt flag
 * @rmtoll CICR         HSI48RDYC       LL_RCC_ClearFlag_HSI48RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_HSI48RDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_HSI48RDYC);
}

/**
 * @brief  Clear PLL1 ready interrupt flag
 * @rmtoll CICR         PLL1RDYC       LL_RCC_ClearFlag_PLL1RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_PLL1RDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_PLLRDYC);
}

/**
 * @brief  Clear PLL2 ready interrupt flag
 * @rmtoll CICR         PLL2RDYC       LL_RCC_ClearFlag_PLL2RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_PLL2RDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_PLL2RDYC);
}

/**
 * @brief  Clear PLL3 ready interrupt flag
 * @rmtoll CICR         PLL3RDYC       LL_RCC_ClearFlag_PLL3RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_PLL3RDY(void) {
  SET_BIT(RCC->CICR, RCC_CICR_PLL3RDYC);
}

/**
 * @brief  Clear LSE Clock security system interrupt flag
 * @rmtoll CICR         LSECSSC         LL_RCC_ClearFlag_LSECSS
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_LSECSS(void) {
  SET_BIT(RCC->CICR, RCC_CICR_LSECSSC);
}

/**
 * @brief  Clear HSE Clock security system interrupt flag
 * @rmtoll CICR         HSECSSC         LL_RCC_ClearFlag_HSECSS
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearFlag_HSECSS(void) {
  SET_BIT(RCC->CICR, RCC_CICR_HSECSSC);
}

/**
 * @brief  Check if LSI ready interrupt occurred or not
 * @rmtoll CIFR         LSIRDYF       LL_RCC_IsActiveFlag_LSIRDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LSIRDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_LSIRDYF) == (RCC_CIFR_LSIRDYF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if LSE ready interrupt occurred or not
 * @rmtoll CIFR         LSERDYF       LL_RCC_IsActiveFlag_LSERDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LSERDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_LSERDYF) == (RCC_CIFR_LSERDYF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if HSI ready interrupt occurred or not
 * @rmtoll CIFR         HSIRDYF       LL_RCC_IsActiveFlag_HSIRDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSIRDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_HSIRDYF) == (RCC_CIFR_HSIRDYF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if HSE ready interrupt occurred or not
 * @rmtoll CIFR         HSERDYF       LL_RCC_IsActiveFlag_HSERDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSERDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_HSERDYF) == (RCC_CIFR_HSERDYF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if CSI ready interrupt occurred or not
 * @rmtoll CIFR         CSIRDYF       LL_RCC_IsActiveFlag_CSIRDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_CSIRDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_CSIRDYF) == (RCC_CIFR_CSIRDYF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if HSI48 ready interrupt occurred or not
 * @rmtoll CIFR         HSI48RDYF       LL_RCC_IsActiveFlag_HSI48RDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSI48RDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_HSI48RDYF) == (RCC_CIFR_HSI48RDYF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL1 ready interrupt occurred or not
 * @rmtoll CIFR         PLLRDYF       LL_RCC_IsActiveFlag_PLL1RDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PLL1RDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_PLLRDYF) == (RCC_CIFR_PLLRDYF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if PLL2 ready interrupt occurred or not
 * @rmtoll CIFR         PLL2RDYF       LL_RCC_IsActiveFlag_PLL2RDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PLL2RDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_PLL2RDYF) == (RCC_CIFR_PLL2RDYF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if PLL3 ready interrupt occurred or not
 * @rmtoll CIFR         PLL3RDYF       LL_RCC_IsActiveFlag_PLL3RDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PLL3RDY(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_PLL3RDYF) == (RCC_CIFR_PLL3RDYF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if LSE Clock security system interrupt occurred or not
 * @rmtoll CIFR         LSECSSF          LL_RCC_IsActiveFlag_LSECSS
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LSECSS(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_LSECSSF) == (RCC_CIFR_LSECSSF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if HSE Clock security system interrupt occurred or not
 * @rmtoll CIFR         HSECSSF          LL_RCC_IsActiveFlag_HSECSS
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_HSECSS(void) {
  return ((READ_BIT(RCC->CIFR, RCC_CIFR_HSECSSF) == (RCC_CIFR_HSECSSF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if RCC flag Low Power D1 reset is set or not.
 * @rmtoll RSR          LPWRRSTF       LL_RCC_IsActiveFlag_LPWRRST (*)\n
 *         RSR          LPWR1RSTF      LL_RCC_IsActiveFlag_LPWRRST (**)
 *
 * (*) Only available for single core devices
 * (**) Only available for Dual core devices
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LPWRRST(void) {
#if defined(DUAL_CORE)
  return ((READ_BIT(RCC->RSR, RCC_RSR_LPWR1RSTF) == (RCC_RSR_LPWR1RSTF)) ? 1UL
                                                                         : 0UL);
#else
  return ((READ_BIT(RCC->RSR, RCC_RSR_LPWRRSTF) == (RCC_RSR_LPWRRSTF)) ? 1UL
                                                                       : 0UL);
#endif /*DUAL_CORE*/
}

#if defined(DUAL_CORE)
/**
 * @brief  Check if RCC flag Low Power D2 reset is set or not.
 * @rmtoll RSR          LPWR2RSTF      LL_RCC_IsActiveFlag_LPWR2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_LPWR2RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_LPWR2RSTF) == (RCC_RSR_LPWR2RSTF)) ? 1UL
                                                                         : 0UL);
}
#endif /*DUAL_CORE*/

/**
 * @brief  Check if RCC flag Window Watchdog 1 reset is set or not.
 * @rmtoll RSR          WWDG1RSTF      LL_RCC_IsActiveFlag_WWDG1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_WWDG1RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_WWDG1RSTF) == (RCC_RSR_WWDG1RSTF)) ? 1UL
                                                                         : 0UL);
}

#if defined(DUAL_CORE)
/**
 * @brief  Check if RCC flag Window Watchdog 2 reset is set or not.
 * @rmtoll RSR          WWDG2RSTF      LL_RCC_IsActiveFlag_WWDG2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_WWDG2RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_WWDG2RSTF) == (RCC_RSR_WWDG2RSTF)) ? 1UL
                                                                         : 0UL);
}
#endif /*DUAL_CORE*/

/**
 * @brief  Check if RCC flag Independent Watchdog 1 reset is set or not.
 * @rmtoll RSR          IWDG1RSTF      LL_RCC_IsActiveFlag_IWDG1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_IWDG1RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_IWDG1RSTF) == (RCC_RSR_IWDG1RSTF)) ? 1UL
                                                                         : 0UL);
}

#if defined(DUAL_CORE)
/**
 * @brief  Check if RCC flag Independent Watchdog 2 reset is set or not.
 * @rmtoll RSR          IWDG2RSTF      LL_RCC_IsActiveFlag_IWDG2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_IWDG2RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_IWDG2RSTF) == (RCC_RSR_IWDG2RSTF)) ? 1UL
                                                                         : 0UL);
}
#endif /*DUAL_CORE*/

/**
 * @brief  Check if RCC flag Software reset is set or not.
 * @rmtoll RSR          SFTRSTF        LL_RCC_IsActiveFlag_SFTRST (*)\n
 *         RSR          SFT1RSTF       LL_RCC_IsActiveFlag_SFTRST (**)
 *
 * (*) Only available for single core devices
 * (**) Only available for Dual core devices
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_SFTRST(void) {
#if defined(DUAL_CORE)
  return ((READ_BIT(RCC->RSR, RCC_RSR_SFT1RSTF) == (RCC_RSR_SFT1RSTF)) ? 1UL
                                                                       : 0UL);
#else
  return ((READ_BIT(RCC->RSR, RCC_RSR_SFTRSTF) == (RCC_RSR_SFTRSTF)) ? 1UL
                                                                     : 0UL);
#endif /*DUAL_CORE*/
}

#if defined(DUAL_CORE)
/**
 * @brief  Check if RCC flag Software reset is set or not.
 * @rmtoll RSR          SFT2RSTF       LL_RCC_IsActiveFlag_SFT2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_SFT2RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_SFT2RSTF) == (RCC_RSR_SFT2RSTF)) ? 1UL
                                                                       : 0UL);
}
#endif /*DUAL_CORE*/

/**
 * @brief  Check if RCC flag POR/PDR reset is set or not.
 * @rmtoll RSR          PORRSTF       LL_RCC_IsActiveFlag_PORRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PORRST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_PORRSTF) == (RCC_RSR_PORRSTF)) ? 1UL
                                                                     : 0UL);
}

/**
 * @brief  Check if RCC flag Pin reset is set or not.
 * @rmtoll RSR          PINRSTF       LL_RCC_IsActiveFlag_PINRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_PINRST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_PINRSTF) == (RCC_RSR_PINRSTF)) ? 1UL
                                                                     : 0UL);
}

/**
 * @brief  Check if RCC flag BOR reset is set or not.
 * @rmtoll RSR          BORRSTF       LL_RCC_IsActiveFlag_BORRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_BORRST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_BORRSTF) == (RCC_RSR_BORRSTF)) ? 1UL
                                                                     : 0UL);
}

#if defined(RCC_RSR_D1RSTF)
/**
 * @brief  Check if RCC flag D1 reset is set or not.
 * @rmtoll RSR          D1RSTF       LL_RCC_IsActiveFlag_D1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_D1RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_D1RSTF) == (RCC_RSR_D1RSTF)) ? 1UL : 0UL);
}
#endif /* RCC_RSR_D1RSTF */

#if defined(RCC_RSR_CDRSTF)
/**
 * @brief  Check if RCC flag CD reset is set or not.
 * @rmtoll RSR          CDRSTF       LL_RCC_IsActiveFlag_CDRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_CDRST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_CDRSTF) == (RCC_RSR_CDRSTF)) ? 1UL : 0UL);
}
#endif /* RCC_RSR_CDRSTF */

#if defined(RCC_RSR_D2RSTF)
/**
 * @brief  Check if RCC flag D2 reset is set or not.
 * @rmtoll RSR          D2RSTF       LL_RCC_IsActiveFlag_D2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_D2RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_D2RSTF) == (RCC_RSR_D2RSTF)) ? 1UL : 0UL);
}
#endif /* RCC_RSR_D2RSTF */

#if defined(RCC_RSR_C1RSTF) || defined(RCC_RSR_CPURSTF)
/**
 * @brief  Check if RCC flag CPU reset is set or not.
 * @rmtoll RSR          CPURSTF       LL_RCC_IsActiveFlag_CPURST (*)\n
 *         RSR          C1RSTF        LL_RCC_IsActiveFlag_CPURST (**)
 *
 * (*) Only available for single core devices
 * (**) Only available for Dual core devices
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_CPURST(void) {
#if defined(DUAL_CORE)
  return ((READ_BIT(RCC->RSR, RCC_RSR_C1RSTF) == (RCC_RSR_C1RSTF)) ? 1UL : 0UL);
#else
  return ((READ_BIT(RCC->RSR, RCC_RSR_CPURSTF) == (RCC_RSR_CPURSTF)) ? 1UL
                                                                     : 0UL);
#endif /*DUAL_CORE*/
}
#endif /* defined(RCC_RSR_C1RSTF) || defined(RCC_RSR_CPURSTF) */

#if defined(DUAL_CORE)
/**
 * @brief  Check if RCC flag CPU2 reset is set or not.
 * @rmtoll RSR          C2RSTF       LL_RCC_IsActiveFlag_CPU2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsActiveFlag_CPU2RST(void) {
  return ((READ_BIT(RCC->RSR, RCC_RSR_C2RSTF) == (RCC_RSR_C2RSTF)) ? 1UL : 0UL);
}
#endif /*DUAL_CORE*/

/**
 * @brief  Set RMVF bit to clear all reset flags.
 * @rmtoll RSR          RMVF          LL_RCC_ClearResetFlags
 * @retval None
 */
__STATIC_INLINE void LL_RCC_ClearResetFlags(void) {
  SET_BIT(RCC->RSR, RCC_RSR_RMVF);
}

#if defined(DUAL_CORE)
/**
 * @brief  Check if RCC_C1 flag Low Power D1 reset is set or not.
 * @rmtoll RSR          LPWR1RSTF      LL_C1_RCC_IsActiveFlag_LPWRRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_LPWRRST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_LPWR1RSTF) == (RCC_RSR_LPWR1RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag Low Power D2 reset is set or not.
 * @rmtoll RSR          LPWR2RSTF      LL_C1_RCC_IsActiveFlag_LPWR2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_LPWR2RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_LPWR2RSTF) == (RCC_RSR_LPWR2RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag Window Watchdog 1 reset is set or not.
 * @rmtoll RSR          WWDG1RSTF      LL_C1_RCC_IsActiveFlag_WWDG1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_WWDG1RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_WWDG1RSTF) == (RCC_RSR_WWDG1RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag Window Watchdog 2 reset is set or not.
 * @rmtoll RSR          WWDG2RSTF      LL_C1_RCC_IsActiveFlag_WWDG2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_WWDG2RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_WWDG2RSTF) == (RCC_RSR_WWDG2RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag Independent Watchdog 1 reset is set or not.
 * @rmtoll RSR          IWDG1RSTF      LL_C1_RCC_IsActiveFlag_IWDG1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_IWDG1RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_IWDG1RSTF) == (RCC_RSR_IWDG1RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag Independent Watchdog 2 reset is set or not.
 * @rmtoll RSR          IWDG2RSTF      LL_C1_RCC_IsActiveFlag_IWDG2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_IWDG2RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_IWDG2RSTF) == (RCC_RSR_IWDG2RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag Software reset is set or not.
 * @rmtoll RSR          SFT1RSTF       LL_C1_RCC_IsActiveFlag_SFTRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_SFTRST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_SFT1RSTF) == (RCC_RSR_SFT1RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag Software reset is set or not.
 * @rmtoll RSR          SFT2RSTF       LL_C1_RCC_IsActiveFlag_SFT2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_SFT2RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_SFT2RSTF) == (RCC_RSR_SFT2RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag POR/PDR reset is set or not.
 * @rmtoll RSR          PORRSTF       LL_C1_RCC_IsActiveFlag_PORRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_PORRST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_PORRSTF) == (RCC_RSR_PORRSTF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag Pin reset is set or not.
 * @rmtoll RSR          PINRSTF       LL_C1_RCC_IsActiveFlag_PINRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_PINRST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_PINRSTF) == (RCC_RSR_PINRSTF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag BOR reset is set or not.
 * @rmtoll RSR          BORRSTF       LL_C1_RCC_IsActiveFlag_BORRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_BORRST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_BORRSTF) == (RCC_RSR_BORRSTF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag D1 reset is set or not.
 * @rmtoll RSR          D1RSTF       LL_C1_RCC_IsActiveFlag_D1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_D1RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_D1RSTF) == (RCC_RSR_D1RSTF)) ? 1UL
                                                                      : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag D2 reset is set or not.
 * @rmtoll RSR          D2RSTF       LL_C1_RCC_IsActiveFlag_D2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_D2RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_D2RSTF) == (RCC_RSR_D2RSTF)) ? 1UL
                                                                      : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag CPU reset is set or not.
 * @rmtoll RSR          C1RSTF       LL_C1_RCC_IsActiveFlag_CPURST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_CPURST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_C1RSTF) == (RCC_RSR_C1RSTF)) ? 1UL
                                                                      : 0UL);
}

/**
 * @brief  Check if RCC_C1 flag CPU2 reset is set or not.
 * @rmtoll RSR          C2RSTF       LL_C1_RCC_IsActiveFlag_CPU2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C1_RCC_IsActiveFlag_CPU2RST(void) {
  return ((READ_BIT(RCC_C1->RSR, RCC_RSR_C2RSTF) == (RCC_RSR_C2RSTF)) ? 1UL
                                                                      : 0UL);
}

/**
 * @brief  Set RMVF bit to clear the reset flags.
 * @rmtoll RSR          RMVF          LL_C1_RCC_ClearResetFlags
 * @retval None
 */
__STATIC_INLINE void LL_C1_RCC_ClearResetFlags(void) {
  SET_BIT(RCC_C1->RSR, RCC_RSR_RMVF);
}

/**
 * @brief  Check if RCC_C2 flag Low Power D1 reset is set or not.
 * @rmtoll RSR          LPWR1RSTF      LL_C2_RCC_IsActiveFlag_LPWRRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_LPWRRST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_LPWR1RSTF) == (RCC_RSR_LPWR1RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag Low Power D2 reset is set or not.
 * @rmtoll RSR          LPWR2RSTF      LL_C2_RCC_IsActiveFlag_LPWR2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_LPWR2RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_LPWR2RSTF) == (RCC_RSR_LPWR2RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag Window Watchdog 1 reset is set or not.
 * @rmtoll RSR          WWDG1RSTF      LL_C2_RCC_IsActiveFlag_WWDG1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_WWDG1RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_WWDG1RSTF) == (RCC_RSR_WWDG1RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag Window Watchdog 2 reset is set or not.
 * @rmtoll RSR          WWDG2RSTF      LL_C2_RCC_IsActiveFlag_WWDG2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_WWDG2RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_WWDG2RSTF) == (RCC_RSR_WWDG2RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag Independent Watchdog 1 reset is set or not.
 * @rmtoll RSR          IWDG1RSTF      LL_C2_RCC_IsActiveFlag_IWDG1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_IWDG1RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_IWDG1RSTF) == (RCC_RSR_IWDG1RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag Independent Watchdog 2 reset is set or not.
 * @rmtoll RSR          IWDG2RSTF      LL_C2_RCC_IsActiveFlag_IWDG2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_IWDG2RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_IWDG2RSTF) == (RCC_RSR_IWDG2RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag Software reset is set or not.
 * @rmtoll RSR          SFT1RSTF       LL_C2_RCC_IsActiveFlag_SFTRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_SFTRST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_SFT1RSTF) == (RCC_RSR_SFT1RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag Software reset is set or not.
 * @rmtoll RSR          SFT2RSTF       LL_C2_RCC_IsActiveFlag_SFT2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_SFT2RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_SFT2RSTF) == (RCC_RSR_SFT2RSTF))
              ? 1UL
              : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag POR/PDR reset is set or not.
 * @rmtoll RSR          PORRSTF       LL_C2_RCC_IsActiveFlag_PORRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_PORRST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_PORRSTF) == (RCC_RSR_PORRSTF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag Pin reset is set or not.
 * @rmtoll RSR          PINRSTF       LL_C2_RCC_IsActiveFlag_PINRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_PINRST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_PINRSTF) == (RCC_RSR_PINRSTF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag BOR reset is set or not.
 * @rmtoll RSR          BORRSTF       LL_C2_RCC_IsActiveFlag_BORRST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_BORRST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_BORRSTF) == (RCC_RSR_BORRSTF)) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag D1 reset is set or not.
 * @rmtoll RSR          D1RSTF       LL_C2_RCC_IsActiveFlag_D1RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_D1RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_D1RSTF) == (RCC_RSR_D1RSTF)) ? 1UL
                                                                      : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag D2 reset is set or not.
 * @rmtoll RSR          D2RSTF       LL_C2_RCC_IsActiveFlag_D2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_D2RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_D2RSTF) == (RCC_RSR_D2RSTF)) ? 1UL
                                                                      : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag CPU reset is set or not.
 * @rmtoll RSR          C1RSTF       LL_C2_RCC_IsActiveFlag_CPURST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_CPURST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_C1RSTF) == (RCC_RSR_C1RSTF)) ? 1UL
                                                                      : 0UL);
}

/**
 * @brief  Check if RCC_C2 flag CPU2 reset is set or not.
 * @rmtoll RSR          C2RSTF       LL_C2_RCC_IsActiveFlag_CPU2RST
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_C2_RCC_IsActiveFlag_CPU2RST(void) {
  return ((READ_BIT(RCC_C2->RSR, RCC_RSR_C2RSTF) == (RCC_RSR_C2RSTF)) ? 1UL
                                                                      : 0UL);
}

/**
 * @brief  Set RMVF bit to clear the reset flags.
 * @rmtoll RSR          RMVF          LL_C2_RCC_ClearResetFlags
 * @retval None
 */
__STATIC_INLINE void LL_C2_RCC_ClearResetFlags(void) {
  SET_BIT(RCC_C2->RSR, RCC_RSR_RMVF);
}
#endif /*DUAL_CORE*/

/**
 * @}
 */

/** @defgroup RCC_LL_EF_IT_Management IT Management
 * @{
 */

/**
 * @brief  Enable LSI ready interrupt
 * @rmtoll CIER         LSIRDYIE      LL_RCC_EnableIT_LSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_LSIRDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_LSIRDYIE);
}

/**
 * @brief  Enable LSE ready interrupt
 * @rmtoll CIER         LSERDYIE      LL_RCC_EnableIT_LSERDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_LSERDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_LSERDYIE);
}

/**
 * @brief  Enable HSI ready interrupt
 * @rmtoll CIER         HSIRDYIE      LL_RCC_EnableIT_HSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_HSIRDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_HSIRDYIE);
}

/**
 * @brief  Enable HSE ready interrupt
 * @rmtoll CIER         HSERDYIE      LL_RCC_EnableIT_HSERDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_HSERDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_HSERDYIE);
}

/**
 * @brief  Enable CSI ready interrupt
 * @rmtoll CIER         CSIRDYIE      LL_RCC_EnableIT_CSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_CSIRDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_CSIRDYIE);
}

/**
 * @brief  Enable HSI48 ready interrupt
 * @rmtoll CIER         HSI48RDYIE      LL_RCC_EnableIT_HSI48RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_HSI48RDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_HSI48RDYIE);
}

/**
 * @brief  Enable PLL1 ready interrupt
 * @rmtoll CIER         PLL1RDYIE      LL_RCC_EnableIT_PLL1RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_PLL1RDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_PLL1RDYIE);
}

/**
 * @brief  Enable PLL2 ready interrupt
 * @rmtoll CIER         PLL2RDYIE  LL_RCC_EnableIT_PLL2RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_PLL2RDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_PLL2RDYIE);
}

/**
 * @brief  Enable PLL3 ready interrupt
 * @rmtoll CIER         PLL3RDYIE  LL_RCC_EnableIT_PLL3RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_PLL3RDY(void) {
  SET_BIT(RCC->CIER, RCC_CIER_PLL3RDYIE);
}

/**
 * @brief  Enable LSECSS interrupt
 * @rmtoll CIER         LSECSSIE  LL_RCC_EnableIT_LSECSS
 * @retval None
 */
__STATIC_INLINE void LL_RCC_EnableIT_LSECSS(void) {
  SET_BIT(RCC->CIER, RCC_CIER_LSECSSIE);
}

/**
 * @brief  Disable LSI ready interrupt
 * @rmtoll CIER         LSIRDYIE      LL_RCC_DisableIT_LSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_LSIRDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_LSIRDYIE);
}

/**
 * @brief  Disable LSE ready interrupt
 * @rmtoll CIER         LSERDYIE      LL_RCC_DisableIT_LSERDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_LSERDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_LSERDYIE);
}

/**
 * @brief  Disable HSI ready interrupt
 * @rmtoll CIER         HSIRDYIE      LL_RCC_DisableIT_HSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_HSIRDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_HSIRDYIE);
}

/**
 * @brief  Disable HSE ready interrupt
 * @rmtoll CIER         HSERDYIE      LL_RCC_DisableIT_HSERDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_HSERDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_HSERDYIE);
}

/**
 * @brief  Disable CSI ready interrupt
 * @rmtoll CIER         CSIRDYIE      LL_RCC_DisableIT_CSIRDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_CSIRDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_CSIRDYIE);
}

/**
 * @brief  Disable HSI48 ready interrupt
 * @rmtoll CIER         HSI48RDYIE      LL_RCC_DisableIT_HSI48RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_HSI48RDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_HSI48RDYIE);
}

/**
 * @brief  Disable PLL1 ready interrupt
 * @rmtoll CIER         PLL1RDYIE      LL_RCC_DisableIT_PLL1RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_PLL1RDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_PLL1RDYIE);
}

/**
 * @brief  Disable PLL2 ready interrupt
 * @rmtoll CIER         PLL2RDYIE  LL_RCC_DisableIT_PLL2RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_PLL2RDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_PLL2RDYIE);
}

/**
 * @brief  Disable PLL3 ready interrupt
 * @rmtoll CIER         PLL3RDYIE  LL_RCC_DisableIT_PLL3RDY
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_PLL3RDY(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_PLL3RDYIE);
}

/**
 * @brief  Disable LSECSS interrupt
 * @rmtoll CIER         LSECSSIE  LL_RCC_DisableIT_LSECSS
 * @retval None
 */
__STATIC_INLINE void LL_RCC_DisableIT_LSECSS(void) {
  CLEAR_BIT(RCC->CIER, RCC_CIER_LSECSSIE);
}

/**
 * @brief  Checks if LSI ready interrupt source is enabled or disabled.
 * @rmtoll CIER         LSIRDYIE      LL_RCC_IsEnableIT_LSIRDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_LSIRDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_LSIRDYIE) == RCC_CIER_LSIRDYIE) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Checks if LSE ready interrupt source is enabled or disabled.
 * @rmtoll CIER         LSERDYIE      LL_RCC_IsEnableIT_LSERDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_LSERDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_LSERDYIE) == RCC_CIER_LSERDYIE) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Checks if HSI ready interrupt source is enabled or disabled.
 * @rmtoll CIER         HSIRDYIE      LL_RCC_IsEnableIT_HSIRDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_HSIRDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_HSIRDYIE) == RCC_CIER_HSIRDYIE) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Checks if HSE ready interrupt source is enabled or disabled.
 * @rmtoll CIER         HSERDYIE      LL_RCC_IsEnableIT_HSERDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_HSERDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_HSERDYIE) == RCC_CIER_HSERDYIE) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Checks if CSI ready interrupt source is enabled or disabled.
 * @rmtoll CIER         CSIRDYIE      LL_RCC_IsEnableIT_CSIRDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_CSIRDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_CSIRDYIE) == RCC_CIER_CSIRDYIE) ? 1UL
                                                                        : 0UL);
}

/**
 * @brief  Checks if HSI48 ready interrupt source is enabled or disabled.
 * @rmtoll CIER         HSI48RDYIE      LL_RCC_IsEnableIT_HSI48RDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_HSI48RDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_HSI48RDYIE) == RCC_CIER_HSI48RDYIE)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Checks if PLL1 ready interrupt source is enabled or disabled.
 * @rmtoll CIER         PLL1RDYIE      LL_RCC_IsEnableIT_PLL1RDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_PLL1RDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_PLL1RDYIE) == RCC_CIER_PLL1RDYIE)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Checks if PLL2 ready interrupt source is enabled or disabled.
 * @rmtoll CIER         PLL2RDYIE  LL_RCC_IsEnableIT_PLL2RDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_PLL2RDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_PLL2RDYIE) == RCC_CIER_PLL2RDYIE)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Checks if PLL3 ready interrupt source is enabled or disabled.
 * @rmtoll CIER         PLL3RDYIE  LL_RCC_IsEnableIT_PLL3RDY
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_PLL3RDY(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_PLL3RDYIE) == RCC_CIER_PLL3RDYIE)
              ? 1UL
              : 0UL);
}

/**
 * @brief  Checks if LSECSS interrupt source is enabled or disabled.
 * @rmtoll CIER         LSECSSIE  LL_RCC_IsEnableIT_LSECSS
 * @retval State of bit (1 or 0).
 */
__STATIC_INLINE uint32_t LL_RCC_IsEnableIT_LSECSS(void) {
  return ((READ_BIT(RCC->CIER, RCC_CIER_LSECSSIE) == RCC_CIER_LSECSSIE) ? 1UL
                                                                        : 0UL);
}
/**
 * @}
 */

#if defined(USE_FULL_LL_DRIVER)
/** @defgroup RCC_LL_EF_Init De-initialization function
 * @{
 */
void LL_RCC_DeInit(void);
/**
 * @}
 */

/** @defgroup RCC_LL_EF_Get_Freq Get system and peripherals clocks frequency
 * functions
 * @{
 */
uint32_t LL_RCC_CalcPLLClockFreq(uint32_t PLLInputFreq, uint32_t M, uint32_t N,
                                 uint32_t FRACN, uint32_t PQR);

void LL_RCC_GetPLL1ClockFreq(LL_PLL_ClocksTypeDef *PLL_Clocks);
void LL_RCC_GetPLL2ClockFreq(LL_PLL_ClocksTypeDef *PLL_Clocks);
void LL_RCC_GetPLL3ClockFreq(LL_PLL_ClocksTypeDef *PLL_Clocks);
void LL_RCC_GetSystemClocksFreq(LL_RCC_ClocksTypeDef *RCC_Clocks);

uint32_t LL_RCC_GetUSARTClockFreq(uint32_t USARTxSource);
uint32_t LL_RCC_GetLPUARTClockFreq(uint32_t LPUARTxSource);
uint32_t LL_RCC_GetI2CClockFreq(uint32_t I2CxSource);
uint32_t LL_RCC_GetLPTIMClockFreq(uint32_t LPTIMxSource);
uint32_t LL_RCC_GetSAIClockFreq(uint32_t SAIxSource);
uint32_t LL_RCC_GetADCClockFreq(uint32_t ADCxSource);
uint32_t LL_RCC_GetSDMMCClockFreq(uint32_t SDMMCxSource);
uint32_t LL_RCC_GetRNGClockFreq(uint32_t RNGxSource);
uint32_t LL_RCC_GetCECClockFreq(uint32_t CECxSource);
uint32_t LL_RCC_GetUSBClockFreq(uint32_t USBxSource);
uint32_t LL_RCC_GetDFSDMClockFreq(uint32_t DFSDMxSource);
#if defined(DFSDM2_BASE)
uint32_t LL_RCC_GetDFSDM2ClockFreq(uint32_t DFSDMxSource);
#endif /* DFSDM2_BASE */
#if defined(DSI)
uint32_t LL_RCC_GetDSIClockFreq(uint32_t DSIxSource);
#endif /* DSI */
uint32_t LL_RCC_GetSPDIFClockFreq(uint32_t SPDIFxSource);
uint32_t LL_RCC_GetSPIClockFreq(uint32_t SPIxSource);
uint32_t LL_RCC_GetSWPClockFreq(uint32_t SWPxSource);
uint32_t LL_RCC_GetFDCANClockFreq(uint32_t FDCANxSource);
uint32_t LL_RCC_GetFMCClockFreq(uint32_t FMCxSource);
#if defined(QUADSPI)
uint32_t LL_RCC_GetQSPIClockFreq(uint32_t QSPIxSource);
#endif /* QUADSPI */
#if defined(OCTOSPI1) || defined(OCTOSPI2)
uint32_t LL_RCC_GetOSPIClockFreq(uint32_t OSPIxSource);
#endif /* defined(OCTOSPI1) || defined(OCTOSPI2) */
uint32_t LL_RCC_GetCLKPClockFreq(uint32_t CLKPxSource);

/**
 * @}
 */
#endif /* USE_FULL_LL_DRIVER */

/**
 * @}
 */

/**
 * @}
 */
#endif /* defined(RCC) */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* STM32H7xx_LL_RCC_H */
