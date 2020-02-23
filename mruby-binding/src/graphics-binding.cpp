#include "graphics-binding.h"
#include "binding-util.h"
#include "EasyDraw.h"

mrb_value GraphicsUpdate(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	ED_Graphics::update();

	return mrb_nil_value();
}

mrb_value GraphicsWait(mrb_state* mrb, mrb_value self)
{
	mrb_int duration = 0;
	mrb_get_args(mrb, "i", &duration);
	// TODO: add your code here.
	ED_Graphics::wait(duration);
	return mrb_nil_value();
}

mrb_value GraphicsFadeOut(mrb_state* mrb, mrb_value self)
{
	mrb_int duration = 0;
	mrb_get_args(mrb, "i", &duration);
	// TODO: add your code here.
	ED_Graphics::fadeout(duration);
	return mrb_nil_value();
}

mrb_value GraphicsFadeIn(mrb_state* mrb, mrb_value self)
{
	mrb_int duration = 0;
	mrb_get_args(mrb, "i", &duration);
	// TODO: add your code here.
	ED_Graphics::fadein(duration);
	return mrb_nil_value();
}

mrb_value GraphicsFreeze(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Graphics::freeze();
	return mrb_nil_value();
}

mrb_value GraphicsTransition(mrb_state* mrb, mrb_value self)
{
	mrb_int duration = 10;
	char* filename = 0;
	mrb_int vague = 40;
	mrb_get_args(mrb, "|izi", &duration, &filename, &vague);
	// TODO: add your code here.
	ED_Graphics::transition(duration, filename, vague);
	return mrb_nil_value();
}

mrb_value GraphicsSnapToBitmap(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Bitmap* b = ED_Graphics::snap_to_bitmap();

	return wrapObject(mrb, b, ED_BitmapType);
}

mrb_value GraphicsFrameReset(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	ED_Graphics::frame_count = 0;
	return mrb_nil_value();
}

mrb_value GraphicsWidth(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_fixnum_value(ED_Graphics::screen_width);
}

mrb_value GraphicsHeight(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_fixnum_value(ED_Graphics::screen_height);
}

mrb_value GraphicsResizeScreen(mrb_state* mrb, mrb_value self)
{
	mrb_int width = 544;
	mrb_int height = 416;
	mrb_get_args(mrb, "ii", &width, &height);
	// TODO: add your code here.

	ED_Graphics::resize_screen(width, height);
	return mrb_nil_value();
}

mrb_value GraphicsPlayMovie(mrb_state* mrb, mrb_value self)
{
	char* filename = 0;
	mrb_get_args(mrb, "z", &filename);
	// TODO: 我知道你实现不了。

	ED_Theora::play_theora(filename, ED_Graphics::screen_width, ED_Graphics::screen_height);
	return self;
}

mrb_value GraphicsGetFrameRate(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_fixnum_value(ED_Graphics::frame_rate);
}

mrb_value GraphicsSetFrameRate(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	ED_Graphics::frame_rate = value;
	return mrb_nil_value();
}

mrb_value GraphicsGetFrameCount(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_fixnum_value(ED_Graphics::frame_count);
}

mrb_value GraphicsSetFrameCount(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Graphics::frame_count = value;
	return mrb_nil_value();
}

mrb_value GraphicsGetBrightness(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	
	return mrb_fixnum_value(ED_Graphics::get_brightness());
}

mrb_value GraphicsSetBrightness(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	ED_Graphics::set_brightness(value);
	return mrb_nil_value();
}

void Init_Graphics(mrb_state* mrb)
{
	RClass* pGraphics = mrb_define_module(mrb, "Graphics");
	mrb_define_module_function(mrb, pGraphics, "update", &GraphicsUpdate, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, pGraphics, "wait", &GraphicsWait, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pGraphics, "fadeout", &GraphicsFadeOut, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pGraphics, "fadein", &GraphicsFadeIn, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pGraphics, "freeze", &GraphicsFreeze, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, pGraphics, "transition", &GraphicsTransition, MRB_ARGS_OPT(3));
	mrb_define_module_function(mrb, pGraphics, "snap_to_bitmap", &GraphicsSnapToBitmap, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, pGraphics, "width", &GraphicsWidth, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, pGraphics, "height", &GraphicsHeight, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, pGraphics, "resize_screen", &GraphicsResizeScreen, MRB_ARGS_REQ(2));

	mrb_define_module_function(mrb, pGraphics, "frame_rate", &GraphicsGetFrameRate, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, pGraphics, "frame_rate=", &GraphicsSetFrameRate, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pGraphics, "frame_count", &GraphicsGetFrameCount, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, pGraphics, "frame_count=", &GraphicsSetFrameCount, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pGraphics, "brightness", &GraphicsGetBrightness, MRB_ARGS_NONE());
	mrb_define_module_function(mrb, pGraphics, "brightness=", &GraphicsSetBrightness, MRB_ARGS_REQ(1));
}

void Final_Graphics(mrb_state* mrb)
{
	return;
}
