#include "bitmap-binding.h"
#include "binding-util.h"
#include "EasyDraw.h"

mrb_value BitmapInitialize(mrb_state* mrb, mrb_value self)
{
	ED_Bitmap* b;
	if (mrb_get_argc(mrb) <= 1)
	{
		char *filename = 0;
		mrb_get_args(mrb, "z", &filename);
		// TODO: add your code here.
		b = new ED_Bitmap(filename);
	}
	else
	{
		mrb_int width, height;
		mrb_get_args(mrb, "ii", &width, &height);
		// TODO: add your code here.
		b = new ED_Bitmap(width, height);
	}
	setPrivateData(mrb, self, b, ED_BitmapType);
	return mrb_nil_value();
}

CLONE_FUNC(Bitmap);

mrb_value BitmapDispose(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	b->dispose();

	return mrb_nil_value();
}

mrb_value BitmapDisposed(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	return mrb_bool_value(b->IsDisposed());
}

mrb_value BitmapWidth(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	return mrb_fixnum_value(b->width());
}

mrb_value BitmapHeight(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	return mrb_fixnum_value(b->height());
}

mrb_value BitmapRect(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	ED_Rect* r = b->rect();

	return wrapObject(mrb, r, ED_RectType);
}

mrb_value BitmapBlt(mrb_state* mrb, mrb_value self)
{
	mrb_int x = 0;
	mrb_int y = 0;
	mrb_value src_bitmap;
	mrb_value src_rect;
	mrb_int opacity = 255;
	mrb_get_args(mrb, "iioo|i", &x, &y, &src_bitmap, &src_rect, &opacity);
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	ED_Bitmap* bmp = getPrivateDataCheck<ED_Bitmap>(mrb, src_bitmap, ED_BitmapType);
	ED_Rect* rt = getPrivateDataCheck<ED_Rect>(mrb, src_rect, ED_RectType);

	b->blt(x, y, bmp, rt, opacity);

	return mrb_nil_value();
}

mrb_value BitmapStretchBlt(mrb_state* mrb, mrb_value self)
{
	mrb_value dest_rect;
	mrb_value src_bitmap;
	mrb_value src_rect;
	mrb_int opacity = 255;
	mrb_get_args(mrb, "ooo|i", &dest_rect, &src_bitmap, &src_rect, &opacity);
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	ED_Rect* dst = getPrivateDataCheck<ED_Rect>(mrb, dest_rect, ED_RectType);
	ED_Bitmap* bmp = getPrivateDataCheck<ED_Bitmap>(mrb, src_bitmap, ED_BitmapType);
	ED_Rect* rt = getPrivateDataCheck<ED_Rect>(mrb, src_rect, ED_RectType);

	b->stretch_blt(dst, bmp, rt, opacity);

	return mrb_nil_value();
}

mrb_value BitmapFillRect(mrb_state* mrb, mrb_value self)
{
	if (mrb_get_argc(mrb) == 2)
	{
		mrb_value rect;
		mrb_value color;
		mrb_get_args(mrb, "oo", &rect, &color);
		// TODO: add your code here.
		ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

		ED_Rect* dst = getPrivateDataCheck<ED_Rect>(mrb, rect, ED_RectType);
		ED_Color* cr = getPrivateDataCheck<ED_Color>(mrb, color, ED_ColorType);

		b->fill_rect(dst, cr);
	}
	else
	{
		mrb_int x = 0;
		mrb_int y = 0;
		mrb_int width = 0;
		mrb_int height = 0;
		mrb_value color;
		mrb_get_args(mrb, "iiiio", &x, &y, &width, &height, &color);
		// TODO: add your code here.
		ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

		ED_Color* cr = getPrivateDataCheck<ED_Color>(mrb, color, ED_ColorType);

		b->fill_rect(x, y, width, height, cr);
	}
	return mrb_nil_value();
}

