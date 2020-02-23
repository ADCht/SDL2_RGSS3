#include "plane-binding.h"
#include "binding-util.h"
#include "EasyDraw.h"

mrb_value PlaneInitialize(mrb_state* mrb, mrb_value self)
{
	mrb_value viewport;
	mrb_get_args(mrb, "|o", &viewport);
	// TODO: add your code here.
	if (mrb_get_argc(mrb) <= 0)
	{
		ED_Plane* pl = new ED_Plane();

		setPrivateData(mrb, self, pl, ED_PlaneType);
	}
	else
	{
		ED_Viewport* vp = getPrivateDataCheck<ED_Viewport>(mrb, viewport, ED_ViewportType);
		ED_Plane* pl = new ED_Plane(vp);

		setPrivateData(mrb, self, pl, ED_PlaneType);
	}
	return mrb_nil_value();
}

CLONE_FUNC(Plane);

mrb_value PlaneDispose(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->dispose();

	return mrb_nil_value();
}

mrb_value PlaneDisposed(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_bool_value(pl->IsDisposed());
}

mrb_value PlaneGetBitmap(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	ED_Bitmap* b = pl->get_bitmap();

	return wrapObject(mrb, b, ED_BitmapType);
}

mrb_value PlaneSetBitmap(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	ED_Bitmap* b = getPrivateDataCheck<ED_Bitmap>(mrb, value, ED_BitmapType);

	pl->set_bitmap(b);
	return mrb_nil_value();
}

mrb_value PlaneGetViewport(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	ED_Viewport* vp = pl->get_viewport();

	return wrapObject(mrb, vp, ED_ViewportType);
}

mrb_value PlaneSetViewport(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	ED_Viewport* vp = getPrivateDataCheck<ED_Viewport>(mrb, value, ED_ViewportType);

	pl->set_viewport(vp);
	return mrb_nil_value();
}

mrb_value PlaneGetVisible(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_bool_value(pl->get_visible());
}

mrb_value PlaneSetVisible(mrb_state* mrb, mrb_value self)
{
	mrb_bool value = true;
	mrb_get_args(mrb, "b", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->set_visible(value);
	return mrb_nil_value();
}

mrb_value PlaneGetZ(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_fixnum_value(pl->get_z());
}

mrb_value PlaneSetZ(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->set_z(value);
	return mrb_nil_value();
}

mrb_value PlaneGetOX(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_fixnum_value(pl->get_ox());
}

mrb_value PlaneSetOX(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->set_ox(value);
	return mrb_nil_value();
}

mrb_value PlaneGetOY(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_fixnum_value(pl->get_oy());
}

mrb_value PlaneSetOY(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->set_oy(value);
	return mrb_nil_value();
}

mrb_value PlaneGetZoomX(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_fixnum_value(pl->get_zoom_x());
}

mrb_value PlaneSetZoomX(mrb_state* mrb, mrb_value self)
{
	mrb_float value = 0;
	mrb_get_args(mrb, "f", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->set_zoom_x(value);
	return mrb_nil_value();
}

mrb_value PlaneGetZoomY(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_fixnum_value(pl->get_zoom_y());
}

mrb_value PlaneSetZoomY(mrb_state* mrb, mrb_value self)
{
	mrb_float value = 0;
	mrb_get_args(mrb, "f", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->set_zoom_y(value);
	return mrb_nil_value();
}

mrb_value PlaneGetOpacity(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_fixnum_value(pl->get_opacity());
}

mrb_value PlaneSetOpacity(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->set_opacity(value);
	return mrb_nil_value();
}

mrb_value PlaneGetBlendType(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	return mrb_fixnum_value(pl->get_blend_type());
}

mrb_value PlaneSetBlendType(mrb_state* mrb, mrb_value self)
{
	mrb_int value = 0;
	mrb_get_args(mrb, "i", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	pl->set_blend_type(value);
	return mrb_nil_value();
}

mrb_value PlaneGetColor(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	ED_Color* c = pl->get_color();

	return wrapObject(mrb, c, ED_ColorType);
}

mrb_value PlaneSetColor(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	ED_Color* c = getPrivateDataCheck<ED_Color>(mrb, value, ED_ColorType);

	pl->set_color(c);
	return mrb_nil_value();
}

mrb_value PlaneGetTone(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	ED_Tone* t = pl->get_tone();

	return wrapObject(mrb, t, ED_ToneType);
}

mrb_value PlaneSetTone(mrb_state* mrb, mrb_value self)
{
	mrb_value value;
	mrb_get_args(mrb, "o", &value);
	// TODO: add your code here.
	ED_Plane* pl = getPrivateData<ED_Plane>(mrb, self);

	ED_Tone* t = getPrivateDataCheck<ED_Tone>(mrb, value, ED_ToneType);

	pl->set_tone(t);
	return mrb_nil_value();
}

void Init_Plane(mrb_state* mrb)
{
	RClass* pPlane = mrb_define_class(mrb, "Plane", mrb->object_class);

	mrb_define_method(mrb, pPlane, "initialize", &PlaneInitialize, MRB_ARGS_OPT(1));
	mrb_define_method(mrb, pPlane, "initialize_copy", &PlaneInitializeCopy, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "dispose", &PlaneDispose, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "disposed?", &PlaneDisposed, MRB_ARGS_NONE());

	mrb_define_method(mrb, pPlane, "bitmap", &PlaneGetBitmap, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "bitmap=", &PlaneSetBitmap, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "viewport", &PlaneGetViewport, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "viewport=", &PlaneSetViewport, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "visible", &PlaneGetVisible, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "visible=", &PlaneSetVisible, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "z", &PlaneGetZ, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "z=", &PlaneSetZ, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "ox", &PlaneGetOX, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "ox=", &PlaneSetOX, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "oy", &PlaneGetOY, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "oy=", &PlaneSetOY, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "zoom_x", &PlaneGetZoomX, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "zoom_x=", &PlaneSetZoomX, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "zoom_y", &PlaneGetZoomY, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "zoom_y=", &PlaneSetZoomY, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "opacity", &PlaneGetOpacity, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "opacity=", &PlaneSetOpacity, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "blend_type", &PlaneGetBlendType, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "blent_type=", &PlaneSetBlendType, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "color", &PlaneGetColor, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "color=", &PlaneSetColor, MRB_ARGS_REQ(1));
	mrb_define_method(mrb, pPlane, "tone", &PlaneGetTone, MRB_ARGS_NONE());
	mrb_define_method(mrb, pPlane, "tone=", &PlaneSetTone, MRB_ARGS_REQ(1));
}

void Final_Plane(mrb_state* mrb)
{
	return;
}
