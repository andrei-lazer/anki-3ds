#ifndef DECK_H
#define DECK_H

#include <citro2d.h>
#include "Card.hpp"

class Deck
{
	public:
		Deck();
		void loadFromApkg(const char* fileName);
		Card cardList[];
};

#endif
