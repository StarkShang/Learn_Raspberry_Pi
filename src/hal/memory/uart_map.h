#ifndef _UART_MAP_H_
#define _UART_MAP_H_

#include "memory_map.h"

#define AUX_IRQ         ((volatile unsigned int*)(MMIO_BASE+0x00215000))
#define AUX_ENABLE      ((volatile AUX_ENABLE_REG*)(MMIO_BASE+0x00215004))
#define AUX_MU_IO       ((volatile unsigned int*)(MMIO_BASE+0x00215040))
#define AUX_MU_IER      ((volatile unsigned int*)(MMIO_BASE+0x00215044))
#define AUX_MU_IIR      ((volatile unsigned int*)(MMIO_BASE+0x00215048))
#define AUX_MU_LCR      ((volatile unsigned int*)(MMIO_BASE+0x0021504C))
#define AUX_MU_MCR      ((volatile unsigned int*)(MMIO_BASE+0x00215050))
#define AUX_MU_LSR      ((volatile unsigned int*)(MMIO_BASE+0x00215054))
#define AUX_MU_MSR      ((volatile unsigned int*)(MMIO_BASE+0x00215058))
#define AUX_MU_SCRATCH  ((volatile unsigned int*)(MMIO_BASE+0x0021505C))
#define AUX_MU_CNTL     ((volatile AUX_MU_CNTL_REG*)(MMIO_BASE+0x00215060))
#define AUX_MU_STAT     ((volatile unsigned int*)(MMIO_BASE+0x00215064))
#define AUX_MU_BAUD     ((volatile unsigned int*)(MMIO_BASE+0x00215068))

typedef struct {
    char MiniUART: 1;
    char SPI1: 1;
    char SPI2: 1;
} AUX_ENABLE_REG;

typedef struct {
    /*
     * If this bit is set the mini UART receiver is enabled.
     * If this bit is clear the mini UART receiver is disabled.
     */
    char RxEnable: 1;
    /*
     * If this bit is set the mini UART transmitter is enabled.
     * If this bit is clear the mini UART transmitter is disabled.
     */
    char TxEnable: 1;
    /*
     * If this bit is set the RTS line will de-assert if the receive FIFO reaches it 'auto flow' level.
     * In fact the RTS line will behave as an RTR (Ready To Receive) line.
     * If this bit is clear the RTS line is controlled by the AUX_MU_MCR_REG register bit 1.
     */
    char RxAutoFlowEnable: 1;
    /*
     * If this bit is set the transmitter will stop if the CTS line is de-asserted.
     * If this bit is clear the transmitter will ignore the status of the CTS line.
     */
    char TxAutoFlowEnable: 1;
    /*
     *These two bits specify at what receiver FIFO level the RTS line is de-asserted in auto-flow mode.
     * 00 : De-assert RTS when the receive FIFO has 3 empty spaces left.
     * 01 : De-assert RTS when the receive FIFO has 2 empty spaces left.
     * 10 : De-assert RTS when the receive FIFO has 1 empty space left.
     * 11 : De-assert RTS when the receive FIFO has 4 empty spaces left.
     */
    char RtsAutoFlowLevel: 2;
    /*
     * This bit allows one to invert the RTS auto flow operation polarity. 
     * If set the RTS auto flow assert level is low.
     * If clear the RTS auto flow assert level is high.
     */
    char RtsAssertLevel: 1;
    /* 
     * This bit allows one to invert the CTS auto flow operation polarity.
     * If set the CTS auto flow assert level is low.
     * If clear the CTS auto flow assert level is high.
     */
    char CtsAssertLevel: 1;
} AUX_MU_CNTL_REG;


#endif
