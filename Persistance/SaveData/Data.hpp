//
// Created by francisc on 8/30/24.
//

#ifndef CPPGAME_DATA_HPP
#define CPPGAME_DATA_HPP
#include <string>

class Data{
    std::string mapName;
    std::uint16_t checkPoint;
    std::string stats;
public:
    Data(std::string mapName, std::uint16_t checkPoint, std::string stats)
    :mapName(std::move(mapName)),
    checkPoint(checkPoint),
    stats(std::move(stats)){};
};


#endif //CPPGAME_DATA_HPP
