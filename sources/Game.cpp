/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** game
*/

#include "Game.hpp"

namespace IndieStudio {

Game::Game() : RayLib(1280, 720)
{
    this->_cam = new EDCamera;
}

Camera3D Game::getCamera()
{
    return (this->_cam->getCamera());
}

Game::~Game()
{
    if (this->_cam)
        delete this->_cam;
}

}