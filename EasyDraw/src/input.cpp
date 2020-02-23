#include "input.h"

namespace {
    static int status[20];
    static int timer[20];
    static bool trigger[20];
    static bool temp[20];
}

static ED_InputKeys get_key_id(SDL_Keycode code)
{
    static ED_InputKeys ret;
    switch (code)
    {
    case SDLK_DOWN:
        ret = K_DOWN;
        break;
    case SDLK_LEFT:
        ret = K_LEFT;
        break;
    case SDLK_RIGHT:
        ret = K_RIGHT;
        break;
    case SDLK_UP:
        ret = K_UP;
        break;

    case SDLK_LSHIFT:
        ret = K_A;
        break;
    case SDLK_RSHIFT:
        ret = K_A;
        break;

    case SDLK_x:
        ret = K_B;
        break;
    case SDLK_ESCAPE:
        ret = K_B;
        break;

    case SDLK_z:
        ret = K_C;
        break;
    case SDLK_SPACE:
        ret = K_C;
        break;

    case SDLK_a:
        ret = K_X;
        break;

    case SDLK_s:
        ret = K_Y;
        break;

    case SDLK_d:
        ret = K_Z;
        break;

    case SDLK_q:
        ret = K_L;
        break;

    case SDLK_w:
        ret = K_R;
        break;

    default:
        ret = K_NONE;
        break;
    }
    return ret;
}

void ED_Input::update()
{
    SDL_Event s_event;
    SDL_PollEvent(&s_event);
    ED_InputKeys id = get_key_id(s_event.key.keysym.sym);
    switch (s_event.type)
    {
    case SDL_KEYDOWN:
        if (id < 0)
            break;
        trigger[id] = true;
        timer[id] += 1;
        if (timer[id] >= 1)
            status[id] = 1; // Press
        if (timer[id] >= 15)
            status[id] = 3; // Repeat
        break;
    case SDL_KEYUP:
        if (id < 0)
            break;
        trigger[id] = false;
        temp[id] = false;
        timer[id] = 0;
        status[id] = 0;
        break;
    case SDL_QUIT:
        exit_event();
        Final_EasyDraw();
        exit(true);
        break;
    default:
        break;
    }
}

bool ED_Input::IsPressed(int key)
{
    if (key < 0 || key > 20) return false;
    return status[key] >= 1;
}

bool ED_Input::IsTriggered(int key)
{
    if (key < 0 || key > 20) return false;
    if (trigger[key] && !temp[key])
    {
        temp[key] = true;
        return true;
    }
    return false;
}

bool ED_Input::IsRepeated(int key)
{
    if (key < 0 || key > 20) return false;
    return status[key] == 3;
}
