#pragma once
#include "SDL.h"

class ED_Tone
{
public:
	ED_Tone();
	ED_Tone(int red_, int green_, int blue_, int grey_ = 0);
	~ED_Tone();

	void set(ED_Tone* tone);
	void set(int red_, int green_, int blue_, int grey_ = 0);

	void entity() {};

public:
	int red;
	int green;
	int blue;
	int grey;

};