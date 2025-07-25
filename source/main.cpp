#include <iostream>
#include <string>

#include <citro2d.h>

#include "common.hpp"
#include "OldApp.hpp"

/*
TODO
- import cards from Anki
- add a queue of cards
- Add review buttons on the bottom screen
*/

int _main(int argc, char* argv[])
{

	// Initializing
	OldApp reviewer;
	g_frontTextBuffer = C2D_TextBufNew(4096);
	g_backTextBuffer = C2D_TextBufNew(4096);
	u32 kDownPrev = -1;


	romfsInit();
	cfguInit();
	// Init libs
	gfxInitDefault();

	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();

	// load the fonts into memory
	initFonts("romfs:/chinese.bcfnt", "romfs:/didot.bcfnt");

	// Create screens
	C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
	// C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	reviewer.initCurrentCard();
	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		// exit on START press down
		u32 kDown = hidKeysHeld();
		if (kDown & KEY_START)
		{
			reviewer.shutdown();
			break;
		}

		// Clear the screen
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(top, background_colour);
        C2D_SceneBegin(top);

		// check for other (new) key presses
		if (kDown != kDownPrev){
			if (kDown & KEY_A)
			{
				reviewer.nextState();
			}
		}
		kDownPrev = kDown;

		// draw in the reviewer
		reviewer.draw();
		C3D_FrameEnd(0);
	}

	// Deinit libs
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}

int main()
{
	Renderer renderer;

	while (aptMainLoop())
	{
		hidScanInput();
		u32 kDown = hidKeysHeld();
		if (kDown & KEY_START)
		{
			break;
		}
	}
}
