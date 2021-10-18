/*
* File: main.cpp
*
* Description: Bare metal main file for turning on the built-in ACT LED on Raspberry Pi.
*
* Revision History:
*
* Date             Name            Change
* ----             ----            ------
* 02.10.2021       F.Kucukbay      Initial Release
*
*/

#include <stdint.h>         // Error: ‘uint32_t’ does not name a type
#include "GPIO/rpi-gpio.h"

int main();

// extern "C" makes a function name in C++ have C linkage and thus, the compiler does not mangle its name.
extern "C"
{
    // Emulate the C/C++ runtime startup.
    void startup()
    {
        // __bss_start__ and __bss_end__ are defined in the linker script.
        extern int __bss_start__;
        extern int __bss_end__;
        
        int* bss = &__bss_start__;
        int* bss_end = &__bss_end__;
        
        // Clear the .bss section.
        while( bss < bss_end )
        {
            *bss++ = 0;
        }
        
        main();
    }
}

int main()
{
    // The physical address of the GPIO Registers in the Raspberry Pi 3b+.
    // GPIORegisters * const p_gpio_regs = (GPIORegisters*) 0x3F200000;
    GPIORegisters& ref_gpio_regs = *(GPIORegisters*) PHYSICAL_GPIO_BASE;
    
    // Make sure bits 29-27 are all cleared. 7 is for 0b0111.
    ref_gpio_regs.GPFSEL2 &= ~(GPIO_BITMASK::FSEL_CLR << GPIO_BITMASK::GPIO_29_OUT_SHIFT);
    
    // Set the bit 27 to enable GPIO pin 29 as an output pin.
    ref_gpio_regs.GPFSEL2 |= (1 << GPIO_BITMASK::GPIO_29_OUT_SHIFT);
    
    while(true)
    {
        // 0 = No effect / 1 = Set GPIO pin n
        // The ACT LED is wired active HIGH, meaning that to turn the ACT LED on, we need to output a 1.
        ref_gpio_regs.GPSET0 = (1 << GPIO_BITMASK::GPIO_29_SETCLR_SHIFT);
    }

}
