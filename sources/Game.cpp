/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** game
*/

#include "Game.hpp"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <algorithm>

// this->_entity->_slots[static_cast<int>(this->_player->getPosition().x) - 1][-static_cast<int>(this->_player->getPosition().z) + 22]

namespace IndieStudio {

Game::Game(std::string map, std::string colmap)
{
    this->_cam = new EDCamera;
    this->_map = new Map(map, "../resources/cubicmap_atlas.png");
    this->_colmap = colmap;
}

Camera3D Game::getCamera()
{
    return (this->_cam->getCamera());
}

Model Game::getModelFromMap()
{
    return (this->_map->getModel());
}

void Game::drawThings()
{
    this->_player->draw(this);
    this->_player2->draw(this);
    this->_player3->draw(this);
    this->_player4->draw(this);
    this->drawBombs();
    this->drawWalls();
}


void Game::drawBombs()
{
    for(auto it = std::begin(this->bombs); it != std::end(this->bombs); ++it) {
        DrawModel((*it)->getModel(), (*it)->getPosition(), 0.5f, BLACK);
    }
}

void Game::drawWalls()
{
    for(auto it = std::begin(this->walls); it != std::end(this->walls); ++it) {
        if((*it)->getType() == BREAKABLE)
        this->drawCube((*it)->getPosition(), 1.0f, 1.0f, 1.0f, BROWN);
    }
}

void Game::event()
{
    this->_player->event();
    this->_player2->event();
    this->_player3->event();
    this->_player4->event();
}

Game::~Game()
{
    if (this->_cam)
        delete this->_cam;
    if (this->_map)
        delete this->_map;
    if (this->_player)
        delete this->_player;
    if (this->_player2)
        delete this->_player2;
    if (this->_player3)
        delete this->_player3;
    if (this->_player4)
        delete this->_player4;
}

void Game::ageBombs()
{
    float elapsed = this->TimeElapsed();
    for(auto it = std::begin(this->bombs); it != std::end(this->bombs); ++it) {
        (*it)->timer -= elapsed;
        if((*it)->timer < 0) {
            this->explode((*it)->getPosition(), (*it)->getPower());
            (*it)->owner->bombs += 1;
        }
    }
    this->bombs.erase(std::remove_if( this->bombs.begin(), this->bombs.end(),
                [](Bomb *obj) { return obj->timer < 0; }), this->bombs.end());

}

void Game::dropBomb(Vector3 position, int power, Character *owner)
{
    if(owner->bombs > 0) {
        Bomb *obj = new Bomb(power, position, 3, owner);
        this->bombs.push_back(obj);
        owner->bombs -= 1;
    }
}

void Game::explode(Vector3 position, int power)
{
    for(int i = 0; i < power; i++){
        this->check_player((Vector3){position.x, position.y, position.z + 1});
        if (this->check_box((Vector3){position.x, position.y, position.z + 1}))
            break;
        if (this->check_wall((Vector3){position.x, position.y, position.z + 1}))
            break;
    }
    for(int i = 0; i < power; i++){
        this->check_player((Vector3){position.x, position.y, position.z - 1});
        if (this->check_box((Vector3){position.x, position.y, position.z - 1}))
            break;
        if (this->check_wall((Vector3){position.x, position.y, position.z - 1}))
            break;
    }
    for(int i = 0; i < power; i++){
        this->check_player((Vector3){position.x + 1, position.y, position.z});
        if (this->check_box((Vector3){position.x + 1, position.y, position.z}))
            break;
        if (this->check_wall((Vector3){position.x + 1, position.y, position.z}))
            break;
    }
    for(int i = 0; i < power; i++){
        this->check_player((Vector3){position.x - 1, position.y, position.z});
        if (this->check_box((Vector3){position.x - 1, position.y, position.z}))
            break;
        if (this->check_wall((Vector3){position.x - 1, position.y, position.z}))
            break;
    }
}

void Game::check_player(Vector3 position)
{
    DrawSphere(position, 0.5f, RED);
    if (
        this->_player->getPosition().x >= (position.x - 0.5f) &&
        this->_player->getPosition().x <= (position.x + 0.5f) &&
        this->_player->getPosition().z >= (position.z - 0.5f) &&
        this->_player->getPosition().z <= (position.z + 0.5f)
        )
        this->_player->kill();
    if (
        this->_player2->getPosition().x >= (position.x - 0.5f) &&
        this->_player2->getPosition().x <= (position.x + 0.5f) &&
        this->_player2->getPosition().z >= (position.z - 0.5f) &&
        this->_player2->getPosition().z <= (position.z + 0.5f)
        )
        this->_player2->kill();
    if (
        this->_player3->getPosition().x >= (position.x - 0.5f) &&
        this->_player3->getPosition().x <= (position.x + 0.5f) &&
        this->_player3->getPosition().z >= (position.z - 0.5f) &&
        this->_player3->getPosition().z <= (position.z + 0.5f)
        )
        this->_player3->kill();
    if (
        this->_player4->getPosition().x >= (position.x - 0.5f) &&
        this->_player4->getPosition().x <= (position.x + 0.5f) &&
        this->_player4->getPosition().z >= (position.z - 0.5f) &&
        this->_player4->getPosition().z <= (position.z + 0.5f)
        )
        this->_player4->kill();
}

bool Game::check_box(Vector3 position)
{
    bool r = false;
    for (Wall *w : this->getWalls()) {
            if (w->getPosition().x == position.x && w->getPosition().z == position.z && w->getType() == BREAKABLE) {
                r = true;
            }
        }
    this->walls.erase(std::remove_if( this->walls.begin(), this->walls.end(),
                [&, position](Wall *w) { return w->getPosition().x == position.x
                && w->getPosition().z == position.z && w->getType() == BREAKABLE; }), this->walls.end());
    return r;
}
bool Game::check_wall(Vector3 position)
{
    bool r = false;
    for (Wall *w : this->getWalls()) {
            if (w->getPosition().x == position.x && w->getPosition().z == position.z && w->getType() == UNBREAKABLE) {
                r = true;
            }
        }
    for(auto it = std::begin(this->bombs); it != std::end(this->bombs); ++it) {
        if((*it)->getPosition().x == position.x && (*it)->getPosition().z == position.z)
           (*it)->timer = 0;
    }
    return r;
}

void Game::ReadColMap()
{
    std::string map("");
    std::string buf("");
    std::ifstream myfile(this->_colmap);
    if (myfile.is_open())
    {
      while(std::getline(myfile, buf))
        {
            map.append(buf);
            map.append("\n");
        }
        myfile.close();
        map.append("\0");
    }
    this->MakeWalls(map);
}

