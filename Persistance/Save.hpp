//
// Created by francisc on 8/28/24.
//

#ifndef CPPGAME_SAVE_HPP
#define CPPGAME_SAVE_HPP
#include <string>
#include <utility>
#include "SaveData/Data.hpp"

class Save {
public:
    static void createSave(const std::string& fileName, Data &data);
    static void loadSave(const std::string& fileName, Data &data);
    static void updateSave(const std::string& fileName, Data &data);
    static void deleteSave(const std::string& fileName);
};


#endif //CPPGAME_SAVE_HPP
