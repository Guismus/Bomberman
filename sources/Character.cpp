/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Character
*/

#include "Game.hpp"

namespace IndieStudio {

    Character::Character(int nb, bool isIA, Game *game, Vector3 position)
    {
        this->_position = position;
        this->player_id = nb;
        this->_model = LoadModel("../resources/bomberman/bomberman.obj");
        this->isIA = isIA;
        this->game = game;
    }

    void Character::move_up()
    {
        if (this->_position.x >= 1.0f)
            this->_position.x -= 0.03f;
    }

    void Character::move_down()
    {
        if (this->_position.x <= 14.0f)
            this->_position.x += 0.03f;
    }

    void Character::move_left()
    {
        if (this->_position.z <= 22)
            this->_position.z += 0.03f;
    }

    void Character::move_right()
    {
        if (this->_position.z >= -7)
            this->_position.z -= 0.03f;
    }

    Vector3 Character::getPosition()
    {
        return (this->_position);
    }

    void Character::draw()
    {
        //rotate
        switch (this->player_id) {
            case 1:
                DrawModel(this->_model, this->_position, 0.5f, RED);
            break;
            case 2:
                DrawModel(this->_model, this->_position, 0.5f, BLUE);
            break;
            case 3:
                DrawModel(this->_model, this->_position, 0.5f, PINK);
            break;
            case 4:
                DrawModel(this->_model, this->_position, 0.5f, GREEN);
            break;
        }
        //unrotate
    }

    void Character::event()
    {
        if(isIA)
            return (this->IA_move());
        if(this->player_id == 1) {
            if (this->game->isKeyPressed(KEY_W))
                this->move_up();
            if (this->game->isKeyPressed(KEY_A))
                this->move_left();
            if (this->game->isKeyPressed(KEY_S))
                this->move_down();
            if (this->game->isKeyPressed(KEY_D))
                this->move_right();
            if (this->game->isKeyPressed(KEY_E))
                this->game->dropBomb(this->_position, this->power);
        }
        if(this->player_id == 2){
            if (this->game->isKeyPressed(KEY_UP))
                this->move_up();
            if (this->game->isKeyPressed(KEY_LEFT))
                this->move_left();
            if (this->game->isKeyPressed(KEY_DOWN))
                this->move_down();
            if (this->game->isKeyPressed(KEY_RIGHT))
                this->move_right();
            if (this->game->isKeyPressed(KEY_ENTER))
                this->game->dropBomb(this->_position, this->power);
        }
    }

    void Character::IA_move()
    {
        //todo
    }

    Character::~Character()
    {
        UnloadModel(this->_model);
    }

}
