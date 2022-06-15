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
    while (!game->isWindowClosed()) {
        game->beginDrawing();
        game->beginDrawing3D(game->getCamera());
        game->drawModel(game->getModelFromMap(), { 0.0f, 0.0f, -8.0f }, 1.0f, WHITE);
        game->drawCube({ 1.0f, 0.0f, 22.0f }, 1.0f, 2.0f, 1.0f, RED);
        game->drawCube({ 1.0f, 0.0f, -7.0f }, 1.0f, 2.0f, 1.0f, RED);
        game->drawSphere({ 12.0f, 0.3f, 22.0f }, 0.3f, RED);
        game->drawCube({ 14.0f, 0.0f, -7.0f }, 1.0f, 2.0f, 1.0f, RED);
        game->endDrawing3D();
        game->drawFPS();
        game->endDrawing();
    }
    delete game;
}