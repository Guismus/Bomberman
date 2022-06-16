/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Character
*/

#include "Character.hpp"

namespace IndieStudio {

    Character::Character(int nb)
    {
        if (nb == 1)
            this->_position = {1.0f, 0.5f, 22.0f};
        if (nb == 2)
            this->_position = {1.0f, 0.5f, -7.0f};
        if (nb == 3)
            this->_position = {14.0f, 0.5f, -7.0f};
        if (nb == 4)
            this->_position = {14.0f, 0.5f, 22.0f};
    }

    void Character::move()
    {
        this->_position = misc::addVector3(this->_position, this->_speed);
    }

    void Character::set_speed(Direction direction)
    {
        switch (direction) {
        case UP:
            this->_speed = {0.1f,0.0f,0.0f};
            break;
        case LEFT:
            this->_speed = {0.0f,0.0f,-0.1f};
            break;
        case DOWN:
            this->_speed = {-0.1f,0.0f,0.0f};
            break;
        case RIGHT:
            this->_speed = {0.0f,0.0f,0.1f};
        }
    }

    Vector3 Character::getPosition()
    {
        return (this->_position);
    }

    Character::~Character() {}

}

