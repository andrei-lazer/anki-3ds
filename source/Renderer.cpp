#include "Renderer.hpp"
#include <string>
#include <map>
#include "c2d/text.h"

// class Renderer {
// private:
//     C2D_TextBuf textBuf;
//     C2D_Text text;
//     C3D_RenderTarget* topScreen;
//     C3D_RenderTarget* bottomScreen;
//
// public:
//     Renderer();
//     ~Renderer();
//     void init();
//     void renderCard(const Card& card, bool showAnswer);
//     void renderMenu(const Deck& deck);
//     void clearScreen();
// };


Renderer::Renderer()
{
	fontMap["english"] = Font("romfs:/chinese.bcfnt");
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

void Renderer::clearScreen()
{
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_TargetClear(topScreen, C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF));
    C2D_TargetClear(bottomScreen, C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF));
    C3D_FrameEnd(0);
}

void Renderer::renderCard(const Card& card, bool showAnswer)
{
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	C2D_TargetClear(topScreen, background_colour);
	C2D_SceneBegin(topScreen);

	// load question text
	C2D_TextBufClear(textBuf);
	C2D_TextFontParse(&text, fontMap["english"].getFont(), textBuf, card.questionRaw);
	C2D_TextOptimize(&text);

	// draw question text
	C2D_DrawText(&text, C2D_AlignCenter | C2D_WithColor, questionX, questionY, 0.0f, 1.5, 1.5, white);

	// load and draw answer text if needed
	if (showAnswer)
	{
		// load question text
		C2D_TextBufClear(textBuf);
		C2D_TextFontParse(&text, fontMap["chinese"].getFont(), textBuf, card.answerRaw);
		C2D_TextOptimize(&text);

		// draw question text
		C2D_DrawText(&text, C2D_AlignCenter | C2D_WithColor, answerX, answerY, 0.0f, 1.5, 1.5, white);
	}


}

Renderer::~Renderer()
{
	C2D_Fini();
	C3D_Fini();
	gfxExit();
}
