#ifndef _PWM_MAP_H_
#define _PWM_MAP_H_

#include "./memory_map.h"

#define PWM_CTL         ((volatile PWM_CTL_REG*)(MMIO_BASE+0x0020C000))
#define PWM_STA         ((volatile PWM_STA_REG*)(MMIO_BASE+0x0020C000))
#define PWM_DMAC        ((volatile PWM_DMAC_REG*)(MMIO_BASE+0x0020C000))
#define PWM_RNG1        ((volatile unsigned int*)(MMIO_BASE+0x0020C000))
#define PWM_DAT1        ((volatile unsigned int*)(MMIO_BASE+0x0020C000))
#define PWM_FIF1        ((volatile unsigned int*)(MMIO_BASE+0x0020C000))
#define PWM_RNG2        ((volatile unsigned int*)(MMIO_BASE+0x0020C000))
#define PWM_DAT2        ((volatile unsigned int*)(MMIO_BASE+0x0020C000))


typedef struct {
    unsigned int PWEN1: 1;
    unsigned int MODE1: 1;
    unsigned int RPTL1: 1;
    unsigned int SBIT1: 1;
    unsigned int POLA1: 1;
    unsigned int USEF1: 1;
    unsigned int CLRF1: 1;
    unsigned int MSEN1: 1;
    unsigned int PWEN2: 1;
    unsigned int MODE2: 1;
    unsigned int RPTL2: 1;
    unsigned int SBIT2: 1;
    unsigned int POLA2: 1;
    unsigned int USEF2: 1;
    unsigned int Reserved: 1;
    unsigned int MSEN2: 1;
} PWM_CTL_REG;

typedef struct {
    // Fifo Full Flag. If this bit is high FIFO is full.
    unsigned int FULL1: 1;
    // Fifo Empty Flag. If this bit is high FIFO is empty.
    unsigned int EMPT1: 1;
    /*
     * Fifo Write Error Flag. 
     * WERR1 bit sets to high when a write when full error occurs.
     * Software must clear this bit by writing 1. Writing 0 to this bit has no effect.
     */
    unsigned int WERR1: 1;
    /*
     * Fifo Read Error Flag.
     * RERR1 bit sets to high when a read when empty error occurs.
     * Software must clear this bit by writing 1. Writing 0 to this bit has no effect.
     */
    unsigned int RERR1: 1;
    /*
     * GAPOi. bit indicates that there has been a gap between transmission of two consecutive data from FIFO.
     * This may happen when FIFO gets empty after state machine has sent a word and waits for the next. 
     * If control bit RPTLi is set to high this event will not occur.
     * Software must clear this bit by writing 1.
     * Writing 0 to this bit has no effect. 
     */
    unsigned int GAPO1: 1;
    unsigned int GAPO2: 1;
    unsigned int GAPO3: 1;
    unsigned int GAPO4: 1;
    /*
     * Bus Error Flag.
     * BERR sets to high when an error has occurred while writing to registers via APB.
     * This may happen if the bus tries to write successively to same set of registers faster than the synchroniser block can cope with.
     * Multiple switching may occur and contaminate the data during synchronisation.
     * Software should clear this bit by writing 1.
     * Writing 0 to this bit has no effect. 
     */
    unsigned int BERR: 1;
    /*
     * STAi bit indicates the current state of the channel which is useful for debugging purposes.
     * 0 means the channel is not currently transmitting.
     * 1 means channel is transmitting data.
     */
    unsigned int STA1: 1;
    unsigned int STA2: 1;
    unsigned int STA3: 1;
    unsigned int STA4: 1;
} PWM_STA_REG;

typedef struct {
    // DMA Threshold for DREQ signal
    unsigned int DREQ: 8;
    // DMA Threshold for PANIC signal 
    unsigned int PANIC: 8;
    unsigned int Reserved: 15;
    /*
     * DMA Enable
     * 0: DMA disabled 
     * 1: DMA enabled
     */
    unsigned int ENAB: 1;
} PWM_DMAC_REG;

#endif
