#include "../memory/gpio_map.h"
#include "gpio.h"


void gpioFuncSelect(int gpioNum, enum GPIOMODE mode) {
    // 保证操作保持在寄存器中，加快计算速度
    register unsigned int r;
    int registerGroup = gpioNum / 10;
    int fselGroup = gpioNum % 10;
    switch (registerGroup) {
        case 0:
            r = *GPFSEL0;
            r &= ~(0b111<<fselGroup); // 将该位清零
            r |= (mode<<fselGroup); // 设置需要的模式
            *GPFSEL0 = r;
            break;
        case 1:
            r = *GPFSEL1;
            r &= ~(0b111<<fselGroup); // 将该位清零
            r |= (mode<<fselGroup); // 设置需要的模式
            *GPFSEL1 = r;
            break;
        case 2:
            r = *GPFSEL2;
            r &= ~(0b111<<fselGroup); // 将该位清零
            r |= (mode<<fselGroup); // 设置需要的模式
            *GPFSEL2 = r;
            break;
        case 3:
            r = *GPFSEL3;
            r &= ~(0b111<<fselGroup); // 将该位清零
            r |= (mode<<fselGroup); // 设置需要的模式
            *GPFSEL3 = r;
            break;
        case 4:
            r = *GPFSEL4;
            r &= ~(0b111<<fselGroup); // 将该位清零
            r |= (mode<<fselGroup); // 设置需要的模式
            *GPFSEL4 = r;
            break;
        case 5:
            r = *GPFSEL5;
            r &= ~(0b111<<fselGroup); // 将该位清零
            r |= (mode<<fselGroup); // 设置需要的模式
            *GPFSEL5 = r;
            break;
        default:
            // TODO: 错误处理
    }
}

void gpioSetHigh(int gpioNum) {
    if (gpioNum < 32) {
        *GPSET0 |= (1 << gpioNum);
    } else if (gpioNum < 54) {
        *GPSET1 |= (1 << (gpioNum - 32));
    } else {
        // TODO: 错误处理
    }
}

void gpioSetLow(int gpioNum) {
    if (gpioNum < 32) {
        *GPCLR0 |= (1 << gpioNum);
    } else if (gpioNum < 54) {
        *GPCLR1 |= (1 << (gpioNum - 32));
    } else {
        // TODO: 错误处理
    }
}

/*
 * 00 = Off – disable pull-up/down 
 * 01 = Enable Pull Down control 
 * 10 = Enable Pull Up control 
 * 11 = Reserved 
 */
void gpioPullDisable() {
    *GPPUD = 0b00;
}
void gpioPullDownEnable() {
    *GPPUD = 0b01;
}
void gpioPullUpEnable() {
    *GPPUD = 0b10;
}

void gpioPullClockEnable(int gpioNum) {
    if (gpioNum < 32) {
        *GPPUDCLK0 |= (0b1 << gpioNum);
    } else if (gpioNum < 54) {
        *GPPUDCLK1 |= (0b1 << (gpioNum - 32));
    } else {
        // TODO: 错误处理
    }
}

void gpioPullClockDisable(int gpioNum) {
    if (gpioNum < 32) {
        *GPPUDCLK0 &= ~(0b1 << gpioNum);
    } else if (gpioNum < 54) {
        *GPPUDCLK1 &= ~(0b1 << (gpioNum - 32));
    } else {
        // TODO: 错误处理
    }
}
