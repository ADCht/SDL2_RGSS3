#include "audio.h"
#include "ed_main.h"

namespace {
	Mix_Music *bgm_data;
	Mix_Chunk *bgs_data;
	int bgs_channel = 0;
	int me_channel = 0;
	int se_channel = 0;
}

void ED_Audio::bgm_play(const char* filename, int volume, int pitch, int pos)
{
	bgm_data = Mix_LoadMUS(filename);
	Mix_PlayMusic(bgm_data, -1);
	Mix_VolumeMusic(volume);
}

void ED_Audio::bgm_stop()
{
	Mix_HaltMusic();
}

void ED_Audio::bgm_fade(int time)
{
	if (Mix_PlayingMusic())
		Mix_FadeOutMusic(time);
}

void ED_Audio::bgs_play(const char* filename, int volume, int pitch, int pos)
{
	bgs_data = Mix_LoadWAV(filename);
	bgs_channel = Mix_PlayChannel(-1, bgs_data, -1);
	Mix_Volume(bgs_channel, volume * MIX_MAX_VOLUME / 100);
}

void ED_Audio::bgs_stop()
{
	if (Mix_Playing(bgs_channel))
		Mix_HaltChannel(bgs_channel);
}

void ED_Audio::bgs_fade(int time)
{
	if (Mix_Playing(bgs_channel))
		Mix_FadeOutChannel(bgs_channel, time);
}

void ED_Audio::me_play(const char* filename, int volume, int pitch)
{
	me_channel = Mix_PlayChannel(-1, Mix_LoadWAV(filename), 0);
	Mix_Volume(me_channel, volume * MIX_MAX_VOLUME / 100);
}

void ED_Audio::me_stop()
{
	if (Mix_Playing(me_channel))
		Mix_HaltChannel(me_channel);
}

void ED_Audio::me_fade(int time)
{
	if (Mix_Playing(me_channel))
		Mix_FadeOutChannel(me_channel, time);
}

void ED_Audio::se_play(const char* filename, int volume, int pitch)
{
	se_channel = Mix_PlayChannel(-1, Mix_LoadWAV(filename), 0);
	Mix_Volume(se_channel, volume * MIX_MAX_VOLUME / 100);
}

void ED_Audio::se_stop()
{
	if (Mix_Playing(se_channel))
		Mix_HaltChannel(se_channel);
}
