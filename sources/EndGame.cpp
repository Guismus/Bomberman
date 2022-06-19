/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** EndGame
*/

#include "EndGame.hpp"

namespace IndieStudio {

EndGame::EndGame() {}

void EndGame::drawTime(int time)
{
    std::string str = "Time: ";
    if (std::to_string(time / 60).length() == 1)
            str.append("0");
        str.append(std::to_string(time / 60)).append(":");
        if (std::to_string(time % 60).length() == 1)
            str.append("0");
        str.append(std::to_string(time % 60));
        this->drawText(str, 530, 350, 40, BLACK);
}

EndGame::~EndGame() {}

}