mrb_value BitmapGradientFillRect(mrb_state* mrb, mrb_value self)
{
	if (mrb_get_argc(mrb) <= 4)
	{
		mrb_value rect;
		mrb_value color1;
		mrb_value color2;
		mrb_bool vertical = false;
		mrb_get_args(mrb, "ooo|b", &rect, &color1, &color2, &vertical);
		// TODO: add your code here.
		ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

		ED_Rect* dst = getPrivateDataCheck<ED_Rect>(mrb, rect, ED_RectType);
		ED_Color* cr1 = getPrivateDataCheck<ED_Color>(mrb, color1, ED_ColorType);
		ED_Color* cr2 = getPrivateDataCheck<ED_Color>(mrb, color2, ED_ColorType);

		b->gradient_fill_rect(dst, cr1, cr2, vertical);
	}
	else
	{
		mrb_int x = 0;
		mrb_int y = 0;
		mrb_int width = 0;
		mrb_int height = 0;
		mrb_value color1;
		mrb_value color2;
		mrb_bool vertical = false;
		mrb_get_args(mrb, "iiiioo|b", &x, &y, &width, &height, &color1, &color2, &vertical);
		// TODO: add your code here.
		ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

		ED_Color* cr1 = getPrivateDataCheck<ED_Color>(mrb, color1, ED_ColorType);
		ED_Color* cr2 = getPrivateDataCheck<ED_Color>(mrb, color2, ED_ColorType);

		b->gradient_fill_rect(x, y, width, height, cr1, cr2, vertical);
	}
	return mrb_nil_value();
}

mrb_value BitmapClear(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);
	
	b->clear();

	return mrb_nil_value();
}

mrb_value BitmapClearRect(mrb_state* mrb, mrb_value self)
{
	if (mrb_get_argc(mrb) <= 1)
	{
		mrb_value rect;
		mrb_get_args(mrb, "o", &rect);
		// TODO: add your code here.
		ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

		ED_Rect* dst = getPrivateDataCheck<ED_Rect>(mrb, rect, ED_RectType);

		b->clear_rect(dst);
	}
	else
	{
		mrb_int x = 0;
		mrb_int y = 0;
		mrb_int width = 0;
		mrb_int height = 0;
		mrb_get_args(mrb, "iiii", &x, &y, &width, &height);
		// TODO: add your code here.
		ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

		b->clear_rect(x, y, width, height);
	}
	return mrb_nil_value();
}

mrb_value BitmapGetPixel(mrb_state* mrb, mrb_value self)
{
	mrb_int x = 0;
	mrb_int y = 0;
	mrb_get_args(mrb, "ii", &x, &y);
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	ED_Color* c = b->get_pixel(x, y);

	return wrapObject(mrb, c, ED_ColorType);
}

mrb_value BitmapSetPixel(mrb_state* mrb, mrb_value self)
{
	mrb_int x = 0;
	mrb_int y = 0;
	mrb_value color;
	mrb_get_args(mrb, "iio", &x, &y, &color);
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	ED_Color* cr = getPrivateDataCheck<ED_Color>(mrb, color, ED_ColorType);

	b->set_pixel(x, y, cr);

	return mrb_nil_value();
}

