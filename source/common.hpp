#ifndef COMMON_H
#define COMMON_H
#include <citro2d.h>


#define TOP_SCREEN_WIDTH 400
#define TOP_SCREEN_HEIGHT 240
#define BOTTOM_SCREEN_WIDTH 320
#define BOTTOM_SCREEN_HEIGHT 240

extern C2D_TextBuf g_frontTextBuffer;
extern C2D_TextBuf g_backTextBuffer;
extern C2D_Text g_frontText;
extern C2D_Text g_backText;

const u32 white = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
const u32 green = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
const u32 red   = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
const u32 blue  = C2D_Color32(0x00, 0x00, 0xFF, 0xFF);

const u32 background_colour = C2D_Color32(0x68, 0xB0, 0xD8, 0xFF);

void fontTextInit(const char* raw_text,
		const char* fontPath,
		C2D_Text* pText,
		C2D_TextBuf* pTextBuf
		);
void plainTextInit(const char* raw_text,
		C2D_Text* pText,
		C2D_TextBuf* pTextBuf
		);

void drawCentredText(C2D_Text* pText, float x, float y, float scale);

#endif
