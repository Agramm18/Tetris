#ifndef MENU_BUTTONS_H
#define MENU_BUTTONS_H

#include "raylib.h"

typedef struct {
    Rectangle playButton;
    Rectangle gameMode;
    Rectangle scoreBoard;
} menu_buttons;

menu_buttons define_menu_buttons(int width, int height);

#endif