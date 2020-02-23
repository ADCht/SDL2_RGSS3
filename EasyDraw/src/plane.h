#pragma once
#include "SDL.h"
#include "viewport.h"

class ED_Sprite;

class ED_Plane
{
public:
	ED_Plane();
	ED_Plane(ED_Viewport* viewport_);
	~ED_Plane();

	void dispose();
	bool IsDisposed();

	ED_Viewport* get_viewport();
	void set_viewport(ED_Viewport* viewport_);
	void set_bitmap(ED_Bitmap* bitmap_);
	ED_Bitmap* get_bitmap();

	bool get_visible();
	void set_visible(bool v);
	int get_z();
	void set_z(int z);
	int get_ox();
	void set_ox(int ox);
	int get_oy();
	void set_oy(int oy);
	double get_zoom_x();
	void set_zoom_x(double zx);
	double get_zoom_y();
	void set_zoom_y(double zy);
	int get_opacity();
	void set_opacity(int opacity);
	int get_blend_type();
	void set_blend_type(int t);
	ED_Color* get_color();
	void set_color(ED_Color* c);
	ED_Tone* get_tone();
	void set_tone(ED_Tone* t);

private:
	ED_Sprite* m_sprite;

};