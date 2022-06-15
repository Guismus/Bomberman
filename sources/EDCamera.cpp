/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Camera
*/

#include "EDCamera.hpp"

namespace IndieStudio {

EDCamera::EDCamera()
{
    Vector3 first = { 35.0f, 25.0f, 7.0f };
    Vector3 second = { 0.0f, 0.0f, 7.0f };
    Vector3 third = { 0.0f, 1.0f, 0.0f };
    this->_cam.position = first; // this->_cam position
    this->_cam.target = second;      // this->_cam looking at point
    this->_cam.up = third;          // this->_cam up vector (rotation towards target)
    this->_cam.fovy = 40.0f;                                // this->_cam field-of-view Y
    this->_cam.projection = CAMERA_PERSPECTIVE;
}

Camera3D EDCamera::getCamera()
{
    return (this->_cam);
}

EDCamera::~EDCamera() {}

}