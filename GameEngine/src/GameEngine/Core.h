#pragma once

#ifdef GAME_ENGINE_PLATFORM_WINDOWS
    #ifdef GAME_ENGINE_BUILD_DLL
        #define GAME_ENGINE_API __declspec(dllexport)
    #else
        #define GAME_ENGINE_API __declspec(dllimport)
    #endif
#else
    #error GameEngine only working on Windows!
#endif
