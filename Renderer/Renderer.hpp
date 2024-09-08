//
// Created by francisc on 8/30/24.
//

#ifndef CPPGAME_RENDERER_HPP
#define CPPGAME_RENDERER_HPP


#include <SDL_render.h>
#include "Canvas/Canvas.hpp"
#include "Camera/Camera.hpp"

class Renderer {
public:
    Renderer(){};
    void drawCanvas(Canvas &c, SDL_Renderer &r, const Camera &cam);
};


#endif //CPPGAME_RENDERER_HPP
