//
// Created by francisc on 8/30/24.
//

#ifndef CPPGAME_TEXTUREMANAGER_HPP
#define CPPGAME_TEXTUREMANAGER_HPP


#include <map>
#include <string>
#include <SDL_render.h>

class TextureManager{
TextureManager() {};
~TextureManager();
std::map<std::string, SDL_Texture*> textures;

static SDL_Texture  *loadTexture(const std::string &resource, SDL_Renderer *renderer);

public:
    TextureManager(const TextureManager&) = delete;
    TextureManager &operator=(const TextureManager&) = delete;
    static TextureManager& getInstance() {
        static TextureManager instance;
        return instance;
    }
    SDL_Texture *getTexture(const std::string &resource, SDL_Renderer *renderer);
};


#endif //CPPGAME_TEXTUREMANAGER_HPP
