#pragma once
#include "SDL.h"
#include "ed_main.h"

namespace ED_Input
{
	void update();

	bool IsPressed(int key);
	bool IsTriggered(int key);
	bool IsRepeated(int key);
}

enum ED_InputKeys {
    K_NONE = -1,
    // Your Arrow Keys.
    K_DOWN = 0,
    K_LEFT,
    K_RIGHT,
    K_UP,
    // Your Normal Keys.
    K_A,
    K_B,
    K_C,
    K_X,
    K_Y,
    K_Z,
    K_L,
    K_R,
    // Your Special Keys.
    K_SHIFT,
    K_CTRL,
    K_ALT,
    // Your FFF Keys.
    K_F5,
    K_F6,
    K_F7,
    K_F8,
    K_F9
};
