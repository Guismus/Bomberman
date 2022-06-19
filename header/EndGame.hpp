/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** EndGame
*/

#ifndef ENDGAME_HPP_
    #define ENDGAME_HPP_

    #include "RayLib.hpp"

namespace IndieStudio {

    class EndGame : public RayLib {
        public:
            EndGame();
            void drawTime(int time);
            ~EndGame();
        private:
    };

}

#endif /* !ENDGAME_HPP_ */
