#ifndef _GPIO_H_
#define _GPIO_H_

enum GPIOMODE {
    GPIO_INPUT = 0,
    GPIO_OUTPUT = 1,
    GPIO_FUNC0,
    GPIO_FUNC1,
    GPIO_FUNC2,
    GPIO_FUNC3,
    GPIO_FUNC4,
    GPIO_FUNC5,
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
