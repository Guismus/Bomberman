/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Wall
*/

#include "Wall.hpp"

namespace IndieStudio {

Wall::Wall(Vector3 position, Walltype type)
{
    this->_position = position;
    this->_type = type;
}

Wall::~Wall()
{
}

}