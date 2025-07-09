#include "imgui.h"

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
int button(int id, int x, int y) {
  // Check whether the button should be hot
  if (regionHit(x, y, 64, 48)) {
    uistate.hotItem = id;
    if (uistate.activeItem == 0 && uistate.isMouseButtonLeftDown)
      uistate.activeItem = id;
  }

  // Render button
  drawrect(x+8, y+8, 64, 48, 0);
  if (uistate.hotitem == id) {
    if (uistate.activeitem == id) {
      // Button is both 'hot' and 'active'
      drawrect(x+2, y+2, 64, 48, 0xffffff);
    } else {
      // Button is merely 'hot'
      drawrect(x, y, 64, 48, 0xffffff);
    }
  } else {
    // button is not hot, but it may be active    
    drawrect(x, y, 64, 48, 0xaaaaaa);
  }

  // If we have keyboard focus, we'll need to process the keys
  if (uistate.kbditem == id) {
    switch (uistate.keyentered) {
	    case SDLK_TAB:
	      // If tab is pressed, lose keyboard focus.
	      // Next widget will grab the focus.
	      uistate.kbditem = 0;
	      // If shift was also pressed, we want to move focus
	      // to the previous widget instead.
	      if (uistate.keymod & KMOD_SHIFT)
	        uistate.kbditem = uistate.lastwidget;
	      // Also clear the key so that next widget
	      // won't process it
	      uistate.keyentered = 0;
	      break;
	    case SDLK_RETURN:
	      // Had keyboard focus, received return,
	      // so we'll act as if we were clicked.
	      return 1;
    }
  }

  uistate.lastwidget = id;

  // If button is hot and active, but mouse button is not
  // down, the user must have clicked the button.
  if (uistate.mousedown == 0 &&
    uistate.hotitem == id &&
    uistate.activeitem == id)
    return 1;

  // Otherwise, no clicky.
  return 0;
}


void imgui_prepare() {
  uistate.hotitem = 0;
}

void imgui_finish() {
  if (uistate.mousedown == 0) {
    uistate.activeitem = 0;
  } else {
    if (uistate.activeitem == 0)
      uistate.activeitem = -1;
  }
}
