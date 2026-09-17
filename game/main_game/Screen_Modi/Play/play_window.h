#ifndef PLAY_WINDOW_H
#define PLAY_WINDOW_H

typedef enum {
    START,
    PLAYING,
    PAUSE,
    END
} board_play_state;

void drawStartScreen(Rectangle board, Rectangle start);
void board_logic(board_play_state *state);
void play_window(const int, const int);

#endif