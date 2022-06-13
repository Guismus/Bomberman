/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** raylib
*/

#include "raylib.h"

#ifndef RAYLIB_HPP_
    #define RAYLIB_HPP_

namespace IndieStudio {

    class Raylib
    {
        public:
            Raylib(int x, int y);
            void initWindow();
            bool isWindowClosed();
            ~Raylib();

        private:
            void _destroyWindow();
            int _x;
            int _y;
    };

}

namespace IndieStudio {

    Raylib::Raylib(int x, int y)
    {
        this->_x = x;
        this->_y = y;
        initWindow();
    }

    void Raylib::initWindow()
    {
        InitWindow(this->_x, this->_y, "Bomberman");
        SetTargetFPS(60);
    }

    bool Raylib::isWindowClosed()
    {
        return (WindowShouldClose());
    }

    void Raylib::_destroyWindow() {
        CloseWindow();
    }

    Raylib::~Raylib() {
        this->_destroyWindow();
    }

}

#endif /* !RAYLIB_HPP_ */
