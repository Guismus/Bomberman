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
    #include "Powerup.hpp"
    #include "Bomb.hpp"
    #include <vector>
    #include "Wall.hpp"

#define RANDPERCENT(x) (((std::rand() % 100) <= x))

namespace IndieStudio {

    class Game : public RayLib {
        public:
            Game(std::string map, std::string colmap);
            Camera3D getCamera();
            Model getModelFromMap();
            std::vector<Wall*> getWalls();
            std::vector<Bomb*> getBombs();
            void ReadColMap();
            void drawThings();
            void drawWalls();
            void drawPowerups();
            void event();
            void dropBomb(Vector3 position, int power, Character *owner);
            void ageBombs();
            void drawBombs();
            void explode(Vector3 position, int power);
            void check_player(Vector3 position);
            bool check_wall(Vector3 position);
            bool check_box(Vector3 position);
            void powerupTick();
            void dropPowerup(Vector3 position);
            void checkPowerups();
            void givePower(Character *player, BonusType power);
            ~Game();
        private:
            void MakeWalls(std::string colMap);
            void newWall(Vector3 position, Walltype type);
            void newCharacter(char id, Vector3 position);
            std::string _colmap;
            EDCamera *_cam = nullptr;
            Map *_map = nullptr;
            Character *_player = nullptr;
            Character *_player2 = nullptr;
            Character *_player3 = nullptr;
            Character *_player4 = nullptr;
            std::vector<Bomb*> bombs;
            std::vector<Wall*> walls;
            std::vector<Powerup *> powerups;
            float powerupt_timer = 15;
    };
}

#endif /* !GAME_HPP_ */
