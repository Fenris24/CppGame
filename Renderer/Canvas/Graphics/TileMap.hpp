//
// Created by francisc on 8/31/24.
//

#ifndef CPPGAME_TILEMAP_HPP
#define CPPGAME_TILEMAP_HPP


#include <SDL_bits.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "GraphicElement.hpp"



class TileMap : public GraphicElement {
    static std::unordered_map<std::string, std::vector<std::vector<int>>> mapCache;
    std::string tileMapPath;

public:
    TileMap(const std::string& spritePath, SDL_Rect sRect, SDL_Rect dRect, const std::string& tileMapPath)
            : GraphicElement(spritePath, sRect, dRect), tileMapPath(tileMapPath) {
        if (mapCache.find(tileMapPath) == mapCache.end()) {
            loadMap();
        }
    };

    void loadMap() {
        std::ifstream file(tileMapPath);
        if (!file.is_open()) {
            std::cerr << "Failed to open tile map file: " << tileMapPath << std::endl;
            return;
        }

        std::vector<std::vector<int>> map;
        std::string line;
        while (getline(file, line)) {
            std::istringstream iss(line);
            std::vector<int> row;
            std::string number;
            while (getline(iss, number, ',')) {
                try {
                    int tile = std::stoi(number);  // Convert string to int
                    row.push_back(tile);
                } catch (const std::exception& e) {
                    std::cerr << "Error converting string to number: " << e.what() << std::endl;
                    continue;
                }
            }
            map.push_back(row);
        }
        file.close();
        mapCache[tileMapPath] = map;
    }

    [[nodiscard]] const std::vector<std::vector<int>>& getMap() const {
        return mapCache[tileMapPath];
    }

    void setTileMapPath(const std::string& newPath) {
        if (newPath != tileMapPath) {
            tileMapPath = newPath;
            if (mapCache.find(newPath) == mapCache.end()) {
                loadMap();
            }
        }
    }
};

#endif //CPPGAME_TILEMAP_HPP
