#include "color.h"

ED_Color::ED_Color()
{
	this->red = 0;
	this->green = 0;
	this->blue = 0;
	this->alpha = 255;
}

ED_Color::ED_Color(int red_, int green_, int blue_, int alpha_)
{
	this->red = red_;
	this->green = green_;
	this->blue = blue_;
	this->alpha = alpha_;
}

ED_Color::~ED_Color()
{
	this->red = 0;
	this->green = 0;
	this->blue = 0;
	this->alpha = 0;
}

void ED_Color::set(ED_Color* color)
{
	this->red = color->red;
	this->green = color->green;
	this->blue = color->blue;
	this->alpha = color->alpha;
}

void ED_Color::set(int red_, int green_, int blue_, int alpha_)
{
	this->red = red_;
	this->green = green_;
	this->blue = blue_;
	this->alpha = alpha_;
}

SDL_Color ED_Color::entity()
{
	static SDL_Color color;
	color.r = this->red;
	color.g = this->green;
	color.b = this->blue;
	color.a = this->alpha;
	return color;
}
