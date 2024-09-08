//
// Created by francisc on 8/30/24.
//

#include "Canvas.hpp"

void Canvas::addElement(std::unique_ptr<GraphicElement> ge) {
    elementList.push_back(std::move(ge));
}

GraphicElement* Canvas::getElement(int n) {
    if (n >= 0 && n < elementList.size()) {
        return elementList[n].get();
    }
    return nullptr;
}

const std::vector<std::unique_ptr<GraphicElement>>& Canvas::getList() const {
    return elementList;
}

void Canvas::blank() {
    elementList.clear();
}
