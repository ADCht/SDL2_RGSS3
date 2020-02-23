#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "color.h"
#include "rect.h"

class ED_Font
{
public:
	ED_Font();
	ED_Font(const char* name);
	ED_Font(const char *name, int size);
	~ED_Font();

	const char* name;
	int size;
	bool bold;
	bool italic;
	bool shadow;
	bool outline;
	ED_Color *color;
	ED_Color *out_color;

	TTF_Font* entity();

public:
	static bool exist(const char *name);

	static const char* default_name;
	static int default_size;
	static bool default_bold;
	static bool default_italic;
	static bool default_shadow;
	static bool default_outline;
	static ED_Color *default_color;
	static ED_Color *default_out_color;

private:
	TTF_Font* m_font;
};
