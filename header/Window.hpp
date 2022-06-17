/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

    #include "IRayLib.hpp"

namespace IndieStudio {

class Window {
    public:
        Window(int width, int height);
        void initWindow();
        ~Window();

    private:
    int _width;
    int _height;
};

}

#endif /* !WINDOW_HPP_ */
