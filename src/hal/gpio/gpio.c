#include "../memory/gpio_map.h"
#include "gpio.h"


void gpioFunctionSelect(int gpioNum, enum GPIOMODE mode) {
    *GPFSEL1 |= (1 << 18); // 16引脚设置为输出
}

void gpioSetHigh(int gpioNum) {
    *GPCLR0 = (1 << 16);
}

void gpioSetLow(int gpioNum) {
    *GPSET0 = (1 << 16);
}