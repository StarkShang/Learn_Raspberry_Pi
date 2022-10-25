#ifndef _GPIO_MAP_H_
#define _GPIO_MAP_H_

#include "memory_map.h"

// GPIO Function Select 0
#define GPFSEL0         ((volatile unsigned int*)(MMIO_BASE+0x00200000))
// GPIO Function Select 1
#define GPFSEL1         ((volatile unsigned int*)(MMIO_BASE+0x00200004))
// GPIO Function Select 2
#define GPFSEL2         ((volatile unsigned int*)(MMIO_BASE+0x00200008))
// GPIO Function Select 3
#define GPFSEL3         ((volatile unsigned int*)(MMIO_BASE+0x0020000C))
// GPIO Function Select 4
#define GPFSEL4         ((volatile unsigned int*)(MMIO_BASE+0x00200010))
// GPIO Function Select 5
#define GPFSEL5         ((volatile unsigned int*)(MMIO_BASE+0x00200014))
// GPIO Pin Output Set 0
#define GPSET0          ((volatile unsigned int*)(MMIO_BASE+0x0020001C))
// GPIO Pin Output Set 1
#define GPSET1          ((volatile unsigned int*)(MMIO_BASE+0x00200020))
// GPIO Pin Output Clear 0
#define GPCLR0          ((volatile unsigned int*)(MMIO_BASE+0x00200028))
// GPIO Pin Output Clear 1
#define GPCLR1          ((volatile unsigned int*)(MMIO_BASE+0x0020002C))
// GPIO Pin Level 0
#define GPLEV0          ((volatile unsigned int*)(MMIO_BASE+0x00200034))
// GPIO Pin Level 1
#define GPLEV1          ((volatile unsigned int*)(MMIO_BASE+0x00200038))
// GPIO Pin Event Detect Status 0
#define GPEDS0          ((volatile unsigned int*)(MMIO_BASE+0x00200040))
// GPIO Pin Event Detect Status 1
#define GPEDS1          ((volatile unsigned int*)(MMIO_BASE+0x00200044))
// GPIO Pin Rising Edge Detect Enable 0
#define GPREN0          ((volatile unsigned int*)(MMIO_BASE+0x0020004C))
// GPIO Pin Rising Edge Detect Enable 1
#define GPREN1          ((volatile unsigned int*)(MMIO_BASE+0x00200050))
// GPIO Pin Falling Edge Detect Enable 0
#define GPFEN0          ((volatile unsigned int*)(MMIO_BASE+0x00200058))
// GPIO Pin Falling Edge Detect Enable 1
#define GPFEN1          ((volatile unsigned int*)(MMIO_BASE+0x0020005C))
// GPIO Pin High Detect Enable 0
#define GPHEN0          ((volatile unsigned int*)(MMIO_BASE+0x00200064))
// GPIO Pin High Detect Enable 1
#define GPHEN1          ((volatile unsigned int*)(MMIO_BASE+0x00200068))
// GPIO Pin Low Detect Enable 0
#define GPLEN0          ((volatile unsigned int*)(MMIO_BASE+0x00200070))
// GPIO Pin Low Detect Enable 1
#define GPLEN1          ((volatile unsigned int*)(MMIO_BASE+0x00200074))
// GPIO Pin Async. Rising Edge Detect 0
#define GPAREN0         ((volatile unsigned int*)(MMIO_BASE+0x0020007C))
// GPIO Pin Async. Rising Edge Detect 1
#define GPAREN1         ((volatile unsigned int*)(MMIO_BASE+0x00200080))
// GPIO Pin Async. Falling Edge Detect 0
#define GPAFEN0         ((volatile unsigned int*)(MMIO_BASE+0x00200088))
// GPIO Pin Async. Falling Edge Detect 1
#define GPAFEN1         ((volatile unsigned int*)(MMIO_BASE+0x0020008C))
// GPIO Pin Pull-up/down Enable
#define GPPUD           ((volatile unsigned int*)(MMIO_BASE+0x00200094))
// GPIO Pin Pull-up/down Enable Clock 0
#define GPPUDCLK0       ((volatile unsigned int*)(MMIO_BASE+0x00200098))
// GPIO Pin Pull-up/down Enable Clock 1
#define GPPUDCLK1       ((volatile unsigned int*)(MMIO_BASE+0x0020009C))

#endif
