#ifndef PLAY_WINDOW_H
#define PLAY_WINDOW_H

#define FIELD_HEIGHT 20
#define FIELD_WIDTH 10
typedef enum {
    LOADING_GAME_SCREEN,
    START_GAME,
    PLAYING,
    PAUSE,
    END
} PlayState;
typedef struct playing_field {
    int width;
    int height;
    int cells[FIELD_HEIGHT][FIELD_WIDTH];
} playing_field;

void drawStartScreen(Rectangle board, Rectangle start);
void board_logic(PlayState *state);
void play_window(const int width,const int height, PlayState *state, playing_field *playingField);

#endif