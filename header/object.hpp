/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** abstract object class from which inherit game objects
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

//#include "main.hpp"
    #include <iostream>
    #include <string>
    #include <vector>

typedef enum {
    UP,
    LEFT,
    DOWN,
    RIGHT
} Orientation;

class object
{
public:
    std::pair<float, float> position;
    std::pair<float, float> speed;
    int animationCounter;
    Orientation orientation;
};

object::object(/* args */)
{
}

object::~object()
{
}

#endif /* !OBJECT_HPP_ */
