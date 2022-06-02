/*
** EPITECH PROJECT, 2021
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** main.hpp
*/


#ifndef __main_H__
#define __main_H__

    #include <iostream>
    #include <string>
    #include <vector>
    #include "raylib.h"

    #define Height 1080
    #define Width 19200

void print_hello();

typedef enum {
    MAIN_MENU,
    CHARACTERS,
    OPTIONS_SOUND,
    OPTIONS_VIDEO,
    CREDITS,
    GAMEPLAY,
    PAUSE
} GameState;

#endif