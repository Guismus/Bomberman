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

    void Character::init_rotate(Direction dir)
    {
        this->_rotation.y = fmod(this->_rotation.y,  360);
        //std::cout << "y == " << this->_rotation.y << std::endl;
        if (this->_rotation.y < 0)
            (this->_rotation.y += 360);
        switch (dir)
        {
        case DOWN:
            if(this->_rotation.y < 180) {
                this->_rotation.y +=X_SPEED;
            }
            else if (this->_rotation.y > 180)
                this->_rotation.y -=X_SPEED;
            break;
        case UP:
            if(this->_rotation.y >= 180 && this->_rotation.y != 0) {
                this->_rotation.y +=X_SPEED;
            }
            else if (this->_rotation.y <= 180 && this->_rotation.y != 0)
                this->_rotation.y -=X_SPEED;
            break;
        case LEFT:
            if((this->_rotation.y > 270 || this->_rotation.y <= 90) && this->_rotation.y != 270) {
                this->_rotation.y -=X_SPEED;
            }
            else if (this->_rotation.y < 270 && this->_rotation.y > 90 && this->_rotation.y != 270)
                this->_rotation.y +=X_SPEED;
            break;
        case RIGHT:
            if((this->_rotation.y >= 270 || this->_rotation.y < 90) && this->_rotation.y != 90) {
                this->_rotation.y +=X_SPEED;
            }
            else if (this->_rotation.y < 270 && this->_rotation.y > 90 && this->_rotation.y != 90)
                this->_rotation.y -=X_SPEED;
            break;
        }
    }

    bool Character::checkCollideUp()
    {
        for (Wall *w : this->game->getWalls()) {
            if (w->getPosition().x == round(_position.x - 0.3f) && w->getPosition().z == round(_position.z)) {
                if(w->getType() == UNBREAKABLE || (!this->ghosting))
                return false;
            }
        }
        for (Bomb *w : this->game->getBombs()) {
            if (w->getPosition().x == round(_position.x - 0.3f) && w->getPosition().z == round(_position.z)) {
                if (!(w->getPosition().x == round(_position.x) && w->getPosition().z == round(_position.z)))
                    return this->ghosting;
            }
        }
        return true;
    }

    void Character::move_up()
    {
        if (this->_position.x >= 1.0f && (this->checkCollideUp()))
            this->_position.x -= this->speed;
    }

    bool Character::checkCollideDown()
    {
        for (Wall *w : this->game->getWalls()) {
            if (w->getPosition().x == round(_position.x + 0.3f) && w->getPosition().z == round(_position.z)) {
                if(w->getType() == UNBREAKABLE || (!this->ghosting))
                return false;
            }
        }
        for (Bomb *w : this->game->getBombs()) {
            if (w->getPosition().x == round(_position.x + 0.3f) && w->getPosition().z == round(_position.z)) {
                if (!(w->getPosition().x == round(_position.x) && w->getPosition().z == round(_position.z)))
                    return this->ghosting;
            }
        }
        return true;
    }

    void Character::move_down()
    {
        if (this->_position.x <= 14.0f && (this->checkCollideDown()))
            this->_position.x += this->speed;
    }

    bool Character::checkCollideLeft()
    {
        for (Wall *w : this->game->getWalls()) {
            if (w->getPosition().x == round(_position.x) && w->getPosition().z == round(_position.z + 0.3f)) {
                if(w->getType() == UNBREAKABLE || (!this->ghosting))
                return false;
            }
        }
        for (Bomb *w : this->game->getBombs()) {
            if (w->getPosition().x == round(_position.x) && w->getPosition().z == round(_position.z + 0.3f)) {
                if (!(w->getPosition().x == round(_position.x) && w->getPosition().z == round(_position.z)))
                    return this->ghosting;
            }
        }
        return true;
    }

    void Character::move_left()
    {
        if (this->_position.z <= 22 && (this->checkCollideLeft()))
            this->_position.z += this->speed;
    }

    bool Character::checkCollideRight()
    {
        for (Wall *w : this->game->getWalls()) {
            if (w->getPosition().x == round(_position.x) && w->getPosition().z == round(_position.z - 0.3f)) {
                if(w->getType() == UNBREAKABLE || (!this->ghosting))
                return false;
            }
        }
        for (Bomb *w : this->game->getBombs()) {
            if (w->getPosition().x == round(_position.x) && w->getPosition().z == round(_position.z - 0.3f)) {
                if (!(w->getPosition().x == round(_position.x) && w->getPosition().z == round(_position.z)))
                    return this->ghosting;
            }
        }
        return true;
    }

    void Character::move_right()
    {
        if (this->_position.z >= -7 && (this->checkCollideRight()))
            this->_position.z -= this->speed;
    }

    Vector3 Character::getPosition()
    {
        return (this->_position);
    }

    void Character::draw(Game *game)
    {
        //rotate
        if (!this->alive)
            return;
        switch (this->player_id) {
            case 1:
                game->drawModel(this->_model, this->_position, 0.5f, RED);
            break;
            case 2:
                game->drawModel(this->_model, this->_position, 0.5f, BLUE);
            break;
            case 3:
                game->drawModel(this->_model, this->_position, 0.5f, PINK);
            break;
            case 4:
                game->drawModel(this->_model, this->_position, 0.5f, GREEN);
            break;
        }
        //unrotate
    }

    void Character::event()
    {
        if(isIA)
            return (this->IA_move());
        if(this->player_id == 1 && this->alive) {
            if (this->game->isKeyPressed(KEY_W)) {
                this->init_rotate(UP);
                this->move_up();
            }
            if (this->game->isKeyPressed(KEY_A)) {
                this->init_rotate(LEFT);
                this->move_left();
            }
            if (this->game->isKeyPressed(KEY_S)) {
                this->init_rotate(DOWN);
                this->move_down();
            }
            if (this->game->isKeyPressed(KEY_D)) {
                this->init_rotate(RIGHT);
                this->move_right();
            }
            if (this->game->isKeyPressed(KEY_E)) {
                this->game->dropBomb(this->_position, this->power, this);
            }
        }
        if(this->player_id == 2 && this->alive){
            if (this->game->isKeyPressed(KEY_UP)) {
                this->init_rotate(UP);
                this->move_up();
            }
            if (this->game->isKeyPressed(KEY_LEFT)) {
                this->init_rotate(LEFT);
                this->move_left();
            }
            if (this->game->isKeyPressed(KEY_DOWN)) {
                this->init_rotate(DOWN);
                this->move_down();
            }
            if (this->game->isKeyPressed(KEY_RIGHT)) {
                this->init_rotate(RIGHT);
                this->move_right();
            }
            if (this->game->isKeyPressed(KEY_ENTER))
                this->game->dropBomb(this->_position, this->power, this);
        }
        this->_model.transform = MatrixRotateXYZ({DEG2RAD*this->_rotation.x, DEG2RAD*this->_rotation.y, DEG2RAD*this->_rotation.z});
        this->bombcd -= game->TimeElapsed();
    }

    bool Character::isAlive()
    {
        return (this->alive);
    }

    void Character::IA_move()
    {
        //todo
    }

    void Character::kill()
    {
        this->alive = false;
    }

    Character::~Character()
    {
        UnloadModel(this->_model);
    }
    void Character::addBomb()
    {
        this->bombs++;
    }
    void Character::addSpeed()
    {
        this->speed += 0.008f;
    }
    void Character::addPower()
    {
        this->power++;
    }
    void Character::addGhosting()
    {
        this->ghosting = true;
    }
}

