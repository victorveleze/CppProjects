///Command example at the end
#pragma once

#include <string>
#include <vector>
#include <memory>
#include <iostream>

class PlayerObject;

struct Vec2
{
    float x;
    float y;

    Vec2(float x, float y)
        : x{ x }
        , y{ y }
    {}

    friend std::ostream& operator << (std::ostream& os, Vec2 vec)
    {
        return os << "x = " << vec.x << "\t y = " << vec.y << "\n";
    }
};

class Command
{
public:
    virtual ~Command();
    virtual void execute() const = 0;

protected:
    PlayerObject* _playerObject;
};

class PhysicsCommand  : public Command
{
public:
    explicit PhysicsCommand(PlayerObject* playerObject, Vec2 position);
    void execute() const override;
    void setPlayerPosition(Vec2 position);
};

class RenderCommand : public Command
{
public:
    explicit RenderCommand(PlayerObject* playerObject, Vec2 vertices);
    void execute() const override;
    void setPlayerVertices(Vec2 vertices);
};

class Renderer //Invoker
{
public:
    void addCommand(std::shared_ptr<Command> command);
    void render();

private:
    std::vector<std::shared_ptr<Command>> _commandVector;
};

class PlayerObject
{
public:
    PlayerObject();
    void setVertices(const Vec2& vertices);
    void setPosition(const Vec2& position);
    const Vec2& getVertices() const;
    const Vec2& getPosition() const;

private:
    Vec2 _vertices;
    Vec2 _position;
};

/*
    std::unique_ptr<PlayerObject> player = std::make_unique<PlayerObject>();    
    Renderer renderer;

    auto commandPos = std::make_shared<PhysicsCommand>(player.get(), Vec2{ 1, 2 });
    renderer.addCommand(commandPos);

    auto commandVertices = std::make_shared<RenderCommand>(player.get(), Vec2{ 10, 20 });
    renderer.addCommand(commandVertices);

    renderer.render();
*/