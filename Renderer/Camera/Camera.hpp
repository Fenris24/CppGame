//
// Created by francisc on 9/8/24.
//

#ifndef CPPGAME_CAMERA_HPP
#define CPPGAME_CAMERA_HPP

#include <algorithm>

struct Camera {
    int x, y;
    int width, height;

    void centerOn(int targetX, int targetY, int levelWidth, int levelHeight) {
        x = targetX - width / 2;
        y = targetY - height / 2;

        x = std::max(0, std::min(x, levelWidth - width));
        y = std::max(0, std::min(y, levelHeight - height));
    }
};


#endif //CPPGAME_CAMERA_HPP
