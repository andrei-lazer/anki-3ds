#include "Anki.hpp"
#include "c3d/renderqueue.h"
#include "common.hpp"
#include <cstring>


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

void Anki::loop()
{
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
		// show the current card
		renderer.renderCard(*currentCard, showAnswer);

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
