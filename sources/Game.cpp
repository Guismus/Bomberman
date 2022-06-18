/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** game
*/

#include "Game.hpp"
#include "stdio.h"
#include <algorithm>

// this->_entity->_slots[static_cast<int>(this->_player->getPosition().x) - 1][-static_cast<int>(this->_player->getPosition().z) + 22]

namespace IndieStudio {

Game::Game()
{
    this->_cam = new EDCamera;
    this->_map = new Map("../resources/map1.png", "../resources/cubicmap_atlas.png");
    this->_player = new Character(1, false, this);
    this->_player2 = new Character(2, false, this);
    this->_player3 = new Character(3, false, this);
    this->_player4 = new Character(4, false, this);
    this->_entity = new Entity;
}

Camera3D Game::getCamera()
{
    return (this->_cam->getCamera());
}

Model Game::getModelFromMap()
{
    return (this->_map->getModel());
}

void Game::drawPlayers()
{
    this->_player->draw();
    this->_player2->draw();
    this->_player3->draw();
    this->_player4->draw();
    this->drawBombs();
}

void Game::drawBombs()
{
    for(auto it = std::begin(this->bombs); it != std::end(this->bombs); ++it) {
        DrawModel((*it)->getModel(), (*it)->getPosition(), 0.5f, BLACK);
    }
}

void Game::event()
{
    this->_player->event();
    this->_player2->event();
    this->_player3->event();
    this->_player4->event();
}

Game::~Game()
{
    if (this->_cam)
        delete this->_cam;
    if (this->_map)
        delete this->_map;
    if (this->_player)
        delete this->_player;
    if (this->_player2)
        delete this->_player2;
    if (this->_player3)
        delete this->_player3;
    if (this->_player4)
        delete this->_player4;
    if (this->_entity)
        delete this->_entity;
}

void Game::ageBombs()
{
    float elapsed = this->TimeElapsed();
    for(auto it = std::begin(this->bombs); it != std::end(this->bombs); ++it) {
        (*it)->timer -= elapsed;
        if((*it)->timer < 0)
            this->explode((*it)->getPosition(), (*it)->getPower());
    }
    this->bombs.erase(std::remove_if( this->bombs.begin(), this->bombs.end(),
                [](Bomb *obj) { return obj->timer < 0; }), this->bombs.end());

}

void Game::dropBomb(Vector3 position, int power)
{
    Bomb *obj = new Bomb(power, position, 5);
    this->bombs.push_back(obj);
}

void Game::explode(Vector3 position, int power)
{
    //todo
}

}