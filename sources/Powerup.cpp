/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Entity
*/

#include "Powerup.hpp"
#include <stdlib.h>

namespace IndieStudio {

    Powerup::Powerup(Vector3 position)
    {
        int type = std::rand() % 4;
        this->position = position;
        switch (type)
        {
            case 0:
                this->type = SPEED;
                this->color = LIME;
                break;
            case 1:
                this->type = STRENGTH;
                this->color = ORANGE;
                break;
            case 2:
                this->type = BOMBS;
                this->color = {0,0,0,120};
                break;
            case 3:
                this->type = GHOST;
                this->color = WHITE;
        }
    }

    Vector3 Powerup::getPosition()
    {
        return this->position;
    }

    BonusType Powerup::getType()
    {
        return this->type;
    }

    Powerup::~Powerup() {}

}