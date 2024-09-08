//
// Created by francisc on 8/29/24.
//

#ifndef CPPGAME_NEWGAMELOGIC_HPP
#define CPPGAME_NEWGAMELOGIC_HPP


#include "../Logic.hpp"
#include "../../GameElements/Map.hpp"
#include "../../GameElements/Layout.hpp"
#include "../../GameElements/Entities.hpp"

class NewGameLogic: public Logic {

public:
    NewGameLogic();
    void processLogic(Data &d, Canvas &c, Camera &cam) override;
    ~NewGameLogic() override;
};


#endif //CPPGAME_NEWGAMELOGIC_HPP
