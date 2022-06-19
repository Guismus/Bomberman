/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Entity
*/

#ifndef POWERUP_HPP_
    #define POWERUP_HPP_

    #include <array>

typedef enum {
    SPEED,
    STRENGTH,
    BOMBS,
    GHOST
} BonusType;

namespace IndieStudio {

    class Powerup {
        public:
            Powerup();
            ~Powerup();
        private:
    };

}

#endif /* !POWERUP_HPP_ */
