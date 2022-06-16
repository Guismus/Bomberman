/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Map
*/

#include "Map.hpp"

namespace IndieStudio {

Map::Map() {
    Image image = LoadImage("../resources/map1.png");
    this->_model = LoadModelFromMesh(GenMeshCubicmap(image, (Vector3){ 1.0f, 1.0f, 1.0f }));
    this->_texture = LoadTexture("../resources/cubicmap_atlas.png");
    this->_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->_texture;
    UnloadImage(image);
}

Model Map::getModel()
{
    return (this->_model);
}

Map::~Map() {
    UnloadTexture(this->_texture);
    UnloadModel(this->_model);
}

}
