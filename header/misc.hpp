/*
** EPITECH PROJECT, 2022
** B-YEP-400-MPL-4-1-indiestudio-paul.comte
** File description:
** lib functions
*/

#ifndef MISC_HPP_
#define MISC_HPP_
// #include relevant files
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
}Direction;

namespace misc {

    Vector3 addVector3(const Vector3 a, const Vector3 b)
    {
        return (Vector3) {a.x + b.x, a.y + b.y, a.z + b.z};
    }
}
#endif /* !MISC_HPP_ */
