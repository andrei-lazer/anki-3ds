#include "Renderer.hpp"
#include <string>
#include <map>
#include "c2d/text.h"
#include "common.hpp"

Renderer::Renderer()
{
	fontMap["english"] = Font("romfs:/english.bcfnt");
	fontMap["chinese"] = Font("romfs:/chinese.bcfnt");
	init();
}

void Renderer::init()
{
	textBuf = C2D_TextBufNew(4096);

	romfsInit();
	cfguInit();
	gfxInitDefault();

	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();

	for (auto& pair : fontMap)
	{
		pair.second.loadFont();
	}

	topScreen = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	bottomScreen = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
}

void Renderer::renderCard(const Card& card, bool showAnswer)
{
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(topScreen, background_colour);
	C2D_SceneBegin(topScreen);

	// load question text
	C2D_TextBufClear(textBuf);
	C2D_TextFontParse(&text, fontMap["chinese"].getFont(), textBuf, card.questionText);
	C2D_TextOptimize(&text);

	// draw question text
	C2D_DrawText(&text, C2D_AlignCenter | C2D_WithColor, AnkiParams::questionX, AnkiParams::questionY, 0.0f, 1.5, 1.5, white);

	// load and draw answer text if needed
	if (showAnswer)
	{
		// load question text
		C2D_TextBufClear(textBuf);
		C2D_TextFontParse(&text, fontMap["english"].getFont(), textBuf, card.answerRaw);
		C2D_TextOptimize(&text);

		// draw question text
		C2D_DrawText(&text, C2D_AlignCenter | C2D_WithColor, AnkiParams::answerX, AnkiParams::answerY, 0.0f, 1.5, 1.5, white);
	}
}

Renderer::~Renderer()
{
	C2D_Fini();
	C3D_Fini();
	gfxExit();
}
