#ifndef BINDINGUTIL_H
#define BINDINGUTIL_H

/*
  retrieve arguments from mrb_state.

  mrb_get_args(mrb, format, ...)

  returns number of arguments parsed.

  format specifiers:

    string  mruby type     C type                 note
    ----------------------------------------------------------------------------------------------
    o:      Object         [mrb_value]
    C:      Class/Module   [mrb_value]
    S:      String         [mrb_value]            when ! follows, the value may be nil
    A:      Array          [mrb_value]            when ! follows, the value may be nil
    H:      Hash           [mrb_value]            when ! follows, the value may be nil
    s:      String         [char*,mrb_int]        Receive two arguments; s! gives (NULL,0) for nil
    z:      String         [char*]                NUL terminated string; z! gives NULL for nil
    a:      Array          [mrb_value*,mrb_int]   Receive two arguments; a! gives (NULL,0) for nil
    f:      Fixnum/Float   [mrb_float]
    i:      Fixnum/Float   [mrb_int]
    b:      boolean        [mrb_bool]
    n:      String/Symbol  [mrb_sym]
    d:      data           [void*,mrb_data_type const] 2nd argument will be used to check data type so it won't be modified; when ! follows, the value may be nil
    I:      inline struct  [void*]
    &:      block          [mrb_value]            &! raises exception if no block given
    *:      rest argument  [mrb_value*,mrb_int]   The rest of the arguments as an array; *! avoid copy of the stack
    |:      optional                              Following arguments are optional
    ?:      optional given [mrb_bool]             true if preceding argument (optional) is given
    ':':    keyword args   [mrb_kwargs const]     Get keyword arguments
 */

#include <iostream>

#include "mruby.h"
#include "mruby/data.h"
#include "mruby/variable.h"
#include "mruby/class.h"

#include "EasyDraw.h"
#include <stdio.h>

#define DEF_TYPE(obj, sym) \
	extern const mrb_data_type obj##Type;

#define CLONE_FUNC(klass) \
mrb_value klass##InitializeCopy(mrb_state* mrb, mrb_value self) \
{ \
	mrb_value other; \
	mrb_get_args(mrb, "o", &other); \
	ED_##klass* obj = getPrivateDataCheck<ED_##klass>(mrb, other, ED_##klass##Type); \
	ED_##klass* new_obj = new ED_##klass(*obj); \
	setPrivateData(mrb, self, new_obj, ED_##klass##Type); \
	return mrb_nil_value(); \
}

inline void
setPrivateData(mrb_state* mrb, mrb_value self, void* p, const mrb_data_type& type)
{
	DATA_PTR(self) = p;
	DATA_TYPE(self) = &type;
}

template<class C>
inline C *
getPrivateData(mrb_state* mrb, mrb_value self)
{
	C *c = static_cast<C*>(DATA_PTR(self));
	return c;
}

template<typename T>
inline T *
getPrivateDataCheck(mrb_state* mrb, mrb_value obj, const mrb_data_type &type)
{
	T* t = static_cast<T*>(DATA_PTR(obj));
	return t;
}

template<typename T>
void
freeInstance(mrb_state *, void *instance)
{
	delete static_cast<T*>(instance);
}

extern mrb_value mrb_instance_alloc_(mrb_state* mrb, mrb_value cv);

inline mrb_value
wrapObject(mrb_state* mrb, void* p, const mrb_data_type& type)
{
	RClass* klass = mrb_class_get(mrb, type.struct_name);
	mrb_value obj = mrb_instance_alloc_(mrb, mrb_obj_value(klass));
	setPrivateData(mrb, obj, p, type);

	return obj;
}

DEF_TYPE(ED_Bitmap, Bitmap);
DEF_TYPE(ED_Color, Color);
DEF_TYPE(ED_Font, Font);
DEF_TYPE(ED_Plane, Plane);
DEF_TYPE(ED_Rect, Rect);
DEF_TYPE(ED_Sprite, Sprite);
DEF_TYPE(ED_Table, Table);
DEF_TYPE(ED_Tone, Tone);
DEF_TYPE(ED_Viewport, Viewport);

#endif // BINDINGUTIL_H
