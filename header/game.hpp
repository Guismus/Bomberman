/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "main.hpp"

class game
{
private:
    /* data */
    std::vector<player*> players;
    std::vector<ennemy*> ennemies;
    std::vector<destructible*> destructibles;
    std::vector<bombs*> bombs;

    GameState currentStatus;

public:
    game(/* args */);
    ~game();
    void start();
};

#endif /* !GAME_HPP_ */
