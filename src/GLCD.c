#include <tm4c123gh6pm.h>
#include <stdio.h>
#include "GLCD.h"

unsigned char Buffer[GLCD_ROWS][GLCD_WIDTH];
unsigned char Memo_Buffer[GLCD_ROWS][GLCD_WIDTH];

const unsigned char Numbers[10][6][20]=
{
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00},{0x00, 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00},{0x00, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x01, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0xe1, 0xff, 0xff, 0xff, 0x7f, 0x1f, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xbf, 0x9f, 0x8f, 0x87, 0x83, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00},{0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x03, 0xe1, 0xe1, 0xe0, 0xe0, 0xe0, 0xf0, 0xf1, 0xff, 0xbf, 0xbf, 0x9f, 0x0f, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0xc0, 0xc0, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xc3, 0xc7, 0xff, 0xff, 0xff, 0xff, 0x7c, 0x00, 0x00},{0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x80, 0xe0, 0xf8, 0xfe, 0x7f, 0x1f, 0x07, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x3e, 0x3f, 0x3f, 0x3f, 0x3d, 0x3c, 0x3c, 0x3c, 0x3c, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3c, 0x3c, 0x3c, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc1, 0xe1, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00},{0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x00},{0x00, 0x00, 0xf0, 0xfe, 0xff, 0xff, 0xff, 0xc7, 0xc1, 0xe1, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xc1, 0x81, 0x00, 0x00, 0x00},{0x00, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xe3, 0x81, 0x81, 0x81, 0x81, 0xc3, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf8, 0xfe, 0xff, 0xff, 0x1f, 0x07, 0x01, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xfc, 0xff, 0xff, 0x7f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x07, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xf1, 0xe0, 0xe0, 0xf1, 0xff, 0xff, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x00},{0x00, 0x00, 0xf8, 0xfc, 0xfe, 0xff, 0xff, 0xc7, 0x83, 0x81, 0x81, 0x83, 0xc7, 0xff, 0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00},{0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	{{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00},{0x00, 0x00, 0x7e, 0xff, 0xff, 0xff, 0xff, 0xe1, 0xc0, 0xc0, 0xc0, 0xc0, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00},{0x00, 0x00, 0x00, 0xc0, 0xc1, 0x83, 0x83, 0x83, 0x83, 0x83, 0xc3, 0xc3, 0xf1, 0xff, 0xff, 0xff, 0x3f, 0x07, 0x00, 0x00},{0x00, 0x00, 0x00, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00},{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
};

const unsigned char Points[6][4]=
{
	{0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00},
	{0x70, 0x70, 0x70, 0x70},
	{0x0e, 0x0e, 0x0e, 0x0e},
	{0x00, 0x00, 0x00, 0x00},
	{0x00, 0x00, 0x00, 0x00}
};

typedef struct{
	const char Data[9];
	const char Length;
}Characters_Structure;

Characters_Structure ASCII[128]={
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0x00,0x00},2},
	{{0xBE,0x00},2},
	{{0x06,0x00,0x06,0x00},4},
	{{0x28,0x7C,0x28,0x7C,0x28,0x00},6},
	{{0x48,0x54,0xFE,0x54,0x24,0x00},6},
	{{0x04,0x4A,0x24,0x10,0x08,0x24,0x52,0x20,0x00},9},
	{{0x44,0xAA,0x92,0xAA,0x44,0xA0,0x00},7},
	{{0x04,0x02,0x00},3},
	{{0x3C,0x42,0x81,0x00},4},
	{{0x81,0x42,0x3C,0x00},4},
	{{0x54,0x38,0x7C,0x38,0x54,0x00},6},
	{{0x10,0x38,0x10,0x00},4},
	{{0x80,0x40,0x00},3},
	{{0x10,0x10,0x10,0x00},4},
	{{0x80,0x00},2},
	{{0x40,0x20,0x10,0x08,0x04,0x00},6},
	{{0x7C,0x82,0x82,0x82,0x7C,0x00},6},
	{{0x88,0x84,0xFE,0x80,0x80,0x00},6},
	{{0x84,0xC2,0xA2,0x92,0x8C,0x00},6},
	{{0x44,0x82,0x92,0x92,0x6C,0x00},6},
	{{0x20,0x30,0x28,0x24,0xFE,0x00},6},
	{{0x8E,0x8A,0x8A,0x8A,0x72,0x00},6},
	{{0x7C,0xA4,0x92,0x92,0x64,0x00},6},
	{{0x82,0x42,0x22,0x12,0x0E,0x00},6},
	{{0x44,0xAA,0x92,0xAA,0x44,0x00},6},
	{{0x0C,0x12,0x12,0x0A,0xFC,0x00},6},
	{{0x28,0x00},2},
	{{0x80,0x50,0x00},3},
	{{0x10,0x28,0x44,0x00},4},
	{{0x28,0x28,0x28,0x00},4},
	{{0x44,0x28,0x10,0x00},4},
	{{0x04,0x02,0xA2,0x12,0x0C,0x00},6},
	{{0x38,0x44,0xBA,0xAA,0xBA,0xA4,0x18,0x00},8},
	{{0xF8,0x24,0x22,0x24,0xF8,0x00},6},
	{{0xFE,0x92,0x92,0x92,0x6C,0x00},6},
	{{0x7C,0x82,0x82,0x82,0x44,0x00},6},
	{{0xFE,0x82,0x82,0x44,0x38,0x00},6},
	{{0xFE,0x92,0x92,0x82,0x82,0x00},6},
	{{0xFE,0x12,0x12,0x02,0x02,0x00},6},
	{{0x7C,0x82,0x92,0x92,0x66,0x00},6},
	{{0xFE,0x10,0x10,0x10,0xFE,0x00},6},
	{{0x82,0x82,0xFE,0x82,0x82,0x00},6},
	{{0x70,0x80,0x80,0x80,0x7E,0x00},6},
	{{0xFE,0x10,0x28,0x44,0x82,0x00},6},
	{{0xFE,0x80,0x80,0x80,0x80,0x00},6},
	{{0xFE,0x04,0x08,0x04,0xFE,0x00},6},
	{{0xFE,0x08,0x10,0x20,0xFE,0x00},6},
	{{0x7C,0x82,0x82,0x82,0x7C,0x00},6},
	{{0xFE,0x12,0x12,0x12,0x0C,0x00},6},
	{{0x7C,0x82,0xA2,0xC2,0xFC,0x00},6},
	{{0xFC,0x32,0x32,0x52,0x8C,0x00},6},
	{{0x8C,0x92,0x92,0x92,0x62,0x00},6},
	{{0x02,0x02,0xFE,0x02,0x02,0x00},6},
	{{0x7E,0x80,0x80,0x80,0x7E,0x00},6},
	{{0x3E,0x40,0x80,0x40,0x3E,0x00},6},
	{{0x7E,0x80,0x40,0x80,0x7E,0x00},6},
	{{0xC6,0x28,0x10,0x28,0xC6,0x00},6},
	{{0x06,0x08,0xF0,0x08,0x06,0x00},6},
	{{0xC2,0xA2,0x92,0x8A,0x86,0x00},6},
	{{0xFE,0x81,0x81,0x00},4},
	{{0x06,0x00},2},
	{{0x81,0x81,0xFE,0x00},4},
	{{0x04,0x02,0x01,0x02,0x04,0x00},6},
	{{0x80,0x80,0x80,0x00},4},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6},
	{{0x40,0xA8,0xA8,0xA8,0x70,0x00},6},
	{{0xFE,0x90,0x90,0x90,0x60,0x00},6},
	{{0x70,0x88,0x88,0x88,0x50,0x00},6},
	{{0x60,0x90,0x90,0x90,0xFE,0x00},6},
	{{0x70,0xA8,0xA8,0xA8,0x90,0x00},6},
	{{0x20,0xF8,0x24,0x04,0x04,0x00},6},
	{{0x08,0x94,0x94,0x94,0x7C,0x00},6},
	{{0xFE,0x20,0x10,0x10,0xE0,0x00},6},
	{{0x80,0x88,0xFA,0x80,0x80,0x00},6},
	{{0x40,0x80,0x88,0x7A,0x00,0x00},6},
	{{0xFE,0x10,0x28,0x44,0x80,0x00},6},
	{{0x00,0x82,0xFE,0x80,0x00,0x00},6},
	{{0xF0,0x08,0xF0,0x08,0xF0,0x00},6},
	{{0xF8,0x10,0x08,0x08,0xF0,0x00},6},
	{{0x70,0x88,0x88,0x88,0x70,0x00},6},
	{{0xF8,0x48,0x48,0x48,0x30,0x00},6},
	{{0x30,0x48,0x48,0x48,0xF8,0x00},6},
	{{0xF8,0x10,0x08,0x08,0x10,0x00},6},
	{{0x90,0xA8,0xA8,0xA8,0x48,0x00},6},
	{{0x08,0x7C,0x88,0x88,0x00,0x00},6},
	{{0x78,0x80,0x80,0x80,0xF8,0x00},6},
	{{0x38,0x40,0x80,0x40,0x38,0x00},6},
	{{0x78,0x80,0x40,0x80,0x78,0x00},6},
	{{0x88,0x50,0x20,0x50,0x88,0x00},6},
	{{0x88,0x50,0x20,0x10,0x08,0x00},6},
	{{0x88,0xC8,0xA8,0x98,0x88,0x00},6},
	{{0x18,0x66,0x81,0x81,0x00},5},
	{{0xFE,0x00},2},
	{{0x81,0x81,0x66,0x18,0x00},5},
	{{0x10,0x08,0x18,0x10,0x08,0x00},6},
	{{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},6}
};


