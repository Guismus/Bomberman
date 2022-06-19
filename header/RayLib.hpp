/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** raylib
*/

#ifndef RAYLIB_HPP_
    #define RAYLIB_HPP_

    #include "IRayLib.hpp"

namespace IndieStudio {

    class RayLib : public IRayLib
    {
        public:
            RayLib();
            bool isWindowClosed() override;
            void clear() override;
            void drawText(std::string str, int x, int y, int size, Color color) override;
            void drawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint) override;
            void drawModel(Model model, Vector3 position, float scale, Color tint) override;
            void drawCube(Vector3 position, float width, float height, float length, Color color) override;
            void drawSphere(Vector3 positon, float radius, Color color) override;
            void drawFPS() override;
            void beginDrawing() override;
            void endDrawing() override;
            void beginDrawing3D(Camera3D camera) override;
            void endDrawing3D() override;
            bool isKeyPressed(int key) override;
            float TimeElapsed();
            ~RayLib();

        private:
    };

}

#endif /* !RAYLIB_HPP_ */
