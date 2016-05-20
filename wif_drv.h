#ifndef WIFI_DRV_H
#define WIFI_DRV_H

#define WIFI_CSN_PIN 
#define WIFI_CE_PIN PD15
#define WIFI_MOSI_PIN
#define WIFI_MISO_PIN
#define WIFI_IRQ_PIN
#define WIFI_SCK_PIN


extern void NRF_PinConfigure();
extern void NRF_InterruptConfigure();

#endif 