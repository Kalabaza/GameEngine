#pragma once

#ifdef GAME_ENGINE_PLATFORM_WINDOWS

#include <iostream>

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argv) {
    std::cout << "GameEngine running!" << std::endl;
    auto app = GameEngine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif
