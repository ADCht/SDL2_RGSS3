#pragma once
#include "SDL.h"

class ED_Rect
{
public:
	ED_Rect();
	ED_Rect(int x_, int y_, int width_, int height_);
	~ED_Rect();

	void set(ED_Rect *rect);
	void set(int x_, int y_, int width_, int height_);
	void empty();

	SDL_Rect* entity();

public:
	int x;
	int y;
	int width;
	int height;
};