#include "commands.h"

extern UIState uistate;

Commands* Commands_New(int x,int y,int w,Canvas* sprite,SDL_Color* palette) {
	Commands* commands=malloc(sizeof(*commands));

	commands->sprite=sprite;
	commands->x=x;
	commands->y=y;
	commands->w=w;
	commands->cursorX=0;
	commands->cursorY=0;
	commands->palette=palette;

	return commands;
}

void Commands_Draw(Commands* commands,SDL_Renderer* renderer) {
	for(int i=0;i<20;i++) {
		int x=(i%commands->w)*16+commands->x+3;
		int y=(i/commands->w)*16+commands->y+3;
		Canvas_Draw(renderer,commands->sprite,commands->palette,x,y,1,26);
		Canvas_Draw(renderer,commands->sprite,commands->palette,x,y,1,i+10);
	}

	Graphics_SetColor(renderer,commands->palette[12]);
	Graphics_DrawRect(renderer,commands->cursorX*16+commands->x+3,commands->cursorY*16+commands->y+3,16,16);

	Graphics_SetColor(renderer,commands->palette[12]);
	Graphics_DrawRect(renderer,commands->x,commands->y,commands->w*16+6,(20/commands->w)*16+6);

}

void Commands_Update(Commands* commands) {
	if(uistate.isMouseButtonLeftDown && inrect(
		uistate.mouseX,uistate.mouseY,
		commands->x+3,commands->y+3,commands->w*16+6,(20/commands->w)*16+6)
	) {
		int x=(uistate.mouseX-commands->x-3)/16;
		int y=(uistate.mouseY-commands->y-3)/16;
		if(x>=0 && x<=9 && y>=0 && y<=1) {
			commands->cursorX=x;
			commands->cursorY=y;
			commands->index=commands->cursorY*commands->w+commands->cursorX;
		}
	}
}
