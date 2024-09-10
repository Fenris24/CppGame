//
// Created by francisc on 9/10/24.
//

#ifndef CPPGAME_VEC2_HPP
#define CPPGAME_VEC2_HPP
#include <math.h>

struct Vec2 {
    float x, y;

    Vec2 operator+(const Vec2& other) const {
        return {x + other.x, y + other.y};
    }

    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2 operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }

    float magnitude() const {
        return sqrt(x * x + y * y);
    }

    Vec2 normalize() const {
        float mag = magnitude();
        return (mag > 0) ? (*this * (1.0f / mag)) : Vec2{0, 0};
    }
};

#endif //CPPGAME_VEC2_HPP
