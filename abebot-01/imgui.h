#ifdef IMGUI_H
#define IMGUI_H

#include "utils.h"

typedef struct UIState {
	int mouseX,mouseY;
	bool isMouseButtonLeftDown;
	bool isMouseButtonRightDown;
	int hotItem;
	int activeItem;
	int lastWidget;
} UIState;

void drawrect(int x, int y, int w, int h, SDL_Color* color);
bool regionHit(int x, int y, int w, int h);
bool button(int id, int x, int y);
void imgui_prepare();
void imgui_finish();

#endif
