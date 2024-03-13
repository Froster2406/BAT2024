#ifndef PIN_CONFIG_H
#define PIN_CONFIG_H

// $[CMU]
// [CMU]$

// $[PRS.ASYNCH0]
// [PRS.ASYNCH0]$

// $[PRS.ASYNCH1]
// [PRS.ASYNCH1]$

// $[PRS.ASYNCH2]
// [PRS.ASYNCH2]$

// $[PRS.ASYNCH3]
// [PRS.ASYNCH3]$

// $[PRS.ASYNCH4]
// [PRS.ASYNCH4]$

// $[PRS.ASYNCH5]
// [PRS.ASYNCH5]$

// $[PRS.ASYNCH6]
// [PRS.ASYNCH6]$

// $[PRS.ASYNCH7]
// [PRS.ASYNCH7]$

// $[PRS.ASYNCH8]
// [PRS.ASYNCH8]$

// $[PRS.ASYNCH9]
// [PRS.ASYNCH9]$

// $[PRS.ASYNCH10]
// [PRS.ASYNCH10]$

// $[PRS.ASYNCH11]
// [PRS.ASYNCH11]$

// $[PRS.SYNCH0]
// [PRS.SYNCH0]$

// $[PRS.SYNCH1]
// [PRS.SYNCH1]$

// $[PRS.SYNCH2]
// [PRS.SYNCH2]$

// $[PRS.SYNCH3]
// [PRS.SYNCH3]$

// $[GPIO]
// GPIO SWCLK on PA01
#ifndef GPIO_SWCLK_PORT                         
#define GPIO_SWCLK_PORT                          gpioPortA
#endif
#ifndef GPIO_SWCLK_PIN                          
#define GPIO_SWCLK_PIN                           1
#endif

// GPIO SWDIO on PA02
#ifndef GPIO_SWDIO_PORT                         
#define GPIO_SWDIO_PORT                          gpioPortA
#endif
#ifndef GPIO_SWDIO_PIN                          
#define GPIO_SWDIO_PIN                           2
#endif

// GPIO TRACEDATA0 on PA03
#ifndef GPIO_TRACEDATA0_PORT                    
#define GPIO_TRACEDATA0_PORT                     gpioPortA
#endif
#ifndef GPIO_TRACEDATA0_PIN                     
#define GPIO_TRACEDATA0_PIN                      3
#endif

// [GPIO]$

// $[TIMER0]
// [TIMER0]$

// $[TIMER1]
// [TIMER1]$

// $[TIMER2]
// [TIMER2]$

// $[TIMER3]
// [TIMER3]$

// $[TIMER4]
// [TIMER4]$

// $[USART0]
// USART0 CLK on PC03
#ifndef USART0_CLK_PORT                         
#define USART0_CLK_PORT                          gpioPortC
#endif
#ifndef USART0_CLK_PIN                          
#define USART0_CLK_PIN                           3
#endif

// USART0 CS on PC02
#ifndef USART0_CS_PORT                          
#define USART0_CS_PORT                           gpioPortC
#endif
#ifndef USART0_CS_PIN                           
#define USART0_CS_PIN                            2
#endif

// USART0 RX on PC00
#ifndef USART0_RX_PORT                          
#define USART0_RX_PORT                           gpioPortC
#endif
#ifndef USART0_RX_PIN                           
#define USART0_RX_PIN                            0
#endif

// USART0 TX on PC01
#ifndef USART0_TX_PORT                          
#define USART0_TX_PORT                           gpioPortC
#endif
#ifndef USART0_TX_PIN                           
#define USART0_TX_PIN                            1
#endif

// [USART0]$

// $[USART1]
// [USART1]$

// $[I2C1]
// [I2C1]$

// $[PDM]
// PDM CLK on PA00
#ifndef PDM_CLK_PORT                            
#define PDM_CLK_PORT                             gpioPortA
#endif
#ifndef PDM_CLK_PIN                             
#define PDM_CLK_PIN                              0
#endif

// PDM DAT0 on PB00
#ifndef PDM_DAT0_PORT                           
#define PDM_DAT0_PORT                            gpioPortB
#endif
#ifndef PDM_DAT0_PIN                            
#define PDM_DAT0_PIN                             0
#endif

// PDM DAT1 on PB01
#ifndef PDM_DAT1_PORT                           
#define PDM_DAT1_PORT                            gpioPortB
#endif
#ifndef PDM_DAT1_PIN                            
#define PDM_DAT1_PIN                             1
#endif

// [PDM]$

// $[LETIMER0]
// [LETIMER0]$

// $[IADC0]
// [IADC0]$

// $[I2C0]
// I2C0 SCL on PC07
#ifndef I2C0_SCL_PORT                           
#define I2C0_SCL_PORT                            gpioPortC
#endif
#ifndef I2C0_SCL_PIN                            
#define I2C0_SCL_PIN                             7
#endif

// I2C0 SDA on PC06
#ifndef I2C0_SDA_PORT                           
#define I2C0_SDA_PORT                            gpioPortC
#endif
#ifndef I2C0_SDA_PIN                            
#define I2C0_SDA_PIN                             6
#endif

// [I2C0]$

// $[EUART0]
// [EUART0]$

// $[PTI]
// PTI DFRAME on PC05
#ifndef PTI_DFRAME_PORT                         
#define PTI_DFRAME_PORT                          gpioPortC
#endif
#ifndef PTI_DFRAME_PIN                          
#define PTI_DFRAME_PIN                           5
#endif

// PTI DOUT on PC04
#ifndef PTI_DOUT_PORT                           
#define PTI_DOUT_PORT                            gpioPortC
#endif
#ifndef PTI_DOUT_PIN                            
#define PTI_DOUT_PIN                             4
#endif

// [PTI]$

// $[MODEM]
// [MODEM]$

// $[CUSTOM_PIN_NAME]
#ifndef _PORT                                   
#define _PORT                                    gpioPortA
#endif
#ifndef _PIN                                    
#define _PIN                                     0
#endif

#ifndef DRV_EN_PORT                             
#define DRV_EN_PORT                              gpioPortA
#endif
#ifndef DRV_EN_PIN                              
#define DRV_EN_PIN                               4
#endif

#ifndef SPI_MISO_PORT                           
#define SPI_MISO_PORT                            gpioPortC
#endif
#ifndef SPI_MISO_PIN                            
#define SPI_MISO_PIN                             0
#endif

#ifndef SPI_MOSI_PORT                           
#define SPI_MOSI_PORT                            gpioPortC
#endif
#ifndef SPI_MOSI_PIN                            
#define SPI_MOSI_PIN                             1
#endif

#ifndef SPI_CS_PORT                             
#define SPI_CS_PORT                              gpioPortC
#endif
#ifndef SPI_CS_PIN                              
#define SPI_CS_PIN                               2
#endif

#ifndef SPI_CLK_PORT                            
#define SPI_CLK_PORT                             gpioPortC
#endif
#ifndef SPI_CLK_PIN                             
#define SPI_CLK_PIN                              3
#endif

// [CUSTOM_PIN_NAME]$

#endif // PIN_CONFIG_H

