#include "ed_main.h"
#include "SDL_opengl.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_thread.h"
#include "input.h"

SDL_Renderer* g_renderer;
SDL_Window* g_window;
ED_Exit exit_event = 0;
ED_Font *default_font;
const char *error_info;

void Init_EasyDraw(int screen_width, int screen_height, const char* title, ED_Exit atexit)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_FLAC);
    TTF_Init();

    ED_Graphics::screen_width = screen_width;
    ED_Graphics::screen_height = screen_height;
    g_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        screen_width, screen_height, SDL_WINDOW_SHOWN);
    g_renderer = SDL_CreateRenderer(g_window, 0, SDL_RENDERER_TARGETTEXTURE);
    SDL_RenderClear(g_renderer);
    SDL_RenderPresent(g_renderer);

    default_font = new ED_Font();
    exit_event = atexit;
    ED_Graphics::init();
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void Final_EasyDraw()
{
    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    Mix_CloseAudio();

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

