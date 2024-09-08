//
// Created by francisc on 8/27/24.
//

#ifndef CPPGAME_LOGIC_HPP
#define CPPGAME_LOGIC_HPP

#include "../Persistance/SaveData/Data.hpp"
#include "../Renderer/Canvas/Canvas.hpp"
#include "../Renderer/Camera/Camera.hpp"

class Logic{
public:
    virtual void processLogic(Data &d, Canvas &c, Camera &cam) = 0;
    virtual ~Logic() = default;
};


#endif //CPPGAME_LOGIC_HPP