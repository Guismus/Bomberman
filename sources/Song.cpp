/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Song
*/

#include "Song.hpp"

namespace IndieStudio {

Song::Song(std::string pathname)
{
    this->_music = LoadMusicStream(const_cast<char*>(pathname.c_str()));
}

void Song::play()
{
    PlayMusicStream(this->_music);
}

void Song::update()
{
    UpdateMusicStream(this->_music);
}

Song::~Song()
{
    UnloadMusicStream(this->_music);
}

}