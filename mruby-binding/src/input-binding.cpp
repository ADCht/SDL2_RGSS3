#include "input-binding.h"
#include "binding-util.h"

mrb_value InputUpdate(mrb_state* mrb, mrb_value self)
{
	ED_Input::update();

	return mrb_nil_value();
}

static inline ED_InputKeys sym_to_key(mrb_state* mrb, mrb_sym sym)
{
	mrb_int length = 0;
	const char* key_code = mrb_sym2name_len(mrb, sym, &length);
	if (length == 1)
	{
		if (key_code[0] == 'A')
			return K_A;
		if (key_code[0] == 'B')
			return K_B;
		if (key_code[0] == 'C')
			return K_C;
		if (key_code[0] == 'X')
			return K_X;
		if (key_code[0] == 'Y')
			return K_Y;
		if (key_code[0] == 'Z')
			return K_Z;
		if (key_code[0] == 'L')
			return K_L;
		if (key_code[0] == 'R')
			return K_R;
	}
	if (length == 2)
	{
		if (key_code[0] == 'U')
			return K_UP;
		if (key_code[0] == 'F')
		{
			if (key_code[1] == '5')
				return K_F5;
			if (key_code[1] == '6')
				return K_F6;
			if (key_code[1] == '7')
				return K_F7;
			if (key_code[1] == '8')
				return K_F8;
			if (key_code[1] == '9')
				return K_F9;
		}
	}
	if (length == 3)
	{
		if (key_code[0] == 'A')
			return K_ALT;
	}
	if (length == 4)
	{
		if (key_code[0] == 'C')
			return K_CTRL;
		if (key_code[0] == 'D')
			return K_DOWN;
		if (key_code[0] == 'L')
			return K_LEFT;
	}
	if (length == 5)
	{
		if (key_code[0] == 'R')
			return K_RIGHT;
		if (key_code[0] == 'S')
			return K_SHIFT;
	}
	return ED_InputKeys();
}

mrb_value InputPressed(mrb_state* mrb, mrb_value self)
{
	mrb_sym key;
	mrb_get_args(mrb, "n", &key);

	return mrb_bool_value(ED_Input::IsPressed(sym_to_key(mrb, key)));
}

mrb_value InputTriggered(mrb_state* mrb, mrb_value self)
{
	mrb_sym key;
	mrb_get_args(mrb, "n", &key);

	return mrb_bool_value(ED_Input::IsTriggered(sym_to_key(mrb, key)));
}

mrb_value InputRepeated(mrb_state* mrb, mrb_value self)
{
	mrb_sym key;
	mrb_get_args(mrb, "n", &key);

	return mrb_bool_value(ED_Input::IsRepeated(sym_to_key(mrb, key)));
}

void Init_Input(mrb_state* mrb)
{
	RClass* pInput = mrb_define_module(mrb, "Input");

	mrb_define_module_function(mrb, pInput, "update", &InputUpdate, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, pInput, "press?", &InputPressed, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pInput, "trigger?", &InputTriggered, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pInput, "repeat?", &InputRepeated, MRB_ARGS_REQ(1));
}

void Final_Input(mrb_state* mrb)
{
	return;
}
