//
// Created by francisc on 8/27/24.
//

#ifndef CPPGAME_GAME_HPP
#define CPPGAME_GAME_HPP


#include "../Context/GameContext.hpp"
#include "../../Logic/Logic.hpp"

class Game
{
    GameContext *gc;
    Logic *l;
public:
    Game();
    ~Game();
    void run();
};


#endif //CPPGAME_GAME_HPP
