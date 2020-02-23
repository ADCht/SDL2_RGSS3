#include "font.h"

const char *ED_Font::default_name = "Fonts/Default.ttf";
int ED_Font::default_size = 24;
bool ED_Font::default_bold = false;
bool ED_Font::default_italic = false;
bool ED_Font::default_outline = true;
bool ED_Font::default_shadow = false;
ED_Color *ED_Font::default_color = new ED_Color(255, 255, 255, 255);
ED_Color *ED_Font::default_out_color = new ED_Color(0, 0, 0, 128);

ED_Font::ED_Font()
{
	this->m_font = TTF_OpenFont(this->default_name, 24);
	this->name = this->default_name;
	this->size = this->default_size;
	this->bold = this->default_bold;
	this->italic = this->default_italic;
	this->outline = this->default_outline;
	this->shadow = this->default_shadow;
	this->color = this->default_color;
	this->out_color = this->default_out_color;
}

ED_Font::ED_Font(const char* name)
{
	this->m_font = TTF_OpenFont(name, 24);
	this->name = this->default_name;
	this->size = this->default_size;
	this->bold = this->default_bold;
	this->italic = this->default_italic;
	this->outline = this->default_outline;
	this->shadow = this->default_shadow;
	this->color = this->default_color;
	this->out_color = this->default_out_color;
}

ED_Font::ED_Font(const char* name, int size)
{
	this->m_font = TTF_OpenFont(name, size);
	this->name = this->default_name;
	this->size = this->default_size;
	this->bold = this->default_bold;
	this->italic = this->default_italic;
	this->outline = this->default_outline;
	this->shadow = this->default_shadow;
	this->color = this->default_color;
	this->out_color = this->default_out_color;
}

ED_Font::~ED_Font()
{
	this->name = 0;
	this->size = 0;
	this->bold = 0;
	this->italic = 0;
	this->outline = 0;
	this->shadow = 0;
	this->color = 0;
	this->out_color = 0;
	TTF_CloseFont(this->m_font);
}

TTF_Font* ED_Font::entity()
{
	int style = TTF_STYLE_NORMAL;

	if (this->bold) style |= TTF_STYLE_BOLD;
	if (this->italic) style |= TTF_STYLE_ITALIC;
	TTF_SetFontStyle(this->m_font, style);

	return this->m_font;
}

bool ED_Font::exist(const char* name)
{
	return true;
}
