#include "binding-util.h"

#define DEF_TYPE_(obj, sym) \
	const mrb_data_type obj##Type = \
	{ \
		#sym, \
		freeInstance<obj> \
	}

DEF_TYPE_(ED_Bitmap, Bitmap);
DEF_TYPE_(ED_Color, Color);
DEF_TYPE_(ED_Font, Font);
DEF_TYPE_(ED_Plane, Plane);
DEF_TYPE_(ED_Rect, Rect);
DEF_TYPE_(ED_Sprite, Sprite);
DEF_TYPE_(ED_Table, Table);
DEF_TYPE_(ED_Tone, Tone);
DEF_TYPE_(ED_Viewport, Viewport);

mrb_value mrb_instance_alloc_(mrb_state* mrb, mrb_value cv)
{
    struct RClass* c = mrb_class_ptr(cv);
    struct RObject* o;
    enum mrb_vtype ttype = MRB_INSTANCE_TT(c);

    if (c->tt == MRB_TT_SCLASS)
        mrb_raise(mrb, E_TYPE_ERROR, "can't create instance of singleton class");

    if (ttype == 0) ttype = MRB_TT_OBJECT;
    if (ttype <= MRB_TT_CPTR) {
        mrb_raisef(mrb, E_TYPE_ERROR, "can't create instance of %v", cv);
    }
    o = (struct RObject*)mrb_obj_alloc(mrb, ttype, c);
    return mrb_obj_value(o);
}