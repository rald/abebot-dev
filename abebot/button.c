#include "button.h"

Button* Button_New(char *filename,int x,int y,SDL_Color* palette) {
	Button* b=malloc(sizeof(*b));

	b->x=x;
	b->y=y;
	b->sprite=Canvas_Load(filename);
	b->palette=palette;
	b->state=0;

	return b;
}

void Button_Draw(Button* b,SDL_Renderer* renderer) {
	int spriteIndex=0;
	switch(b->state) {
		case BUTTON_STATE_UP:		spriteIndex=0; break;
		case BUTTON_STATE_OVER:	spriteIndex=1; break;
		case BUTTON_STATE_DOWN:	spriteIndex=2; break;
		default: break;
	}
	Canvas_Draw(renderer,b->sprite,b->palette,b->x,b->y,1,spriteIndex);
}

bool Button_Update(Button* b,Mouse *m) {

	return false;
}
