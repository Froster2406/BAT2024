/***************************************************************************//**
 * @file
 * @brief Core application logic.
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/
#include "em_common.h"
#include "app_assert.h"
#include "sl_bluetooth.h"
#include "app.h"
#include <stdio.h>

// The advertising set handle allocated from Bluetooth stack.
static uint8_t advertising_set_handle = 0xff;

#include "custom\BAT_RTC.h"
#include "custom\BAT_SPI.h"
#include "custom\BAT_I2C.h"
#include "custom\BAT_PDM.h"
#include "custom\BAT_LETIMER.h"


//#define MIC_SAMPLE_RATE            44100
//#define MIC_SAMPLE_BUFFER_SIZE     1024
//static int16_t buffer[MIC_SAMPLE_BUFFER_SIZE];

/**************************************************************************//**
 * Application Init.
 *****************************************************************************/
SL_WEAK void app_init(void)
{
  BAT_GPIO_init();
  BAT_RTC_init();
  BAT_SPI_init();
//  char string[512] = "This is an EEPROM test";
//  BAT_SPI_writePage(string);
  BAT_I2C_init();
  BAT_PDM_init();
  BAT_TIMER_init();
//  sl_mic_init(MIC_SAMPLE_RATE, 1);
  uint32_t clock_freqPDM = CMU_ClockFreqGet(cmuClock_PDM);    /* 3072000 */
  uint32_t clock_freqI2C = CMU_ClockFreqGet(cmuClock_I2C0);   /* 19200000 */
  uint32_t clock_freqSPI = CMU_ClockFreqGet(cmuClock_USART0); /* 38400000 */
  uint32_t clock_freqSYSCLK = CMU_ClockFreqGet(cmuClock_SYSCLK); /* 38400000 */
  uint32_t clock_freq = CMU_ClockFreqGet(cmuClock_EM01GRPBCLK);
  uint32_t clock_freq2 = CMU_ClockFreqGet(cmuClock_PDM);
  uint32_t clock_freq3 = CMU_ClockFreqGet(cmuClock_PDMREF);
//  CMU_Lock();
}

/**************************************************************************//**
 * Application Process Action.
 *****************************************************************************/
SL_WEAK void app_process_action(void)
{
//  int32_t buffer[128] = {0};
//  /* read microphone */
//  BAT_PDM_readMicrophone(buffer, 128);
//  buffer[1] = 0;
//  float sound_level_0;
//  uint32_t n_samples = 1024;
//  // Read samples from the microphone
//  sl_mic_get_n_samples(buffer, n_samples);
//
//  while (!sl_mic_sample_buffer_ready()) {
//    // Wait until sample buffer ready
//  }
//  // Calculate sound level
//  sl_mic_calculate_sound_level(&sound_level_0, buffer, n_samples, 0);
//  sound_level_0 = 10;
//  bool status = false;
//  status = BAT_SPI_eepromIsAvailable();
//  status = true;
//  BAT_I2C_enableLedRange(8);
//  BAT_I2C_readTemperature();
//  double buffer[128];
//  BAT_PDM_readMicrophone(buffer, 128);
//  char string[512] = "";
//  BAT_SPI_writePage(string);
}

/**************************************************************************//**
 * Bluetooth stack event handler.
 * This overrides the dummy weak implementation.
 *
 * @param[in] evt Event coming from the Bluetooth stack.
 *****************************************************************************/
void sl_bt_on_event(sl_bt_msg_t *evt)
{
  sl_status_t sc;

  switch (SL_BT_MSG_ID(evt->header)) {
    // -------------------------------
    // This event indicates the device has started and the radio is ready.
    // Do not call any stack command before receiving this boot event!
    case sl_bt_evt_system_boot_id:
      // Create an advertising set.
      sc = sl_bt_advertiser_create_set(&advertising_set_handle);
      app_assert_status(sc);

      // Generate data for advertising
      sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                 sl_bt_advertiser_general_discoverable);
      app_assert_status(sc);

      // Set advertising interval to 100ms.
      sc = sl_bt_advertiser_set_timing(
        advertising_set_handle,
        160, // min. adv. interval (milliseconds * 1.6)
        160, // max. adv. interval (milliseconds * 1.6)
        0,   // adv. duration
        0);  // max. num. adv. events
      app_assert_status(sc);
      // Start advertising and enable connections.
      sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                         sl_bt_legacy_advertiser_connectable);
      app_assert_status(sc);
      break;

    // -------------------------------
    // This event indicates that a new connection was opened.
    case sl_bt_evt_connection_opened_id:
      break;

    // -------------------------------
    // This event indicates that a connection was closed.
    case sl_bt_evt_connection_closed_id:
      // Generate data for advertising
      sc = sl_bt_legacy_advertiser_generate_data(advertising_set_handle,
                                                 sl_bt_advertiser_general_discoverable);
      app_assert_status(sc);

      // Restart advertising after client has disconnected.
      sc = sl_bt_legacy_advertiser_start(advertising_set_handle,
                                         sl_bt_legacy_advertiser_connectable);
      app_assert_status(sc);
      break;

    ///////////////////////////////////////////////////////////////////////////
    // Add additional event handlers here as your application requires!      //
    ///////////////////////////////////////////////////////////////////////////

    // -------------------------------
    // Default event handler.
    default:
      break;
  }
}
