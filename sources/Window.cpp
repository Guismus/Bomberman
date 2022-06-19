/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Window
*/

#include "Window.hpp"

namespace IndieStudio {

    Window::Window(int width, int height)
    {
        this->_width = width;
        this->_height = height;
        initWindow();
    }


    void Window::initWindow()
    {
        InitWindow(this->_width, this->_height, "Bomberman");
        Camera camera = { { 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
        SetTargetFPS(70);
    }

    Window::~Window()
    {
        CloseWindow();
    }

}
