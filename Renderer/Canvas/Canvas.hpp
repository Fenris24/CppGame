//
// Created by francisc on 8/30/24.
//

#ifndef CPPGAME_CANVAS_HPP
#define CPPGAME_CANVAS_HPP


#include <vector>
#include <memory>
#include "Graphics/GraphicElement.hpp"

class Canvas {
    std::vector<std::unique_ptr<GraphicElement>> elementList;

public:
    Canvas() = default;
    void addElement(std::unique_ptr<GraphicElement> ge);
    GraphicElement* getElement(int n);
    [[nodiscard]] const std::vector<std::unique_ptr<GraphicElement>>& getList() const;
    void blank();
};


#endif //CPPGAME_CANVAS_HPP