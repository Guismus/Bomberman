/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** main
*/

#include "main.hpp"

int main(void)
{
    IndieStudio::GameState *tkt = new IndieStudio::GameState;
    tkt->menu();
    delete(tkt);
}

/*
enum GameState {
    MENU,
    GAME,
    END
}

while !GameState::END {

    if GameState::MENU {
        Menu::renderMenu();
    }

    if GameState::GAME {
        Menu::renderGame();
        Menu::checkInteractions(); // Check keyboard input, and manage entity location movements
    }
}

*/