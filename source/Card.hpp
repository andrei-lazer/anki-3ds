#ifndef CARD_H
#define CARD_H

#include <citro2d.h>

class Card
{
	public:
		Card(const char* qRaw, const char* aRaw);
		// void initEntries(const char* qRaw, const char* aRaw);
		// void initFront();
		// void showFront();
		// void initBack();
		// void showBack();
	// private:
		const char* questionText;
		const char* answerRaw;
};

#endif
