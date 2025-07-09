#include "editor.h"

extern SDL_Color palette[];

Editor* Editor_New(int x,int y,int w,int h,Canvas* sprite,SDL_Color* palette) {
	Editor* editor=malloc(sizeof(*editor));

	editor->sprite=sprite;
	editor->x=x;
	editor->y=y;
	editor->w=w;
	editor->h=h;
	editor->cursorX=0;
	editor->cursorY=0;
	editor->palette=palette;
	editor->code=malloc(sizeof(*editor->code)*(w*h));

	for(int i=0;i<w*h;i++) {
		editor->code[i]=0b00010000;
	}

	return editor;
}

void Editor_Draw(Editor* editor,SDL_Renderer* renderer) {
	for(int i=0;i<10;i++) {
		Canvas_Draw(renderer,editor->sprite,editor->palette,i*16+16+editor->x+3,editor->y+3,1,i);
		Canvas_Draw(renderer,editor->sprite,editor->palette,editor->x+3,i*16+16+editor->y+3,1,i);
	}

	for(int i=0;i<100;i++) {
		int x=(i%10)*16+16+editor->x+3;
		int y=(i/10)*16+16+editor->y+3;

		Canvas_Draw(renderer,editor->sprite,editor->palette,x,y,1,((editor->code[i] & 0b01100000)>>5)+26);
		Canvas_Draw(renderer,editor->sprite,editor->palette,x,y,1,(editor->code[i] & 0b00011111)+10);
	}

	Graphics_SetColor(renderer,editor->palette[12]);
	Graphics_DrawRect(renderer,editor->x,editor->y,(editor->w+1)*16+6,(editor->h+1)*16+6);

}

