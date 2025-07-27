#ifndef ANKI_H
#define ANKI_H

#include <vector>

#include "3ds.h"
#include "citro2d.h"

#include "Renderer.hpp"
#include "Button.hpp"

class Anki
{
	enum inputActions
	{
		NO_ACTION = 0,
		BREAK,
		NEXT,
		UNDO
	};

public:
	Anki();
	void init();
	void run();
	~Anki();
private:
	inputActions manageInputs();
	void nextCard();
private:
	Renderer renderer;
	bool showAnswer;
	Card* currentCard;
	std::vector<Card> deck;
	u32 cardIndex;
};


#endif // !ANKI_H
#define ANKI_H
