/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Personnage
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

    #include "raylib.h"
    #include "misc.hpp"

namespace IndieStudio {

    class Character {
        public:
            Character(int nb);
            void move();
            void set_speed(Direction direction);
            Vector3 getPosition();
            ~Character();
        private:
            Vector3 _position = {0};
            Vector3 _speed = {0};
    };

}

#endif /* !Character_HPP_ */
