/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Character
*/

#include "Character.hpp"

namespace IndieStudio {

    Character::Character(int nb, bool isIA)
    {
        if (nb == 1)
            this->_position = {1.0f, 0.0f, 22.0f};
        if (nb == 2)
            this->_position = {1.0f, 0.0f, -7.0f};
        if (nb == 3)
            this->_position = {14.0f, 0.0f, -7.0f};
        if (nb == 4)
            this->_position = {14.0f, 0.0f, 22.0f};
        this->player_id = nb;
        this->_model = LoadModel("../resources/bomberman/bomberman.obj");
        this->isIA = isIA;
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
    }

    void Character::event()
    {
        if(isIA)
            return (this->IA_move());
        if(this->player_id == 1) {
            if (IsKeyDown(KEY_W))
                this->move_up();
            if (IsKeyDown(KEY_A))
                this->move_left();
            if (IsKeyDown(KEY_S))
                this->move_down();
            if (IsKeyDown(KEY_D))
                this->move_right();
        }
        if(this->player_id == 2){
            if (IsKeyDown(KEY_UP))
                this->move_up();
            if (IsKeyDown(KEY_LEFT))
                this->move_left();
            if (IsKeyDown(KEY_DOWN))
                this->move_down();
            if (IsKeyDown(KEY_RIGHT))
                this->move_right();
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

