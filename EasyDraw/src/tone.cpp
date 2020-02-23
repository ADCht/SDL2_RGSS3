#include "tone.h"

ED_Tone::ED_Tone()
{
	this->red = 0;
	this->green = 0;
	this->blue = 0;
	this->grey = 0;
}

ED_Tone::ED_Tone(int red_, int green_, int blue_, int grey_)
{
	this->red = red_;
	this->green = green_;
	this->blue = blue_;
	this->grey = grey_;
}

ED_Tone::~ED_Tone()
{
	this->red = 0;
	this->green = 0;
	this->blue = 0;
	this->grey = 0;
}

void ED_Tone::set(ED_Tone* tone)
{
	this->red = tone->red;
	this->green = tone->green;
	this->blue = tone->blue;
	this->grey = tone->grey;
}

void ED_Tone::set(int red_, int green_, int blue_, int grey_)
{
	this->red = red_;
	this->green = green_;
	this->blue = blue_;
	this->grey = grey_;
}
