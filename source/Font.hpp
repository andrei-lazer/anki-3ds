#ifndef FONT_H
#define FONT_H

#include "citro2d.h"
#include <string>

class Font
{
public:
	Font(const char* fontPath);
	Font() = default;
	void loadFont();
	C2D_Font getFont();
public:
	C2D_Font font;
private:
	const char* path;
};



#endif // !FONT_H
