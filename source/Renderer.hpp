#ifndef RENDERER_H
#define RENDERER_H

#include "citro2d.h"
#include <map>
#include <string>

#include "common.hpp"
#include "Font.hpp"
#include "Card.hpp"
#include "Button.hpp"

class Renderer {
public:
    Renderer();
    ~Renderer();
    void init();
	void initFrame();
	void clearScreen(screen_t screenEnum);
	void renderCard(const Card& card, bool showAnswer);
	// void renderCentredText(const char* text);
	void renderButton(const Button& button, screen_t screenEnum);
private:
	C3D_RenderTarget* enumToScreen(screen_t screen);
    C2D_TextBuf C2DTextBuf;
    C2D_Text C2DText;
    C3D_RenderTarget* topScreen;
    C3D_RenderTarget* bottomScreen;
	std::map<std::string, Font> fontMap;
};

#endif // !RENDERER_H
