#include "../memory/uart_map.h"
#include "../gpio/gpio.h"
#include "uart.h"

/**
 * Set baud rate and characteristics (115200 8N1) and map to GPIO
 */
void uartInit()
{
    register unsigned int r;
    /* initialize UART */
    *AUX_ENABLE |=1;       // enable UART1, AUX mini uart
    *AUX_MU_CNTL = 0;
    *AUX_MU_LCR = 3;       // 8 bits
    *AUX_MU_MCR = 0;
    *AUX_MU_IER = 0;
    *AUX_MU_IIR = 0xc6;    // disable interrupts
    *AUX_MU_BAUD = 270;    // 115200 baud
    /* map UART1 to GPIO pins */
    gpioFuncSelect(14, GPIO_FUNC0); // GPIO14
    gpioFuncSelect(15, GPIO_FUNC0); // GPIO15
    gpioPullDisable();            // enable pins 14 and 15
    r=150; while(r--) { asm volatile("nop"); } // 等待150个时钟周期，手册要求
    gpioPullClockEnable(14);
    gpioPullClockEnable(15);
    r=150; while(r--) { asm volatile("nop"); }
    gpioPullClockDisable(14); // flush GPIO setup
    gpioPullClockDisable(15);
    *AUX_MU_CNTL = 3;      // enable Tx, Rx
}

/**
 * Send a character
 */
void uartSend(unsigned int c) {
    /* wait until we can send */
    do{asm volatile("nop");}while(!(*AUX_MU_LSR&0x20));
    /* write the character to the buffer */
    *AUX_MU_IO=c;
}

/**
 * Receive a character
 */
char uartGetChar() {
    char r;
    /* wait until something is in the buffer */
    do{asm volatile("nop");}while(!(*AUX_MU_LSR&0x01));
    /* read it and return */
    r=(char)(*AUX_MU_IO);
    /* convert carriage return to newline */
    return r=='\r'?'\n':r;
}

/**
 * Display a string
 */
void uartSendString(char *s) {
    while(*s) {
        /* convert newline to carriage return + newline */
        if(*s=='\n')
            uartSend('\r');
        uartSend(*s++);
    }
}
