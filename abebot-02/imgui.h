#ifndef IMGUI_H
#define IMGUI_H

#include <SDL2/SDL.h>

#include <stdbool.h>

// If you're going to render widgets to the same
// UI from different source files, you can avoid
// ID collisions by defining IMGUI_SRC_ID before
// this define block:
#ifdef IMGUI_SRC_ID
#define GEN_ID ((IMGUI_SRC_ID) + (__LINE__))
#else
#define GEN_ID (__LINE__)
#endif

typedef struct UIState {
	int mouseX,mouseY;
	bool isMouseButtonLeftDown;
	bool isMouseButtonRightDown;
	int hotItem;
	int activeItem;
	int lastWidget;
} UIState;

void drawrect(int x, int y, int w, int h, SDL_Color color);
bool regionHit(int x, int y, int w, int h);
bool button(int id, int x, int y,SDL_Color* palette);
void imgui_prepare();
void imgui_finish();

#endif
