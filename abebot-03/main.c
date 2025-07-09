#include <SDL2/SDL.h>

#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "palette.h"
#include "canvas.h"
#include "imgui.h"
#include "board.h"
#include "editor.h"
#include "commands.h"
#include "button.h"

const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 256;

bool quit=false;

typedef enum GameState {
	GAME_STATE_BOARD=0,
	GAME_STATE_EDITOR,
	GAME_STATE_MAX
} GameState;

GameState gameState = GAME_STATE_BOARD;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;
UIState uistate;

Canvas* sprite = NULL;

Board* board = NULL;
Editor* editor = NULL;
Commands* commands = NULL;

Canvas* modeSelectButtonSprite = NULL;
bool modeSelectButtonClicked = false;

void render() {
	SDL_Color bgcolor={0x00,0x00,0x00,0xFF};
 	drawrect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,bgcolor);

 	imgui_prepare();
		modeSelectButtonClicked=button(GEN_ID,SCREEN_WIDTH-16,SCREEN_HEIGHT-16,modeSelectButtonSprite,palette);
	imgui_finish();

	switch(gameState) {
		case GAME_STATE_BOARD:
			Board_Draw(board,renderer);
		break;
		case GAME_STATE_EDITOR:
			Editor_Draw(editor,renderer);
			Commands_Draw(commands,renderer);
		break;
	}

	SDL_RenderPresent(renderer);
}

void update() {

	Commands_Update(commands);

	if(modeSelectButtonClicked) {
		gameState=(gameState+1)%GAME_STATE_MAX;
	}
}

int main(int argc,char *argv[]) {

	if(argc!=2) {
		printf("%s level_file\n",argv[0]);
		exit(1);
	}

	srand(time(NULL));

	SDL_Init(SDL_INIT_VIDEO);

	window=SDL_CreateWindow( "Abebot", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	renderer=SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

	SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0xFF);
	SDL_RenderClear(renderer);

	sprite=Canvas_Load("sprite.cvs");

	board=Board_New(argv[1],0,0,sprite,palette);
	editor=Editor_New(0,0,10,10,sprite,palette);
	commands=Commands_New(0,185,10,sprite,palette);

	modeSelectButtonSprite=Canvas_Load("ModeSelectButton.cvs");

	while(!quit) {

		render();
		update();

		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT: quit=true; break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym) {
						case SDLK_ESCAPE: quit=true; break;
						default: break;
					}
				break;
				case SDL_MOUSEMOTION:
					uistate.mouseX = event.motion.x;
					uistate.mouseY = event.motion.y;
				break;
				case SDL_MOUSEBUTTONDOWN:
					if(event.button.button==SDL_BUTTON_LEFT) uistate.isMouseButtonLeftDown=true;
					if(event.button.button==SDL_BUTTON_RIGHT) uistate.isMouseButtonRightDown=true;
				break;
				case SDL_MOUSEBUTTONUP:
					if(event.button.button==SDL_BUTTON_LEFT) uistate.isMouseButtonLeftDown=false;
					if(event.button.button==SDL_BUTTON_RIGHT) uistate.isMouseButtonRightDown=false;
				break;
				default: break;
			}
		}

	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
