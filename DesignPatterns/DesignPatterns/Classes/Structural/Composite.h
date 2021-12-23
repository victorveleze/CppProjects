#pragma once
#include <memory>
#include <string>
#include <vector>

class Component : public std::enable_shared_from_this<Component>
{
public:
    virtual ~Component() = default;
    virtual void addComponent(const std::shared_ptr<Component>& component){}
    virtual void removeComponent(const std::shared_ptr<Component>& component){}
    virtual bool getIsComposite() const;
    virtual void operation() = 0;
    virtual const std::string& getName() const;
    std::shared_ptr<Component> getParent() const;
    void setParent(const std::shared_ptr<Component>& parent);

protected:
    std::shared_ptr<Component> parent_ = nullptr;
    std::string name_;
    bool isComposite_ = false;
};

class AvatarPart : public Component
{
public:
    explicit AvatarPart(const std::string&& name) noexcept;
    void addComponent(const std::shared_ptr<Component>&) override;
    void removeComponent(const std::shared_ptr<Component>&) override;
    void operation() override;
private:
    std::shared_ptr<Component> component_;
};

class Avatar : public Component
{
public:
    Avatar() noexcept;
    void addComponent(const std::shared_ptr<Component>&) override;
    void removeComponent(const std::shared_ptr<Component>&) override;
    void operation() override;

private:
    std::vector<std::shared_ptr<Component>> components_;
};

/* Composite example:
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
 */