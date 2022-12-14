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
    #define X_SPEED 10.0f
    #define Y_SPEED 10.0f

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
            void addBomb();
            void addSpeed();
            void addPower();
            void addGhosting();
            void kill();
            bool isAlive();
            Vector3 getPosition();
            ~Character();
            int bombs = 1;
            float bombcd = 0.0f;
        private:
            Game *game;
            void IA_move();
            Vector3 _position = {0};
            Vector3 _rotation = {0};
            Model _model;
            int power = 1;
            bool alive = true;
            bool isIA = false;
            int player_id = 0;
            float speed = 0.03f;
            bool ghosting = false;
    };

}

#endif /* !Character_HPP_ */
