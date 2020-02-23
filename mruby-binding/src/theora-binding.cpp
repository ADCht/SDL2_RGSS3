#include "theora-binding.h"
#include "binding-util.h"
#include "theora.h"

bool start_play = false;
const char* play_filename = 0;
int play_screen[2] = { 0, 0 };
bool play_finished = false;

mrb_value TheoraPlay(mrb_state* mrb, mrb_value self)
{
	char* filename = 0;
	mrb_int w = ED_Graphics::screen_width, h = ED_Graphics::screen_height;
	mrb_get_args(mrb, "z|ii", &filename, &w, &h);
	
	play_filename = filename;
	play_screen[0] = w;
	play_screen[1] = h;
	play_finished = false;
	start_play = true;

	SDL_Event lpevent;
	while (!play_finished)
		SDL_Delay(1000 / ED_Graphics::frame_rate);

	return mrb_nil_value();
};

void Init_Theora(mrb_state* mrb)
{
	RClass* pTheora = mrb_define_module(mrb, "Theora");

	mrb_define_module_function(mrb, pTheora, "play_theora", &TheoraPlay, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(2));
}

void Final_Theora(mrb_state* mrb)
{
	return;
}