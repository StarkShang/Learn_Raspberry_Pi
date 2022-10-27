#ifndef _CLOCK_MAP_H_
#define _CLOCK_MAP_H_

// Clock Manager General Purpose Clocks Control
#define CMGP0CTL        ((volatile unsigned int*)(MMIO_BASE+0x00101070))
// Clock Manager General Purpose Clock Divisors
#define CMGP0DIV        ((volatile unsigned int*)(MMIO_BASE+0x00101074))
// Clock Manager General Purpose Clocks Control
#define CMGP1CTL        ((volatile unsigned int*)(MMIO_BASE+0x00101078))
// Clock Manager General Purpose Clock Divisors
#define CMGP1DIV        ((volatile unsigned int*)(MMIO_BASE+0x0010107C))
// Clock Manager General Purpose Clocks Control
#define CMGP2CTL        ((volatile unsigned int*)(MMIO_BASE+0x00101080))
// Clock Manager General Purpose Clock Divisors
#define CMGP2DIV        ((volatile unsigned int*)(MMIO_BASE+0x00101084))

// 寄存器地址在数据手册里面没有，详见https://elinux.org/BCM2835_registers
// 
#define CMPWMCTL        ((volatile CLK_CNTL_REG*)(MMIO_BASE+0x001010A0))
#define CMPWMDIV        ((volatile CLK_DIV_REG*)(MMIO_BASE+0x001010A4))

// Clock Manager password “5a”, for GPIO Clocks
#define CLK_PASSWORD 0x5A

typedef struct {
    /*
     * Clock source
     * 0 = GND 
     * 1 = oscillator 
     * 2 = testdebug0 
     * 3 = testdebug1 
     * 4 = PLLA per 
     * 5 = PLLC per 
     * 6 = PLLD per 
     * 7 = HDMI auxiliary 
     * 8-15 = GND 
     * To avoid lock-ups and glitches do not change this control while BUSY=1 and do not change this control at the same time as asserting ENAB. 
     */
    unsigned int SRC: 4;
    /*
     * Enable the clock generator
     * This requests the clock to start or stop without glitches.
     * The output clock will not stop immediately because the cycle must be allowed to complete to avoid glitches.
     * The BUSY flag will go low when the final cycle is completed. 
     */
    unsigned int ENAB: 1;
    /*
     * Kill the clock generator
     * 0 = no action 
     * 1 = stop and reset the clock generator 
     * This is intended for test/debug only.
     * Using this control may cause a glitch on the clock generator output. 
     */
    unsigned int KILL: 1;
    unsigned int Unused1: 1;
    /*
     * lock generator is running
     * Indicates the clock generator is running. 
     * To avoid glitches and lock-ups, clock sources and setups must not be changed while this flag is set.
     */
    unsigned int BUSY: 1;
    /*
     * Invert the clock generator output
     * This is intended for use in test/debug only.
     * Switching this control will generate an edge on the clock generator output.
     * To avoid output glitches do not switch this control while BUSY=1. 
     */
    unsigned int FLIP: 1;
    /*
     * MASH control
     * 0 = integer division 
     * 1 = 1-stage MASH (equivalent to non-MASH dividers) 
     * 2 = 2-stage MASH 
     * 3 = 3-stage MASH 
     * To avoid lock-ups and glitches do not change this control while BUSY=1 and do not change this control at the same time as asserting ENAB. 
     */
    unsigned int MASH: 2;
    unsigned int Unused2: 13;
    // Clock Manager password “5a”
    unsigned int PASSWD: 8;
} CLK_CNTL_REG;

typedef struct {
    /*
     * Fractional part of divisor
     * To avoid lock-ups and glitches do not change this control while BUSY=1. 
     */
    unsigned int DIVF: 12;
    /*
     * Integer part of divisor
     * This value has a minimum limit determined by the MASH setting.
     * See text for details. To avoid lock-ups and glitches do not change this control while BUSY=1.
     */
    unsigned int DIVI: 12;
    // Clock Manager password “5a”
    unsigned int PASSWD: 8;
} CLK_DIV_REG;

#endif
