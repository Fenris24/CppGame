//
// Created by francisc on 8/29/24.
//

#include "NewGameLogic.hpp"
#include "../../Renderer/Canvas/Graphics/TileMap.hpp"
#include "../../GameElements/Entities/Player/Player.hpp"
#include <SDL_keyboard.h>
#include <chrono>

NewGameLogic::NewGameLogic() {

}

static std::chrono::steady_clock::time_point lastUpdateTime = std::chrono::steady_clock::now();
float getDeltaTime() {
    auto currentTime = std::chrono::steady_clock::now();
    float deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(currentTime - lastUpdateTime).count();
    lastUpdateTime = currentTime;
    return deltaTime;
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
SDL_Rect getCameraOn(int entityX, int entityY, int entityW, int entityH, int mapW, int mapH, Camera &cam) {
    int desiredCamX = entityX - cam.width / 2;
    int desiredCamY = entityY - cam.height / 2;
    int camX = std::clamp(desiredCamX, 0, mapW - cam.width);
    int camY = std::clamp(desiredCamY, 0, mapH - cam.height);
    return {entityX - camX - entityW / 2,
            entityY - camY - entityH / 2,
            entityW,
            entityH};
}

void NewGameLogic::processLogic(Data &d, Canvas &c, Camera &cam) {
    const Uint8 *state = SDL_GetKeyboardState(nullptr);
    Map *m = new Map("Resources/Maps/FirstMap/AncientForest.png", 5,
                     SDL_Rect{0, 0, 48, 48},
                     SDL_Rect{0, 0, 48, 48});
    //process inputs...
    //do stuff with inputs or verify logic
    //like collisions, mob spawning, interactions, etc
    //render the stuff
    //lets say we fetch the data about our character from Data
    static Player *player = new Player("Resources/Player/Idle_Simple.png", 0, 0, 100, 100, 300);

    player->processInputs(state, getDeltaTime());

    cam.centerOn(player->getX(), player->getY(), 48 * 30, 48 * 30);
    m->addLayersToCanvas(c, "Resources/Maps/FirstMap/InitialPoint_layer_");

    int currentFrame = getCurrentAnimationFrame(0.7f, 4);

    std::unique_ptr<GraphicElement> ge = std::make_unique<GraphicElement>("Resources/Player/Idle_Simple.png",
                                                                          SDL_Rect{currentFrame * 48, 0, 48, 48},
                                                                          getCameraOn(player->getX(), player->getY(), 144, 144, 48 * 30, 48 * 30, cam));
    c.addElement(std::move(ge));
    delete m;
}

NewGameLogic::~NewGameLogic() {

}
