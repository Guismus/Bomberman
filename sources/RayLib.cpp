/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** RayLib
*/

#include "RayLib.hpp"

namespace IndieStudio {

    RayLib::RayLib(int width, int height)
    {
        this->_width = width;
        this->_height = height;
        initWindow();
    }

    void RayLib::initWindow()
    {
        InitWindow(this->_width, this->_height, "Bomberman");
        Camera camera = { { 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
        SetTargetFPS(144);
    }

    void RayLib::drawFPS()
    {
        DrawFPS(10, 10);
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