static char Memo_CurrentRow=0,Memo_CurrentColumn=0,Memo_OldRow=0,Memo_OldColumn=0,Memo_CurrentCharacter=0,Memo_BeforeSave_Row=0,Memo_BeforeSave_Column=0;
	
static Characters_Structure *Memo_PtrChar[252];

void GLCD_Init(void)
{
	//Initialize SPI
	SSI0_Master_Init();
	
	SYSCTL -> RCGCGPIO |= (1<<0);
	
		//Wait 3 clock cycles for clock to be unlocked
	__ASM volatile("nop");
	__ASM volatile("nop");
	__ASM volatile("nop");
	
	//Set Data/Command,Reset,Chip Enable pins as output
	GLCD_PORT->DIR |= (GLCD_DC | GLCD_RST | GLCD_BL);
	GLCD_PORT->DEN |= (GLCD_DC | GLCD_RST | GLCD_BL);
	GLCD_PORT->DR8R |= (GLCD_BL);
	

	//Reset the GLCD
	GLCD_PORT->DATA &= ~GLCD_RST;
	for(int i=0;i<10;i++);
	GLCD_PORT->DATA |= GLCD_RST;

	//Initialize the GLCD
	GLCD_Send(GLCD_CMD,0x21);	//Chip is active,Horizontal Addressing, Use extended Instruction Set
	GLCD_Send(GLCD_CMD,0xA0);	//Set Operation Voltage to 5 Volts
	GLCD_Send(GLCD_CMD,0x04);	//Set Temperature Coefficient 0
	GLCD_Send(GLCD_CMD,0x14);	//Set Bias System
	GLCD_Send(GLCD_CMD,0x20);	//Chip is active,Horizontal Addressing, Use Basic Instruction Set
	GLCD_Send(GLCD_CMD,0x0C);	//Set Display Configuration to Normal Mode

	GLCD_ClearBuffer();

}

