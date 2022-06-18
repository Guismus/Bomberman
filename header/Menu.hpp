/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "RayLib.hpp"
#include "Map.hpp"

namespace IndieStudio {

    class Menu : public RayLib {
        public:
            Menu();
            void event();
            void drawMap();
            bool isMulti();
            ~Menu();

        private:
            bool _multi = false;
            int _nb = 0;
            Map *_map = nullptr;
            Map *_map2 = nullptr;
            Map *_map3 = nullptr;
    };

}

#endif /* !MENU_HPP_ */
