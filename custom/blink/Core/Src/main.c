//#include "stm32g431xx.h"
/*
//__attribute__((optimize("O0")))
void delay() {
    for (uint32_t i = 0; i < 2000000; i++) asm("nop");
}

int main() {
    RCC->AHB2ENR = 2;

    while(1) {
        GPIOB->MODER = 1 << 26;
        GPIOB->BSRR = 1<<13;
        delay();
        GPIOB->BSRR = 1<<29;
        delay();
    }
}
*/
/*
#define LED_Pin GPIO_BSRR_BS13 
#define LED_GPIO_Port GPIOB

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))
#define READ_BIT(REG, BIT)    ((REG) & (BIT))
#define CLEAR_REG(REG)        ((REG) = (0x0))
#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))
#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
#define POSITION_VAL(VAL)     (__CLZ(__RBIT(VAL)))

inline void init(void);

void delay(void);

int main() {
    RCC->AHB2ENR = RCC_AHB2ENR_GPIOBEN;
    uint32_t i = 0;

    while(1) {
        GPIOB->MODER = 1 << 26;
        GPIOB->BSRR = 1<<13;
        for (i = 0; i < 2000000; i++) asm("nop");
        GPIOB->BSRR = 1<<29;
        for (; i < 4000000; i++) asm("nop");
    }
}

// possibility of waiting 1 tick less
void delay(void) {
    for (uint32_t i = 0; i < 2000000; i++) {
        asm("nop");
    }
    //int16_t ms = 500;
    //(void)SysTick->CTRL;
    
    //while (ms != 0) {
    //    if(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) {
    //        ms--;
    //    }
    //}
}

void init(void) {
    //SCB->VTOR = VECT_TAB_BASE_ADDRESS | VECT_TAB_OFFSET;

    //SET_BIT(RCC->AHB2ENR, RCC_APB2ENR_SYSCFGEN);
    //(void)READ_BIT(RCC->AHB2ENR, RCC_APB2ENR_SYSCFGEN);

    //SET_BIT(RCC->AHB1ENR, RCC_APB1ENR1_PWREN);
    //(void)READ_BIT(RCC->AHB1ENR, RCC_APB1ENR1_PWREN);

    //NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

    //NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),15, 0));

    //SET_BIT(PWR->CR3, PWR_CR3_UCPD_DBDIS);
    
    //MODIFY_REG(FLASH->ACR, FLASH_ACR_LATENCY, FLASH_ACR_LATENCY_4WS);
    //while (READ_BIT(FLASH->ACR, FLASH_ACR_LATENCY) != FLASH_ACR_LATENCY_4WS) {}

    //MODIFY_REG(PWR->CR1, PWR_CR1_VOS, PWR_CR1_VOS_0);

    //SET_BIT(RCC->CR, RCC_CR_HSEON);
    //while(READ_BIT(RCC->CR, RCC_CR_HSERDY) != RCC_CR_HSERDY) {}

    //MODIFY_REG(RCC->PLLCFGR, RCC_PLLCFGR_PLLSRC | RCC_PLLCFGR_PLLM | RCC_PLLCFGR_PLLN | RCC_PLLCFGR_PLLR,
    //         RCC_PLLCFGR_PLLSRC_HSE | 0 | (18 << RCC_PLLCFGR_PLLN_Pos) | 0);
    //SET_BIT(RCC->PLLCFGR, RCC_PLLCFGR_PLLREN);
    //SET_BIT(RCC->CR, RCC_CR_PLLON);
    //while (READ_BIT(RCC->CR, RCC_CR_PLLRDY) != RCC_CR_PLLRDY) {}

    //MODIFY_REG(RCC->CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
    //MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_CFGR_HPRE_DIV2);
    //while (READ_BIT(RCC->CFGR, RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {}

    //for (__IO uint32_t i = (170 >> 1); i !=0; i--);

    //MODIFY_REG(RCC->CFGR, RCC_CFGR_HPRE, RCC_CFGR_HPRE_DIV1);
    //MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE1, RCC_CFGR_PPRE1_DIV1);
    //MODIFY_REG(RCC->CFGR, RCC_CFGR_PPRE2, RCC_CFGR_PPRE2_DIV1);

    //SysTick->LOAD  = (uint32_t)((16000000 / 1000U) - 1UL);
    //SysTick->VAL   = 0UL;
    //SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_ENABLE_Msk;

    //SystemCoreClock = 144000000; 

    //SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN);
    //__IO uint32_t tmp3 = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOFEN);
    //(void)tmp3;
    //SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
    RCC->AHB2ENR = RCC_AHB2ENR_GPIOBEN;
    asm("nop");
    //(void)READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOBEN);
    //SET_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN);
    //__IO uint32_t tmp5 = READ_BIT(RCC->AHB2ENR, RCC_AHB2ENR_GPIOAEN);
    //(void)tmp5;

    //MODIFY_REG(LED_GPIO_Port->OSPEEDR, (GPIO_OSPEEDR_OSPEED0 << (POSITION_VAL(LED_Pin) * 2U)), (0 << (POSITION_VAL(LED_Pin) * 2U)));
    //MODIFY_REG(LED_GPIO_Port->OTYPER, LED_Pin, (LED_Pin * 0));
    //MODIFY_REG(LED_GPIO_Port->PUPDR, (GPIO_PUPDR_PUPD0 << (POSITION_VAL(LED_Pin) * 2U)), (0 << (POSITION_VAL(LED_Pin) * 2U)));
    //MODIFY_REG(LED_GPIO_Port->MODER, (GPIO_MODER_MODE0 << (POSITION_VAL(LED_Pin) * 2U)),
    //      (GPIO_MODER_MODE0_0 << (POSITION_VAL(LED_Pin) * 2U)));
    //GPIOB->MODER &= ~(0b11 << 26);
    GPIOB->MODER = 0xF7FFFFFF;
}
*/
