#include "Renderer.hpp"
#include <string>
#include <map>
#include "c2d/text.h"
#include "c3d/renderqueue.h"
#include "common.hpp"

Renderer::Renderer()
{
	fontMap["english"] = Font("romfs:/english.bcfnt");
	fontMap["chinese"] = Font("romfs:/chinese.bcfnt");
	init();
}

Renderer::~Renderer()
{
	C2D_Fini();
	C3D_Fini();
	gfxExit();
}

void Renderer::init()
{
	C2DTextBuf = C2D_TextBufNew(4096);

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

void Renderer::initFrame()
{
	C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
}

void Renderer::renderCard(const Card& card, bool showAnswer)
{
	C2D_SceneBegin(topScreen);

	// load question text
	C2D_TextBufClear(C2DTextBuf);
	C2D_TextFontParse(&C2DText, fontMap["chinese"].getFont(), C2DTextBuf, card.questionText);
	C2D_TextOptimize(&C2DText);

	// draw question text
	C2D_DrawText(&C2DText, C2D_AlignCenter | C2D_WithColor, AnkiParams::questionX, AnkiParams::questionY, 0.0f, 1.5, 1.5, white);

	// load and draw answer text if needed
	if (showAnswer)
	{
		// load question text
		C2D_TextBufClear(C2DTextBuf);
		C2D_TextFontParse(&C2DText, fontMap["english"].getFont(), C2DTextBuf, card.answerRaw);
		C2D_TextOptimize(&C2DText);

		// draw question text
		C2D_DrawText(&C2DText, C2D_AlignCenter | C2D_WithColor, AnkiParams::answerX, AnkiParams::answerY, 0.0f, 1.5, 1.5, white);
	}
}

C3D_RenderTarget* Renderer::enumToScreen(screen_t screenEnum)
{
	switch (screenEnum)
	{
		case TOP:
			return topScreen;
			break;
		case BOTTOM:
		default:
			return bottomScreen;
			break;
	}
}

void Renderer::clearScreen(screen_t screenEnum)
{
	C2D_TargetClear(enumToScreen(screenEnum), background_colour);
}


void Renderer::renderButton(const Button& button, screen_t screenEnum)
{
	C2D_SceneBegin(enumToScreen(screenEnum));

	// draw the shape of the button
	C2D_DrawRectangle(button.x, button.y, 0, button.width, button.height, button.currentColour, button.currentColour, button.currentColour, button.currentColour);

	// draw the text centred in the rectangle
	float textWidth, textHeight;
	C2D_TextGetDimensions(&C2DText, 1.0f, 1.0f, &textWidth, &textHeight);
	float textX = button.x + (button.width  - textWidth)  / 2.0f;
	float textY = button.y + (button.height - textHeight) / 2.0f;

	C2D_TextBufClear(C2DTextBuf);
	C2D_TextFontParse(&C2DText, fontMap["english"].getFont(), C2DTextBuf, button.label);
	C2D_TextOptimize(&C2DText);

	C2D_DrawText(&C2DText, C2D_WithColor, textX, textY, 0.0f, 1, 1, white);
}
