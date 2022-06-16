/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** RayLib
*/

#include "RayLib.hpp"

namespace IndieStudio {

    RayLib::RayLib() {}

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

    void RayLib::clear()
    {
        ClearBackground(RAYWHITE);
    }

    void RayLib::beginDrawing()
    {
        BeginDrawing();
        this->clear();
    }

    void RayLib::endDrawing()
    {
        EndDrawing();
    }

    void RayLib::beginDrawing3D(Camera3D camera)
    {
        BeginMode3D(camera);
    }

    void RayLib::endDrawing3D()
    {
        EndMode3D();
    }

    bool RayLib::isKeyPressed(int key)
    {
        return (IsKeyDown(key));
    }

    RayLib::~RayLib() {}

}