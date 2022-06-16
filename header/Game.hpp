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
    #include "Character.hpp"
    #include "Entity.hpp"

namespace IndieStudio {

    class Game : public RayLib {
        public:
            Game();
            Camera3D getCamera();
            Model getModelFromMap();
            void drawPlayers();
            void event();
            ~Game();
        private:
            EDCamera *_cam = nullptr;
            Map *_map = nullptr;
            Character *_player = nullptr;
            Character *_player2 = nullptr;
            Character *_player3 = nullptr;
            Character *_player4 = nullptr;
            Entity *_entity = nullptr;
    };
}

#endif /* !GAME_HPP_ */
