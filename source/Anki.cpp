#include "Anki.hpp"
#include "c2d/base.h"
#include "c3d/renderqueue.h"
#include "common.hpp"
#include <cstring>
#include <functional>


Anki::Anki()
{
	showAnswer = false;
	renderer.init();
	deck = {
		Card("感觉", "feeling"),
		Card("你好", "hello"),
		Card("名字", "name"),
		Card("看", "look")
	};
	cardIndex = 0;
	currentCard = &deck[cardIndex];
}

Anki::inputActions Anki::manageInputs()
{
	static u32 kDownPrev;
	hidScanInput();

	// exit on START press down
	u32 kDown = hidKeysHeld();
	if (kDown & KEY_START)
	{
		return BREAK;
	}
	// check keys that have just been pressed down
	if (kDown != kDownPrev)
	{
		kDownPrev = kDown;
		if (kDown & KEY_A)
		{
			return NEXT;
		}
	}

	return NO_ACTION;
}

void Anki::nextCard()
{
	if (cardIndex + 1 < deck.size())
	{
		currentCard = &deck[++cardIndex];
	}

}

void testFunc()
{
	return;
}

void Anki::run()
{
	// create "Again" button
	Button againButton(10, 0, BOTTOM_SCREEN_WIDTH/4, BOTTOM_SCREEN_HEIGHT, green, red, "Again", testFunc);

	Button passButton(BOTTOM_SCREEN_WIDTH*0.75, 0, BOTTOM_SCREEN_WIDTH/4, BOTTOM_SCREEN_HEIGHT, green, red, "Pass", testFunc);

	// create "Pass" button

	while (aptMainLoop())
	{
		switch (manageInputs())
		{
			case NEXT:
				if (showAnswer)
				{
					showAnswer = false;
					nextCard();
				}
				else
				{
					showAnswer = true;
				}
				break;
			case BREAK:
				goto loop_end;
				break;
			case NO_ACTION:
			default:
				break;
		}

		// check touch screen
		touchPosition touch;
		hidTouchRead(&touch);
		passButton.handleTouch(touch);
		againButton.handleTouch(touch);


		
		renderer.initFrame();
		// show the current card

		renderer.clearScreen(TOP);

		renderer.renderCard(*currentCard, showAnswer);
		renderer.clearScreen(BOTTOM);
		renderer.renderButton(passButton, BOTTOM);
		renderer.renderButton(againButton, BOTTOM);

		C3D_FrameEnd(0);
	}
loop_end:
	return;
}

Anki::~Anki()
{
	C3D_Fini();
	C2D_Fini();
	gfxExit();
}
