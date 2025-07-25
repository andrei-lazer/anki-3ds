#include "Anki.hpp"


Anki::Anki()
{
	renderer.init();
}

void Anki::run()
{
}

Anki::~Anki()
{
	C3D_Fini();
	C2D_Fini();
	gfxExit();
}
