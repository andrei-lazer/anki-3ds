#include "Font.hpp"

Font::Font(const char* fontPath)
{
	path = fontPath;
}

void Font::loadFont()
{
	font = C2D_FontLoad(path);
}

C2D_Font Font::getFont()
{
	return font;
}

