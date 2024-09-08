//
// Created by francisc on 8/30/24.
//

#include <SDL_image.h>
#include <iostream>
#include "Renderer.hpp"
#include "TextureManager/TextureManager.hpp"
#include "Canvas/Graphics/TileMap.hpp"

void renderMap(SDL_Renderer &r, SDL_Texture *t, const TileMap &tileMap, const Camera &camera) {
    auto &mapData = tileMap.getMap();
    int srcTileWidth = tileMap.getSRect()->w;
    int srcTileHeight = tileMap.getSRect()->h;
    int dstTileWidth = tileMap.getDRect()->w;
    int dstTileHeight = tileMap.getDRect()->h;

    int textureWidth, textureHeight;
    if (SDL_QueryTexture(t, nullptr, nullptr, &textureWidth, &textureHeight) != 0) {
        std::cerr << "SDL_QueryTexture error: " << SDL_GetError() << std::endl;
        return;
    }

    int tilesPerRow = textureWidth / srcTileWidth;

    for (int i = 0; i < mapData.size(); i++) {
        for (int j = 0; j < mapData[i].size(); j++) {
            int tileIndex = mapData[i][j];
            int tileX = (tileIndex % tilesPerRow) * srcTileWidth;
            int tileY = (tileIndex / tilesPerRow) * srcTileHeight;
            SDL_Rect srcRect = {tileX, tileY, srcTileWidth, srcTileHeight};
            SDL_Rect dstRect = {
                    (j * dstTileWidth) - camera.x,
                    (i * dstTileHeight) - camera.y,
                    dstTileWidth,
                    dstTileHeight
            };

            SDL_RenderCopy(&r, t, &srcRect, &dstRect);
        }
    }
}

void Renderer::drawCanvas(Canvas &c, SDL_Renderer &r, const Camera &cam) {
    const auto& elementList = c.getList();
    SDL_Texture *t;

    SDL_SetRenderDrawColor(&r, 30, 30, 30, 255);
    SDL_RenderClear(&r);

    TextureManager &tm = TextureManager::getInstance();
    for (const auto& element : elementList) {
        t = tm.getTexture(element->getPath(), &r);
        const TileMap* tileMap = dynamic_cast<const TileMap*>(element.get());
        if (tileMap) {
            renderMap(r, t, *tileMap, cam);
        } else {
            SDL_RenderCopy(&r, t, element->getSRect(), element->getDRect());
        }
    }
    SDL_RenderPresent(&r);
    c.blank();
}

