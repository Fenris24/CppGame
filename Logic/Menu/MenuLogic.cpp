//
// Created by francisc on 8/29/24.
//

#include "MenuLogic.hpp"
#include "../../Persistance/Save.hpp"

enum MenuOptions {NewGame, LoadGame, Settings, Exit} option;

void MenuLogic::processLogic(Data &d, Canvas &c, Camera &cam) {
    Save s;
    switch (option) {
        case NewGame:
            //loads game from start
            break;
        case LoadGame:
            //loads save states interface
            //check if there are any safe files -> display accordingly
            //then you move up/down to chose between saves
            //and left/right to chose between create/load/delete savefile
            break;
        case Settings:
            //loads settings interface
            break;
        case Exit:
            //closes the game
            break;
    }
}
