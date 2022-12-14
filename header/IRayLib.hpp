/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** raylib
*/

#ifndef IRAYLIB_HPP_
    #define IRAYLIB_HPP_

    #include "raylib.h"
    #include <string>

namespace IndieStudio {

    class IRayLib
    {
        public:
            IRayLib() {}
            ~IRayLib() = default;
            virtual bool isWindowClosed() = 0;
            virtual void clear() = 0;
            virtual void drawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) = 0;
            virtual void drawModel(Model model, Vector3 position, float scale, Color tint) = 0;
            virtual void drawCube(Vector3 position, float width, float height, float length, Color color) = 0;
            virtual void drawSphere(Vector3 position, float radius, Color color) = 0;
            virtual void drawText(std::string str, int x, int y, int size, Color color) = 0;
            virtual void drawFPS() = 0;
            virtual void beginDrawing() = 0;
            virtual void endDrawing() = 0;
            virtual void beginDrawing3D(Camera3D camera) = 0;
            virtual void endDrawing3D() = 0;
            virtual bool isKeyPressed(int key) = 0;
            virtual float TimeElapsed() = 0;
    };

}

#endif /* !IRAYLIB_HPP_ */
