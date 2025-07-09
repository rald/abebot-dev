#ifndef MOUSE_H
#define MOUSE_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Mouse {
	int x,y;
	bool isButtonLeftDown;
	bool isButtonRightDown;
} Mouse;

Mouse* Mouse_New();
void Mouse_Update(Mouse* m,SDL_Event* e);

#endif
