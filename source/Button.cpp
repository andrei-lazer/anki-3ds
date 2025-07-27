#include "Button.hpp"
#include "Anki.hpp"

Button::Button(float x, float y, float width, float height, u32 pressColour, u32 unpressColour, const char* label, Callback callback)
	: x(x), y(y), width(width), height(height), label(label), currentColour(unpressColour), unpressColour(unpressColour), pressColour(pressColour), onClick(callback), isTouched(false)
{}

void Button::handleTouch(touchPosition touch)
{
	if (touch.px >= x && touch.px <= x + width &&
			touch.py >= y && touch.py <= y + height)
	{
		if (!isTouched)
		{
			currentColour = pressColour;
		}
		isTouched = true;
	}
	else
	{
		if (isTouched)
		{
			currentColour = unpressColour;
		}
		isTouched = false;
	}
}

