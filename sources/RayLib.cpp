/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** RayLib
*/

#include "RayLib.hpp"

namespace IndieStudio {

    RayLib::RayLib(int width, int height)
    {
        this->_width = width;
        this->_height = height;
        initWindow();
    }

    void RayLib::initWindow()
    {
        InitWindow(this->_width, this->_height, "Bomberman");
        Camera camera = { { 16.0f, 14.0f, 16.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };
        SetTargetFPS(144);
    }

    void RayLib::drawFPS()
    {
        DrawFPS(10, 10);
    }

    void RayLib::drawModel(Model model, Vector3 position, float scale, Color color)
    {
        DrawModel(model, position, scale, color);
    }

    void RayLib::drawCube(Vector3 position, float width, float height, float length, Color color)
    {
        DrawCube(position, width, height, length, color);
    }

    void RayLib::drawSphere(Vector3 position, float radius, Color color)
    {
        DrawSphere(position, radius, color);
    }

    bool RayLib::isWindowClosed()
    {
        return (WindowShouldClose());
    }

    void RayLib::destroyWindow() {
        CloseWindow();
    }

    void RayLib::clear() {
        ClearBackground(RAYWHITE);
    }

    void RayLib::beginDrawing() {
        BeginDrawing();
        this->clear();
    }

    void RayLib::endDrawing() {
        EndDrawing();
    }

    void RayLib::beginDrawing3D(Camera3D camera) {
        BeginMode3D(camera);
    }

    void RayLib::endDrawing3D() {
        EndMode3D();
    }

    RayLib::~RayLib() {
        this->destroyWindow();
    }

}