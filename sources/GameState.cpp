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
    int state = 0;
    while (!menu->isWindowClosed())
    {
        if (menu->isKeyPressed(KEY_ENTER)) {
            if (this->game(menu->getMap(), menu->getColMap()))
                return;
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

int GameState::game(std::string map, std::string colmap)
{
    IndieStudio::Game *game = new IndieStudio::Game(map, colmap);
    int time = 0;
    int victory = 0;
    game->ReadColMap();
    Song *music = new Song("../resources/music.xm");
    music->play();
    while (!game->isWindowClosed()) {
        victory = game->isWin();
        if (victory != 0)
            break;
        time++;
        if (time % 70 == 0)
            game->addTime();
        music->update();
        game->event();
        game->beginDrawing();
        game->drawHUD();
        game->beginDrawing3D(game->getCamera());
        game->drawModel(game->getModelFromMap(), { 0.0f, 0.0f, -8.0f }, 1.0f, WHITE);
        game->powerupTick();
        game->drawThings();
        game->ageBombs();
        game->checkPowerups();
        game->endDrawing3D();
        game->drawFPS();
        game->endDrawing();
    }
    time = game->getTime();
    delete game;
    if (victory != 0)
        return (this->endGame(victory, time));
    return (0);
}

int GameState::endGame(int id, int time)
{
    IndieStudio::EndGame *end = new IndieStudio::EndGame;
    while (!end->isWindowClosed()) {
        if (end->isKeyPressed(KEY_ENTER))
            return (0);
        end->beginDrawing();
        switch (id) {
            case -1:
                end->drawText("DRAW!", 500, 720 / 2 - 150, 100, BLACK);
                break;
            case 1:
                end->drawText("Well played player 1!!!", 375, 720 / 2 - 100, 50, BLACK);
                break;
            case 2:
                end->drawText("Well played player 2!!!", 375, 720 / 2 - 100, 50, BLACK);
                break;
            case 3:
                end->drawText("Well played player 3!!!", 375, 720 / 2 - 100, 50, BLACK);
                break;
            case 4:
                end->drawText("Well played player 4!!!", 375, 720 / 2 - 100, 50, BLACK);
                break;
        }
        end->drawTime(time);
        end->drawText("Press ENTER to return in the menu", 450, 720 / 2 + 200, 20, LIGHTGRAY);
        end->drawText("Press ESCAPE to exit the game", 475, 720 / 2 + 230, 20, LIGHTGRAY);
        end->endDrawing();
    }
    delete (end);
    return (1);
}

GameState::~GameState() {
    if (this->_window)
        delete (this->_window);
    CloseAudioDevice();
}

}