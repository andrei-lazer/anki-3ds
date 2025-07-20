#ifndef REVIEWER_H
#define REVIEWER_H

#include <citro2d.h>

#include "Card.hpp"

typedef enum review_state {
	FRONT = 0,
	BACK = 1
} review_state_t;

class Reviewer
{
	public:
		Reviewer();
		review_state getState(void);
		review_state nextState(void);

		void initCurrentCard(void);
		void draw(void);
		void shutdown(void);
		Card current_card;
	private:
		review_state qa_state;
};

#endif
