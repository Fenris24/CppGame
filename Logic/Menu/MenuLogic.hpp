//
// Created by francisc on 8/29/24.
//

#ifndef CPPGAME_MENULOGIC_HPP
#define CPPGAME_MENULOGIC_HPP


#include "../Logic.hpp"

class MenuLogic: public Logic {
public:
    //MenuLogic();
    void processLogic(Data &d, Canvas &c, Camera &cam) override;
    //~MenuLogic() override;
};


#endif //CPPGAME_MENULOGIC_HPP
