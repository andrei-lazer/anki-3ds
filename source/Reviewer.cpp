#include "Reviewer.hpp"
#include <iostream>

Reviewer::Reviewer(void)
{
	qa_state = FRONT;
	current_card.initEntries("感觉", "feeling");
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

void Reviewer::initCurrentCard(void)
{
	current_card.initFront();
	current_card.initBack();
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
