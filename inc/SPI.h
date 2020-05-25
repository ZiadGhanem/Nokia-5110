#ifndef SPI_H_
#define SPI_H_

#define SSI0Clk (1<<2)
#define SSI0Fss	(1<<3)
#define SSI0Tx	(1<<5)

extern void SSI0_Master_Init(void);
extern void	SSI0_Master_Write(unsigned char Data);

#endif
