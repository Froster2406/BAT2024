################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_default_common_linker.c \
../gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_hal_flash.c \
../gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_lock.c 

OBJS += \
./gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_default_common_linker.o \
./gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_hal_flash.o \
./gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_lock.o 

C_DEPS += \
./gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_default_common_linker.d \
./gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_hal_flash.d \
./gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_lock.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_default_common_linker.o: ../gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_default_common_linker.c gecko_sdk_4.4.1/platform/emdrv/nvm3/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DBGM220PC22HNA=1' '-DSL_APP_PROPERTIES=1' '-DBOOTLOADER_APPLOADER=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<sl_mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\config" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\config\btconf" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\Device\SiliconLabs\BGM22\Include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\common\util\app_assert" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\common\util\app_timer" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\protocol\bluetooth\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\common\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\protocol\bluetooth\bgstack\ll\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\hardware\board\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\bootloader" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\bootloader\api" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\CMSIS\Core\Include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_cryptoacc_library\include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_cryptoacc_library\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\device_init\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\dmadrv\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\common\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emlib\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\fem_util" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\bluetooth\common\gatt_service_device_information" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\driver\i2cspm\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\bluetooth\common\in_place_ota_dfu" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_mbedtls_support\config" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_mbedtls_support\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\third_party\mbedtls\include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\third_party\mbedtls\library" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\hardware\driver\mic\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\mpu\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\nvm3\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\power_manager\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_psa_driver\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\common" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\ble" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\ieee802154" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\wmbus" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\zwave" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\chip\efr32\efr32xg2x" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\sidewalk" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\pa-conversions" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\pa-conversions\efr32xg22" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\rail_util_power_manager_init" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\rail_util_pti" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\se_manager\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\se_manager\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\silicon_labs\silabs_core\memory_manager" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\common\toolchain\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\system\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\sleeptimer\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_protocol_crypto\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\spidrv\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\udelay\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\autogen" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_default_common_linker.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_hal_flash.o: ../gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_hal_flash.c gecko_sdk_4.4.1/platform/emdrv/nvm3/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DBGM220PC22HNA=1' '-DSL_APP_PROPERTIES=1' '-DBOOTLOADER_APPLOADER=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<sl_mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\config" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\config\btconf" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\Device\SiliconLabs\BGM22\Include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\common\util\app_assert" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\common\util\app_timer" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\protocol\bluetooth\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\common\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\protocol\bluetooth\bgstack\ll\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\hardware\board\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\bootloader" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\bootloader\api" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\CMSIS\Core\Include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_cryptoacc_library\include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_cryptoacc_library\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\device_init\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\dmadrv\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\common\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emlib\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\fem_util" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\bluetooth\common\gatt_service_device_information" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\driver\i2cspm\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\bluetooth\common\in_place_ota_dfu" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_mbedtls_support\config" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_mbedtls_support\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\third_party\mbedtls\include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\third_party\mbedtls\library" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\hardware\driver\mic\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\mpu\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\nvm3\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\power_manager\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_psa_driver\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\common" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\ble" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\ieee802154" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\wmbus" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\zwave" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\chip\efr32\efr32xg2x" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\sidewalk" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\pa-conversions" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\pa-conversions\efr32xg22" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\rail_util_power_manager_init" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\rail_util_pti" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\se_manager\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\se_manager\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\silicon_labs\silabs_core\memory_manager" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\common\toolchain\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\system\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\sleeptimer\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_protocol_crypto\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\spidrv\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\udelay\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\autogen" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_hal_flash.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_lock.o: ../gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_lock.c gecko_sdk_4.4.1/platform/emdrv/nvm3/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DBGM220PC22HNA=1' '-DSL_APP_PROPERTIES=1' '-DBOOTLOADER_APPLOADER=1' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DSL_BOARD_NAME="BRD4314A"' '-DSL_BOARD_REV="A02"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<sl_mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\config" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\config\btconf" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\Device\SiliconLabs\BGM22\Include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\common\util\app_assert" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\common\util\app_timer" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\protocol\bluetooth\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\common\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\protocol\bluetooth\bgstack\ll\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\hardware\board\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\bootloader" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\bootloader\api" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\CMSIS\Core\Include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_cryptoacc_library\include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_cryptoacc_library\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\device_init\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\dmadrv\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\common\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emlib\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\fem_util" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\bluetooth\common\gatt_service_device_information" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\driver\i2cspm\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\app\bluetooth\common\in_place_ota_dfu" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_mbedtls_support\config" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_mbedtls_support\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\third_party\mbedtls\include" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\third_party\mbedtls\library" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\hardware\driver\mic\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\mpu\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\nvm3\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\power_manager\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_psa_driver\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\common" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\ble" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\ieee802154" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\wmbus" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\zwave" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\chip\efr32\efr32xg2x" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\protocol\sidewalk" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\pa-conversions" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\pa-conversions\efr32xg22" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\rail_util_power_manager_init" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\radio\rail_lib\plugin\rail_util_pti" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\se_manager\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\se_manager\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\util\silicon_labs\silabs_core\memory_manager" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\common\toolchain\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\system\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\sleeptimer\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\security\sl_component\sl_protocol_crypto\src" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\emdrv\spidrv\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\gecko_sdk_4.4.1\platform\service\udelay\inc" -I"C:\Studium\Module\TA.BA_BAA+E.F2401\Entwicklung\Software\autogen" -O0 -Wall -Wextra -fomit-frame-pointer -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.1/platform/emdrv/nvm3/src/nvm3_lock.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


