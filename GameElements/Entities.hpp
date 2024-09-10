//
// Created by francisc on 8/28/24.
//

#ifndef CPPGAME_ENTITIES_HPP
#define CPPGAME_ENTITIES_HPP


#include <string>
#include "Directions.hpp"

class Entities {
    float x, y;
    int hp;
    int damage;
    int speed;
    std::string spritePath;
public:
    Entities(std::string spritePath, float x, float y, int hp, int damage, int speed)
    :spritePath(std::move(spritePath)), x(x), y(y), hp(hp), damage(damage), speed(speed) {};
    void move(Directions dir, float deltaTime);
    [[nodiscard]] float getX() const {return x;}
    [[nodiscard]] float getY() const {return y;}

};


#endif //CPPGAME_ENTITIES_HPP