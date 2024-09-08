//
// Created by francisc on 8/30/24.
//

#include "TextureManager.hpp"
#include <iostream>
#include <SDL_image.h>

TextureManager::~TextureManager() {
    for (auto &t : textures) {
        SDL_DestroyTexture(t.second);
    }
    textures.clear();
}

SDL_Texture* TextureManager::getTexture(const std::string& resource, SDL_Renderer* renderer) {
    auto it = textures.find(resource);
    if (it != textures.end()) {
        return it->second;
    } else {
        SDL_Texture* newTexture = loadTexture(resource, renderer);
        if (newTexture) {
            textures[resource] = newTexture;
            return newTexture;
        } else {
            return nullptr;
        }
    }
}

SDL_Texture* TextureManager::loadTexture(const std::string& filename, SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (!surface) {
        std::cerr << "Failed to load image: " << SDL_GetError() << '\n';
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << '\n';
    }
    return texture;
}