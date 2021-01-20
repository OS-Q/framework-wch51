#include <ch554.h>
#include "spi.h"

void SPIMasterModeSet(uint8_t mode)
{
    SPI0_SETUP = 0;
    if(mode == 0)
    {
        SPI0_CTRL = 0x60;
    }
    else if(mode == 3)
    {
        SPI0_CTRL = 0x68;
    }
    P1_MOD_OC &= 0x0F;
    P1_DIR_PU |= 0xB0;
    P1_DIR_PU &= 0xBF;

    // Set clock speed
    SPI0_CK_SE = 0x02;
}


void CH554SPIInterruptInit()
{
    //IP_EX |= bIP_SPI0;
    SPI0_SETUP |= bS0_IE_FIFO_OV | bS0_IE_BYTE;
    SPI0_CTRL |= bS0_AUTO_IF;
    SPI0_STAT |= 0xff;
#ifdef SPI_Interrupt
    IE_SPI0 = 1;
#endif
}


void CH554SPIMasterWrite(uint8_t dat)
{
    SPI0_DATA = dat;
    while(S0_FREE == 0);
}


uint8_t CH554SPIMasterRead()
{
    SPI0_DATA = 0xff;
    while(S0_FREE == 0);
    return SPI0_DATA;
}


void SPISlvModeSet( )
{
    SPI0_SETUP = 0x80;
    SPI0_CTRL = 0x81;
    P1_MOD_OC &= 0x0F;
    P1_DIR_PU &= 0x0F;
}


void CH554SPISlvWrite(uint8_t dat)
{
    SPI0_DATA = dat;
    while(S0_IF_BYTE==0);
    S0_IF_BYTE = 0;
}


uint8_t CH554SPISlvRead()
{
    while(S0_IF_BYTE==0);
    S0_IF_BYTE = 0;
    return SPI0_DATA;
}

