#include "raylib.h"
#include "menu_buttons.h"

menu_buttons define_menu_buttons(int width, int height)
{
    (void)width;
    (void)height;

    menu_buttons buttons;

    buttons.playButton = (Rectangle){
        50,
        250,
        200,
        60
    };

    buttons.gameMode = (Rectangle){
        300,
        250,
        200,
        60
    };

    buttons.scoreBoard = (Rectangle){
        550,
        250,
        200,
        60
    };

    DrawRectangleRec(buttons.playButton, WHITE);
    DrawText(
        "Play",
        130,
        270,
        20,
        BLACK
    );

    DrawRectangleRec(buttons.gameMode, WHITE);
    DrawText(
        "Select Game Mode",
        315,
        270,
        20,
        BLACK
    );

    DrawRectangleRec(buttons.scoreBoard, WHITE);
    DrawText(
        "View Scores",
        590,
        270,
        20,
        BLACK
    );

    return buttons;
}