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
            RayLib(int width, int height);
            void initWindow() override;
            bool isWindowClosed() override;
            void destroyWindow() override;
            void clear() override;
            void drawModel(Model model, Vector3 position, float scale, Color tint) override;
            void drawCube(Vector3 position, float width, float height, float length, Color color) override;
            void drawSphere(Vector3 positon, float radius, Color color) override;
            void drawFPS() override;
            void beginDrawing() override;
            void endDrawing() override;
            void beginDrawing3D(Camera3D camera) override;
            void endDrawing3D() override;
            ~RayLib();

        private:
            int _width;
            int _height;
    };

}

#endif /* !RAYLIB_HPP_ */
