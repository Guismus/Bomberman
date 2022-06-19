/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Entity
*/

#ifndef POWERUP_HPP_
    #define POWERUP_HPP_

    #include <array>
    #include "raylib.h"

typedef enum {
    SPEED,
    STRENGTH,
    BOMBS,
    GHOST
} BonusType;

namespace IndieStudio {

    class Powerup {
        public:
            Powerup(Vector3 position);
            ~Powerup();
            Color color;
            Vector3 getPosition();
            BonusType getType();
        private:
            BonusType type;
            Vector3 position;
    };

}

#endif /* !POWERUP_HPP_ */
