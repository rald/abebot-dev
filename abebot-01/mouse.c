#include "mouse.h"

Mouse* Mouse_New() {
	Mouse* m=malloc(sizeof(*m));

	m->x=0;
	m->y=0;
	m->isButtonLeftDown=false;
	m->isButtonRightDown=false;

	return m;
}

void Mouse_Update(Mouse* m,SDL_Event* e) {
	switch(e->type) {
		case SDL_MOUSEBUTTONDOWN:
			m->x=e->motion.x;
			m->y=e->motion.y;
			if(e->button.button==SDL_BUTTON_LEFT) {
				m->isButtonLeftDown=true;
			} else if(e->button.button==SDL_BUTTON_RIGHT) {
				m->isButtonRightDown=true;
			}
		break;
		case SDL_MOUSEBUTTONUP:
			m->x=e->motion.x;
			m->y=e->motion.y;
			if(e->button.button==SDL_BUTTON_LEFT) {
				m->isButtonLeftDown=false;
			} else if(e->button.button==SDL_BUTTON_RIGHT) {
				m->isButtonRightDown=false;
			}
		break;
		case SDL_MOUSEMOTION:
			m->x=e->motion.x;
			m->y=e->motion.y;
		break;
		default: break;
	}
}
