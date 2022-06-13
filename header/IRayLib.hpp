/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** raylib
*/

#ifndef IRAYLIB_HPP_
    #define IRAYLIB_HPP_
    
    #include "raylib.h"

namespace IndieStudio {

    class IRayLib
    {
        public:
            IRayLib() {}
            ~IRayLib() = default;
            virtual void initWindow() = 0;
            virtual bool isWindowClosed() = 0;
            virtual void destroyWindow() = 0;
    };

}

#endif /* !IRAYLIB_HPP_ */
