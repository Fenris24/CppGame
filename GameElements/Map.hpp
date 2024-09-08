//
// Created by francisc on 8/28/24.
//

#include <string>
#include <utility>
#include <SDL_rect.h>
#include "../Renderer/Canvas/Canvas.hpp"

#ifndef CPPGAME_TILEMAP_HPP
#define CPPGAME_MAP_HPP


class Map {
    std::string mapName;
    int nrLayers;
    SDL_Rect sRect;
    SDL_Rect dRect;
public:
    Map(std::string mapName, int nrLayers, SDL_Rect sRect, SDL_Rect dRect)
    : mapName(std::move(mapName)), nrLayers(nrLayers),
      sRect(sRect), dRect(dRect){};
    void addLayersToCanvas(Canvas &c, const std::string &path);
};


#endif //CPPGAME_TILEMAP_HPP
