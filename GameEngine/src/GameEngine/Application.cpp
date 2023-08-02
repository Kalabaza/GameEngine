#include "Application.h"

#include "GameEngine/Events/ApplicationEvent.h"
#include "Logger.h"

namespace GameEngine {
    void Application::Run() {
        WindowResizeEvent e(1280, 720);
        Log().Debug(e);

        while(true);
    }
}
