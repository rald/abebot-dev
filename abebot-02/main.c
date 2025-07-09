#include <SDL2/SDL.h>

#include <stdbool.h>
#include <time.h>
#include <math.h>

#include "palette.h"
#include "imgui.h"

const int SCREEN_WIDTH = 256;
const int SCREEN_HEIGHT = 256;

bool quit=false;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Event event;
UIState uistate;



void render() {
	SDL_Color bgcolor={0x00,0x00,0x00,0xFF};
 	drawrect(0,0,640,480,bgcolor);

 	imgui_prepare();

	button(GEN_ID,50,50,palette);
	button(GEN_ID,150,50,palette);

	imgui_finish();

	SDL_RenderPresent(renderer);
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

	while(!quit) {

		render();

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
