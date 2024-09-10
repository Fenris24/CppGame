//
// Created by francisc on 8/27/24.
//

#include "Game.hpp"
#include "../../Logic/Game/NewGameLogic.hpp"
#include "../../Logic/Menu/MenuLogic.hpp"
#include "../../Persistance/SaveData/Data.hpp"
#include "../../Renderer/Renderer.hpp"
#include <atomic>
#include <thread>
#include <chrono>

Game::Game() {
    gc = new GameContext();
    l = new MenuLogic();
}

Game::~Game() {
    delete gc;
    delete l;
}

std::atomic<bool> gameIsRunning(true);
void checkQuitting() {
    SDL_Event event;
    while (gameIsRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
                gameIsRunning = false;
                SDL_Quit();
                break;
            }
        }
        SDL_Delay(50);
    }
}

const int FPS = 144;
const std::chrono::milliseconds frameDuration(1000 / FPS);

// Function to cap the frame rate
void capFrameRate(const std::chrono::steady_clock::time_point& frameStart) {
    auto frameEnd = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart);
    auto delayTime = frameDuration - elapsedTime;

    if (delayTime.count() > 0) {
        std::this_thread::sleep_for(delayTime);
    }
}

void Game::run() {
    delete l;
    l = new NewGameLogic();

    Data *d = new Data("FirstMap", 0, "1234");
    std::thread thread_poll(checkQuitting);

    Renderer *r = new Renderer();
    Canvas *c = new Canvas();
    Camera cam = {0, 0, 1280, 720};

    while (gameIsRunning) {
        auto frameStart = std::chrono::steady_clock::now();
        l->processLogic(*d, *c, cam);
        r->drawCanvas(*c, *gc->getRenderer(), cam);
        capFrameRate(frameStart);
    }

    thread_poll.join();
    SDL_DestroyWindow(gc->getWindow());
    SDL_DestroyRenderer(gc->getRenderer());
}