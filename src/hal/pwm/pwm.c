#include "../memory/clock_map.h"
#include "../memory/pwm_map.h"
#include "../gpio/gpio.h"


void pwmInit() {
    register CLK_DIV_REG clkDiv;
    register CLK_CNTL_REG clkCntl;
    register PWM_CTL_REG pwmCntl;

    /* 设置GPIO功能 */
    gpioFuncSelect(12, GPIO_ALT0);  // 配置GPIO12为PWM0模式
    gpioFuncSelect(13, GPIO_ALT0);  // 配置GPIO13为PWM1模式

    /* 设置PWM时钟 */
    // 停止PWM时钟
    clkCntl = *CMPWMCTL;
    clkCntl.PASSWD = CLK_PASSWORD;  //设置密码
    clkCntl.KILL = 1;               // Stop clock
    *CMPWMCTL = clkCntl;
    // wait_msec(2);
    // 设置PWM时钟频率
    clkDiv = *CMPWMDIV;
    clkDiv.PASSWD = CLK_PASSWORD;   // 设置密码
    clkDiv.DIVI = 2;                // 设置时钟
    *CMPWMDIV = clkDiv;
    // 启动PWM时钟
    clkCntl = *CMPWMCTL;
    clkCntl.SRC = 1;                // 使用晶振作为时钟源
    clkCntl.ENAB = 1;               // 使能PWM时钟
    *CMPWMCTL = clkCntl;

    /* 设置PWM */
    *((unsigned int*)PWM_CTL) = 0;
    // wait_msec(2);
    // 44.1khz, Stereo, 8-bit (54Mhz / 44100 / 2)
    *PWM_RNG1 = 0x264;
    *PWM_DAT1 = 0x99;
    *PWM_RNG2 = 0x264;
    *PWM_DAT2 = 0x99;
    // 设置PWM
    pwmCntl = *PWM_CTL;
    pwmCntl.USEF1 = 1;              // Data from FIFO
    pwmCntl.PWEN1 = 1;              // Channel enable
    pwmCntl.USEF2 = 1;              // Data from FIFO
    pwmCntl.PWEN2 = 1;              // Channel enable
    *PWM_CTL = pwmCntl;
}
