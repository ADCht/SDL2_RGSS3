#include "graphics.h"
#include "ed_main.h"
#include "input.h"

SDL_Surface* ED_Graphics::canvas = 0;
std::vector<ED_Viewport*> ED_Graphics::viewports;
unsigned char* ED_Graphics::screen_buffer = 0;
int ED_Graphics::screen_width = 0;
int ED_Graphics::screen_height = 0;
int ED_Graphics::screen_brightness = 255;
bool ED_Graphics::need_sort = false;
bool ED_Graphics::is_freezed = false;

int ED_Graphics::frame_rate = 60;
int ED_Graphics::frame_count = 0;

namespace {
	SDL_Surface* g_freeze_surf;
}

void ED_Graphics::init() {}

void ED_Graphics::update()
{
	SDL_RenderClear(g_renderer);
	if (need_sort) {
		std::sort(viewports.begin(), viewports.end(), [](ED_Viewport* a, ED_Viewport* b) { return a->get_z() < b->get_z(); }); // < = ÉýÐò | > = ½µÐò
		need_sort = false;
	}
	for (auto iter = viewports.begin(); iter != viewports.end(); iter++) {
		if ((*iter)->visible)
			(*iter)->draw();
	}
	SDL_RenderPresent(g_renderer);
	delay(1000 / frame_rate);
	frame_count += 1;
}

void ED_Graphics::wait(int time)
{
	for (int index = 0; index < time; index++)
		update();
}

void ED_Graphics::delay(int ms)
{
	SDL_Delay(ms);
}

ED_Bitmap* ED_Graphics::snap_to_bitmap()
{
	ED_Bitmap* bmp = new ED_Bitmap(screen_width, screen_height);
	SDL_RenderReadPixels(g_renderer, NULL, SDL_PIXELFORMAT_RGBA32, bmp->entity()->pixels, bmp->entity()->pitch);
	return bmp;
}

void ED_Graphics::fadein(int duration)
{
	int step = 255 / duration;
	for (int i = 0; i < duration; i++)
	{
		screen_brightness = i * step;
		update();
	}
	screen_brightness = 255;
}

void ED_Graphics::fadeout(int duration)
{
	int step = 255 / duration;
	for (int i = 0; i < duration; i++)
	{
		screen_brightness = 255 - i * step;
		update();
	}
	screen_brightness = 0;
}

void ED_Graphics::freeze()
{
}

void ED_Graphics::transition(int duration, char* filename, int vague)
{
}

void ED_Graphics::resize_screen(int width, int height)
{
	SDL_SetWindowSize(g_window, width, height);
	screen_width = width;
	screen_height = height;
}

void ED_Graphics::set_brightness(float value)
{
	screen_brightness = value;
}

int ED_Graphics::get_brightness()
{
	return screen_brightness;
}
