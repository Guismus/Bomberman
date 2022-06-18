/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Menu
*/

#include "Menu.hpp"

namespace IndieStudio {

Menu::Menu() {
    this->_map = new Map("../resources/map1.png", "../resources/map1.png");
    this->_map2 = new Map("../resources/map2.png", "../resources/map2.png");
    this->_map3 = new Map("../resources/map3.png", "../resources/map3.png");
    this->_nb = 1;
    this->_multi = false;
}

void Menu::event()
{
    if (IsKeyPressed(KEY_SPACE))
        this->_multi = !this->_multi;
    if (IsKeyPressed(KEY_A))
        this->_nb--;
    if (IsKeyPressed(KEY_D))
        this->_nb++;
    if (this->_nb <= 0)
        this->_nb = 3;
    if (this->_nb >= 4)
        this->_nb = 1;
}

bool Menu::isMulti()
{
    return (this->_multi);
}

void Menu::drawMap()
{
    switch (this->_nb)
    {
        case 1:
            DrawTextureEx(this->_map->getTexture(), {1100, 100}, 90.0f, 30.0f, WHITE);
            break;
        case 2:
            DrawTextureEx(this->_map2->getTexture(), {1100, 100}, 90.0f, 30.0f, WHITE);
            break;
        case 3:
            DrawTextureEx(this->_map3->getTexture(), {1100, 100}, 90.0f, 30.0f, WHITE);
            break;
    }
}

Menu::~Menu() {
    if (this->_map)
        delete (this->_map);
    if (this->_map2)
        delete (this->_map2);
    if (this->_map3)
        delete (this->_map3);
}

}