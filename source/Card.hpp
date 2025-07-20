#ifndef CARD_H
#define CARD_H

#include <citro2d.h>

class Card
{
	public:
		Card();
		void initEntries(const char* qRaw, const char* aRaw);
		void initFront();
		void showFront();
		void initBack();
		void showBack();
	// private:
		const char* questionRaw;
		const char* answerRaw;
};

#endif
