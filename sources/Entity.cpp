/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Entity
*/

#include "Entity.hpp"

namespace IndieStudio {

    Entity::Entity()
    {
        for (int i = 3; i != 12; i++)
            this->_slots[3][i] = 1;
        for (int i = 4; i != 11; i++)
            this->_slots[i][7] = 1;
        for (int i = 2; i != 13; i++)
            this->_slots[i][14] = 1;
    }

    Entity::~Entity() {}

}