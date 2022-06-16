/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** GameState
*/

#include "GameState.hpp"
#include "Game.hpp"

namespace IndieStudio {

GameState::GameState()
{
    this->_window = new Window(1280, 720);
    InitAudioDevice();
}

void GameState::menu()
{
    this->game();
}

void GameState::game()
{
    IndieStudio::Game *game = new IndieStudio::Game;
    Song *music = new Song("../resources/country.mp3");
    music->play();
    while (!game->isWindowClosed()) {
        music->update();
        game->event();
        game->beginDrawing();
        game->beginDrawing3D(game->getCamera());
        game->drawModel(game->getModelFromMap(), { 0.0f, 0.0f, -8.0f }, 1.0f, WHITE);
        game->drawPlayers();
        game->drawCube({ 6.0f, 0.0f, -7.0f }, 1.0f, 2.0f, 1.0f, BROWN);
        game->endDrawing3D();
        game->drawFPS();
        game->endDrawing();
    }
    delete game;
}

GameState::~GameState() {
    if (this->_window)
        delete (this->_window);
    CloseAudioDevice();
}

}