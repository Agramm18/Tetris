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

void board_logic(PlayState *state, playing_field *playField) {
    typedef struct {
        Rectangle board;
        Rectangle startButton;
    } StartBoard;

    switch (*state) {
        
        case LOADING_GAME_SCREEN: {
            printf("\nLoading Game Screen\n");
            
            *state = START_GAME;
            break;
        }


        case START_GAME: {
            StartBoard startBoard;

            printf("\nInitializing Board\n");

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
                printf("\nExecuting Game Modus\n");
            }

            break;

        }

        case PLAYING: {

            Rectangle board = {50, 100, 700, 600};

            int points = 0;
            int level = 1;
            int fontsize = 20;

            const char *pointsText = TextFormat("Points: %d", points);
            int pointsWidth = MeasureText(pointsText, fontsize);

            const char *levelText = TextFormat("Level %d", level);
            int levelWidth = MeasureText(levelText, fontsize);

            DrawRectangleRec(board, GRAY);

            DrawText(pointsText, board.x + board.width - pointsWidth - 10,
                board.y + 10,
                fontsize,
                GREEN
            );
            
            DrawText(
                levelText,
                board.x + (board.width - levelWidth) / 2,
                board.y + 10,
                fontsize,
                GREEN
            );

            DrawText("Game is Running", 250, 300, 30, GREEN);
            break;
        }

    }
}

void play_window(const int width,const int height, PlayState *state, playing_field *playField) {         
    form forms[7];
    load_forms(forms);

    board_logic(state, playField);
}