/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Camera
*/

#ifndef EDCAMERA_HPP_
    #define EDCAMERA_HPP_

    #include "raylib.h"

namespace IndieStudio {

class EDCamera {
    public:
        EDCamera();
        ~EDCamera();
        Camera3D getCamera();
    private:
        Camera3D _cam = {0};
};

}

#endif /* !EDCamera_HPP_ */
