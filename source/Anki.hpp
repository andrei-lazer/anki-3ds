#ifndef ANKI_H
#define ANKI_H

#include <vector>

#include "3ds.h"
#include "citro2d.h"

#include "Renderer.hpp"

class Anki
{
private:
	enum inputActions
	{
		NO_ACTION = 0,
		BREAK,
		NEXT,
		UNDO
	};
	Renderer renderer;
	bool showAnswer;
	Card* currentCard;
	std::vector<Card> deck;
	u32 cardIndex;
private:
	inputActions manageInputs();
	void nextCard();
public:
	Anki();
	void init();
	void loop();
	~Anki();
};


#endif // !ANKI_H
#define ANKI_H
