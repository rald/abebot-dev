#ifndef EDITOR_H
#define EDITOR_H

#include <SDL2/SDL.h>
#include "canvas.h"

typedef struct Editor {
	int x,y;
	int w,h;
	int cursorX,cursorY;
	int *code;
	Canvas* sprite;
	SDL_Color *palette;
} Editor;

Editor* Editor_New(int x,int y,int w,int h,Canvas* sprite,SDL_Color* palette);

void Editor_Draw(Editor* editor,SDL_Renderer* renderer);

#endif

