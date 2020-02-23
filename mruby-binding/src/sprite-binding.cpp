#include "sprite-binding.h"
#include "binding-util.h"
#include "EasyDraw.h"

mrb_value SpriteInitialize(mrb_state* mrb, mrb_value self)
{
	ED_Sprite* sp;
	if (mrb_get_argc(mrb) >= 1)
	{
		mrb_value viewport;
		mrb_get_args(mrb, "o", &viewport);
		// TODO: add your code here.
		ED_Viewport* vp = getPrivateDataCheck<ED_Viewport>(mrb, viewport, ED_ViewportType);

		sp = new ED_Sprite(vp);
		setPrivateData(mrb, self, sp, ED_SpriteType);
	}
	else
	{
		// TODO: add your code here.
		sp = new ED_Sprite();
		setPrivateData(mrb, self, sp, ED_SpriteType);
	}
	return mrb_nil_value();
}

CLONE_FUNC(Sprite);

mrb_value SpriteDispose(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->dispose();

	return mrb_nil_value();
}

mrb_value SpriteDisposed(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_bool_value(sp->IsDisposed());
}

mrb_value SpriteFlash(mrb_state* mrb, mrb_value self)
{
	mrb_value color;
	mrb_int duration = 0;
	mrb_get_args(mrb, "oi", &color, &duration);
	// TODO: add your code here.

	return self;
}

mrb_value SpriteUpdate(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return self;
}

mrb_value SpriteDrawTo(mrb_state* mrb, mrb_value self)
{
	mrb_value obj;
	mrb_get_args(mrb, "o", &obj);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Bitmap* b = getPrivateDataCheck<ED_Bitmap>(mrb, obj, ED_BitmapType);

	sp->draw_to(b);
	return self;
}

mrb_value SpriteGetBitmap(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Bitmap* b = sp->get_bitmap();

	return wrapObject(mrb, b, ED_BitmapType);
}

mrb_value SpriteSetBitmap(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Bitmap* b = getPrivateDataCheck<ED_Bitmap>(mrb, value, ED_BitmapType);

	sp->set_bitmap(b);
	return mrb_nil_value();
}

mrb_value SpriteGetSrcRect(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Rect* rt = sp->src_rect;

	return wrapObject(mrb, rt, ED_RectType);
}

mrb_value SpriteSetSrcRect(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Rect* rt = getPrivateDataCheck<ED_Rect>(mrb, value, ED_RectType);

	sp->src_rect = rt;
	return mrb_nil_value();
}

mrb_value SpriteGetViewport(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Viewport* vp = sp->get_viewport();

	return wrapObject(mrb, vp, ED_ViewportType);
}

mrb_value SpriteSetViewport(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Viewport* vp = getPrivateDataCheck<ED_Viewport>(mrb, value, ED_ViewportType);

	return mrb_nil_value();
}

mrb_value SpriteGetVisible(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_bool_value(sp->visible);
}

mrb_value SpriteSetVisible(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = true;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->visible = value;
	return mrb_nil_value();
}

mrb_value SpriteGetX(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_fixnum_value(sp->x);
}

mrb_value SpriteSetX(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->x = value;
	return mrb_nil_value();
}

mrb_value SpriteGetY(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_fixnum_value(sp->y);
}

mrb_value SpriteSetY(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->y = value;
	return mrb_nil_value();
}

mrb_value SpriteGetZ(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_fixnum_value(sp->get_z());
}

mrb_value SpriteSetZ(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->set_z(value);
	return mrb_nil_value();
}

mrb_value SpriteGetOX(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_fixnum_value(sp->ox);
}

mrb_value SpriteSetOX(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->ox = value;
	return mrb_nil_value();
}

mrb_value SpriteGetOY(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_fixnum_value(sp->oy);
}

mrb_value SpriteSetOY(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->oy = value;
	return mrb_nil_value();
}

mrb_value SpriteGetZoomX(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_float_value(mrb, sp->zoom_x);
}

