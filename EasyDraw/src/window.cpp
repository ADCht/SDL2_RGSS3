#include "window.h"
#include "SDL2_rotozoom.h"

ED_Window::ED_Window(int x_, int y_, int width_, int height_)
{
	this->m_viewport = new ED_Viewport(x_, y_, width_, height_);
	this->x = x_;
	this->y = y_;
	this->width = width_;
	this->height = height_;
	this->z = 0;

	this->m_frame_spr = new ED_Sprite(this->m_viewport);
	this->m_contents_spr = new ED_Sprite(this->m_viewport);
	this->m_bg_spr = new ED_Sprite(this->m_viewport);

	this->m_frame = new ED_Bitmap(width_, height_);
	this->m_bg = new ED_Bitmap(width_ - 4, height_ - 4);
	this->m_contents = new ED_Bitmap(width_ - 24, height_ - 24);

	this->padding = 12;
	this->bottom_padding = 12;
}

ED_Window::~ED_Window()
{
	this->dispose();
}

void ED_Window::dispose()
{
	if (this->m_disposed) return;



	this->m_disposed = true;
}

bool ED_Window::IsDisposed()
{
	return this->m_disposed;
}

void ED_Window::update()
{

}

void ED_Window::move(int x_, int y_, int width_, int height_)
{

}

bool ED_Window::opened()
{
	return false;
}

bool ED_Window::closed()
{
	return false;
}

ED_Bitmap* ED_Window::get_windowskin()
{
	return this->m_windowskin;
}

void ED_Window::set_windowskin(ED_Bitmap* bmp)
{
	this->m_windowskin = bmp;
}

ED_Bitmap* ED_Window::get_contents()
{
	return nullptr;
}

void ED_Window::set_contents(ED_Bitmap* bmp)
{

}

ED_Bitmap* ED_Window::get_cursor_rect()
{
	return nullptr;
}

void ED_Window::set_cursor_rect(ED_Bitmap* bmp)
{

}

ED_Bitmap* ED_Window::get_viewport()
{
	return nullptr;
}

void ED_Window::set_viewport(ED_Bitmap* bmp)
{

}

ED_Bitmap* ED_Window::get_active()
{
	return nullptr;
}

void ED_Window::set_active(ED_Bitmap* bmp)
{

}

ED_Bitmap* ED_Window::get_visible()
{
	return nullptr;
}

void ED_Window::set_visible(ED_Bitmap* bmp)
{

}

void ED_Window::update_skin()
{
	ED_Rect* rt1 = new ED_Rect(64, 0, 16, 16); // LEFT UP
	ED_Rect* rt2 = new ED_Rect(64, 48, 16, 16); // LEFT DOWN
	ED_Rect* rt3 = new ED_Rect(112, 0, 16, 16); // RIGHT UP
	ED_Rect* rt4 = new ED_Rect(112, 48, 16, 16); // RIGHT DOWN
	this->m_frame->blt(0, 0, this->m_windowskin, rt1);
	this->m_frame->blt(0, this->height - 16, this->m_windowskin, rt2);
	this->m_frame->blt(this->width - 16, 0, this->m_windowskin, rt3);
	this->m_frame->blt(this->width - 16, this->height - 16, this->m_windowskin, rt4);

	rotozoomSurfaceSize(, , , , , );
}
