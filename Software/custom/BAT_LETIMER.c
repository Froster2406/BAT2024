/*
 * BAT_LETIMER.c
 *
 *  Created on: 02.04.2024
 *      Author: Stefano Nicora
 */

#include "BAT_LETIMER.h"

static uint32_t time = 0;                         /* holds the overall time */
static char timestamp[10];                        /* holds string in format hh:mm:ss */
static char inputStorageBuffer[512] = {0};        /* holds data  read from EEPROM */
static char outputStorageBuffer[512] = {0};       /* holds data to be written to EEPROM */
static int32_t buffer[BUFFERSIZE] = {0};          /* holds the measured and converted PCM samples */
static int32_t bufferWeighted[BUFFERSIZE] = {0};  /* holds the weighted PCM samples */

/***************************************************************************//**
 * @brief
 *   Initialize the Timer peripheral
 *
 ******************************************************************************/
void BAT_TIMER_init(void){
  /* Enable clock for LETIMER0 */
  CMU_ClockEnable(cmuClock_LETIMER0, true);

  /* calculate overflow value based on current clock value */
  uint16_t clock = CMU_ClockFreqGet(cmuClock_LETIMER0);
  uint32_t overflowValue = clock * BAT_MEASUREMENT_INTERVAL / 1000;

  /* Initialize LETIMER */
  LETIMER_Init_TypeDef letimerInit = LETIMER_INIT_DEFAULT;
  letimerInit.comp0Top = true;          /* Set COMP0 to generate an interrupt on overflow */
  letimerInit.topValue = overflowValue; /* Set the top value to the maximum to count upwards */
  LETIMER_Init(LETIMER0, &letimerInit);

  /* Set COMP0 to trigger an interrupt every BAT_MEASUREMENT_INTERVAL */
  LETIMER_CompareSet(LETIMER0, 0, overflowValue);

  /* Enable COMP0 interrupt */
  LETIMER_IntEnable(LETIMER0, LETIMER_IF_COMP0);
  NVIC_EnableIRQ(LETIMER0_IRQn);
}

/***************************************************************************//**
 * @brief
 *   Deinitialize the Timer peripheral
 *
 ******************************************************************************/
void BAT_TIMER_deInit(void){

}

/***************************************************************************//**
 * @brief
 *   Create the interrupt handler called each BAT_MEASUREMENT_INTERVAL.
 *   Acts as the main measurement loop
 *
 ******************************************************************************/
void LETIMER0_IRQHandler(void)
{
  /* Clear the interrupt flag */
  LETIMER_IntClear(LETIMER0, LETIMER_IF_COMP0);

  /* is device charging? YES: Enable BLE and transmit Data | NO: log data to memory */
  if(GPIO_PinInGet(BAT_CHARGING_PORT, BAT_CHARGING_PIN)){ /* device is charging; transmit data */
      time = BAT_RTC_getTime();
      BAT_I2C_enableLedRange(0);
      /* transmit data from EEPROM via BLE */
      /* INSERT CODE HERE */
      /* use function BAT_SPI_readPage(inputStorageBuffer) to read data from EEPROM */
  } else{  /* log data */
      /* define needed variables */
      static uint8_t value_counter = 0;
      static uint8_t cnt = 0;
      static uint16_t avg = 0;
      float dBSPL = 0;

      /* 1kHz test signal; disable function "readMicrophone" below when using signal to test filtering */
//      int32_t buffer[BUFFERSIZE] = {300685,279800,258476,238030,219150,201087,183789,165630,144348,119923,94915,73493,56692,42662,31234,23530,20245,19897,20291,21956,25273,31921,42187,56265,73310,91798,111052,130175,148902,167234,185802,204126,222435,242800,266981,288400,304096,316439,329735,341780,348756,351363,352512,352959,349914,343126,332948,319205,301057,280005,258520,238257,219392,201375,184152,166222,144975,120268,95193,73888,57292,43620,31722,24432,21278,21013,20834,22288,25267,31467,41736,55156,72610,91476,110705,129673,148136,166493,184912,203381,221436,241909,265843,287509,303630,316289,329163,340804,348117,350556,351857,351927,349310,342439,332244,318573,300786,279849,258246,237781,218630,200310,182887,165014,144200,119508,94364,72573,56145,42331,30838,23093,19709,18855,19097,20446,23868,30391,40469,54121,71481,89775,108640,127733,146889,165508,184193,202468};

      /* read microphone */
      BAT_PDM_readMicrophone(buffer, BUFFERSIZE);

      /* read RTC */
      time = BAT_RTC_getTime();

      /* convert timestamp to string */
      BAT_RTC_convertTimeToString(time, timestamp);

      /* apply filtering */
//    BAT_PDM_applyAWeightingFilter(buffer, bufferWeighted, BUFFERSIZE);
//    BAT_PDM_applyCWeightingFilter(buffer, bufferWeighted, BUFFERSIZE);

      /* convert data to dBSPL */
      BAT_PDM_convertPCMTodBSPL(buffer, BUFFERSIZE, &dBSPL);
//    BAT_PDM_convertPCMTodBSPL(bufferWeighted, BUFFERSIZE, &dBSPL);

      /* convert dBSPL value to string */
      char dBSPLstr[7] = {0};  /* holds dBSPL value in string format */
      BAT_PDM_convertSPLToString(dBSPL, dBSPLstr);

      /* enable LEDs */
      avg += (uint8_t)dBSPL;
      cnt++;
      if(cnt == 4){
          dBSPL = avg / cnt;
          if (dBSPL <= (LED_THRESHOLD_1 - 5)){
              BAT_I2C_enableLedRange(0);
          } else if (dBSPL <= LED_THRESHOLD_1){
              BAT_I2C_enableLedRange(1);
          } else if (dBSPL <= LED_THRESHOLD_2){
              BAT_I2C_enableLedRange(2);
          } else if (dBSPL <= LED_THRESHOLD_3){
              BAT_I2C_enableLedRange(3);
          } else if (dBSPL <= LED_THRESHOLD_4){
              BAT_I2C_enableLedRange(4);
          } else if (dBSPL <= LED_THRESHOLD_5){
              BAT_I2C_enableLedRange(5);
          } else if (dBSPL <= LED_THRESHOLD_6){
              BAT_I2C_enableLedRange(6);
          } else if (dBSPL <= LED_THRESHOLD_7){
              BAT_I2C_enableLedRange(7);
          } else {
              BAT_I2C_enableLedRange(8);
          }
          avg = 0;
          cnt = 0;
      }
      /* add measured data to memory chunk */
      /* store Data in memory if enough data is available */
      char string[16] = {0};
      BAT_LOGGING_generateLogString(string, timestamp, dBSPLstr);
      value_counter++;
      if (value_counter == (512 / BAT_LEN_MEAS_STR) && BAT_SPI_eepromIsAvailable()){
          BAT_SPI_writePage(outputStorageBuffer);
      }
      EMU_EnterEM1(); // Enter energy mode 1 to save power
  }
}
