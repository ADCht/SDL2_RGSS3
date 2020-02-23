#pragma once
#include "SDL.h"
#include "viewport.h"
#include "bitmap.h"
#include "graphics.h"
#include "tone.h"
#include "theora.h"

class ED_Viewport;

class ED_Sprite
{
public:
	ED_Sprite();
	ED_Sprite(ED_Viewport *viewport_);
	~ED_Sprite();

	void dispose();
	bool IsDisposed();

	ED_Viewport* get_viewport();
	void set_viewport(ED_Viewport* viewport_);
	void set_bitmap(ED_Bitmap* bitmap_);
	ED_Bitmap* get_bitmap();

	ED_Rect* src_rect;
	bool visible;
	int x;
	int y;
	int get_z();
	void set_z(int z_);
	int ox;
	int oy;
	double zoom_x;
	double zoom_y;
	int angle;
	bool mirror;
	bool vertical;
	int opacity;
	int blend_type;
	ED_Color *color;
	ED_Tone *tone;

	// EXPERIENCE
	void draw_to(ED_Bitmap* target);

private:
	ED_Viewport* viewport;
	ED_Bitmap* bitmap;
	bool m_disposed;
	int z;

public:
	void draw();

};