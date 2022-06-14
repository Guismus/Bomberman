/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** main
*/

#include "main.hpp"

int main(void)
{
    IndieStudio::Game *game = new IndieStudio::Game;
    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };
    Vector3 cubePosition2 = { 0.0f, 0.0f, -2.0f };
    Vector3 cubePosition3 = { 0.0f, 0.0f, -4.0f };
    while (!game->isWindowClosed()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(game->getCamera());
        DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, BLUE);
        DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        DrawCube(cubePosition2, 2.0f, 2.0f, 2.0f, WHITE);
        DrawCubeWires(cubePosition2, 2.0f, 2.0f, 2.0f, RED);
        DrawCube(cubePosition3, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires(cubePosition3, 2.0f, 2.0f, 2.0f, RED);
        EndMode3D();
        game->drawFPS();
        EndDrawing();
    }
    delete game;
}