void GLCD_BackLight(BackLight_Settings BackLight_Config)
{
	switch(BackLight_Config)
	{
		case BackLight_Off:
			GLCD_PORT->DATA &= ~GLCD_BL;
			break;
		
		case BackLight_On:
			GLCD_PORT->DATA |= GLCD_BL;
			break;
		
		case BackLight_Toggle:
			GLCD_PORT->DATA ^= GLCD_BL;
			break;
		
		default:
			break;
	}
}

BackLight_Settings GLCD_GetCurrentBackLightState(void)
{
	if(GLCD_PORT->DATA & GLCD_BL)
	{
		return BackLight_On;
	}
	else
	{
		return BackLight_Off;
	}
}

void GLCD_Send(unsigned char Data_CMD,unsigned char Byte)
{
	if(Data_CMD)	//If Data was selected
		GLCD_PORT->DATA |= (GLCD_DC);	//Set Data/Command pin
	else	//If Command was selected
		GLCD_PORT->DATA &= ~(GLCD_DC);	//Clear Data/Command pin

	//Kick the byte
	SSI0_Master_Write(Byte);
}

void GLCD_SetContrast(unsigned char Contrast)
{
	GLCD_Send(GLCD_CMD,0x21);	//Chip is active,Horizontal Addressing, Use extended Instruction Set
	GLCD_Send(GLCD_CMD,0x80 | Contrast);
	GLCD_Send(GLCD_CMD,0x20);	//Chip is active,Horizontal Addressing, Use Basic Instruction Set
}

