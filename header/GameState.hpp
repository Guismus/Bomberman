/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** GameState
*/

#ifndef GAMESTATE_HPP_
    #define GAMESTATE_HPP_

    #include "RayLib.hpp"
    #include "Window.hpp"
    #include "Song.hpp"
    #include "Game.hpp"
    #include "Menu.hpp"
    #include "EndGame.hpp"

namespace IndieStudio {

class GameState {
    public:
        GameState();
        void menu();
        int game(std::string map, std::string colmap);
        int endGame(int id, int time);
        ~GameState();

    private:
        Window *_window = nullptr;
};

}

#endif /* !GAMESTATE_HPP_ */
