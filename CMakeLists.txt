cmake_minimum_required(VERSION 3.20)

project(Tetris
    VERSION 1.0.0
    LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

find_package(raylib REQUIRED)

add_executable(tetris
    main.c
    game/sub_main.c
    game/main_window/build_main_window.c
    game/main_window/Menu/menu_buttons.c

    game/main_game/Screen_Modi/Play/play_window.c
    game/main_game/Screen_Modi/Highscoores/highscore_window.c
    game/main_game/Screen_Modi/Game_Mode/game_modus.c

)

target_include_directories(tetris PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/game
    ${CMAKE_CURRENT_SOURCE_DIR}/game/main_window
    ${CMAKE_CURRENT_SOURCE_DIR}/game/main_window/Menu
    ${CMAKE_CURRENT_SOURCE_DIR}/game/main_game/Screen_Modi/Play
    ${CMAKE_CURRENT_SOURCE_DIR}/game/main_game/Screen_Modi/Highscoores
    ${CMAKE_CURRENT_SOURCE_DIR}/game/main_game/Screen_Modi/Game_Mode
)

target_link_libraries(tetris PRIVATE
    raylib
)

target_compile_options(tetris PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)