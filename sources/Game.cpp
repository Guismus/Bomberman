/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** game
*/

#include "Game.hpp"
#include "stdio.h"

// this->_entity->_slots[static_cast<int>(this->_player->getPosition().x) - 1][-static_cast<int>(this->_player->getPosition().z) + 22]

namespace IndieStudio {

Game::Game()
{
    this->_cam = new EDCamera;
    this->_map = new Map;
    this->_player = new Character(1);
    this->_player2 = new Character(2);
    this->_player3 = new Character(3);
    this->_player4 = new Character(4);
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
    this->drawSphere(this->_player->getPosition(), 0.5f, GREEN);
    this->drawSphere(this->_player2->getPosition(), 0.5f, BLUE);
    this->drawSphere(this->_player3->getPosition(), 0.5f, PURPLE);
    this->drawSphere(this->_player4->getPosition(), 0.5f, YELLOW);
}

void Game::event()
{
    // Joueur 1
    if (this->isKeyPressed(KEY_W))
        this->_player->move_up();
    if (this->isKeyPressed(KEY_A))
        this->_player->move_left();
    if (this->isKeyPressed(KEY_S))
        this->_player->move_down();
    if (this->isKeyPressed(KEY_D))
        this->_player->move_right();
    // Joueur 2
    if (this->isKeyPressed(KEY_UP))
        this->_player2->move_up();
    if (this->isKeyPressed(KEY_LEFT))
        this->_player2->move_left();
    if (this->isKeyPressed(KEY_DOWN))
        this->_player2->move_down();
    if (this->isKeyPressed(KEY_RIGHT))
        this->_player2->move_right();
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

}