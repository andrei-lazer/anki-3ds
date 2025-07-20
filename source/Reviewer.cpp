#include "Reviewer.hpp"

Reviewer::Reviewer(void) : current_card("感觉", "feeling", "romfs:/chinese_font.bcfnt",  "romfs:/arial.bcfnt")
{
	qa_state = FRONT;
	current_card = Card("感觉", "feeling", "romfs:/chinese_font.bcfnt",  "romfs:/arial.bcfnt");
}

review_state Reviewer::getState(void)
{
	return qa_state;
}

review_state Reviewer::nextState(void)
{
	if (qa_state == FRONT)
	{
		qa_state = BACK;
	}
	else if (qa_state == BACK)
	{
		qa_state = FRONT;
	}
	return qa_state;
}

void Reviewer::shutdown(void)
{
	return;
}

void Reviewer::draw(void)
{
	if (qa_state == FRONT)
	{
		current_card.showFront();
	}
	else if (qa_state == BACK)
	{
		current_card.showBack();
	}
}
