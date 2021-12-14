#include <iostream>
#include <memory>
#include <vector>
#include "Classes/Behavioral/Command.h"

int main()
{
    std::unique_ptr<PlayerObject> player = std::make_unique<PlayerObject>();
    Renderer renderer;

    auto commandPos = std::make_shared<PhysicsCommand>(player.get(), Vec2{1, 2});
    renderer.addCommand(commandPos);

    auto commandVertices = std::make_shared<RenderCommand>(player.get(), Vec2{ 10, 20 });
    renderer.addCommand(commandVertices);


    renderer.render();

}

