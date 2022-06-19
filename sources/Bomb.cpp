/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** bomb
*/

#include "Game.hpp"
#include <cmath>

namespace IndieStudio {

    Bomb::Bomb(int power, Vector3 position, float timer, Character *owner)
    {
        this->power = power;
        this->owner = owner;
        this->position.x = round(position.x);
        this->position.z = round(position.z);
        this->position.y = 0.0f;
        this->timer = timer;
        this->_model = LoadModel("../resources/parts_bomberman/bomberman-8-body.obj");
    }

    Vector3 Bomb::getPosition()
    {
        return (this->position);
    }

    Model Bomb::getModel()
    {
        return this->_model;
    }

    int Bomb::getPower()
    {
        return this->power;
    }

    Bomb::~Bomb()
    {
        UnloadModel(this->_model);
    }

}