//
// Created by francisc on 8/27/24.
//

#ifndef CPPGAME_GAMECONTEXT_HPP
#define CPPGAME_GAMECONTEXT_HPP
#include <SDL.h>
#include <SDL_image.h>


class GameContext {
    SDL_Window  *window;
    SDL_Renderer *renderer;
public:
    GameContext();
    SDL_Window *getWindow(){return window;};
    SDL_Renderer *getRenderer(){return renderer;};
};


#endif //CPPGAME_GAMECONTEXT_HPP
