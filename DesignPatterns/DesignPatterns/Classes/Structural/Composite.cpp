#include "Composite.h"
#include <iostream>
#include <algorithm>

bool Component::getIsComposite() const
{
    return isComposite_;
}

const std::string& Component::getName() const
{
    return name_;
}

std::shared_ptr<Component> Component::getParent() const
{
    return parent_;
}

void Component::setParent(const std::shared_ptr<Component>& parent)
{
    parent_ = parent;
}

AvatarPart::AvatarPart(const std::string&& name) noexcept
{
    name_ = name;
}

void AvatarPart::addComponent(const std::shared_ptr<Component>& component)
{
    component_ = component;
}

void AvatarPart::removeComponent(const std::shared_ptr<Component>& component)
{
    if(component == component_)
    {
        component_ = nullptr;
    }
}

void AvatarPart::operation()
{
    std::cout << name_ << "\n";
    if(component_)
    {
        std::cout << "\t" << component_->getName() << "\n";
    }
}

Avatar::Avatar() noexcept
{
    isComposite_ = true;
}

void Avatar::addComponent(const std::shared_ptr<Component>& component)
{
    component->setParent(shared_from_this());
    components_.push_back(component);
}

void Avatar::removeComponent(const std::shared_ptr<Component>& component)
{
    const auto componentIter = std::find(components_.begin(), components_.end(), component);
    if (componentIter != components_.end())
    {
        component->setParent(nullptr);
        components_.erase(componentIter);
    }
}

void Avatar::operation()
{
    std::cout << "Avatar begins: \n";
    std::for_each(components_.begin(), components_.end(), [&](const std::shared_ptr<Component> component) {
        if(component == components_.back())
        {
            component->operation();
        }
        else
        {
            component->operation();
            std::cout << " + \n";
        }
    });
    std::cout << "Avatar ends\n";

}
