#ifndef BOARD_H
#define BOARD_H

#include <SDL2/SDL.h>
#include "canvas.h"
#include "graphics.h"

typedef struct Board {
	int x,y;
	int w,h;
	int px,py,pd;
	Canvas *sprite;
	SDL_Color *palette;
	int *p;
} Board;

Board* Board_New(char *filename,int x,int y,Canvas* sprite,SDL_Color* palette);

void Board_Draw(Board* b,SDL_Renderer* renderer);

#endif