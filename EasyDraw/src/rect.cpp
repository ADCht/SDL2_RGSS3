#include "rect.h"

ED_Rect::ED_Rect()
{
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

ED_Rect::ED_Rect(int x_, int y_, int width_, int height_)
{
	this->x = x_;
	this->y = y_;
	this->width = width_;
	this->height = height_;
}

ED_Rect::~ED_Rect()
{
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

void ED_Rect::set(ED_Rect *rect)
{
	this->x = rect->x;
	this->y = rect->y;
	this->width = rect->width;
	this->height = rect->height;
}

void ED_Rect::set(int x_, int y_, int width_, int height_)
{
	this->x = x_;
	this->y = y_;
	this->width = width_;
	this->height = height_;
}

void ED_Rect::empty()
{
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

SDL_Rect* ED_Rect::entity()
{
	static SDL_Rect pRect;
	pRect.x = this->x;
	pRect.y = this->y;
	pRect.w = this->width;
	pRect.h = this->height;
	return &pRect;
}
