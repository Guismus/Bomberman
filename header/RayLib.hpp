/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** raylib
*/

#ifndef RAYLIB_HPP_
    #define RAYLIB_HPP_

    #include "IRayLib.hpp"

namespace IndieStudio {

    class RayLib : public IRayLib
    {
        public:
            RayLib(int x, int y);
            void initWindow() override;
            bool isWindowClosed() override;
            void destroyWindow() override;
            ~RayLib();

        private:
            int _x;
            int _y;
    };

}

#endif /* !RAYLIB_HPP_ */
