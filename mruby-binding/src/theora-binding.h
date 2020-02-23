#ifndef THEORA_H
#define THEORA_H

#include "mruby.h"

extern bool start_play;
extern const char *play_filename;
extern int play_screen[2];
extern bool play_finished;

void Init_Theora(mrb_state* mrb);

void Final_Theora(mrb_state* mrb);

#endif