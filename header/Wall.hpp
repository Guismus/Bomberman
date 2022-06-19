/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** WALLS
*/

#ifndef WALLS_HPP_
#define WALLS_HPP_

#include "raylib.h"

typedef enum {
    BREAKABLE,
    UNBREAKABLE
} Walltype;

namespace IndieStudio {

    class Wall {
        public:
            Wall(Vector3 position, Walltype type);
            Vector3 getPosition();
            Walltype getType();
            ~Wall();
        private:
            Vector3 _position;
            Walltype _type = UNBREAKABLE;
    };
}

#endif /* !WALLS_HPP_ */
