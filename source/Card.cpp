#include "Card.hpp"
#include "common.hpp"

const float questionX = float(TOP_SCREEN_WIDTH) / 2;
const float questionY = float(TOP_SCREEN_WIDTH) / 4;

const float answerX = float(TOP_SCREEN_WIDTH) / 2;
const float answerY = TOP_SCREEN_HEIGHT * 0.75;

Card::Card(const char* qRaw, const char* aRaw)
{
	questionText = qRaw;
	answerRaw =  aRaw;
	return;
}
