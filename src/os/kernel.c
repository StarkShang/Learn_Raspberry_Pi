#include "../hal/pwm/pwm.h"
#include "../hal/gpio/gpio.h"

void main() {
    gpioFuncSelect(20, GPIO_OUTPUT);  // 配置GPIO20为输出模式
    gpioFuncSelect(21, GPIO_OUTPUT);  // 配置GPIO21为输出模式
    gpioSetHigh(20);
    gpioSetLow(21);
    pwmInit();
    while(1) {
    }
}
