#include "sprite.h"
#include "SDL2_rotozoom.h"
#include "ed_main.h"

ED_Sprite::ED_Sprite()
{
	this->viewport = new ED_Viewport();
	this->bitmap = 0;
	this->src_rect = 0;
	this->visible = true;
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->ox = 0;
	this->oy = 0;
	this->zoom_x = 1;
	this->zoom_y = 1;
	this->angle = 0;
	this->opacity = 255;
	this->blend_type = 0;
	this->tone = 0;
	this->color = 0;
	this->mirror = false;
	this->viewport->add_sprite(this);
}

ED_Sprite::ED_Sprite(ED_Viewport* viewport_)
{
	this->viewport = viewport_;
	this->bitmap = 0;
	this->src_rect = 0;
	this->visible = true;
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->ox = 0;
	this->oy = 0;
	this->zoom_x = 1;
	this->zoom_y = 1;
	this->angle = 0;
	this->opacity = 255;
	this->blend_type = 0;
	this->tone = 0;
	this->color = 0;
	this->mirror = false;
	this->viewport->add_sprite(this);
}

ED_Sprite::~ED_Sprite()
{
	this->dispose();
}

void ED_Sprite::dispose()
{
	if (this->m_disposed) return;
	this->viewport->del_sprite(this);
	this->viewport = 0;
	this->bitmap = 0;
	this->src_rect = 0;
	this->visible = false;
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->ox = 0;
	this->oy = 0;
	this->zoom_x = 1;
	this->zoom_y = 1;
	this->angle = 0;
	this->opacity = 255;
	this->tone = new ED_Tone();
	this->color = new ED_Color();
	this->blend_type = 0;
	this->mirror = false;
	this->m_disposed = true;
}

bool ED_Sprite::IsDisposed()
{
	return this->m_disposed;
}

ED_Viewport* ED_Sprite::get_viewport()
{
	return this->viewport;
}

void ED_Sprite::set_viewport(ED_Viewport* viewport_)
{
	if (viewport_ = 0) // dispose viewport
	{
		this->viewport->del_sprite(this);
		this->viewport = 0;
	}
	else 
	{
		this->viewport->del_sprite(this);
		this->viewport = viewport_;
		this->viewport->add_sprite(this);
	}
}

void ED_Sprite::set_bitmap(ED_Bitmap* bitmap_)
{
	this->bitmap = bitmap_;
	this->src_rect = bitmap_->rect();
}

ED_Bitmap* ED_Sprite::get_bitmap()
{
	return this->bitmap;
}

int ED_Sprite::get_z()
{
	return this->z;
}

void ED_Sprite::set_z(int z_)
{
	this->viewport->need_sort = true;
	this->z = z_;
}

#define SDL_LOCKIFMUST(s) (SDL_MUSTLOCK(s) ? SDL_LockSurface(s) : 0)
#define SDL_UNLOCKIFMUST(s) { if(SDL_MUSTLOCK(s)) SDL_UnlockSurface(s); }

int* reverse_array(int* orig, unsigned short int b)
{
	unsigned short int a = 0;
	int swap;
	for (a; a < --b; a++) //increment a and decrement b until they meet eachother
	{
		swap = orig[a];       //put what's in a into swap space
		orig[a] = orig[b];    //put what's in b into a
		orig[b] = swap;       //put what's in the swap (a) into b
	}
	return orig;    //return the new (reversed) string (a pointer to it)
}

int set_surface_mirror(SDL_Surface* surface)
{
	if (SDL_LOCKIFMUST(surface) < 0)
		return -1;
	if (surface->w < 2) {
		SDL_UNLOCKIFMUST(surface);
		return 0;
	}
	Uint8* pixels = (Uint8*)surface->pixels;
	int temp = 0;
	int height_add = 0;
	for (int y1 = 0; y1 < surface->h; y1++) {
		for (int x1 = 1; x1 <= surface->w; x1++) {
			temp = surface->w - x1 + 1;
			height_add = y1 * (surface->w * 4);
			std::swap(pixels[x1 * 4 - 4 + height_add], pixels[temp * 4 - 4 + height_add]);
			std::swap(pixels[x1 * 4 - 3 + height_add], pixels[temp * 4 - 3 + height_add]);
			std::swap(pixels[x1 * 4 - 2 + height_add], pixels[temp * 4 - 2 + height_add]);
			std::swap(pixels[x1 * 4 - 1 + height_add], pixels[temp * 4 - 1 + height_add]);
			if (x1 > surface->w / 2) break;
		}
	}
	SDL_UNLOCKIFMUST(surface);
	return 0;
}

int set_surface_vertical(SDL_Surface* surface)
{
	Uint8* t;
	register Uint8* a, * b;
	Uint8* last;
	register Uint16 pitch;

	if (SDL_LOCKIFMUST(surface) < 0)
		return -2;

	/* do nothing unless at least two lines */
	if (surface->h < 2) {
		SDL_UNLOCKIFMUST(surface);
		return 0;
	}

	/* get a place to store a line */
	pitch = surface->pitch;
	t = (Uint8*)malloc(pitch);

	if (t == NULL) {
		SDL_UNLOCKIFMUST(surface);
		return -2;
	}

	/* get first line; it's about to be trampled */
	memcpy(t, surface->pixels, pitch);

	/* now, shuffle the rest so it's almost correct */
	a = (Uint8*)surface->pixels;
	last = a + pitch * (surface->h - 1);
	b = last;

	while (a < b) {
		memcpy(a, b, pitch);
		a += pitch;
		memcpy(b, a, pitch);
		b -= pitch;
	}

	/* in this shuffled state, the bottom slice is too far down */
	memmove(b, b + pitch, last - b);

	/* now we can put back that first row--in the last place */
	memcpy(last, t, pitch);

	/* everything is in the right place; close up. */
	free(t);
	SDL_UNLOCKIFMUST(surface);

	return 0;
}

