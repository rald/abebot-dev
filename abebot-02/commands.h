#ifndef COMMANDS_H
#define COMMANDS_H

#include <SDL2/SDL.h>

#include "canvas.h"

typedef struct Commands {
	int x,y;
	int w;
	int cursorX,cursorY;
	Canvas *sprite;
	SDL_Color *palette;
} Commands;

Commands* Commands_New(int x,int y,int w,Canvas* sprite,SDL_Color* palette);

void Commands_Draw(Commands* commands,SDL_Renderer* renderer);

#endif
