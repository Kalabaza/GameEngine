#include <GameEngine.h>

class SandBox : public GameEngine::Application {
public:
    SandBox() = default;
    ~SandBox() = default;
};

GameEngine::Application* GameEngine::CreateApplication() {
    return new SandBox();
}
