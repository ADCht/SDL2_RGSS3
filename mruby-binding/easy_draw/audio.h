#pragma once
#include "SDL_audio.h"
#include "SDL_mixer.h"

namespace ED_Audio
{
	void bgm_play(const char *filename, int volume = 100, int pitch = 100, int pos = 0);
	void bgm_stop();
	void bgm_fade(int time);

	void bgs_play(const char* filename, int volume = 100, int pitch = 100, int pos = 0);
	void bgs_stop();
	void bgs_fade(int time);

	void me_play(const char* filename, int volume = 100, int pitch = 100);
	void me_stop();
	void me_fade(int time);

	void se_play(const char *filename, int volume = 100, int pitch = 100);
	void se_stop();
}