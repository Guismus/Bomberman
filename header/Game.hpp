/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

    #include "RayLib.hpp"
    #include "EDCamera.hpp"
    #include "Map.hpp"

namespace IndieStudio {

    class Game : public RayLib {
        public:
            Game();
            Camera3D getCamera();
            Model getModelFromMap();
            ~Game();
        private:
            EDCamera *_cam = nullptr;
            Map *_map = nullptr;
    };
}

#endif /* !GAME_HPP_ */
