//
// Created by francisc on 8/29/24.
//

#include "NewGameLogic.hpp"
#include "../../Renderer/Canvas/Graphics/TileMap.hpp"
#include <SDL_keyboard.h>
#include <chrono>

NewGameLogic::NewGameLogic() {

}

int getCurrentAnimationFrame(const float animationDuration, const int totalFrames) {
    static auto lastUpdate = std::chrono::steady_clock::now();
    static int currentFrame = 0;

    auto now = std::chrono::steady_clock::now();
    float elapsedSeconds = std::chrono::duration<float>(now - lastUpdate).count();

    if (elapsedSeconds >= (animationDuration / totalFrames)) {
        currentFrame = (currentFrame + 1) % totalFrames;
        lastUpdate = now;
    }

    return currentFrame;
}
//void processInputs() {
//    const Uint8 *state = SDL_GetKeyboardState(nullptr);
//
//    // Check for arrow keys or WASD keys
//    if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]) {
//        player.y -= player.speed;  // Move up
//    }
//    if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S]) {
//        player.y += player.speed;  // Move down
//    }
//    if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A]) {
//        player.x -= player.speed;  // Move left
//    }
//    if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D]) {
//        player.x += player.speed;  // Move right
//    }
//}
void NewGameLogic::processLogic(Data &d, Canvas &c, Camera &cam) {
    Map *m = new Map("Resources/Maps/FirstMap/AncientForest.png", 5,
                     SDL_Rect{0, 0, 48, 48},
                     SDL_Rect{0, 0, 48, 48});
    //process inputs...
    //do stuff with inputs or verify logic
    //like collisions, mob spawning, interactions, etc
    //render the stuff
    //lets say we fetch the data about our character from Data
    cam.centerOn(500, 500, 0, 0);

    m->addLayersToCanvas(c, "Resources/Maps/FirstMap/InitialPoint_layer_");

    int currentFrame = getCurrentAnimationFrame(0.7f, 4);
    std::unique_ptr<GraphicElement> ge = std::make_unique<GraphicElement>("Resources/Player/Idle_Simple.png",
                                                                          SDL_Rect{currentFrame * 48, 0, 48, 48},
                                                                          SDL_Rect{(cam.width - 144) / 2,
                                                                                   (cam.height - 144) / 2,
                                                                                   144, 144});
    c.addElement(std::move(ge));
    delete m;
}

NewGameLogic::~NewGameLogic() {

}
