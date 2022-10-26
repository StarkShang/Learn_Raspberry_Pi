#ifndef _UART_H_
#define _UART_H_

void uartInit();
void uartSendChar(unsigned char);
char uartGetChar();
void uartSendString(char*);

#endif
