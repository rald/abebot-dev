#include "button.h"

extern UIState uistate;

Button* Button_New(int id,char *filename,int x,int y,SDL_Color* palette) {
	Button* b=malloc(sizeof(*b));

	b->id=id;
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

bool Button_Update(Button* b) {

	if(regionHit(b->x,b->y,b->sprite->w,b->sprite->h)) {
	  uistate.hotItem = b->id;
    if (uistate.activeItem == 0 && uistate.isMouseButtonLeftDown)
      uistate.activeItem = b->id;
	}

	// Render button
  if (uistate.hotItem == b->id) {
    if (uistate.activeItem == b->id) {
      // Button is both 'hot' and 'active'
			b->state=BUTTON_STATE_DOWN;
    } else {
      // Button is merely 'hot'
			b->state=BUTTON_STATE_OVER;
    }
  } else {
    // button is not hot, but it may be active
		b->state=BUTTON_STATE_UP;
  }

  // If we have keyboard focus, we'll need to process the keys
  uistate.lastWidget = b->id;

  // If button is hot and active, but mouse button is not
  // down, the user must have clicked the button.
  if(	!uistate.isMouseButtonLeftDown &&
    	uistate.hotItem == b->id &&
    	uistate.activeItem == b->id)
	{
    return true;
  }

	return false;
}
