#include "font-binding.h"
#include "binding-util.h"
#include "EasyDraw.h"

mrb_value FontInitialize(mrb_state* mrb, mrb_value self)
{
	char* name = 0;
	mrb_int size = 24;
	mrb_get_args(mrb, "|zi", &name, &size);
	// TODO: add your code here.
	ED_Font* ft = new ED_Font(name, size);

	setPrivateData(mrb, self, ft, ED_FontType);

	return mrb_nil_value();
}

CLONE_FUNC(Font);

mrb_value FontExist(mrb_state* mrb, mrb_value self) // Static Method
{
	char* name = 0;
	mrb_get_args(mrb, "z", &name);
	// TODO: add your code here.

	return mrb_bool_value(ED_Font::exist(name));
}

mrb_value FontGetName(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	return mrb_str_new_cstr(mrb, ft->name);
}

mrb_value FontSetName(mrb_state* mrb, mrb_value self)
{
	char* value = 0;
	mrb_get_args(mrb, "z", &value);
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ft->name = value;
	return mrb_nil_value();
}

mrb_value FontGetSize(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	return mrb_fixnum_value(ft->size);
}

mrb_value FontSetSize(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ft->size = value;
	return mrb_nil_value();
}

mrb_value FontGetBold(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	return mrb_bool_value(ft->bold);
}

mrb_value FontSetBold(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = 0;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ft->bold = value;
	return mrb_nil_value();
}

mrb_value FontGetItalic(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	return mrb_bool_value(ft->italic);
}

mrb_value FontSetItalic(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = 0;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ft->italic = value;
	return mrb_nil_value();
}

mrb_value FontGetOutline(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	return mrb_bool_value(ft->outline);
}

mrb_value FontSetOutline(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = 0;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ft->outline = value;
	return mrb_nil_value();
}

mrb_value FontGetShadow(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	return mrb_bool_value(ft->shadow);
}

mrb_value FontSetShadow(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = 0;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ft->shadow = value;
	return mrb_nil_value();
}

mrb_value FontGetColor(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ED_Color* cr = ft->color;

	return wrapObject(mrb, cr, ED_ColorType);
}

mrb_value FontSetColor(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ED_Color* cr = getPrivateDataCheck<ED_Color>(mrb, value, ED_ColorType);

	ft->color = cr;
	return mrb_nil_value();
}

mrb_value FontGetOutColor(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ED_Color* cr = ft->out_color;

	return wrapObject(mrb, cr, ED_ColorType);
}

mrb_value FontSetOutColor(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Font* ft = getPrivateData<ED_Font>(mrb, self);

	ED_Color* cr = getPrivateDataCheck<ED_Color>(mrb, value, ED_ColorType);

	ft->out_color = cr;
	return mrb_nil_value();
}

// ----------------------- Static Method -----------------------
mrb_value FontGetNameDef(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_str_new_cstr(mrb, ED_Font::default_name);
}

mrb_value FontSetNameDef(mrb_state* mrb, mrb_value self)
{
	char* value = 0;
	mrb_get_args(mrb, "z", &value);
	// TODO: add your code here.
	ED_Font::default_name = value;

	return mrb_nil_value();
}

mrb_value FontGetSizeDef(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_fixnum_value(ED_Font::default_size);
}

mrb_value FontSetSizeDef(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	ED_Font::default_size = value;
	return mrb_nil_value();
}

mrb_value FontGetBoldDef(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_bool_value(ED_Font::default_bold);
}

mrb_value FontSetBoldDef(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = 0;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.

	ED_Font::default_bold = value;
	return mrb_nil_value();
}

mrb_value FontGetItalicDef(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_bool_value(ED_Font::default_italic);
}

mrb_value FontSetItalicDef(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = 0;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.

	ED_Font::default_italic = value;
	return mrb_nil_value();
}

mrb_value FontGetOutlineDef(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_bool_value(ED_Font::default_outline);
}

