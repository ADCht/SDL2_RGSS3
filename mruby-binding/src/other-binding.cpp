#include "other-binding.h"
#include "SDL.h"
#include "ed_main.h"
#include <mruby/array.h>
#include <mruby/proc.h>
#include <mruby/compile.h>
#include <mruby/dump.h>
#include <mruby/string.h>
#include <mruby/variable.h>
#include <mruby/throw.h>

mrb_value KernelMsgbox(mrb_state* mrb, mrb_value self)
{
	char* text = 0;
	mrb_int flags = 0;
	mrb_get_args(mrb, "z|i", &text, &flags);
	SDL_MessageBoxData data;
	data.flags = flags;
	data.message = text;
	data.title = SDL_GetWindowTitle(g_window);
	SDL_ShowMessageBox(&data, 0);
	return mrb_nil_value();
}

mrb_value KernelMsgboxP(mrb_state* mrb, mrb_value self)
{
	mrb_value obj;
	mrb_int flags = 0;
	mrb_get_args(mrb, "o|i", &obj, &flags);
	SDL_MessageBoxData data;
	char* msg = mrb_locale_from_utf8(RSTRING_PTR(mrb_inspect(mrb, obj)), (int)RSTRING_LEN(mrb_inspect(mrb, obj)));
	data.flags = flags;
	data.message = msg;
	data.title = SDL_GetWindowTitle(g_window);
	SDL_ShowMessageBox(&data, 0);
	mrb_locale_free(msg);
	return mrb_nil_value();
}

void Init_Other(mrb_state* mrb)
{
	RClass* kernel = mrb->kernel_module;

	mrb_define_module_function(mrb, kernel, "msgbox", &KernelMsgbox, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
	mrb_define_module_function(mrb, kernel, "msgbox_p", &KernelMsgboxP, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
	mrb_define_global_const(mrb, "MSGBOX_ERR", mrb_fixnum_value(16));
	mrb_define_global_const(mrb, "MSGBOX_INFO", mrb_fixnum_value(32));
	mrb_define_global_const(mrb, "MSGBOX_MSG", mrb_fixnum_value(64));

}

void Final_Other(mrb_state* mrb)
{
	return;
}