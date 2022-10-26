#include "../hal/uart/uart.h"

void main() {
    // set up serial console
    uartInit();
    // say hello
    uartSendString("Hello World!\n");
    // echo everything back
    while(1) {
        uartSendChar(uartGetChar());
    }
}
