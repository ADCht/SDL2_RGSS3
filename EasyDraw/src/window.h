#pragma once
#include "SDL.h"
#include "bitmap.h"
#include "viewport.h"
#include "sprite.h"

class ED_Window
{
public:
	ED_Window(int x_ = 0, int y_ = 0, int width_ = 0, int height_ = 0);
	~ED_Window();

	void dispose();
	bool IsDisposed();
	void update();
	void move(int x_, int y_, int width_, int height_);
	bool opened();
	bool closed();
	
	ED_Bitmap* get_windowskin();
	void set_windowskin(ED_Bitmap* bmp);
	ED_Bitmap* get_contents();
	void set_contents(ED_Bitmap* bmp);
	ED_Bitmap* get_cursor_rect();
	void set_cursor_rect(ED_Bitmap* bmp);
	ED_Bitmap* get_viewport();
	void set_viewport(ED_Bitmap* bmp);
	ED_Bitmap* get_active();
	void set_active(ED_Bitmap* bmp);
	ED_Bitmap* get_visible();
	void set_visible(ED_Bitmap* bmp);

private:
	void update_skin();

private:
	bool m_disposed;

	ED_Bitmap* m_windowskin;

	ED_Viewport* m_viewport;
	ED_Bitmap* m_frame;
	ED_Bitmap* m_bg;
	ED_Bitmap* m_contents;

	ED_Sprite* m_bg_spr;
	ED_Sprite* m_frame_spr;
	ED_Sprite* m_contents_spr;

	int x;
	int y;
	int width;
	int height;
	int z;

	int padding;
	int bottom_padding;
};