#pragma once
#include "SDL.h"

class ED_Color
{
public:
	ED_Color();
	ED_Color(int red_, int green_, int blue_, int alpha_ = 255);
	~ED_Color();

	void set(ED_Color* color);
	void set(int red_, int green_, int blue_, int alpha_ = 255);

	SDL_Color entity();

public:
	int red;
	int green;
	int blue;
	int alpha;
};
