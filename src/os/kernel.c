#include "../hal/gpio/gpio.h"

void main() {
    gpioFunctionSelect(1, GPIO_OUTPUT);
    while(1) {
        for(int tim = 0; tim < 500000; tim++)
            gpioSetHigh(5);
        for(int tim = 0; tim < 500000; tim++)
            gpioSetLow(5);
    }
}
