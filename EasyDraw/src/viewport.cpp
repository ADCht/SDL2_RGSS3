#include "viewport.h"

ED_Viewport::ED_Viewport()
{
	this->rect = new ED_Rect(0, 0, ED_Graphics::screen_width, ED_Graphics::screen_height);
	this->visible = true;
	this->z = 0;
	this->ox = 0;
	this->oy = 0;
	this->tone = new ED_Tone(0, 0, 0, 0);
	ED_Graphics::viewports.push_back(this);
}

ED_Viewport::ED_Viewport(ED_Rect* rect_)
{
	this->rect = rect_;
	this->visible = true;
	this->z = 0;
	this->ox = 0;
	this->oy = 0;
	this->tone = new ED_Tone(0, 0, 0, 0);
	ED_Graphics::viewports.push_back(this);
}

ED_Viewport::ED_Viewport(int x_, int y_, int width_, int height_)
{
	this->rect = new ED_Rect(x_, y_, width_, height_);
	this->visible = true;
	this->z = 0;
	this->ox = 0;
	this->oy = 0;
	this->tone = new ED_Tone(0, 0, 0, 0);
	ED_Graphics::viewports.push_back(this);
}

ED_Viewport::~ED_Viewport()
{
	this->dispose();
}

void ED_Viewport::dispose()
{
	if (this->m_disposed) return;
	for (auto iter = this->m_sprites.begin(); iter != this->m_sprites.end(); iter++)
		(*iter)->set_viewport(0);
	for (auto i = ED_Graphics::viewports.begin(); i != ED_Graphics::viewports.end(); i++)
	{
		if (*i == this)
		{
			ED_Graphics::viewports.erase(i);
			break;
		}
	}
	this->m_disposed = true;
}

bool ED_Viewport::IsDisposed()
{
	return this->m_disposed;
}

void ED_Viewport::set_z(int z_)
{
	ED_Graphics::need_sort = true;
	this->z = z_;
}

int ED_Viewport::get_z()
{
	return this->z;
}

void ED_Viewport::add_sprite(ED_Sprite* sprite)
{
	this->m_sprites.push_back(sprite);
}

void ED_Viewport::del_sprite(ED_Sprite* sprite)
{
	for (auto iter = this->m_sprites.begin(); iter != this->m_sprites.end(); iter++)
	{
		if (*iter == sprite)
		{
			this->m_sprites.erase(iter);
			break;
		}
	}
}

void ED_Viewport::draw()
{
	if (this->m_disposed) return;

	if (this->need_sort) {
		std::sort(this->m_sprites.begin(), this->m_sprites.end(), [](ED_Sprite* a, ED_Sprite* b) { return a->get_z() < b->get_z(); }); // < = ÉıĞò | > = ½µĞò
		this->need_sort = false;
	}
	for (auto iter = this->m_sprites.begin(); iter != this->m_sprites.end(); iter++)
	{
		if (!(*iter)->IsDisposed())
			(*iter)->draw();
	}
}
