#ifndef CARD_H
#define CARD_H

#include <citro2d.h>

class Card
{
	public:
		Card(const char* frontRaw, const char* backRaw, const char* frontFont, const char* backFont);
		void initFront();
		void showFront();
		void initBack();
		void showBack();
	private:
		const char* questionRaw;
		const char* answerRaw;
		const char* questionFont;
		const char* answerFont;

};

#endif
