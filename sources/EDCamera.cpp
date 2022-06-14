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
    this->_cam.position = (Vector3){ 10.0f, 10.0f, 0.0f }; // this->_cam position
    this->_cam.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // this->_cam looking at point
    this->_cam.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // this->_cam up vector (rotation towards target)
    this->_cam.fovy = 45.0f;                                // this->_cam field-of-view Y
    this->_cam.projection = CAMERA_PERSPECTIVE;
}

Camera3D EDCamera::getCamera()
{
    return (this->_cam);
}

EDCamera::~EDCamera() {}

}