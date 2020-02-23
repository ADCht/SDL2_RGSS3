#pragma once
#include "SDL.h"
#include "graphics.h"
#include "font.h"

#include <iostream>

extern const char *error_info;
extern bool has_error;

typedef void(*ED_Exit)();
extern SDL_Renderer* g_renderer;
extern SDL_Window* g_window;
extern ED_Exit exit_event;
extern ED_Font *default_font;

void Init_EasyDraw(int screen_width, int screen_height, const char *title, ED_Exit atexit);

void Final_EasyDraw();

template<typename T>
T clamp(T val, T min, T max)
{
	if (val < min)
		return min;
	if (val > max)
		return max;
	return val;
}