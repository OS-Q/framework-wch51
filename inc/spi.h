#pragma once

#include <stdint.h>


#define  SPI_CK_SET( n ) (SPI0_CK_SE = n)                                     //SPIÊ±ÖÓÉèÖÃº¯Êý

#define SPIMasterAssertCS() (SCS = 0)
#define SPIMasterDeassertCS() (SCS = 1)


void SPIMasterModeSet(uint8_t mode);

void CH554SPIInterruptInit();

void CH554SPIMasterWrite(uint8_t dat);

uint8_t CH554SPIMasterRead();

void SPISlvModeSet( );

void CH554SPISlvWrite(uint8_t dat);

uint8_t CH554SPISlvRead();
