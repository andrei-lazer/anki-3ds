#include "common.hpp"

C2D_TextBuf g_frontTextBuffer;
C2D_TextBuf g_backTextBuffer;
C2D_Text g_frontText;
C2D_Text g_backText;

void fontTextInit(const char* raw_text,
		const char* fontPath,
		C2D_Text* pText,
		C2D_TextBuf* pTextBuf
		)
{
	C2D_TextBufClear(*pTextBuf);
	C2D_Font font = C2D_FontLoad(fontPath);

	C2D_TextFontParse(pText, font, *pTextBuf, raw_text);
	C2D_TextOptimize(pText);
}


void plainTextInit(const char* raw_text,
		C2D_Text* pText,
		C2D_TextBuf* pTextBuf
		)
{
	C2D_TextBufClear(*pTextBuf);

	C2D_TextParse(pText, *pTextBuf, raw_text);
	C2D_TextOptimize(pText);
}

void drawCentredText(C2D_Text* pText, float x, float y, float scale)
{
	C2D_DrawText(pText, C2D_AlignCenter | C2D_WithColor, x, y, 0.0f, scale, scale, white);
}
