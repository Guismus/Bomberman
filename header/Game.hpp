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

namespace IndieStudio {

    class Game : public RayLib {
        public:
            Game();
            Camera3D getCamera();
            ~Game();
        private:
            EDCamera *_cam = nullptr;
    };
}

#endif /* !GAME_HPP_ */