mrb_value SpriteSetZoomX(mrb_state* mrb, mrb_value self)
{
	mrb_float value = 0;
	mrb_get_args(mrb, "f", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->zoom_x = value;
	return mrb_nil_value();
}

mrb_value SpriteGetZoomY(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_float_value(mrb, sp->zoom_y);
}

mrb_value SpriteSetZoomY(mrb_state* mrb, mrb_value self)
{
	mrb_float value = 0;
	mrb_get_args(mrb, "f", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->zoom_y = value;
	return mrb_nil_value();
}

mrb_value SpriteGetAngle(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_fixnum_value(sp->angle);
}

mrb_value SpriteSetAngle(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->angle = value;
	return mrb_nil_value();
}

mrb_value SpriteGetWaveAmp(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteSetWaveAmp(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteGetWaveLength(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteSetWaveLength(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteGetWaveSpeed(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteSetWaveSpeed(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteGetWavePhase(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteSetWavePhase(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteGetMirror(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_bool_value(sp->mirror);
}

mrb_value SpriteSetMirror(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = false;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->mirror = value;
	return mrb_nil_value();
}

mrb_value SpriteGetBushDepth(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteSetBushDepth(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteGetBushOpacity(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteSetBushOpacity(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteGetOpacity(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_fixnum_value(sp->opacity);
}

mrb_value SpriteSetOpacity(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->opacity = value;
	return mrb_nil_value();
}

mrb_value SpriteGetBlendType(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	return mrb_fixnum_value(sp->blend_type);
}

mrb_value SpriteSetBlendType(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	sp->blend_type = value;
	return mrb_nil_value();
}

mrb_value SpriteGetColor(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteSetColor(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.

	return mrb_nil_value();
}

mrb_value SpriteGetTone(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Tone* t = sp->tone;

	return wrapObject(mrb, t, ED_ToneType);
}

mrb_value SpriteSetTone(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Sprite* sp = getPrivateData<ED_Sprite>(mrb, self);

	ED_Tone* t = getPrivateDataCheck<ED_Tone>(mrb, value, ED_ToneType);

	sp->tone = t;
	return mrb_nil_value();
}

void Init_Sprite(mrb_state* mrb)
{
	RClass* pSprite = mrb_define_class(mrb, "Sprite", mrb->object_class);

	mrb_define_method(mrb, pSprite, "initialize", &SpriteInitialize, MRB_ARGS_OPT(1));
	mrb_define_method(mrb, pSprite, "initialize_copy", &SpriteInitializeCopy, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "dispose", &SpriteDispose, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "disposed?", &SpriteDisposed, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "flash", &SpriteFlash, MRB_ARGS_REQ(2));
	mrb_define_method(mrb, pSprite, "update", &SpriteUpdate, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "draw_to", &SpriteDrawTo, MRB_ARGS_REQ(1));

	mrb_define_method(mrb, pSprite, "bitmap", &SpriteGetBitmap, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "bitmap=", &SpriteSetBitmap, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "src_rect", &SpriteGetSrcRect, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "src_rect=", &SpriteSetSrcRect, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "viewport", &SpriteGetViewport, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "viewport=", &SpriteSetViewport, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "visible", &SpriteGetVisible, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "visible=", &SpriteSetVisible, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "x", &SpriteGetX, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "x=", &SpriteSetX, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "y", &SpriteGetY, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "y=", &SpriteSetY, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "z", &SpriteGetZ, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "z=", &SpriteSetZ, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "ox", &SpriteGetOX, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "ox=", &SpriteSetOX, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "oy", &SpriteGetOY, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "oy=", &SpriteSetOY, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "zoom_x", &SpriteGetZoomX, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "zoom_x=", &SpriteSetZoomX, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "zoom_y", &SpriteGetZoomY, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "zoom_y=", &SpriteSetZoomY, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "angle", &SpriteGetAngle, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "angle=", &SpriteSetAngle, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "wave_amp", &SpriteGetWaveAmp, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "wave_amp=", &SpriteSetWaveAmp, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "wave_length", &SpriteGetWaveLength, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "wave_length=", &SpriteSetWaveLength, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "wave_speed", &SpriteGetWaveSpeed, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "wave_speed=", &SpriteSetWaveSpeed, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "wave_phase", &SpriteGetWavePhase, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "wave_phase=", &SpriteSetWavePhase, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "mirror", &SpriteGetMirror, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "mirror=", &SpriteSetMirror, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "bush_depth", &SpriteGetBushDepth, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "bush_depth=", &SpriteSetBushDepth, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "bush_opacity", &SpriteGetBushOpacity, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "bush_opacity=", &SpriteSetBushOpacity, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "opacity", &SpriteGetOpacity, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "opacity=", &SpriteSetOpacity, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "blend_type", &SpriteGetBlendType, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "blend_type=", &SpriteSetBlendType, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "color", &SpriteGetColor, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "color=", &SpriteSetColor, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pSprite, "tone", &SpriteGetTone, MRB_ARGS_NONE());
	mrb_define_method(mrb, pSprite, "tone=", &SpriteSetTone, MRB_ARGS_REQ(1));
}

void Final_Sprite(mrb_state* mrb)
{
	return;
}