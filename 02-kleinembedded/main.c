/*#include <stdint.h>

#define PERIPHERAL_BASE (0x40000000U)
#define APB2_BASE (PERIPHERAL_BASE + 0x10000U)
#define GPIOC_BASE (APB2_BASE + 0x1000U)

#define RCC_APB2ENR_OFFSET (0x18U)
#define RCC_APB2ENR ((volatile uint32_t*) (APB2_BASE + RCC_APB2ENR_OFFSET))
#define RCC_APB2ENR_IOPCEN (0x04U)

#define GPIOC_CRH_OFFSET (0x04U)
#define GPIOC_CRH ((volatile uint32_t*) (GPIOC_BASE + GPIOC_CRH_OFFSET))
#define GPIOC_ODR_OFFSET (0x0C)
#define GPIOC_ODR ((volatile uint32_t*) (GPIOC_BASE + GPIOC_ODR_OFFSET))




void main(void)
{
    *RCC_APB2ENR |= (1 << RCC_APB2ENR_IOPCEN);

    *GPIOC_CRH = 0x44244444;

    while (1) 
    {
        // toggle led
        *GPIOC_ODR ^= (1 << 13);

        // delay
        for (uint32_t i = 0; i < 1000000; i++);
    }
}


// #define AHB_BASE (PERIPHERAL_BASE + 0x18000U)
// #define RCC_BASE (AHB_BASE + 0x3000U)

*/




/*  

// WORKS GREAT!!!

#define PERIPH_BASE     0x40000000
#define APB2PERIPH_BASE (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0x20000)

#define RCC_BASE   (AHBPERIPH_BASE + 0x00001000)
#define GPIOC_BASE (APB2PERIPH_BASE + 0x00001000)

#define RCC_APB2ENR  (*(volatile unsigned int*)(RCC_BASE + 0x18))
#define GPIOC_CRH    (*(volatile unsigned int*)(GPIOC_BASE + 0x04))
#define GPIOC_BSRR   (*(volatile unsigned int*)(GPIOC_BASE + 0x10))

void delay(volatile unsigned int count) {
    while (count--) {
        __asm__("nop");  // No Operation (ensures accurate delay)
    }
}

int main(void) {
    // Enable GPIOC Clock
    RCC_APB2ENR |= (1 << 4);  // Enable GPIOC (Bit 4 in APB2ENR)

    // Configure PC13 as output (Push-Pull, 2MHz speed)
    GPIOC_CRH &= ~(0xF << 20);  // Clear CNF and MODE bits for PC13
    GPIOC_CRH |=  (0x1 << 20);  // MODE13 = 01 (Output mode, max speed 10 MHz)
                                // CNF13  = 00 (General purpose output push-pull)

    while (1) {
        GPIOC_BSRR = (1 << 13);      // Set PC13 HIGH (LED OFF on Blue Pill)
        delay(1000000);              // Delay

        GPIOC_BSRR = (1 << (13 + 16)); // Reset PC13 LOW (LED ON)
        delay(1000000);                // Delay
    }
}

*/


