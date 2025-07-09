#include <SDL2/SDL.h>

#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "palette.h"
#include "canvas.h"
#include "graphics.h"
#include "editor.h"
#include "commands.h"
#include "board.h"
#include "button.h"
#include "mouse.h"



const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 256;

typedef enum GameState {
	GAME_STATE_BOARD=0,
	GAME_STATE_EDITOR,
	GAME_STATE_MAX
} GameState;

int mouseX=0,mouseY=0;
bool isMouseButtonLeftDown=false;
bool isMouseButtonRightDown=false;

int main(int argc,char *argv[]) {

	if(argc!=2) {
		printf("%s level_file\n",argv[0]);
		exit(1);
	}

	bool quit=false;

	int frame=0;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Event event;

	srand(time(NULL));

	SDL_Init(SDL_INIT_VIDEO);

	window=SDL_CreateWindow( "Abebot", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	renderer=SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

	SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);

	SDL_SetRenderDrawColor(renderer,0x00,0x00,0x00,0xFF);
	SDL_RenderClear(renderer);

	Canvas* sprite=Canvas_Load("sprite.cvs");
	Editor* editor=Editor_New(4,4,10,10,sprite,palette);
	Commands* commands=Commands_New(4,188,10,sprite,palette);
	Board* board=Board_New("level-00.abe",0,0,sprite,palette);
	Mouse* mouse=Mouse_New();

	Button* modeSelectButton=Button_New("ModeSelectButton.cvs",SCREEN_WIDTH-16,SCREEN_HEIGHT-16,palette);

	GameState gameState=GAME_STATE_BOARD;

	while(!quit) {

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
					if(event.button.button==SDL_BUTTON_LEFT) uistate.mouseButtonLeftDown=true;
					if(event.button.button==SDL_BUTTON_RIGHT) uistate.mouseButtonRightDown=true;
				break;
				case SDL_MOUSEBUTTONUP:
					if(event.button.button==SDL_BUTTON_LEFT) uistate.mouseButtonLeftDown=false;
					if(event.button.button==SDL_BUTTON_RIGHT) uistate.mouseButtonRightDown=false;
				break;
				default: break;
			}
		}

		switch(gameState) {
			case GAME_STATE_BOARD:
				Board_Draw(board,renderer);
				Button_Draw(modeSelectButton,renderer);
				if(Button_Update(modeSelectButton,mouse)) {
					gameState=GAME_STATE_EDITOR;
				};
			break;
			case GAME_STATE_EDITOR:
				Editor_Draw(editor,renderer);
				Commands_Draw(commands,renderer);
				Button_Draw(modeSelectButton,renderer);
				if(Button_Update(modeSelectButton,mouse)) {
					gameState=GAME_STATE_BOARD;
				};
			break;
			default: break;
		}

		frame++;

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
