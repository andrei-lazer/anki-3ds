#ifndef BUTTON_H
#define BUTTON_H

#include "common.hpp"
#include <string>

class Button {
public:
    using Callback = void(*)();

	Button(float x, float y, float width, float height, u32 pressColour, u32 unpressColour, const char* label, Callback callback);

    void draw(C2D_TextBuf textBuf, C2D_Font font);
	void handleTouch(touchPosition touch);

    float x, y, width, height;
    const char* label;
	u32 currentColour;
private:
	u32 unpressColour;
	u32 pressColour;
    Callback onClick;
	bool isTouched;
};

#endif // !BUTTON_H
