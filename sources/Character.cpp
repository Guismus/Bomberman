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

    void Character::move_up()
    {
        if (this->_position.x >= 1.0f)
            this->_position.x -= 0.03f;
    }

    void Character::move_down()
    {
        if (this->_position.x <= 14.0f)
            this->_position.x += 0.03f;        
    }

    void Character::move_left()
    {
        if (this->_position.z <= 22)
            this->_position.z += 0.03f;
    }

    void Character::move_right()
    {
        if (this->_position.z >= -7)
            this->_position.z -= 0.03f;
    }

    Vector3 Character::getPosition()
    {
        return (this->_position);
    }

    Character::~Character() {}

}

