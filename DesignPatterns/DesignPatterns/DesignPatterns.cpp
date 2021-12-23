#include <iostream>
#include <memory>
#include <vector>
#include "Classes/Structural/Composite.h"

int main()
{
    const std::shared_ptr<Component> avatar { std::make_shared<Avatar>() };

    const std::shared_ptr<Component> leftArm{std::make_shared<AvatarPart>("Left arm")};
    avatar->addComponent(leftArm);
    const std::shared_ptr<Component> rightArm{std::make_shared<AvatarPart>("Right arm")};
    avatar->addComponent(rightArm);
    const std::shared_ptr<Component> axe{std::make_shared<AvatarPart>("Axe")};
    rightArm->addComponent(axe);
    const std::shared_ptr<Component> candle{ std::make_shared<AvatarPart>("Candle") };
    leftArm->addComponent(candle);

    avatar->operation();

    std::cout << "Let's imagine that the avatar stumbled and the axe felt \n";
    avatar->removeComponent(leftArm);

    avatar->operation();
}

