#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include "canvas.h"
#include "utils.h"
#include "mouse.h"

typedef enum ButtonState {
	BUTTON_STATE_UP=0,
	BUTTON_STATE_OVER,
	BUTTON_STATE_DOWN,
	BUTTON_STATE_MAX
} ButtonState;

typedef struct Button {
	int x,y;
	ButtonState state;
	Canvas* sprite;
	SDL_Color* palette;
} Button;

Button* Button_New(char *filename,int x,int y,SDL_Color* palette);
void Button_Draw(Button* b,SDL_Renderer* renderer);
bool Button_Update(Button* b,Mouse *m);


#endif
