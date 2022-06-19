/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Personnage
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

    #include "raylib.h"
    #include "raymath.h"
    #define X_SPEED 1.5
    #define Y_SPEED 1.2

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

namespace IndieStudio {

    class Game;

}
namespace IndieStudio {

    class Character {
        public:
            Character(int nb, bool isIA, Game *game, Vector3 position);
            void event();
            void move_up();
            void move_down();
            void move_left();
            void move_right();
            bool checkCollideUp();
            bool checkCollideLeft();
            bool checkCollideDown();
            bool checkCollideRight();
            void init_rotate(Direction);
            void draw(Game *game);
            Vector3 getPosition();
            ~Character();
        private:
            Game *game;
            void IA_move();
            Vector3 _position = {0};
            Vector3 _rotation = {0};
            Model _model;
            int max_bomb = 1;
            int bomb = 1;
            int power = 1;
            bool alive = true;
            bool isIA = false;
            int player_id = 0;
    };

}

#endif /* !Character_HPP_ */
