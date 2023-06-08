#pragma once

#include "Core.h"

namespace GameEngine {
    class GAME_ENGINE_API Application {
    public:
        Application() = default;
        virtual ~Application() = default;

        void Run();
    };

    // This has to be implemented in the client application
    Application* CreateApplication();
}
