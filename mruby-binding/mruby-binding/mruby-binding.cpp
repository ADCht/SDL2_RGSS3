// mruby-binding.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "readini.h"
#include <iostream>
#include <mruby.h>
#include <mruby/array.h>
#include <mruby/proc.h>
#include <mruby/compile.h>
#include <mruby/dump.h>
#include <mruby/string.h>
#include <mruby/variable.h>
#include <mruby/throw.h>

#include "EasyDraw.h"
#include "..\src\bitmap-binding.h"
#include "..\src\color-binding.h"
#include "..\src\font-binding.h"
#include "..\src\graphics-binding.h"
#include "..\src\plane-binding.h"
#include "..\src\rect-binding.h"
#include "..\src\sprite-binding.h"
#include "..\src\table-binding.h"
#include "..\src\tone-binding.h"
#include "..\src\viewport-binding.h"
#include "..\src\input-binding.h"
#include "..\src\audio-binding.h"
#include "..\src\theora-binding.h"
#include "..\src\other-binding.h"

#include "SDL_main.h"
#include "SDL_thread.h"

static mrb_state* mrb;

void at_exit()
{
    mrb_close(mrb);
}

extern int rgss_thread(void* frb);

int main(int argc, char *argv[])
{
    CMyINI* ini = new CMyINI();

    mrb = mrb_open();

    ini->ReadINI("Config.ini");

    Init_EasyDraw(std::stoi(ini->GetValue("Game", "Width")), std::stoi(ini->GetValue("Game", "Height")),
        ini->GetValue("Game", "Title").c_str(), at_exit);

    Init_Audio(mrb);
    Init_Bitmap(mrb);
    Init_Color(mrb);
    Init_Font(mrb);
    Init_Graphics(mrb);
    Init_Plane(mrb);
    Init_Rect(mrb);
    Init_Sprite(mrb);
    Init_Table(mrb);
    Init_Tone(mrb);
    Init_Viewport(mrb);
    Init_Input(mrb);
    Init_Theora(mrb);
    Init_Other(mrb);

    FILE* frb = fopen(ini->GetValue("Game", "Scripts").c_str(), "rb");
    SDL_CreateThread(&rgss_thread, "rgss_thread", frb);

    while (true)
    {
        ED_Input::update();
        if (start_play)
        {
            ED_Theora::play_theora(play_filename, play_screen[0], play_screen[1]);
            start_play = false;
            play_finished = true;
        }
    }

    mrb_close(mrb);
    Final_EasyDraw();
    return 0;
}

int rgss_thread(void* frb)
{
    mrb_load_file(mrb, (FILE*)frb);

    fclose((FILE*)frb);

    if (mrb->exc)
    {
        mrb_value exc = mrb_obj_value(mrb->exc);
        const char* exc_type = mrb_obj_classname(mrb, exc);
        const char* exc_message = RSTRING_PTR(mrb_funcall(mrb, exc, "message", 0));
        char msg[100];
        sprintf(msg, "%s: \n%s", exc_type, exc_message);
        MessageBoxA(0, msg, SDL_GetWindowTitle(g_window), MB_ICONERROR);
        mrb->exc = 0;
    }

    mrb_close(mrb);
    Final_EasyDraw();
    exit(true);
    return true;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
