#ifndef _UART_H_
#define _UART_H_

void uartInit();
void uartSend(unsigned int);
char uartGetChar();
void uartSendString(char*);

#endif
