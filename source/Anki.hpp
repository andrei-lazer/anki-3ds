#ifndef ANKI_H
#define ANKI_H

#include "3ds.h"
#include "citro2d.h"

#include "Renderer.hpp"

class Anki
{
public:
	Anki();
	void init();
	void run();
	~Anki();

private:
	Renderer renderer;
	bool showingAnswer;
};


#endif // !ANKI_H
#define ANKI_H
