#ifndef _GPIO_H_
#define _GPIO_H_

enum GPIOMODE {
    GPIO_INPUT  = 0b000,
    GPIO_OUTPUT = 0b001,
    GPIO_ALT0   = 0b100,
    GPIO_ALT1   = 0b101,
    GPIO_ALT2   = 0b110,
    GPIO_ALT3   = 0b111,
    GPIO_ALT4   = 0b011,
    GPIO_ALT5   = 0b010,
};


void gpioFuncSelect(int, enum GPIOMODE);
void gpioSetHigh(int);
void gpioSetLow(int);
extern void gpioPullDisable();
extern void gpioPullDownEnable();
extern void gpioPullUpEnable();
extern void gpioPullClockEnable(int);
extern void gpioPullClockDisable(int);

#endif
