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
        if (menu->isKeyPressed(KEY_ENTER)) {
            this->game(menu->getMap(), menu->getColMap());
        }
        menu->event();
        menu->beginDrawing();
        if (menu->isMulti())
            menu->drawText("2 player mode", 500, 30, 40, BLACK);
        else
            menu->drawText("1 player mode", 500, 30, 40, BLACK);
        menu->drawMap();
        menu->drawText("Press SPACE to enable / disable 2 players local mode!", 50, 630, 20, LIGHTGRAY);
        menu->drawText("Press Q / D to change map!", 50, 660, 20, LIGHTGRAY);
        menu->drawText("Press ENTER to start the game!", 50, 690, 20, LIGHTGRAY);
        menu->endDrawing();
    }
}

void GameState::game(std::string map, std::string colmap)
{
    IndieStudio::Game *game = new IndieStudio::Game(map, colmap);
    int time = 0;
    game->ReadColMap();
    Song *music = new Song("../resources/music.xm");
    music->play();
    while (!game->isWindowClosed()) {
        time++;
        if (time % 70 == 0)
            game->addTime();
        game->drawHUD();
        music->update();
        game->event();
        game->beginDrawing();
        game->beginDrawing3D(game->getCamera());
        game->drawModel(game->getModelFromMap(), { 0.0f, 0.0f, -8.0f }, 1.0f, WHITE);
        game->drawThings();
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