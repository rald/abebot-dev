#ifndef CANVAS_H
#define CANVAS_H

#include <SDL2/SDL.h>

#include "graphics.h"

typedef struct Canvas {
	int w,h;
	int f,t;
	int *p;
} Canvas;

Canvas* Canvas_Load(char* filename);

void Canvas_Draw(SDL_Renderer* renderer,Canvas* c,SDL_Color* palette,int x,int y,int s,int f);

#endif
