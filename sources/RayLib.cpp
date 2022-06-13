/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** RayLib
*/

#include "RayLib.hpp"

namespace IndieStudio {

    RayLib::RayLib(int x, int y)
    {
        this->_x = x;
        this->_y = y;
        initWindow();
    }

    void RayLib::initWindow()
    {
        InitWindow(this->_x, this->_y, "Bomberman");
        SetTargetFPS(60);
    }

    bool RayLib::isWindowClosed()
    {
        return (WindowShouldClose());
    }

    void RayLib::destroyWindow() {
        CloseWindow();
    }

    RayLib::~RayLib() {
        this->destroyWindow();
    }

}