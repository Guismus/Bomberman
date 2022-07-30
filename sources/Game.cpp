/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** game
*/

#include "Game.hpp"
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
    this->drawPowerups();
}

void Game::drawPowerups()
{
    for(auto it = std::begin(this->powerups); it != std::end(this->powerups); ++it)
        this->drawSphere((*it)->getPosition(), 0.4f, (*it)->color);
}
void Game::addTime()
{
    this->_time++;
}

void Game::drawHUD()
{
    std::string time = "";
    if (_player->isAlive())
        this->drawText("Player 1: Alive", 300, 30, 30, BLACK);
    else
        this->drawText("Player 1: Dead", 300, 30, 30, LIGHTGRAY);

    if (_player2->isAlive())
        this->drawText("Player 2: Alive", 750, 30, 30, BLACK);
    else
        this->drawText("Player 2: Dead", 750, 30, 30, LIGHTGRAY);

    if (_player3->isAlive())
        this->drawText("Player 3: Alive", 300, 70, 30, BLACK);
    else
        this->drawText("Player 3: Dead", 300, 70, 30, LIGHTGRAY);
    
    if (_player4->isAlive())
        this->drawText("Player 4: Alive", 750, 70, 30, BLACK);
    else
        this->drawText("Player 4: Dead", 750, 70, 30, LIGHTGRAY);
    if (std::to_string(this->_time / 60).length() == 1)
        time.append("0");
    time.append(std::to_string(this->_time / 60)).append(":");
    if (std::to_string(this->_time % 60).length() == 1)
        time.append("0");
    time.append(std::to_string(this->_time % 60));
    this->drawText(time, 520, 175, 100, BLACK);
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

int Game::getTime()
{
    return (this->_time);
}

int Game::isWin()
{
    int nb_death = 0;
    if (!this->_player->isAlive())
        nb_death++;
    if (!this->_player2->isAlive())
        nb_death++;
    if (!this->_player3->isAlive())
        nb_death++;
    if (!this->_player4->isAlive())
        nb_death++;
    if (nb_death == 3) {
        if (this->_player->isAlive())
            return (1);
        if (this->_player2->isAlive())
            return (2);
        if (this->_player3->isAlive())
            return (3);
        if (this->_player4->isAlive())
            return (4);
    }
    if (nb_death == 4) {
        return (-1);
    }
    return (0);
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
                [](Bomb *obj) { return obj->timer <= 0; }), this->bombs.end());
}

void Game::dropBomb(Vector3 position, int power, Character *owner)
{
    if(owner->bombs > 0 && owner->bombcd <= 0) {
        Bomb *obj = new Bomb(power, position, 3, owner);
        this->bombs.push_back(obj);
        owner->bombs -= 1;
        owner->bombcd = 1;
    }
}

static Vector3 getPos(float x, float y, float z)
{
    Vector3 vec = {};
    vec.x = x;
    vec.y = y;
    vec.z = z;

    return (vec);
}

void Game::explode(Vector3 position, int power)
{
    int i = 0;
    for(i = 0; i <= power; i++){
        this->check_player(getPos(position.x, position.y, position.z + i));
        if (this->check_box(getPos(position.x, position.y, position.z + i)))
            break;
        if (this->check_wall(getPos(position.x, position.y, position.z + i)))
            break;
    }
    for(i = 0; i <= power; i++){
        this->check_player(getPos(position.x, position.y, position.z - i));
        if (this->check_box(getPos(position.x, position.y, position.z - i)))
            break;
        if (this->check_wall(getPos(position.x, position.y, position.z - i)))
            break;
    }
    for(i = 0; i <= power; i++){
        this->check_player(getPos(position.x + i, position.y, position.z));
        if (this->check_box(getPos(position.x + i, position.y, position.z)))
            break;
        if (this->check_wall(getPos(position.x + i, position.y, position.z)))
            break;
    }
    for(i = 0; i <= power; i++){
        this->check_player(getPos(position.x - i, position.y, position.z));
        if (this->check_box(getPos(position.x - i, position.y, position.z)))
            break;
        if (this->check_wall(getPos(position.x - i, position.y, position.z)))
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
    if (r && RANDPERCENT(50))
        this->dropPowerup(position);
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

    void Game::powerupTick()
    {
        float time = this->TimeElapsed();
        this->powerupt_timer -= time;
        if (this->powerupt_timer <= 0) {
            this->powerupt_timer = 15;
            this->dropPowerup(getPos((float) (std::rand() % 16),
                0, (float) (std::rand() % 29) -7));
        }
    }

    void Game::dropPowerup(Vector3 position)
    {
        Powerup *obj = new Powerup(position);
        this->powerups.push_back(obj);
    }

    void Game::checkPowerups()
    {
        auto it = this->powerups.begin();
        for (; it != std::end(this->powerups); ++it) {
    if (
        this->_player->getPosition().x >= ((*it)->getPosition().x - 0.5f) &&
        this->_player->getPosition().x <= ((*it)->getPosition().x + 0.5f) &&
        this->_player->getPosition().z >= ((*it)->getPosition().z - 0.5f) &&
        this->_player->getPosition().z <= ((*it)->getPosition().z + 0.5f)
        ) {
        this->givePower(this->_player, (*it)->getType());
        this->powerups.erase(it);
        break;
        }
    if (
        this->_player2->getPosition().x >= ((*it)->getPosition().x - 0.5f) &&
        this->_player2->getPosition().x <= ((*it)->getPosition().x + 0.5f) &&
        this->_player2->getPosition().z >= ((*it)->getPosition().z - 0.5f) &&
        this->_player2->getPosition().z <= ((*it)->getPosition().z + 0.5f)
        ) {
        this->givePower(this->_player2, (*it)->getType());
        this->powerups.erase(it);
        break;
        }
    if (
        this->_player3->getPosition().x >= ((*it)->getPosition().x - 0.5f) &&
        this->_player3->getPosition().x <= ((*it)->getPosition().x + 0.5f) &&
        this->_player3->getPosition().z >= ((*it)->getPosition().z - 0.5f) &&
        this->_player3->getPosition().z <= ((*it)->getPosition().z + 0.5f)
        ) {
        this->givePower(this->_player3, (*it)->getType());
        this->powerups.erase(it);
        break;
        }
    if (
        this->_player4->getPosition().x >= ((*it)->getPosition().x - 0.5f) &&
        this->_player4->getPosition().x <= ((*it)->getPosition().x + 0.5f) &&
        this->_player4->getPosition().z >= ((*it)->getPosition().z - 0.5f) &&
        this->_player4->getPosition().z <= ((*it)->getPosition().z + 0.5f)
        ) {
        this->givePower(this->_player4, (*it)->getType());
        this->powerups.erase(it);
        break;
        }
        }
    }

    void Game::givePower(Character *player, BonusType type)
    {
        switch (type) {
            case STRENGTH:
            player->addPower();
            break;
            case SPEED:
            player->addSpeed();
            break;
            case BOMBS:
            player->addBomb();
            break;
            case GHOST:
            player->addGhosting();
            break;
        }
    }
}
