#include "bitmap.h"
#include "ed_main.h"
#include "SDL_image.h"

ED_Bitmap::ED_Bitmap(int width, int height)
{
	this->m_font = default_font;

	this->m_buffer = new unsigned char[width * height * 4];
	this->m_surface = SDL_CreateRGBSurfaceWithFormatFrom(this->m_buffer, width, height,
		32, 4 * width, SDL_PIXELFORMAT_RGBA32);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

ED_Bitmap::ED_Bitmap(const char* filename)
{
	this->m_font = default_font;

	this->m_surface = IMG_Load(filename);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

ED_Bitmap::~ED_Bitmap()
{
	this->dispose();
}

void ED_Bitmap::dispose()
{
	if (this->m_disposed) return;
	SDL_DestroyTexture(this->m_texture);
	SDL_FreeSurface(this->m_surface);
	delete[]this->m_buffer;
	this->m_disposed = true;
}

bool ED_Bitmap::IsDisposed()
{
	return this->m_disposed;
}

int ED_Bitmap::width()
{
	return this->m_surface->w;
}

int ED_Bitmap::height()
{
	return this->m_surface->h;
}

ED_Rect *ED_Bitmap::rect()
{
	ED_Rect *pRect = new ED_Rect(0, 0, this->width(), this->height());
	return pRect;
}

void ED_Bitmap::stretch_blt(ED_Rect *dest_rect, ED_Bitmap *src_bitmap, ED_Rect *src_rect, int opacity)
{
	SDL_SetSurfaceAlphaMod(src_bitmap->entity(), opacity);
	SDL_BlitSurface(src_bitmap->entity(), src_rect->entity(), this->m_surface, dest_rect->entity());
	SDL_SetSurfaceAlphaMod(src_bitmap->entity(), 255);
	SDL_DestroyTexture(this->m_texture);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

void ED_Bitmap::blt(int x, int y, ED_Bitmap *src_bitmap, ED_Rect *src_rect, int opacity)
{
	SDL_Rect rt;
	rt.x = x;
	rt.y = y;
	rt.w = this->width();
	rt.h = this->height();
	SDL_SetSurfaceAlphaMod(src_bitmap->entity(), opacity);
	SDL_BlitSurface(src_bitmap->entity(), src_rect->entity(), this->m_surface, &rt);
	SDL_SetSurfaceAlphaMod(src_bitmap->entity(), 255);
	SDL_DestroyTexture(this->m_texture);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

void ED_Bitmap::gradient_fill_rect(int x, int y, int width, int height, ED_Color *color1_, ED_Color *color2_, int vertical)
{
	x = clamp<int>(x, 0, this->width());
	y = clamp<int>(y, 0, this->height());
	int temp = 0;
	temp = width + x - this->width();
	width -= temp;
	temp = height + y - this->height();
	height -= temp;
	if (width < 0)
		width = 0;
	if (height < 0)
		height = 0;
    SDL_Color color1 = color1_->entity();
    SDL_Color color2 = color2_->entity();
    unsigned char* pixels = (unsigned char*)this->m_surface->pixels;
    if (vertical) {
        for (int yi = 0; yi < height; yi++) {
            unsigned char r, g, b, a;
            r = (color1.r * (height - yi) + color2.r * yi) / height;
            g = (color1.g * (height - yi) + color2.g * yi) / height;
            b = (color1.b * (height - yi) + color2.b * yi) / height;
            a = (color1.a * (height - yi) + color2.a * yi) / height;
            for (int xi = 0; xi < width; xi++) {
                int index = ((yi + y) * width + xi + x) << 2;
                pixels[index] = r;
                pixels[index + 1] = g;
                pixels[index + 2] = b;
                pixels[index + 3] = a;
            }
        }
    }
    else {
        for (int xi = 0; xi < width; xi++) {
            unsigned char r, g, b, a;
            r = (color1.r * (width - xi) + color2.r * xi) / width;
            g = (color1.g * (width - xi) + color2.g * xi) / width;
            b = (color1.b * (width - xi) + color2.b * xi) / width;
            a = (color1.a * (width - xi) + color2.a * xi) / width;
            for (int yi = 0; yi < height; yi++) {
                int index = ((yi + y) * width + xi + x) << 2;
                pixels[index] = r;
                pixels[index + 1] = g;
                pixels[index + 2] = b;
                pixels[index + 3] = a;
            }
        }
    }
	SDL_DestroyTexture(this->m_texture);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

void ED_Bitmap::gradient_fill_rect(ED_Rect *rect, ED_Color *color1, ED_Color *color2, int vertical)
{
    this->gradient_fill_rect(rect->x, rect->y, rect->width, rect->height, color1, color2, vertical);
}

void ED_Bitmap::fill_rect(ED_Rect* rect, ED_Color* color)
{
	this->fill_rect(rect->x, rect->y, rect->width, rect->height, color);
}

void ED_Bitmap::fill_rect(int x, int y, int width, int height, ED_Color* color)
{
	SDL_Rect rt;
	rt.x = x;
	rt.y = y;
	rt.w = width;
	rt.h = height;
	SDL_FillRect(this->m_surface, &rt, SDL_MapRGBA(this->m_surface->format, color->red, color->green, color->blue, color->alpha));
	SDL_DestroyTexture(this->m_texture);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

void ED_Bitmap::clear()
{
    delete[]this->m_buffer;
    this->m_buffer = new unsigned char[this->width() * this->height() * 4];
	SDL_DestroyTexture(this->m_texture);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

void ED_Bitmap::clear_rect(int x, int y, int width, int height)
{
    SDL_Rect rt;
    rt.x = x;
    rt.y = y;
    rt.w = width;
    rt.h = height;
    SDL_FillRect(this->m_surface, &rt, SDL_MapRGBA(this->m_surface->format, 0, 0, 0, 0));
	SDL_DestroyTexture(this->m_texture);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

void ED_Bitmap::clear_rect(ED_Rect* rect)
{
    this->clear_rect(rect->x, rect->y, rect->width, rect->height);
}

static uint32_t& getPixelAt(SDL_Surface* surf, SDL_PixelFormat* form, int x, int y)
{
	size_t offset = x * form->BytesPerPixel + y * surf->pitch;
	uint8_t* bytes = (uint8_t*)surf->pixels + offset;

	return *((uint32_t*)bytes);
}

ED_Color* ED_Bitmap::get_pixel(int x, int y)
{
	x = clamp<int>(x, 0, this->width());
	y = clamp<int>(y, 0, this->height());
	SDL_Color rgba;
	uint32_t pixel = getPixelAt(this->m_surface, this->m_surface->format, x, y);
	SDL_GetRGBA(pixel, this->m_surface->format, &rgba.r, &rgba.g, &rgba.b, &rgba.a);

	ED_Color* cr = new ED_Color(rgba.r, rgba.g, rgba.b, rgba.a);

	return cr;
}

void ED_Bitmap::set_pixel(int x, int y, ED_Color* color)
{
	x = clamp<int>(x, 0, this->width());
	y = clamp<int>(y, 0, this->height());
	uint32_t& surfPixel = getPixelAt(this->m_surface, this->m_surface->format, x, y);
	surfPixel = SDL_MapRGBA(this->m_surface->format, color->red, color->green, color->blue, color->alpha);
	SDL_DestroyTexture(this->m_texture);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

void ED_Bitmap::hue_change(int hue)
{
	return;
}

static std::string fixupString(const char* str)
{
	std::string s(str);
	for (size_t i = 0; i < s.size(); ++i)
		if (s[i] == '\r' || s[i] == '\n')
			s[i] = ' ';

	return s;
}

static void applyShadow(SDL_Surface*& in, const SDL_PixelFormat& fm, const SDL_Color& c)
{
	SDL_Surface* out = SDL_CreateRGBSurface
	(0, in->w + 1, in->h + 1, fm.BitsPerPixel, fm.Rmask, fm.Gmask, fm.Bmask, fm.Amask);

	float fr = c.r / 255.0f;
	float fg = c.g / 255.0f;
	float fb = c.b / 255.0f;

	/* We allocate an output surface one pixel wider and higher than the input,
	 * (implicitly) blit a copy of the input with RGB values set to black into
	 * it with x/y offset by 1, then blend the input surface over it at origin
	 * (0,0) using the bitmap blit equation (see shader/bitmapBlit.frag) */

	for (int y = 0; y < in->h + 1; ++y)
		for (int x = 0; x < in->w + 1; ++x)
		{
			/* src: input pixel, shd: shadow pixel */
			uint32_t src = 0, shd = 0;

			/* Output pixel location */
			uint32_t* outP = ((uint32_t*)((uint8_t*)out->pixels + y * out->pitch)) + x;

			if (y < in->h && x < in->w)
				src = ((uint32_t*)((uint8_t*)in->pixels + y * in->pitch))[x];

			if (y > 0 && x > 0)
				shd = ((uint32_t*)((uint8_t*)in->pixels + (y - 1) * in->pitch))[x - 1];

			/* Set shadow pixel RGB values to 0 (black) */
			shd &= fm.Amask;

			if (x == 0 || y == 0)
			{
				*outP = src;
				continue;
			}

			if (x == in->w || y == in->h)
			{
				*outP = shd;
				continue;
			}

			/* Input and shadow alpha values */
			uint8_t srcA, shdA;
			srcA = (src & fm.Amask) >> fm.Ashift;
			shdA = (shd & fm.Amask) >> fm.Ashift;

			if (srcA == 255 || shdA == 0)
			{
				*outP = src;
				continue;
			}

			if (srcA == 0 && shdA == 0)
			{
				*outP = 0;
				continue;
			}

			float fSrcA = srcA / 255.0f;
			float fShdA = shdA / 255.0f;

			/* Because opacity == 1, co1 == fSrcA */
			float co2 = fShdA * (1.0f - fSrcA);
			/* Result alpha */
			float fa = fSrcA + co2;
			/* Temp value to simplify arithmetic below */
			float co3 = fSrcA / fa;

			/* Result colors */
			uint8_t r, g, b, a;

			if (fr * co3 > 1) r = 255.0f;
			if (fr * co3 < 0) r = 0.0f;
			if (fg * co3 > 1) g = 255.0f;
			if (fg * co3 < 0) g = 0.0f;
			if (fb * co3 > 1) b = 255.0f;
			if (fb * co3 < 0) b = 0.0f;
			if (fa > 1) a = 255.0f;
			if (fa < 0) a = 0.0f;

			*outP = SDL_MapRGBA(&fm, r, g, b, a);
		}

	/* Store new surface in the input pointer */
	SDL_FreeSurface(in);
	in = out;
}

#define OUTLINE_SIZE 1
void ED_Bitmap::draw_text(ED_Rect* rect, const char* str, int align)
{
	align = clamp<int>(align, 0, 2);
	std::string fixed = fixupString(str);
	str = fixed.c_str();

	if (*str == '\0')
		return;

	if (str[0] == ' ' && str[1] == '\0')
		return;

	TTF_Font *font = this->m_font->entity();
	ED_Color *fontColor = this->m_font->color;
	ED_Color *outColor = this->m_font->out_color;

	SDL_Color c = fontColor->entity();
	c.a = 255;

	SDL_Surface* txtSurf;

	txtSurf = TTF_RenderUTF8_Blended(font, str, c);

	int rawTxtSurfH = txtSurf->h;

	if (this->m_font->shadow)
		applyShadow(txtSurf, *this->m_surface->format, c);

	/* outline using TTF_Outline and blending it together with SDL_BlitSurface
	 * FIXME: outline is forced to have the same opacity as the font color */
	if (this->m_font->outline)
	{
		SDL_Color co = outColor->entity();
		co.a = 255;
		SDL_Surface* outline;
		/* set the next font render to render the outline */
		TTF_SetFontOutline(font, OUTLINE_SIZE);
		outline = TTF_RenderUTF8_Blended(font, str, co);
		SDL_Rect outRect = { OUTLINE_SIZE, OUTLINE_SIZE, txtSurf->w, txtSurf->h };
		SDL_SetSurfaceBlendMode(txtSurf, SDL_BLENDMODE_BLEND);
		SDL_BlitSurface(txtSurf, NULL, outline, &outRect);
		SDL_FreeSurface(txtSurf);
		txtSurf = outline;
		/* reset outline to 0 */
		TTF_SetFontOutline(font, 0);
	}

	int alignX = rect->x;

	switch (align)
	{
	default:
	case 0:
		break;

	case 1:
		alignX += (rect->width - txtSurf->w) / 2;
		break;

	case 2:
		alignX += rect->width - txtSurf->w;
		break;
	}

	if (alignX < rect->x)
		alignX = rect->x;

	int alignY = rect->y + (rect->height - rawTxtSurfH) / 2;

	float squeeze = (float)rect->width / txtSurf->w;

	if (squeeze > 1)
		squeeze = 1;

	ED_Rect *posRect = new ED_Rect(alignX, alignY, txtSurf->w * squeeze, txtSurf->h);

	SDL_BlitSurface(txtSurf, NULL, this->m_surface, posRect->entity());

	SDL_FreeSurface(txtSurf);

	SDL_DestroyTexture(this->m_texture);
	this->m_texture = SDL_CreateTextureFromSurface(g_renderer, this->m_surface);
}

void ED_Bitmap::draw_text(int x, int y, int width, int height, const char* str, int align)
{
	ED_Rect* rt = new ED_Rect(x, y, width, height);
	this->draw_text(rt, str, align);
}

/* http://www.lemoda.net/c/utf8-to-ucs2/index.html */
static uint16_t utf8_to_ucs2(const char* _input,
	const char** end_ptr)
{
	const unsigned char* input =
		reinterpret_cast<const unsigned char*>(_input);
	*end_ptr = _input;

	if (input[0] == 0)
		return -1;

	if (input[0] < 0x80)
	{
		*end_ptr = _input + 1;

		return input[0];
	}

	if ((input[0] & 0xE0) == 0xE0)
	{
		if (input[1] == 0 || input[2] == 0)
			return -1;

		*end_ptr = _input + 3;

		return (input[0] & 0x0F) << 12 |
			(input[1] & 0x3F) << 6 |
			(input[2] & 0x3F);
	}

	if ((input[0] & 0xC0) == 0xC0)
	{
		if (input[1] == 0)
			return -1;

		*end_ptr = _input + 2;

		return (input[0] & 0x1F) << 6 |
			(input[1] & 0x3F);
	}

	return -1;
}

ED_Rect *ED_Bitmap::text_size(const char* str)
{
	TTF_Font* font = this->m_font->entity();

	std::string fixed = fixupString(str);
	str = fixed.c_str();

	int w, h;
	TTF_SizeUTF8(font, str, &w, &h);

	const char* endPtr;
	uint16_t ucs2 = utf8_to_ucs2(str, &endPtr);

	if (this->m_font->italic && *endPtr == '\0')
		TTF_GlyphMetrics(font, ucs2, 0, 0, 0, 0, &w);

	ED_Rect *rt = new ED_Rect(0, 0, w, h);
	return rt;
}

SDL_Surface* ED_Bitmap::entity()
{
	return this->m_surface;
}

ED_Bitmap::ED_Bitmap(SDL_Surface* src_surf)
{
	this->m_surface = src_surf;
}