void GLCD_SetPosition(unsigned char Row,unsigned char Column)
{
	if((Row < GLCD_ROWS) && (Column<GLCD_WIDTH))
	{
		GLCD_Send(GLCD_CMD,0x80 | Column);	//Set X Address
		GLCD_Send(GLCD_CMD,0x40 | Row);	//Set Y Address
	}
}

void GLCD_Clear(void)
{
	GLCD_SetPosition(0,0);
	for(int i=0;i<GLCD_SIZE;i++)
	{
		GLCD_Send(GLCD_DATA,0x00);
	}
}

void GLCD_Update(void)
{
	int i,j;
	
	GLCD_SetPosition(0,0);
	for(i=0;i<GLCD_ROWS;i++)
	{
		for(j=0;j<GLCD_WIDTH;j++)
		{
			GLCD_Send(GLCD_DATA,Buffer[i][j]);
		}
	}
}
void GLCD_ClearBuffer(void)
{
	int i,j;
	for(i=0;i<GLCD_ROWS;i++)
	{
		for(j=0;j<GLCD_WIDTH;j++)
		{
			Buffer[i][j]=0;
		}
	}
}

void GLCD_SetPixel(unsigned char X,unsigned char Y,unsigned char BW)
{
	if((X<GLCD_WIDTH) && (Y<GLCD_HEIGHT))
	{
		//Example: If X=2 & Y=11 , So The Buffer index = 2+(11/8)*84=2+1*84=86
		if(BW)
			Buffer[Y/8][X] |= 1<<(Y%8);
		else
			Buffer[Y/8][X] &= ~(1<<(Y%8));
	}
}

void GLCD_PrintString(unsigned char Row,unsigned char Column,char *String)
{
	int Count;
	unsigned char Current_Row=Row;
	unsigned char Current_Column=Column;
	Characters_Structure *PtrChar;
	
	while(*String)
	{
		PtrChar=&ASCII[*String];
		
		if(Current_Column > GLCD_WIDTH-(PtrChar->Length))
		{
			Current_Column = 0;
			Current_Row ++;
			if(Current_Row==GLCD_ROWS)
			{
				Current_Row=0;
				Current_Column=0;
			}
		}
		
		for(Count=0;Count<(PtrChar->Length);Count++)
		{
			Buffer[Current_Row][Current_Column]=(PtrChar->Data)[Count];
			Current_Column++;
		}

		String++;
	}
}

void GLCD_PrintNumber(unsigned char Row,unsigned char Column,int Number)
{
	char String[11];
	
	sprintf(String,"%d",Number);
	
	GLCD_PrintString(Row,Column,String);
}

void GLCD_DrawLine(unsigned char X1,unsigned char Y1,unsigned char X2,unsigned char Y2,unsigned char BW)
{
	#define Sign(Value)	((Value>0)? 1 : ((Value==0)? 0 : (-1)))
	unsigned char dx,dy,sdx,sdy,dxabs,dyabs,px,py,x,y,i;

	dx=X2-X1;
	dy=Y2-Y1;

	sdx=Sign(dx);
	sdy=Sign(dy);

	dxabs=(dx>0)? dx:-dx;
	dyabs=(dy>0)? dy:-dy;

	x=0;
	y=0;

	px=X1;
	py=Y1;

	if(dxabs>=dyabs)
	{
		for(i=0;i<=dxabs;i++)
		{
			y+=dyabs;
			if(y>=dxabs)
			{
				y-=dxabs;
				py+=sdy;
			}
			GLCD_SetPixel(px,py,BW);
			px+=sdx;
		}
	}

	else
	{
		for(i=0;i<=dyabs;i++)
		{
			x+=dxabs;
			if(x>=dyabs)
			{
				x-=dyabs;
				px+=sdx;
			}
			GLCD_SetPixel(px,py,BW);
			py+=sdy;
		}
	}
}

