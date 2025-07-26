#ifndef COMMON_H
#define COMMON_H
#include <citro2d.h>

#define TOP_SCREEN_WIDTH 400
#define TOP_SCREEN_HEIGHT 240
#define BOTTOM_SCREEN_WIDTH 320
#define BOTTOM_SCREEN_HEIGHT 240

namespace AnkiParams
{
	extern float questionX;
	extern float questionY;
					
	extern float answerX;
	extern float answerY;
}

const u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
const u32 green = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
const u32 red   = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
const u32 blue  = C2D_Color32(0x00, 0x00, 0xFF, 0xFF);

const u32 background_colour = C2D_Color32(0x68, 0xB0, 0xD8, 0xFF);

#endif
