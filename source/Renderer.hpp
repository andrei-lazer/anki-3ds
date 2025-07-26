#ifndef RENDERER_H
#define RENDERER_H

#include "citro2d.h"
#include <map>
#include <string>

#include "common.hpp"
#include "Font.hpp"
#include "Card.hpp"

class Renderer {
public:
    Renderer();
    ~Renderer();
    void init();
    void clearScreen();
	void renderCard(const Card& card, bool showAnswer);
// private:
    C2D_TextBuf textBuf;
    C2D_Text text;
    C3D_RenderTarget* topScreen;
    C3D_RenderTarget* bottomScreen;
	std::map<std::string, Font> fontMap;
};

#endif // !RENDERER_H