void GLCD_DrawRect(unsigned char X,unsigned char Y,unsigned char Width,unsigned char Height,unsigned char BW)
{
	unsigned char X2 = X + Width;
	unsigned char Y2 = Y + Height;
	GLCD_DrawLine(X,Y,X2,Y,BW);
	GLCD_DrawLine(X,Y2,X2,Y2,BW);
	GLCD_DrawLine(X,Y,X,Y2,BW);
	GLCD_DrawLine(X2,Y,X2,Y2,BW);

}

void GLCD_FillRect(unsigned char X,unsigned char Y,unsigned char Width,unsigned char Height,unsigned char BW)
{
	int i,j;
	unsigned char X2 = X + Width;
	unsigned char Y2 = Y + Height;

	for(i = Y ; i<=Y2 ; i++)
	{
		for(j=X; j<=X2 ; j++)
		{
			GLCD_SetPixel(j,i,BW);
		}
	}
}

void GLCD_DrawCircle(unsigned char X_Center,unsigned char Y_Center,unsigned char Radius,unsigned char BW)
{
	int X=0,
		Y=Radius,
		dp=3-2*Radius;

	while(X<=Y)
	{
		GLCD_SetPixel(X+X_Center,Y+Y_Center,BW);
		GLCD_SetPixel(-X+X_Center,-Y+Y_Center,BW);
		GLCD_SetPixel(X+X_Center,-Y+Y_Center,BW);
		GLCD_SetPixel(-X+X_Center,Y+Y_Center,BW);
		GLCD_SetPixel(Y+X_Center,X+Y_Center,BW);
		GLCD_SetPixel(-Y+X_Center,-X+Y_Center,BW);
		GLCD_SetPixel(-Y+X_Center,X+Y_Center,BW);
		GLCD_SetPixel(Y+X_Center,-X+Y_Center,BW);

		if(dp<=0)
	    {
			dp+=4*X+6;
	    }

	    else
	    {
	     dp+=4*(X-Y)+10;
	     Y--;
	    }

		X++;
	}
}


void GLCD_DrawImage(const unsigned char Image[][84])
{
	char i,j;
	
	for(i=0;i<GLCD_ROWS;i++)
	{
		for(j=0;j<GLCD_WIDTH;j++)
		{
			Buffer[i][j]=Image[i][j];
		}
	}
}


void GLCD_SetMenu(char *String,int Selection)
{
	int Row=0,Column=0,Characters_Count,LinesSkip_Count=0;
	Characters_Structure *PtrChar;
	
	while(LinesSkip_Count < Selection-5)
	{
		if(*String == '\n')
		{
			LinesSkip_Count++;
		}
		String++;
	}
	
	while(*String)
	{
		PtrChar=&ASCII[*String];
		
		if((Column > GLCD_WIDTH-(PtrChar->Length)) || (*String == '\n'))
		{
			if((Row == Selection) || ((Row == GLCD_ROWS-1) && (Selection > 5)))
			{
				while(Column < GLCD_WIDTH-1)
				{
					Buffer[Row][Column]=0xFF;
					Column++;
				}
			}
			
			while(*String != '\n')
			{
				String++;
			}
			
			Row++;
			Column=0;

		}
		else
		{
			if((Row == Selection) || ((Row == GLCD_ROWS-1) && (Selection > 5)))
			{
				for(Characters_Count=0;Characters_Count<(PtrChar->Length);Characters_Count++)
				{
					Buffer[Row][Column]=~(PtrChar->Data)[Characters_Count];
					Column++;
				}
			}

			else
			{
				for(Characters_Count=0;Characters_Count<(PtrChar->Length);Characters_Count++)
				{
					Buffer[Row][Column]=(PtrChar->Data)[Characters_Count];
					Column++;
				}
			}
		}

		String++;
	}
}


