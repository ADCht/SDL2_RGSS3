#pragma once
#include "SDL.h"
#include "rect.h"
#include "color.h"
#include "font.h"
#include <string>

#include "SDL_ttf.h"
#include "SDL_opengl.h"
#include <algorithm>

class ED_Bitmap
{
public:
	ED_Bitmap(int width, int height);
	ED_Bitmap(const char *filename);
	~ED_Bitmap();

	void dispose();
	bool IsDisposed();

	int width();
	int height();
	ED_Rect *rect();

	void stretch_blt(ED_Rect *dest_rect, ED_Bitmap *src_bitmap, ED_Rect *src_rect, int opacity = 255);
	void blt(int x, int y, ED_Bitmap* src_bitmap, ED_Rect* src_rect, int opacity = 255);

	void gradient_fill_rect(int x, int y, int width, int height, ED_Color *color1_, ED_Color *color2_, int vertical);
	void gradient_fill_rect(ED_Rect *rect, ED_Color *color1, ED_Color *color2, int vertical);

	void fill_rect(ED_Rect *rect, ED_Color *color);
	void fill_rect(int x, int y, int width, int height, ED_Color* color);

	void clear();

	void clear_rect(int x, int y, int width, int height);
	void clear_rect(ED_Rect *rect);

	ED_Color* get_pixel(int x, int y);
	void set_pixel(int x, int y, ED_Color* color);

	void hue_change(int hue);

	void draw_text(ED_Rect *rect, const char *str, int align);
	void draw_text(int x, int y, int width, int height, const char* str, int align);

	ED_Rect* text_size(const char* str);

	ED_Font* m_font;

	SDL_Surface* entity();
	ED_Bitmap(SDL_Surface* src_surf);
	SDL_Texture* m_texture;

private:
	unsigned char* m_buffer;
	SDL_Surface* m_surface;
	bool m_disposed;

};