mrb_value FontSetOutlineDef(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = 0;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.

	ED_Font::default_outline = value;
	return mrb_nil_value();
}

mrb_value FontGetShadowDef(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_bool_value(ED_Font::default_shadow);
}

mrb_value FontSetShadowDef(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = 0;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.

	ED_Font::default_shadow = value;
	return mrb_nil_value();
}

mrb_value FontGetColorDef(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return wrapObject(mrb, ED_Font::default_color, ED_ColorType);
}

mrb_value FontSetColorDef(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.

	ED_Color* cr = getPrivateDataCheck<ED_Color>(mrb, value, ED_ColorType);

	ED_Font::default_color = cr;
	return mrb_nil_value();
}

mrb_value FontGetOutColorDef(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return wrapObject(mrb, ED_Font::default_out_color, ED_ColorType);
}

mrb_value FontSetOutColorDef(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.

	ED_Color* cr = getPrivateDataCheck<ED_Color>(mrb, value, ED_ColorType);

	ED_Font::default_out_color = cr;
	return mrb_nil_value();
}

void Init_Font(mrb_state* mrb)
{
	RClass* pFont = mrb_define_class(mrb, "Font", mrb->object_class);

	mrb_define_method(mrb, pFont, "initialize", &FontInitialize, MRB_ARGS_OPT(2));
	mrb_define_method(mrb, pFont, "initialize_copy", &FontInitializeCopy, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, pFont, "exist?", &FontExist, MRB_ARGS_REQ(1));

	mrb_define_method(mrb, pFont, "name", &FontGetName, MRB_ARGS_NONE());
	mrb_define_method(mrb, pFont, "name=", &FontSetName, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pFont, "size", &FontGetSize, MRB_ARGS_NONE());
	mrb_define_method(mrb, pFont, "size=", &FontSetSize, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pFont, "bold", &FontGetBold, MRB_ARGS_NONE());
	mrb_define_method(mrb, pFont, "bold=", &FontSetBold, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pFont, "italic", &FontGetItalic, MRB_ARGS_NONE());
	mrb_define_method(mrb, pFont, "italic=", &FontSetItalic, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pFont, "outline", &FontGetOutline, MRB_ARGS_NONE());
	mrb_define_method(mrb, pFont, "outline=", &FontSetOutline, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pFont, "shadow", &FontGetShadow, MRB_ARGS_NONE());
	mrb_define_method(mrb, pFont, "shadow=", &FontSetShadow, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pFont, "color", &FontGetColor, MRB_ARGS_NONE());
	mrb_define_method(mrb, pFont, "color=", &FontSetColor, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pFont, "out_color", &FontGetOutColor, MRB_ARGS_NONE());
	mrb_define_method(mrb, pFont, "out_color=", &FontSetOutColor, MRB_ARGS_REQ(1));

	mrb_define_class_method(mrb, pFont, "default_name", &FontGetNameDef, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, pFont, "default_name=", &FontSetNameDef, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, pFont, "default_size", &FontGetSizeDef, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, pFont, "default_size=", &FontSetSizeDef, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, pFont, "default_bold", &FontGetBoldDef, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, pFont, "default_bold=", &FontSetBoldDef, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, pFont, "default_italic", &FontGetItalicDef, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, pFont, "default_italic=", &FontSetItalicDef, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, pFont, "default_outline", &FontGetOutlineDef, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, pFont, "default_outline=", &FontSetOutlineDef, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, pFont, "default_shadow", &FontGetShadowDef, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, pFont, "default_shadow=", &FontSetShadowDef, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, pFont, "default_color", &FontGetColorDef, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, pFont, "default_color=", &FontSetColorDef, MRB_ARGS_REQ(1));
	mrb_define_class_method(mrb, pFont, "default_out_color", &FontGetOutColorDef, MRB_ARGS_NONE());
	mrb_define_class_method(mrb, pFont, "default_out_color=", &FontSetOutColorDef, MRB_ARGS_REQ(1));
}

void Final_Font(mrb_state* mrb)
{
	return;
}