void GLCD_DisplayClock(int Hours_H,int Hours_L,int Minutes_H,int Minutes_L,int Seconds)
{
	
	for(int i=1;i<GLCD_ROWS-1;i++)	//Skip first & last rows because they are empty
	{
		for(int j=0;j<20;j++)
		{
			Buffer[i][j]=Numbers[Hours_H][i][j];
			Buffer[i][j+20]=Numbers[Hours_L][i][j];
			Buffer[i][j+44]=Numbers[Minutes_H][i][j];
			Buffer[i][j+63]=Numbers[Minutes_L][i][j];
		}
	}
	
	if(Seconds)
	{
		for(int i=2;i<4;i++)	//Skip first & last two rows as they are empty
		{
			for(int j=40;j<44;j++)
			{
				Buffer[i][j]=Points[i][j-40];
			}
		}
	}
}


void Memo_PrintChar(char Character,Keypad_KeyState_Type Keypad_KeyState)
{
	int Count;
	Characters_Structure *PtrNewChar;
	PtrNewChar=&ASCII[Character];
	
	if(Keypad_KeyState==Keypad_OldKey)
	{
		for(Count=Memo_OldColumn;Count<(Memo_OldColumn+(Memo_PtrChar[Memo_CurrentCharacter]->Length));Count++)
		{
			Buffer[Memo_OldRow][Count]=0;
		}
		
		Memo_CurrentRow=Memo_OldRow;
		Memo_CurrentColumn=Memo_OldColumn;
	}
	
	else
	{
		Memo_OldRow=Memo_CurrentRow;
		Memo_OldColumn=Memo_CurrentColumn;
		Memo_PtrChar[Memo_CurrentCharacter]=PtrNewChar;
		Memo_CurrentCharacter++;
	}
		
	if(Memo_CurrentColumn > GLCD_WIDTH-(PtrNewChar->Length))
	{
		Memo_CurrentColumn = 0;
		Memo_CurrentRow ++;
		if(Memo_CurrentRow==GLCD_ROWS)
		{
			Memo_CurrentRow=0;
			Memo_CurrentColumn=0;
		}
	}
		
	for(Count=0;Count<(PtrNewChar->Length);Count++)
	{
		Buffer[Memo_CurrentRow][Memo_CurrentColumn]=(PtrNewChar->Data)[Count];
		Memo_CurrentColumn++;
	}
}


void Memo_DeleteChar(void)
{
	if(Memo_CurrentCharacter>0)
	{	
		Memo_CurrentCharacter--;
	}
	
	for(int Count=Memo_OldColumn;Count<(Memo_OldColumn+(Memo_PtrChar[Memo_CurrentCharacter]->Length));Count++)
	{
		Buffer[Memo_OldRow][Count]=0;
	}
	
	Memo_CurrentRow=Memo_OldRow;
	Memo_CurrentColumn=Memo_OldColumn;
	
	if(Memo_OldColumn>((Memo_PtrChar[Memo_CurrentCharacter-1]->Length)-1))
	{
		Memo_OldColumn-=(Memo_PtrChar[Memo_CurrentCharacter-1]->Length);
	}
	else if(Memo_OldRow>0)
	{
			Memo_OldColumn=84-(Memo_PtrChar[Memo_CurrentCharacter-1]->Length);
			Memo_OldRow--;
	}
}


void Memo_NextLine(void)
{
	if(Memo_CurrentRow<5)
	{
		Memo_CurrentColumn=0;
		Memo_OldColumn=0;
		
		Memo_CurrentRow++;
		Memo_OldRow++;
	}
}


extern void Memo_Save(void)
{
	for(int Row=0;Row<GLCD_ROWS-1;Row++)
	{
		for(int Column=0;Column<GLCD_WIDTH-1;Column++)
		{
			Memo_Buffer[Row][Column]=Buffer[Row][Column];
		}
	}
	
	Memo_BeforeSave_Row=Memo_CurrentRow;
	Memo_BeforeSave_Column=Memo_CurrentColumn;
}


void Memo_Update(void)
{
	for(int Row=0;Row<GLCD_ROWS-1;Row++)
	{
		for(int Column=0;Column<GLCD_WIDTH-1;Column++)
		{
			Buffer[Row][Column]=Memo_Buffer[Row][Column];
		}
	}
}

void Memo_Back(void)
{
	Memo_CurrentRow=Memo_BeforeSave_Row;
	Memo_CurrentColumn=Memo_BeforeSave_Column;

	Memo_OldRow=Memo_BeforeSave_Row;
	Memo_OldColumn=Memo_BeforeSave_Column;
}
	
	

