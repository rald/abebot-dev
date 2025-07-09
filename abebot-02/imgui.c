#include "imgui.h"

extern SDL_Renderer* renderer;
extern struct UIState uistate;

// Simplified interface to SDL's fillrect call
void drawrect(int x, int y, int w, int h, SDL_Color color) {
  SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
  SDL_RenderFillRect(renderer,&(SDL_Rect){x,y,w,h});
}

// Check whether current mouse position is within a rectangle
bool regionHit(int x, int y, int w, int h) {
  if (uistate.mouseX < x ||
    uistate.mouseY < y ||
    uistate.mouseX >= x + w ||
    uistate.mouseY >= y + h)
    return false;
  return true;
}

// Simple button IMGUI widget
bool button(int id, int x, int y,SDL_Color* palette) {
  // Check whether the button should be hot
  if (regionHit(x, y, 64, 48)) {
    uistate.hotItem = id;
    if (uistate.activeItem == 0 && uistate.isMouseButtonLeftDown)
      uistate.activeItem = id;
  }

  // Render button
  drawrect(x+8, y+8, 64, 48, palette[0]);
  if (uistate.hotItem == id) {
    if (uistate.activeItem == id) {
      // Button is both 'hot' and 'active'
      drawrect(x+2, y+2, 64, 48, palette[12]);
    } else {
      // Button is merely 'hot'
      drawrect(x, y, 64, 48, palette[12]);
    }
  } else {
    // button is not hot, but it may be active
    drawrect(x, y, 64, 48, palette[13]);
  }

  // If we have keyboard focus, we'll need to process the keys
  uistate.lastWidget = id;

  // If button is hot and active, but mouse button is not
  // down, the user must have clicked the button.
  if (!uistate.isMouseButtonLeftDown &&
    uistate.hotItem == id &&
    uistate.activeItem == id)
    return true;

  // Otherwise, no clicky.
  return false;
}

void imgui_prepare() {
  uistate.hotItem = 0;
}

void imgui_finish() {
  if (uistate.isMouseButtonLeftDown == 0) {
    uistate.activeItem = 0;
  } else if (uistate.activeItem == 0) {
    uistate.activeItem = -1;
  }
}
