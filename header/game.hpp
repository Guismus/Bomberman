/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

    #include "raylib.hpp"

namespace IndieStudio {

    class Game {
        private:
            Raylib *ray;

        public:
            Game(/* args */);
            bool isWindowClosed();
            ~Game();
    };
}

namespace IndieStudio {

Game::Game()
{
    this->ray = new Raylib(1280, 720);
}

bool Game::isWindowClosed()
{
    return (this->ray->isWindowClosed());
}

Game::~Game()
{
    if (this->ray != nullptr)
        delete this->ray;
}
}

#endif /* !GAME_HPP_ */
