#include <stdio.h>
#include "raylib.h"

#include "Forms/forms.h"
#include "play_window.h"

void drawStartScreen(Rectangle board, Rectangle start) {
    DrawRectangleRec(board, GRAY);

    DrawRectangleRec(start, DARKGREEN);

    const char *text = "PLAY";
    int fontsize = 30;

    int textWidth = MeasureText(text, fontsize);

    float textX = start.x + (start.width - textWidth) / 2;
    float textY = start.y + (start.height - fontsize) / 2;

    DrawText(text, textX, textY, fontsize, WHITE);
}

void load_forms(form forms[7]) {
    configure_forms(forms);
}

void board_logic(board_play_state *state) {
    typedef struct {
        Rectangle board;
        Rectangle startButton;
    } StartBoard;
    
    switch (*state) {
        
        case START: {
            StartBoard startBoard;

            startBoard.board = (Rectangle) {
                50,
                100,
                700,
                600
            };

            float buttonWidth = 250;
            float buttonHeight = 75;

            startBoard.startButton = (Rectangle) {
                startBoard.board.x + (startBoard.board.width - buttonWidth) / 2,
                startBoard.board.y + (startBoard.board.height - buttonHeight) / 2,

                buttonWidth,
                buttonHeight
            };

            drawStartScreen(startBoard.board, startBoard.startButton);
            
            Vector2 mouse_position = GetMousePosition();
            bool mouseOverStart = CheckCollisionPointRec(mouse_position, startBoard.startButton);

            if (mouseOverStart && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER)) {
        
                *state = PLAYING;
                printf("\nExecuting Game Modus");
            }

            break;
        }

    }
}

void play_window(const int width,const int height) {         
    form forms[7];
    load_forms(forms);

    static board_play_state current_modus = START;
    board_logic(&current_modus);
}