    std::vector<Wall*> Game::getWalls()
    {
        return (this->walls);
    }

    std::vector<Bomb*> Game::getBombs()
    {
        return (this->bombs);
    }

    void Game::MakeWalls(std::string map)
    {
        int line = 0;
        int collumn = 24;

        for (int i = 0; i < map.size(); i++, collumn--)
        {
            switch (map[i])
            {
            case 'W':
                this->newWall({(float)line, 0.0f, (float)collumn}, UNBREAKABLE);
                break;
            case '_':
                if(RANDPERCENT(50))
                    this->newWall({(float)line, 0.0f, (float)collumn}, BREAKABLE);
            case '1':
            case '2':
            case '3':
            case '4':
                this->newCharacter(map[i], {(float)line, 0.0f, (float)collumn});
            break;
            case '\n':
                collumn = 24;
                line++;
            break;
            }
        }
    }

    void Game::newWall(Vector3 position, Walltype type)
    {
    Wall *obj = new Wall(position, type);
    this->walls.push_back(obj);
    }

    void Game::newCharacter(char id, Vector3 position)
    {
        switch (id){
        case '1':
            this->_player = new Character(1, false, this, position);
        break;
        case '2':
            this->_player2 = new Character(2, false, this, position);
        break;
        case '3':
            this->_player3 = new Character(3, false, this, position);
        break;
        case '4':
            this->_player4 = new Character(4, false, this, position);
        }
    }
}