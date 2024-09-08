//
// Created by francisc on 8/28/24.
//

#include "Map.hpp"
#include "../Renderer/Canvas/Graphics/TileMap.hpp"

void Map::addLayersToCanvas(Canvas &c, const std::string &path) {
    for(char nr = '1'; nr - 48 <= nrLayers; nr++) {
        std::unique_ptr<GraphicElement> layer = std::make_unique<TileMap>(
                mapName,
                sRect,
                dRect,
                path + nr + ".csv");
        c.addElement(std::move(layer));
    }
}
