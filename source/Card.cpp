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

// void Card::initEntries(const char* qRaw, const char* aRaw)
// {	
// }

// 	void Card::initFront()
// 	C2D_TextBufClear(g_frontTextBuffer);
// 	C2D_TextFontParse(&g_frontText, questionFont, g_frontTextBuffer, questionText);
// 	C2D_TextOptimize(&g_frontText);
// }
//
// void Card::showFront()
// {
// 	drawCentredText(&g_frontText, questionX, questionY, 1.5);
// }
//
// void Card::initBack()
// {
// 	fontTextInit(questionText, &questionFont, &g_frontText, &g_frontTextBuffer);
// 	fontTextInit(answerRaw, &answerFont, &g_backText, &g_backTextBuffer);
// }
//
// void Card::showBack()
// {
// 	drawCentredText(&g_frontText, questionX, questionY, 1.5);
// 	drawCentredText(&g_backText, answerX, answerY, 1);
//
// }
