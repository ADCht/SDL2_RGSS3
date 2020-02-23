#include "audio-binding.h"
#include "binding-util.h"
#include "EasyDraw.h"

mrb_value AudioBGMPlay(mrb_state* mrb, mrb_value self)
{
	char* filename = 0;
	mrb_int volume = 100;
	mrb_int pitch = 100;
	mrb_int pos = 0;
	mrb_get_args(mrb, "z|iii", &filename, &volume, &pitch, &pos);
	// TODO: add your code here.

	ED_Audio::bgm_play(filename, volume, pitch, pos);
	return mrb_nil_value();
}

mrb_value AudioBGMFade(mrb_state* mrb, mrb_value self)
{
	mrb_int time = 0;
	mrb_get_args(mrb, "i", &time);
	// TODO: add your code here.

	ED_Audio::bgm_fade(time);
	return mrb_nil_value();
}

mrb_value AudioBGMStop(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	ED_Audio::bgm_stop();
	return mrb_nil_value();
}

mrb_value AudioBGSPlay(mrb_state* mrb, mrb_value self)
{
	char* filename = 0;
	mrb_int volume = 100;
	mrb_int pitch = 100;
	mrb_int pos = 0;
	mrb_get_args(mrb, "z|iii", &filename, &volume, &pitch, &pos);
	// TODO: add your code here.

	ED_Audio::bgs_play(filename, volume, pitch, pos);
	return mrb_nil_value();
}

mrb_value AudioBGSFade(mrb_state* mrb, mrb_value self)
{
	mrb_int time = 0;
	mrb_get_args(mrb, "i", &time);
	// TODO: add your code here.

	ED_Audio::bgs_fade(time);
	return mrb_nil_value();
}

mrb_value AudioBGSStop(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	ED_Audio::bgs_stop();
	return mrb_nil_value();
}

mrb_value AudioMEPlay(mrb_state* mrb, mrb_value self)
{
	char* filename = 0;
	mrb_int volume = 100;
	mrb_int pitch = 100;
	mrb_get_args(mrb, "z|ii", &filename, &volume, &pitch);
	// TODO: add your code here.

	ED_Audio::me_play(filename, volume, pitch);
	return mrb_nil_value();
}

mrb_value AudioMEFade(mrb_state* mrb, mrb_value self)
{
	mrb_int time = 0;
	mrb_get_args(mrb, "i", &time);
	// TODO: add your code here.

	ED_Audio::me_fade(time);
	return mrb_nil_value();
}

mrb_value AudioMEStop(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	ED_Audio::me_stop();
	return mrb_nil_value();
}

mrb_value AudioSEPlay(mrb_state* mrb, mrb_value self)
{
	char* filename = 0;
	mrb_int volume = 100;
	mrb_int pitch = 100;
	mrb_get_args(mrb, "z|ii", &filename, &volume, &pitch);
	// TODO: add your code here.

	ED_Audio::se_play(filename, volume, pitch);
	return mrb_nil_value();
}

mrb_value AudioSEStop(mrb_state* mrb, mrb_value self)
{
	// TODO: add your code here.

	ED_Audio::se_stop();
	return mrb_nil_value();
}

void Init_Audio(mrb_state* mrb)
{
	RClass* pAudio = mrb_define_module(mrb, "Audio");
	
	mrb_define_module_function(mrb, pAudio, "bgm_play", &AudioBGMPlay, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(3));
	mrb_define_module_function(mrb, pAudio, "bgm_fade", &AudioBGMFade, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pAudio, "bgm_stop", &AudioBGMStop, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, pAudio, "bgs_play", &AudioBGSPlay, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(3));
	mrb_define_module_function(mrb, pAudio, "bgm_fade", &AudioBGSFade, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pAudio, "bgm_stop", &AudioBGSStop, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, pAudio, "me_play", &AudioMEPlay, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(2));
	mrb_define_module_function(mrb, pAudio, "me_fade", &AudioMEFade, MRB_ARGS_REQ(1));
	mrb_define_module_function(mrb, pAudio, "me_stop", &AudioMEStop, MRB_ARGS_NONE());

	mrb_define_module_function(mrb, pAudio, "se_play", &AudioSEPlay, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(2));
	mrb_define_module_function(mrb, pAudio, "se_stop", &AudioSEStop, MRB_ARGS_NONE());
}

void Final_Audio(mrb_state* mrb)
{
	return;
}
