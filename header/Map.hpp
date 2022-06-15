/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_

    #include "raylib.h"

namespace IndieStudio {

class Map {
    public:
        Map();
        Model getModel();
        ~Map();

    private:
        Model _model = {0};
        Texture2D _texture = {0};
};

}

#endif /* !MAP_HPP_ */
