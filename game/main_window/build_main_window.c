#include <stdio.h>
#include "raylib.h"
#include <stdbool.h>

#include "build_main_window.h"
#include "Menu/menu_buttons.h"

#include "../game/main_game/Screen_Modi/Game_Mode/game_modus.h"
#include "../game/main_game/Screen_Modi/Highscoores/highscore_window.h"
#include "../game/main_game/Screen_Modi/Play/play_window.h"

void configure_window(const int width, const int height,const char *window_name) {

    bool is_running = true;

    typedef enum {
        SCREEN_MENU,
        SCREEN_GAME,
        SCREEN_GAME_MODE,
        SCREEN_SCORES
    } GameScreen;

    GameScreen current_screen = SCREEN_MENU;
    PlayState current_state = LOADING_GAME_SCREEN;

    playing_field playingField = {
        .width = FIELD_WIDTH,
        .height = FIELD_HEIGHT,
        .cells = {0}
    };

    InitWindow(width, height, window_name);

    SetTargetFPS(144);

    while (is_running && !WindowShouldClose()) {

        Vector2 mouse_position = GetMousePosition();

        BeginDrawing();
            ClearBackground(BLACK);

            switch (current_screen) {
                case SCREEN_MENU: {
                    DrawText("Welcome to Tetris made by Agramm", 200, 185, 25, WHITE);

                    menu_buttons buttons = define_menu_buttons(width, height);

                    bool mouseOverPlay = CheckCollisionPointRec(mouse_position, buttons.playButton);
                    bool mouseOverGameMode = CheckCollisionPointRec(mouse_position, buttons.gameMode);
                    bool mouseOverScores = CheckCollisionPointRec(mouse_position, buttons.scoreBoard);

                    if (mouseOverPlay && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        printf("The Mouse is over Play and Mouse was Pressed Switching to the Game\n");
                        current_screen  = SCREEN_GAME;
                        current_state = LOADING_GAME_SCREEN;

                    } else if (mouseOverGameMode && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        printf("The Mouse is over the Game Mode and Mouse was Pressed\n");
                        current_screen = SCREEN_GAME_MODE;

                    } else if (mouseOverScores && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                        printf("The Mouse is over the Scores and Mouse was Pressed\n");
                        current_screen = SCREEN_SCORES;
                    }

                    break;
                }

                case SCREEN_GAME: {

                    int fps = GetFPS();

                    DrawText(TextFormat("FPS: %d", fps), width - 100, 25, 20, GREEN);

                    play_window(width, height, &current_state, &playingField);
                    break;
                }

                case SCREEN_GAME_MODE: {
                    game_mode_window();
                    break;
                }

                case SCREEN_SCORES: {
                    highscore_window();
                    break;
                }
            }

            //Global UI Configuration

            Rectangle exitButton = {0,0,200,50};

            DrawRectangleRec(exitButton, GRAY);
            DrawText("Exit Programm", 10, 10, 20, BLACK);
            
            Rectangle menuButton = {300, 0, 200, 50};
            DrawRectangleRec(menuButton, GRAY);
            DrawText("Menu", 375, 15, 20, BLACK);

            DrawText("Game Version 0.1.0 Prod.", 330, 785, 10, GREEN);

            bool mouseOverExit = CheckCollisionPointRec(mouse_position, exitButton);
            bool mouseOverMenu = CheckCollisionPointRec(mouse_position, menuButton);

            if (mouseOverExit && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ESCAPE)) {
                printf("\nQuitting the Programm Good bye!!\n");
                is_running = false;
            } else if (mouseOverMenu && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                printf("\nReturning to the Menu\n");

                current_screen = SCREEN_MENU;
            }

        EndDrawing();
    }

    CloseWindow();
}