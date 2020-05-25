#include <tm4c123gh6pm.h>
#include "SPI.h"

void SSI0_Master_Init(void)
{
	SYSCTL->RCGCGPIO |= (1<<0);	//Enable PORTA
	
	SYSCTL->RCGCSSI |= (1<<0);		//Enable SSI0 Clock
	
		//Wait 3 clock cycles for clock to be unlocked
	__ASM volatile("nop");
	__ASM volatile("nop");
	__ASM volatile("nop");
	
	GPIOA->DIR |= (SSI0Clk | SSI0Fss | SSI0Tx);		//Set Pins as output
	
	GPIOA->AFSEL |= (SSI0Clk | SSI0Fss | SSI0Tx);	//Enable Pins Alternate Functions
	
	GPIOA->PCTL |= (0x2<<8 | 0x2<<12 | 0x2<<20);	//Set Alternate Function
	
	GPIOA->DEN |= (SSI0Clk | SSI0Fss | SSI0Tx);	//Enable Digital Function
	
	SSI0->CR1 &= ~(1<<1);	//Make sure the SPI is disabled
	
	SSI0->CR1 = 0;
	SSI0->CC = 0;
	
	//Setup Register for 1 Mbps Clock 
	SSI0->CPSR = 2;
	SSI0->CR0 |= (0x7<<8 | 0x7<<0);
	
	SSI0->CR1 |= (1<<1);	//Enable SSI0
}

void SSI0_Master_Write(unsigned char Data)
{
	GPIOA->DATA &= ~(SSI0Fss);
	
	SSI0->DR = Data;
	while(!(SSI0->SR & (1<<0)));
	
	GPIOA->DATA |= (SSI0Fss);
}
