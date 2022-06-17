/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
    #define ENTITY_HPP_

    #include <array>

namespace IndieStudio {

    class Entity {
        public:
            Entity();
            ~Entity();
            int _slots[30][14] = {0};
        private:
    };

}

#endif /* !ENTITY_HPP_ */
