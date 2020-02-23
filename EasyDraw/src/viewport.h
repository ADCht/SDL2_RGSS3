#pragma once
#include "SDL.h"
#include "sprite.h"
#include "rect.h"
#include "graphics.h"
#include <vector>
#include "tone.h"

class ED_Sprite;
class ED_Tone;

class ED_Viewport
{
public:
	ED_Viewport();
	ED_Viewport(ED_Rect *rect_);
	ED_Viewport(int x_, int y_, int width_, int height_);
	~ED_Viewport();

	void dispose();
	bool IsDisposed();

	ED_Rect* rect;
	bool visible;
	void set_z(int z_);
	int get_z();
	int ox;
	int oy;
	ED_Tone* tone;

	void add_sprite(ED_Sprite* sprite);
	void del_sprite(ED_Sprite* sprite);

public:
	void draw();
	bool need_sort;

private:
	int z;
	std::vector<ED_Sprite*> m_sprites;
	bool m_disposed;

};
