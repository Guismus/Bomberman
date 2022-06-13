/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** main
*/

#include "raylib.h"
#include "main.hpp"

int main(void)
{
    IndieStudio::IRayLib *game = new IndieStudio::Game;
    while (!game->isWindowClosed()) {
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
    }
    delete game;
}