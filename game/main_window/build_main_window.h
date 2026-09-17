#ifndef BOARD_H
#define BOARD_H

#include "raylib.h"

void configure_window(const int,const int, const char *);

typedef struct button_plan{
    int width;
    int height;
} button_plan;

#endif