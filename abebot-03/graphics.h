#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>

void Graphics_SetColor(SDL_Renderer* renderer,SDL_Color color);
void Graphics_DrawRect(SDL_Renderer* renderer,int x,int y,int w,int h);
void Graphics_FillRect(SDL_Renderer* renderer,int x,int y,int w,int h);

#endif