mrb_value BitmapHueChange(mrb_state* mrb, mrb_value self)
{
	mrb_int hue = 0;
	mrb_get_args(mrb, "i", &hue);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value BitmapBlur(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value BitmapRadialBlur(mrb_state* mrb, mrb_value self)
{
	mrb_int angle = 0;
	mrb_int division = 0;
	mrb_get_args(mrb, "ii", &angle, &division);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value BitmapDrawText(mrb_state* mrb, mrb_value self)
{
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);
	if (mrb_get_argc(mrb) <= 3)
	{
		mrb_value rect;
		char* str = 0;
		mrb_int align = 0;
		mrb_get_args(mrb, "oz|i", &rect, &str, &align);
		// TODO: add your code here.
		ED_Rect* rt = getPrivateDataCheck<ED_Rect>(mrb, rect, ED_RectType);

		b->draw_text(rt, str, align);
	}
	else
	{
		mrb_int x = 0;
		mrb_int y = 0;
		mrb_int width = 0;
		mrb_int height = 0;
		char* str = 0;
		mrb_int align = 0;
		mrb_get_args(mrb, "iiiiz|i", &x, &y, &width, &height, &str, &align);
		// TODO: add your code here.
		b->draw_text(x, y, width, height, str, align);
	}
	return mrb_nil_value();
}

mrb_value BitmapTextSize(mrb_state* mrb, mrb_value self)
{
	char* str = 0;
	mrb_get_args(mrb, "z", &str);
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);
	
	ED_Rect* rt = b->text_size(str);

	return wrapObject(mrb, rt, ED_RectType);
}

mrb_value BitmapGetFont(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	ED_Font* ft = b->m_font;

	return wrapObject(mrb, ft, ED_FontType);
}

mrb_value BitmapSetFont(mrb_state* mrb, mrb_value self)
{
	mrb_value font;
	mrb_get_args(mrb, "o", &font);
	// TODO: add your code here.
	ED_Bitmap* b = getPrivateData<ED_Bitmap>(mrb, self);

	ED_Font* ft = getPrivateDataCheck<ED_Font>(mrb, font, ED_FontType);

	b->m_font = ft;

	return mrb_nil_value();
}

void Init_Bitmap(mrb_state* mrb)
{
	RClass* pBitmap = mrb_define_class(mrb, "Bitmap", mrb->object_class);

	mrb_define_method(mrb, pBitmap, "initialize", &BitmapInitialize, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
	mrb_define_method(mrb, pBitmap, "initialize_copy", &BitmapInitializeCopy, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pBitmap, "dispose", &BitmapDispose, MRB_ARGS_NONE());
	mrb_define_method(mrb, pBitmap, "disposed?", &BitmapDisposed, MRB_ARGS_NONE());
	mrb_define_method(mrb, pBitmap, "width", &BitmapWidth, MRB_ARGS_NONE());
	mrb_define_method(mrb, pBitmap, "height", &BitmapHeight, MRB_ARGS_NONE());
	mrb_define_method(mrb, pBitmap, "rect", &BitmapRect, MRB_ARGS_NONE());
	mrb_define_method(mrb, pBitmap, "blt", &BitmapBlt, MRB_ARGS_REQ(4) | MRB_ARGS_OPT(1));
	mrb_define_method(mrb, pBitmap, "stretch_blt", &BitmapStretchBlt, MRB_ARGS_REQ(3) | MRB_ARGS_OPT(1));
	mrb_define_method(mrb, pBitmap, "fill_rect", &BitmapFillRect, MRB_ARGS_REQ(2) | MRB_ARGS_OPT(2));
	mrb_define_method(mrb, pBitmap, "gradient_fill_rect", &BitmapGradientFillRect, MRB_ARGS_REQ(3) | MRB_ARGS_OPT(4));
	mrb_define_method(mrb, pBitmap, "clear", &BitmapClear, MRB_ARGS_NONE());
	mrb_define_method(mrb, pBitmap, "clear_rect", &BitmapClearRect, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(3));
	mrb_define_method(mrb, pBitmap, "get_pixel", &BitmapGetPixel, MRB_ARGS_REQ(2));
	mrb_define_method(mrb, pBitmap, "set_pixel", &BitmapSetPixel, MRB_ARGS_REQ(3));
	mrb_define_method(mrb, pBitmap, "hue_change", &BitmapHueChange, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pBitmap, "blur", &BitmapBlur, MRB_ARGS_NONE());
	mrb_define_method(mrb, pBitmap, "radial_blur", &BitmapRadialBlur, MRB_ARGS_REQ(2));
	mrb_define_method(mrb, pBitmap, "draw_text", &BitmapDrawText, MRB_ARGS_REQ(2) | MRB_ARGS_OPT(4));
	mrb_define_method(mrb, pBitmap, "text_size", &BitmapTextSize, MRB_ARGS_REQ(1));

	mrb_define_method(mrb, pBitmap, "font", &BitmapGetFont, MRB_ARGS_NONE());
	mrb_define_method(mrb, pBitmap, "font=", &BitmapSetFont, MRB_ARGS_REQ(1));
}

void Final_Bitmap(mrb_state* mrb)
{
	return;
}