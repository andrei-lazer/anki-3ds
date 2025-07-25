#ifndef RENDERER_H
#endif // !RENDERER_H

#include "citro2d.h"
#include <map>
#include <string>

#include "common.hpp"
#include "Font.hpp"
#include "Card.hpp"

const float questionX = float(TOP_SCREEN_WIDTH) / 2;
const float questionY = float(TOP_SCREEN_WIDTH) / 4;

const float answerX = float(TOP_SCREEN_WIDTH) / 2;
const float answerY = TOP_SCREEN_HEIGHT * 0.75;

class Renderer {
public:
    Renderer();
    ~Renderer();
    void init();
    void clearScreen();
	void renderCard(const Card& card, bool showAnswer);
private:
    C2D_TextBuf textBuf;
    C2D_Text text;
    C3D_RenderTarget* topScreen;
    C3D_RenderTarget* bottomScreen;
	std::map<std::string, Font> fontMap;
};