void set_surface_grey(SDL_Surface* image)
{
	Uint32* pixels = (Uint32*)image->pixels;
	for (int y = 0; y < image->h; y++)
	{
		for (int x = 0; x < image->w; x++)
		{
			Uint32 pixel = (Uint32)pixels[y * image->w + x];
			Uint8 v = (((Uint8*)pixels)[0] + ((Uint8*)pixels)[1] + ((Uint8*)pixels)[2]) / 3;
			pixel = (0xFF << 24) | (v << 16) | (v << 8) | v;
			pixels[y * image->w + x] = pixel;
		}
	}
}

void ED_Sprite::draw_to(ED_Bitmap* target)
{
	if (this->m_disposed) return;

	if (!this->visible) return;
	if (!this->bitmap) return;

	int base_x = 0, base_y = 0;
	base_x = this->x - this->ox;
	base_y = this->y - this->oy;

	if (this->viewport)
	{
		SDL_SetClipRect(target->entity(), this->viewport->rect->entity());
		base_x += this->viewport->rect->x - this->viewport->ox;
		base_y += this->viewport->rect->y - this->viewport->oy;
	}

	SDL_Rect dst_rect;
	if (this->viewport)
	{
		dst_rect.x = base_x + this->viewport->rect->x;
		dst_rect.y = base_y + this->viewport->rect->y;
		dst_rect.w = this->src_rect->width;
		dst_rect.h = this->src_rect->height;
	}
	else
	{
		dst_rect.x = base_x;
		dst_rect.y = base_y;
		dst_rect.w = this->src_rect->width;
		dst_rect.h = this->src_rect->height;
	}

	SDL_Surface* pNew = rotozoomSurfaceXY(this->bitmap->entity(), this->angle, this->zoom_x, this->zoom_y, SMOOTHING_ON);

	if (this->vertical)
		set_surface_vertical(pNew);
	if (this->mirror)
		set_surface_mirror(pNew);

	SDL_Rect src_rect;
	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = pNew->w;
	src_rect.h = pNew->h;

	switch (this->blend_type)
	{
	case 1:
		SDL_SetSurfaceBlendMode(pNew, SDL_BLENDMODE_ADD);
		break;
	case 2:
		SDL_SetSurfaceBlendMode(pNew, SDL_BLENDMODE_BLEND);
		break;
	default:
		break;
	}

	if (this->tone)
	{
		SDL_SetSurfaceColorMod(pNew, this->tone->red, this->tone->green, this->tone->blue);
	}
	SDL_SetSurfaceAlphaMod(pNew, this->opacity);

	SDL_BlitSurface(pNew, &src_rect, target->entity(), &dst_rect);

	SDL_FreeSurface(pNew);

	if (this->viewport)
		SDL_SetClipRect(target->entity(), 0);
}

void ED_Sprite::draw()
{
	if (this->m_disposed) return;

	if (!this->bitmap) return;
	if (this->bitmap->IsDisposed()) return;

	int base_x = 0, base_y = 0;
	base_x = this->x - this->ox;
	base_y = this->y - this->oy;

	if (this->viewport)
	{
		SDL_RenderSetClipRect(g_renderer, this->viewport->rect->entity());
		base_x += this->viewport->rect->x - this->viewport->ox;
		base_y += this->viewport->rect->y - this->viewport->oy;
	}

	SDL_Rect dst_rect;
	if (this->viewport)
	{
		dst_rect.x = base_x + this->viewport->rect->x;
		dst_rect.y = base_y + this->viewport->rect->y;
		dst_rect.w = this->src_rect->width;
		dst_rect.h = this->src_rect->height;
	}
	else
	{
		dst_rect.x = base_x;
		dst_rect.y = base_y;
		dst_rect.w = this->src_rect->width;
		dst_rect.h = this->src_rect->height;
	}
	dst_rect.w *= this->zoom_x;
	dst_rect.h *= this->zoom_y;

	SDL_Texture* pNew = this->bitmap->m_texture;

	SDL_Rect src_rect;
	src_rect.x = 0;
	src_rect.y = 0;
	src_rect.w = this->bitmap->width();
	src_rect.h = this->bitmap->height();

	SDL_BlendMode sub = SDL_ComposeCustomBlendMode(SDL_BLENDFACTOR_ZERO, SDL_BLENDFACTOR_ONE_MINUS_SRC_COLOR, SDL_BLENDOPERATION_ADD, SDL_BLENDFACTOR_ZERO, SDL_BLENDFACTOR_ONE, SDL_BLENDOPERATION_ADD);
	switch (this->blend_type)
	{
	case 1:
		SDL_SetTextureBlendMode(pNew, SDL_BLENDMODE_ADD);
		break;
	case 2:
		SDL_SetTextureBlendMode(pNew, sub);
		break;
	default:
		break;
	}

	if (this->color)
		SDL_SetTextureColorMod(pNew, this->color->red, this->color->green, this->color->blue);
	SDL_SetTextureAlphaMod(pNew, this->opacity);

	int flip = SDL_FLIP_NONE;
	if (this->mirror)
		flip |= SDL_FLIP_HORIZONTAL;
	if (this->vertical)
		flip |= SDL_FLIP_VERTICAL;
	SDL_RenderCopyEx(g_renderer, pNew, &src_rect, &dst_rect, this->angle, 0, (SDL_RendererFlip)flip);
	
	if (this->viewport)
		SDL_RenderSetClipRect(g_renderer, 0);
}
