//
// Created by francisc on 9/8/24.
//

#include <SDL_stdinc.h>
#include <SDL_scancode.h>
#include "Player.hpp"

void Player::processInputs(const Uint8 *keys, float deltaTime) {
    int dir = NONE;
    if (keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_W]) {
        dir |= UP;
        state = MOVING;
    }
    if (keys[SDL_SCANCODE_DOWN] || keys[SDL_SCANCODE_S]) {
        dir |= DOWN;
        state = MOVING;
    }
    if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_A]) {
        dir |= LEFT;
        state = MOVING;
    }
    if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_D]) {
        dir |= RIGHT;
        state = MOVING;
    }
    if (keys[SDL_SCANCODE_SPACE]) {
        state = JUMPING;
    }
    switch (state) {
        case MOVING:
            move((Directions)dir, deltaTime);
            break;
        case RUNNING:
            break;
        case JUMPING:
            break;
        case ATTACKING:
            break;
        case DEFENDING:
            break;
        case CASTING:
            break;
        default:
            break;
    }

}
