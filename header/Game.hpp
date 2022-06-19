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
    #include "Bomb.hpp"
    #include <vector>
    #include "Wall.hpp"

#define RANDPERCENT(x) (((std::rand() % 100) <= x))

namespace IndieStudio {

    class Game : public RayLib {
        public:
            Game();
            Camera3D getCamera();
            Model getModelFromMap();
            void ReadColMap();
            void drawThings();
            void drawWalls();
            void event();
            void dropBomb(Vector3 position, int power);
            void ageBombs();
            void drawBombs();
            void explode(Vector3 position, int power);
            ~Game();
        private:
            void MakeWalls(std::string colMap);
            void newWall(Vector3 position, Walltype type);
            void newCharacter(char id, Vector3 position);
            EDCamera *_cam = nullptr;
            Map *_map = nullptr;
            Character *_player = nullptr;
            Character *_player2 = nullptr;
            Character *_player3 = nullptr;
            Character *_player4 = nullptr;
            Entity *_entity = nullptr;
            std::vector<Bomb*> bombs;
            std::vector<Wall*> walls;
    };
}

#endif /* !GAME_HPP_ */
