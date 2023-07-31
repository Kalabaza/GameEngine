#pragma once

#ifdef GAME_ENGINE_PLATFORM_WINDOWS

#include <Logger.h>

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argv) {
    Log().Info("GameEngine running!");
    auto app = GameEngine::CreateApplication();
    app->Run();
    delete app;
    return 0;
}

#endif
