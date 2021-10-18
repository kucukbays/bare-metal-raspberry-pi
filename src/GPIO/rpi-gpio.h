/*
* File: rpi-gpio.h
*
* Description: Raspberry Pi GPIO-related header file.
*
* Revision History:
*
* Date             Name            Change
* ----             ----            ------
* 02.10.2021       F.Kucukbay      Initial Release
*
*/

#ifndef RPI_GPIO_H
#define RPI_GPIO_H

/*
    arm-none-eabi-g++ version 10.3-2021.07 does not support C++17. Thus, the traditional
    #ifdef preprocessor macros are to be used for conditional compilation.

// Conditional compilation using C++17 feature "if constexpr(...)".
static uint32_t PHYSICAL_GPIO_BASE;
if constexpr (RPI0 || RPI1)
{
    PHYSICAL_GPIO_BASE = 0x20200000;
}
else if constexpr (RPI4)
{
    PHYSICAL_GPIO_BASE = 0xFE200000;
}
else
{
    // Default case is for RPI2 || RPI3 compilation.
    PHYSICAL_GPIO_BASE = 0x3F200000;
}
 */

// Conditional compilation using "#if defined(...) / #elif defined(...)" preprocessor macros.
#if defined( RPI0 ) || defined( RPI1 )
    #define PHYSICAL_GPIO_BASE       0x20200000
#elif defined( RPI4 )
    #define PHYSICAL_GPIO_BASE       0xFE200000
#else
    // Default case is for RPI2 || RPI3 compilation.
    #define PHYSICAL_GPIO_BASE       0x3F200000
#endif


// 32-bit device register.
typedef volatile uint32_t DeviceRegister;

struct GPIORegisters
{
    // GPIO Function Select Registers.
    DeviceRegister GPFSEL0;
    DeviceRegister GPFSEL1;
    DeviceRegister GPFSEL2;
    DeviceRegister GPFSEL3;
    DeviceRegister GPFSEL4;
    DeviceRegister GPFSEL5;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED0;
    
    // GPIO Output Set Registers.
    DeviceRegister GPSET0;
    DeviceRegister GPSET1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED1;
    
    // GPIO Output Clear Registers.
    DeviceRegister GPCLR0;
    DeviceRegister GPCLR1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED2;
    
    // GPIO Level Registers.
    DeviceRegister GPLEV0;
    DeviceRegister GPLEV1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED3;
    
    // GPIO Event Detect Status Registers.
    DeviceRegister GPEDS0;
    DeviceRegister GPEDS1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED4;
    
    // GPIO Rising Edge Detect Enable Registers.
    DeviceRegister GPREN0;
    DeviceRegister GPREN1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED5;
    
    // GPIO Falling Edge Detect Enable Registers.
    DeviceRegister GPFEN0;
    DeviceRegister GPFEN1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED6;
    
    // GPIO High Detect Enable Registers.
    DeviceRegister GPHEN0;
    DeviceRegister GPHEN1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED7;
    
    // GPIO Low Detect Enable Registers.
    DeviceRegister GPLEN0;
    DeviceRegister GPLEN1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED8;
    
    // GPIO Async. Rising Edge Detect Registers.
    DeviceRegister GPAREN0;
    DeviceRegister GPAREN1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED9;
    
    // GPIO Async. Falling Edge Detect Registers.
    DeviceRegister GPAFEN0;
    DeviceRegister GPAFEN1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED10;
    
    // GPIO Pull-up/down Enable Registers.
    DeviceRegister GPPUD;
    
    // GPIO Pull-up/down Enable Clock Registers.
    DeviceRegister GPPUDCLK0;
    DeviceRegister GPPUDCLK1;
    
    // Marked as reserved in the datasheet.
    DeviceRegister RESERVED11;
};

enum GPIO_BITMASK
{
    FSEL_CLR = 7,               // 7 = 0b111.
    
    GPIO_29_OUT_SHIFT = 27,     // GPIO 29 is controlled by the bits 29-27 in the GPFSEL2 function select register.
    GPIO_29_SETCLR_SHIFT = 29   // GPIO 29 is controlled by the bit 29 of the GPSET0 and GPCLR0 registers.
};

#endif // RPI_GPIO_H
