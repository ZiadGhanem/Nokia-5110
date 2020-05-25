#ifndef DELAY_H_
#define DELAY_H_

extern void SysTick_Delay_Init(void);
extern void SysTick_Delay_ms(volatile unsigned long Value);
extern void SysTick_Delay_us(volatile unsigned long Value);

#endif
