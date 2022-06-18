/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** GameState
*/

#include "GameState.hpp"
#include "Game.hpp"
#include "Menu.hpp"

namespace IndieStudio {

GameState::GameState()
{
    this->_window = new Window(1280, 720);
    InitAudioDevice();
}

void GameState::menu()
{
    IndieStudio::Menu *menu = new IndieStudio::Menu;
    while (!menu->isWindowClosed())
    {
        if (menu->isKeyPressed(KEY_ENTER))
            this->game();
        menu->event();
        menu->beginDrawing();
        if (menu->isMulti())
            DrawText("2 player mode", 500, 30, 40, BLACK);
        else
            DrawText("1 player mode", 500, 30, 40, BLACK);
        menu->drawMap();
        DrawText("Press SPACE to enable / disable 2 players local mode!", 50, 630, 20, LIGHTGRAY);
        DrawText("Press Q / D to change map!", 50, 660, 20, LIGHTGRAY);
        DrawText("Press ENTER to start the game!", 50, 690, 20, LIGHTGRAY);
        menu->endDrawing();
    }
    
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
        game->ageBombs();
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