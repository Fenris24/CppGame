//
// Created by francisc on 8/28/24.
//

#include "Entities.hpp"
#include <math.h>
#include <iostream>

void Entities::move(Directions dir, float deltaTime) {
    float dx = 0, dy = 0;

    if (dir & UP) dy -= 1;
    if (dir & DOWN) dy += 1;
    if (dir & LEFT) dx -= 1;
    if (dir & RIGHT) dx += 1;

    if (dx != 0 && dy != 0) {
        dx /= sqrt(2);
        dy /= sqrt(2);
    }

    x += dx * speed * deltaTime;
    y += dy * speed * deltaTime;
}
