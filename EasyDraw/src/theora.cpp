#include "theora.h"
#include "input.h"
#include "ed_main.h"

static Uint32 baseticks = 0;

typedef struct AudioQueue {
	const THEORAPLAY_AudioPacket* audio;
	int offset;
	struct AudioQueue* next;
} AudioQueue;

static volatile AudioQueue* audio_queue = NULL;
static volatile AudioQueue* audio_queue_tail = NULL;

static void SDLCALL audio_callback(void* userdata, Uint8* stream, int len) {
	Sint16* dst = (Sint16*)stream;

	while (audio_queue && (len > 0)) {
		volatile AudioQueue* item = audio_queue;
		AudioQueue* next = item->next;
		const int channels = item->audio->channels;

		const float* src = item->audio->samples + (item->offset * channels);
		int cpy = (item->audio->frames - item->offset) * channels;
		int i;

		if (cpy > (len / sizeof(Sint16)))
			cpy = len / sizeof(Sint16);

		for (i = 0; i < cpy; i++) {
			const float val = *(src++);
			if (val < -1.0f)
				*(dst++) = -32768;
			else if (val > 1.0f)
				*(dst++) = 32767;
			else
				*(dst++) = (Sint16)(val * 32767.0f);
		}

		item->offset += (cpy / channels);
		len -= cpy * sizeof(Sint16);

		if (item->offset >= item->audio->frames) {
			THEORAPLAY_freeAudio(item->audio);
			SDL_free((void*)item);
			audio_queue = next;
		}
	}

	if (!audio_queue)
		audio_queue_tail = NULL;

	if (len > 0)
		memset(dst, '\0', len);
}


static void queue_audio(const THEORAPLAY_AudioPacket* audio) {
	AudioQueue* item = (AudioQueue*)SDL_malloc(sizeof(AudioQueue));
	if (!item) {
		THEORAPLAY_freeAudio(audio);
		return;
	}

	item->audio = audio;
	item->offset = 0;
	item->next = NULL;

	SDL_LockAudio();
	if (audio_queue_tail)
		audio_queue_tail->next = item;
	else
		audio_queue = item;
	audio_queue_tail = item;
	SDL_UnlockAudio();
}


static void playfile(const char* fname, int width_, int height_) {
	THEORAPLAY_Decoder* decoder = NULL;
	const THEORAPLAY_VideoFrame* video = NULL;
	const THEORAPLAY_AudioPacket* audio = NULL;
	SDL_Texture* texture = NULL;
	SDL_AudioSpec spec;
	SDL_Event event;
	Uint32 framems = 0;
	int initfailed = 0;
	int quit = 0;

	decoder = THEORAPLAY_startDecodeFile(fname, 30, THEORAPLAY_VIDFMT_IYUV);

	while (!audio || !video) {
		if (!audio) audio = THEORAPLAY_getAudio(decoder);
		if (!video) video = THEORAPLAY_getVideo(decoder);
		SDL_Delay(10);
	}

	int width = video->width;
	int height = video->height;

	framems = (video->fps == 0.0) ? 0 : ((Uint32)(1000.0 / video->fps));

	SDL_Renderer* renderer = g_renderer;

	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING, video->width, video->height);

	initfailed = quit = !texture;

	memset(&spec, '\0', sizeof(SDL_AudioSpec));
	spec.freq = audio->freq;
	spec.format = AUDIO_S16SYS;
	spec.channels = audio->channels;
	spec.samples = 2048;
	spec.callback = audio_callback;
	initfailed = quit = (initfailed || (SDL_OpenAudio(&spec, NULL) != 0));

	void* pixels = NULL;
	int pitch = 0;

	while (audio) {
		queue_audio(audio);
		audio = THEORAPLAY_getAudio(decoder);
	}

	baseticks = SDL_GetTicks();

	if (!quit)
		SDL_PauseAudio(0);

	while (!quit && THEORAPLAY_isDecoding(decoder)) {
		const Uint32 now = SDL_GetTicks() - baseticks;

		if (!video)
			video = THEORAPLAY_getVideo(decoder);

		if (video && (video->playms <= now)) {
			if (framems && ((now - video->playms) >= framems)) {
				const THEORAPLAY_VideoFrame* last = video;
				while ((video = THEORAPLAY_getVideo(decoder)) != NULL) {
					THEORAPLAY_freeVideo(last);
					last = video;
					if ((now - video->playms) < framems)
						break;
				}

				if (!video)
					video = last;
			}

			SDL_LockTexture(texture, NULL, &pixels, &pitch);
			const int w = video->width;
			const int h = video->height;
			const Uint8* y = (const Uint8*)video->pixels;
			const Uint8* u = y + (w * h);
			const Uint8* v = u + ((w / 2) * (h / 2));
			Uint8* dst = (Uint8*)pixels;
			int i;

			//memcpy(pixels, video->pixels, video->height * pitch);

			for (i = 0; i < h; i++, y += w, dst += pitch) {
				SDL_memcpy(dst, y, w);
			}

			for (i = 0; i < h / 2; i++, u += w / 2, dst += pitch / 2) {
				SDL_memcpy(dst, u, w / 2);
			}

			for (i = 0; i < h / 2; i++, v += w / 2, dst += pitch / 2) {
				SDL_memcpy(dst, v, w / 2);
			}

			SDL_UnlockTexture(texture);

			THEORAPLAY_freeVideo(video);
			video = NULL;
		}
		else {
			SDL_Delay(10);
		}

		while ((audio = THEORAPLAY_getAudio(decoder)) != NULL)
			queue_audio(audio);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {

			case SDL_QUIT:
				exit_event();
				exit(-1);
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
					quit = 1;
				break;
			}
		}

		SDL_RenderClear(renderer);
		SDL_Rect dst_rect;
		dst_rect.x = ED_Graphics::screen_width / 2 - width_ / 2;
		dst_rect.y = ED_Graphics::screen_height / 2 - height_ / 2;
		dst_rect.w = width_;
		dst_rect.h = height_;
		SDL_RenderCopy(renderer, texture, NULL, &dst_rect);
		SDL_RenderPresent(renderer);
	}

	while (!quit) {
		SDL_LockAudio();
		quit = (audio_queue == NULL);
		SDL_UnlockAudio();
		if (!quit)
			SDL_Delay(100);
	}

	if (texture) SDL_DestroyTexture(texture);
	if (video) THEORAPLAY_freeVideo(video);
	if (audio) THEORAPLAY_freeAudio(audio);
	if (decoder) THEORAPLAY_stopDecode(decoder);
}

void ED_Theora::play_theora(const char* filename, int width, int height)
{
	playfile(filename, width, height);
}
