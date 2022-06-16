/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Music
*/

#ifndef SONG_HPP_
    #define SONG_HPP_
    #include "raylib.h"
    #include <iostream>
    #include <string>

namespace IndieStudio {
    class Song {
        public:
            Song(std::string pathname);
            void play();
            void update();
            ~Song();
        private:
        Music _music;
    };
}

#endif /* !SONG_HPP_ */
