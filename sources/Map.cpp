/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Map
*/

#include "Map.hpp"

namespace IndieStudio {

Map::Map(std::string map, std::string texture) {
    Image image = LoadImage(const_cast<char*>(map.c_str()));
    this->_model = LoadModelFromMesh(GenMeshCubicmap(image, { 1.0f, 1.0f, 1.0f }));
    this->_texture = LoadTexture(const_cast<char*>(texture.c_str()));
    this->_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->_texture;
    UnloadImage(image);
}

Model Map::getModel()
{
    return (this->_model);
}

Texture2D Map::getTexture ()
{
    return (this->_texture);
}

Map::~Map() {
    UnloadTexture(this->_texture);
    UnloadModel(this->_model);
}

}
