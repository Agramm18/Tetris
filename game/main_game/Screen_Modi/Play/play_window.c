#include <stdio.h>
#include "raylib.h"

#include "Forms/forms.h"

void load_forms() {
    configure_forms();
}

void drawBoard(Rectangle board, Rectangle start) {
    DrawRectangleRec(board, GRAY);

    DrawRectangleRec(start, DARKGREEN);

    const char *text = "PLAY";
    int fontsize = 30;

    int textWidth = MeasureText(text, fontsize);

    float textX = start.x + (start.width - textWidth) / 2;
    float textY = start.y + (start.height - fontsize) / 2;

    DrawText(text, textX, textY, fontsize, WHITE);
}

void play_window(const int width,const int height) {

    typedef enum {
        START,
        PLAYING,
        PAUSE,
        END
    } board_modus;

    Rectangle board = {50, 100, 700, 600};

    float buttonWidth = 250;
    float buttonHeight = 75;

    Rectangle start = {
        board.x + (board.width - buttonWidth) / 2,
        board.y + (board.height - buttonHeight) / 2,

        buttonWidth,
        buttonHeight
    };

    drawBoard(board, start);


    Vector2 mouse_position = GetMousePosition();
    bool mouseOverStart = CheckCollisionPointRec(mouse_position, start);

    if (mouseOverStart && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER)) {
        printf("\nStarting Game\n");
    }
}