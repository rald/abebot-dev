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

#endif
