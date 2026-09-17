#include <stdio.h>
#include "raylib.h"

#include "main_window/build_main_window.h"

void execute_programm(void) {
    printf("\nLoading Titlescreen and Game Configuration\n");

    const int screen_width = 800;
    const int screen_height = 800;

    const char *window_name = "Tetris";

    configure_window(screen_width, screen_height, window_name);

}