#include "plane.h"

ED_Plane::ED_Plane()
{
	this->m_sprite = new ED_Sprite();
}

ED_Plane::ED_Plane(ED_Viewport* viewport_)
{
	this->m_sprite = new ED_Sprite(viewport_);
}

ED_Plane::~ED_Plane()
{
	this->dispose();
}

void ED_Plane::dispose()
{
	this->m_sprite->dispose();
}

bool ED_Plane::IsDisposed()
{
	return this->m_sprite->IsDisposed();
}

ED_Viewport* ED_Plane::get_viewport()
{
	return this->m_sprite->get_viewport();
}

void ED_Plane::set_viewport(ED_Viewport* viewport_)
{
	this->m_sprite->set_viewport(viewport_);
}

void ED_Plane::set_bitmap(ED_Bitmap* bitmap_)
{
	this->m_sprite->set_bitmap(bitmap_);
}

ED_Bitmap* ED_Plane::get_bitmap()
{
	return this->m_sprite->get_bitmap();
}

bool ED_Plane::get_visible()
{
	return this->m_sprite->visible;
}

void ED_Plane::set_visible(bool v)
{
	this->m_sprite->visible = v;
}

int ED_Plane::get_z()
{
	return this->m_sprite->get_z();
}

void ED_Plane::set_z(int z)
{
	this->m_sprite->set_z(z);
}

int ED_Plane::get_ox()
{
	return this->m_sprite->ox;
}

void ED_Plane::set_ox(int ox)
{
	this->m_sprite->ox = ox;
}

int ED_Plane::get_oy()
{
	return this->m_sprite->oy;
}

void ED_Plane::set_oy(int oy)
{
	this->m_sprite->oy = oy;
}

double ED_Plane::get_zoom_x()
{
	return this->m_sprite->zoom_x;
}

void ED_Plane::set_zoom_x(double zx)
{
	this->m_sprite->zoom_x = zx;
}

double ED_Plane::get_zoom_y()
{
	return this->m_sprite->zoom_y;
}

void ED_Plane::set_zoom_y(double zy)
{
	this->m_sprite->zoom_y = zy;
}

int ED_Plane::get_opacity()
{
	return this->m_sprite->opacity;
}

void ED_Plane::set_opacity(int opacity)
{
	this->m_sprite->opacity = opacity;
}

int ED_Plane::get_blend_type()
{
	return this->m_sprite->blend_type;
}

void ED_Plane::set_blend_type(int t)
{
	this->m_sprite->blend_type = t;
}

ED_Color* ED_Plane::get_color()
{
	return this->m_sprite->color;
}

void ED_Plane::set_color(ED_Color* c)
{
	this->m_sprite->color = c;
}

ED_Tone* ED_Plane::get_tone()
{
	return this->m_sprite->tone;
}

void ED_Plane::set_tone(ED_Tone* t)
{
	this->m_sprite->tone = t;
}
