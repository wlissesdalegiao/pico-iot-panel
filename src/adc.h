#ifndef ADC_H
#define ADC_H

#include <stdint.h>

// Inicializa ADC e sensor interno
void adc_init_all(void);

// Lê canal ADC (0–3 externos, 4 interno)
uint16_t adc_read_channel(uint8_t channel);

// Lê temperatura interna do Pico W
float read_internal_temperature(void);

#endif