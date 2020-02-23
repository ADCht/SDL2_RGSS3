#include "color-binding.h"
#include "binding-util.h"
#include "EasyDraw.h"

mrb_value ColorInitialize(mrb_state* mrb, mrb_value self)
{
	if (mrb_get_argc(mrb))
	{
		mrb_float red = 0;
		mrb_float green = 0;
		mrb_float blue = 0;
		mrb_float alpha = 255;
		mrb_get_args(mrb, "fff|f", &red, &green, &blue, &alpha);
		// TODO: add your code here.
		ED_Color* c = new ED_Color(red, green, blue, alpha);

		setPrivateData(mrb, self, c, ED_ColorType);
	}
	else
	{
		mrb_float red = 0;
		mrb_float green = 0;
		mrb_float blue = 0;
		mrb_float alpha = 0;
		// TODO: add your code here.
		ED_Color* c = new ED_Color(red, green, blue, alpha);

		setPrivateData(mrb, self, c, ED_ColorType);
	}
	return mrb_nil_value();
}

CLONE_FUNC(Color);

mrb_value ColorSet(mrb_state* mrb, mrb_value self)
{
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);
	if (mrb_get_argc(mrb) <= 1)
	{
		mrb_value color;
		mrb_get_args(mrb, "o", &color);
		// TODO: add your code here.
		ED_Color* cr = getPrivateDataCheck<ED_Color>(mrb, color, ED_ColorType);

		c->set(cr);
	}
	else
	{
		mrb_float red = 0;
		mrb_float green = 0;
		mrb_float blue = 0;
		mrb_float alpha = 255;
		mrb_get_args(mrb, "fff|f", &red, &green, &blue, &alpha);
		// TODO: add your code here.
		c->set(red, green, blue, alpha);
	}
	return mrb_nil_value();
}

mrb_value ColorGetRed(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);

	return mrb_fixnum_value(c->red);
}

mrb_value ColorSetRed(mrb_state* mrb, mrb_value self)
{
	mrb_float red = 0;
	mrb_get_args(mrb, "f", &red);
	if (red > 255) red = 255;
	if (red < 0) red = 0;
	// TODO: add your code here.
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);

	c->red = red;
	return mrb_nil_value();
}

mrb_value ColorGetGreen(mrb_state* mrb, mrb_value self)
{
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);

	return mrb_fixnum_value(c->green);
}

mrb_value ColorSetGreen(mrb_state* mrb, mrb_value self)
{
	mrb_float green = 0;
	mrb_get_args(mrb, "f", &green);
	if (green > 255) green = 255;
	if (green < 0) green = 0;
	// TODO: add your code here.
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);

	c->green = green;
	return mrb_nil_value();
}

mrb_value ColorGetBlue(mrb_state* mrb, mrb_value self)
{
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);

	return mrb_fixnum_value(c->blue);
}

mrb_value ColorSetBlue(mrb_state* mrb, mrb_value self)
{
	mrb_float blue = 0;
	mrb_get_args(mrb, "f", &blue);
	if (blue > 255) blue = 255;
	if (blue < 0) blue = 0;
	// TODO: add your code here.
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);

	c->blue = blue;
	return mrb_nil_value();
}

mrb_value ColorGetAlpha(mrb_state* mrb, mrb_value self)
{
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);

	return mrb_fixnum_value(c->alpha);
}

mrb_value ColorSetAlpha(mrb_state* mrb, mrb_value self)
{
	mrb_float alpha = 0;
	mrb_get_args(mrb, "f", &alpha);
	if (alpha > 255) alpha = 255;
	if (alpha < 0) alpha = 0;
	// TODO: add your code here.
	ED_Color* c = getPrivateData<ED_Color>(mrb, self);

	c->alpha = alpha;
	return mrb_nil_value();
}

void Init_Color(mrb_state* mrb)
{
	RClass* pColor = mrb_define_class(mrb, "Color", mrb->object_class);

	mrb_define_method(mrb, pColor, "initialize", &ColorInitialize, MRB_ARGS_OPT(4));
	mrb_define_method(mrb, pColor, "initialize_copy", &ColorInitializeCopy, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pColor, "set", &ColorSet, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(3));

	mrb_define_method(mrb, pColor, "red", &ColorGetRed, MRB_ARGS_NONE());
	mrb_define_method(mrb, pColor, "red=", &ColorSetRed, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pColor, "green", &ColorGetGreen, MRB_ARGS_NONE());
	mrb_define_method(mrb, pColor, "green=", &ColorSetGreen, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pColor, "blue", &ColorGetBlue, MRB_ARGS_NONE());
	mrb_define_method(mrb, pColor, "blue=", &ColorSetBlue, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pColor, "alpha", &ColorGetAlpha, MRB_ARGS_NONE());
	mrb_define_method(mrb, pColor, "alpha=", &ColorSetAlpha, MRB_ARGS_REQ(1));
}

void Final_Color(mrb_state* mrb)
{
	return;
}