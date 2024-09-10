//
// Created by francisc on 9/8/24.
//

#ifndef CPPGAME_PLAYER_HPP
#define CPPGAME_PLAYER_HPP


#include <utility>

#include "../Entities.hpp"

class Player: public Entities {
    enum player_state{IDLE, MOVING, RUNNING, ATTACKING, CASTING, DEFENDING, JUMPING} state = IDLE;
public:
    Player(std::string spritePath, float x, float y, int hp, int damage, int speed)
    : Entities(std::move(spritePath), x, y, hp, damage, speed){};
    void processInputs(const Uint8 *state, float deltaTime);
};


#endif //CPPGAME_PLAYER_HPP
