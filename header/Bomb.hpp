/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "raylib.h"

namespace IndieStudio {

    class Character;

}

namespace IndieStudio {

    class Bomb
    {
    private:
        int power;
        Vector3 position;
        Model _model;
    public:
        Character *owner = nullptr;
        float timer;
        Vector3 getPosition();
        int getPower();
        Model getModel();
        Bomb(int power, Vector3 position, float timer, Character *owner);
        ~Bomb();
    };

}

#endif /* !BOMB_HPP_ */
