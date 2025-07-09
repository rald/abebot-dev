#include "graphics.h"

void Graphics_SetColor(SDL_Renderer* renderer,SDL_Color color) {
	SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
}

void Graphics_DrawRect(SDL_Renderer* renderer,int x,int y,int w,int h) {
	SDL_RenderDrawRect(renderer,&(SDL_Rect){x,y,w,h});
}

void Graphics_FillRect(SDL_Renderer* renderer,int x,int y,int w,int h) {
	SDL_RenderFillRect(renderer,&(SDL_Rect){x,y,w,h});
}
