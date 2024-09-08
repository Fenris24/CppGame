//
// Created by francisc on 8/30/24.
//

#ifndef CPPGAME_GRAPHICELEMENT_HPP
#define CPPGAME_GRAPHICELEMENT_HPP


#include <string>
#include <SDL_rect.h>

class GraphicElement {
protected:
    std::string spritePath;
    SDL_Rect sRect;
    SDL_Rect dRect;
public:
    GraphicElement(std::string spritePath, SDL_Rect sRect, SDL_Rect dRect)
            :spritePath(std::move(spritePath)),
             sRect(sRect), dRect(dRect){};
    [[nodiscard]] virtual const char * getPath() const { return spritePath.c_str(); };
    [[nodiscard]] virtual const SDL_Rect *getSRect() const { return &sRect;}
    [[nodiscard]] virtual const SDL_Rect *getDRect() const { return &dRect;}
    virtual void setSRect(SDL_Rect rect) { sRect = rect;}
    virtual void setDRect(SDL_Rect rect) { dRect = rect;}
    virtual ~GraphicElement() = default;
};


#endif //CPPGAME_GRAPHICELEMENT_HPP
