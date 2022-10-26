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
    AUX_ENABLE->MiniUART = 1;           // 使能miniUART
    *((unsigned int*)AUX_MU_CNTL) = 0;  // 清零MiniUART控制寄存器
    *AUX_MU_LCR = 3;                    // 8 bits
    *AUX_MU_MCR = 0;
    *AUX_MU_IER = 0;
    *AUX_MU_IIR = 0xC6;                 // disable interrupts
    *AUX_MU_BAUD = 270;                 // 115200 baud
    /* map UART1 to GPIO pins */
    gpioFuncSelect(14, GPIO_ALT5);      // GPIO14
    gpioFuncSelect(15, GPIO_ALT5);      // GPIO15
    gpioPullDisable(); // enable pins 14 and 15
    r=150; while(r--) { asm volatile("nop"); }  // 等待150个时钟周期，手册要求
    gpioPullClockEnable(14);
    gpioPullClockEnable(15);
    r=150; while(r--) { asm volatile("nop"); }
    gpioPullClockDisable(14);           // flush GPIO setup
    gpioPullClockDisable(15);
    AUX_MU_CNTL->RxEnable = 1;          // 使能接收
    AUX_MU_CNTL->TxEnable = 1;          // 使能发送

}

/**
 * Send a character
 */
void uartSendChar(unsigned char ch) {
    /* wait until we can send */
    do{ asm volatile("nop"); } while(!(*AUX_MU_LSR & 0x20));
    /* write the character to the buffer */
    *AUX_MU_IO = ch;
}

/**
 * Receive a character
 */
char uartGetChar() {
    char r;
    /* wait until something is in the buffer */
    do{asm volatile("nop");} while(!(*AUX_MU_LSR & 0x01));
    /* read it and return */
    r=(char)(*AUX_MU_IO);
    /* convert carriage return to newline */
    return r=='\r'?'\n':r;
}

/**
 * Display a string
 */
void uartSendString(char *buffer) {
    while(*buffer) {
        /* convert newline to carriage return + newline */
        if(*buffer == '\n') uartSendChar('\r');
        uartSendChar(*buffer++);
    }
}
