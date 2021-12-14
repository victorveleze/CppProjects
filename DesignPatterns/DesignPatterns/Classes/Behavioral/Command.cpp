#include "Command.h"
#include <iostream>
#include <algorithm>

Command::~Command()
{
    std::cout << "[COMMAND DESTRUCTOR] Destroying Command\n";
}

PhysicsCommand::PhysicsCommand(PlayerObject* playerObject, Vec2 position)
{
    _playerObject = playerObject;
    setPlayerPosition(position);
}

void PhysicsCommand::execute() const
{
    std::cout << "[PHYSICS COMMAND] Moving player to position " << _playerObject->getPosition();
}

void PhysicsCommand::setPlayerPosition(Vec2 position)
{
    _playerObject->setPosition(position);
}

RenderCommand::RenderCommand(PlayerObject* playerObject, Vec2 vertices)
{
    _playerObject = playerObject;
    setPlayerVertices(vertices);
}

void RenderCommand::execute() const
{
    std::cout << "[RENDER COMMAND] Rendering player vertices at " << _playerObject->getVertices();
}

void RenderCommand::setPlayerVertices(Vec2 vertices)
{
    _playerObject->setVertices(vertices);
}

void Renderer::addCommand(std::shared_ptr<Command> command)
{
    _commandVector.push_back(command);
}

void Renderer::render()
{
    std::for_each(_commandVector.begin(), _commandVector.end(), [](std::shared_ptr<Command> command){
        command->execute();
    });
}

PlayerObject::PlayerObject()
    : _vertices{ Vec2{0.0f, 0.0f} }
    , _position{ Vec2{0.0f, 0.0f} }
{}

void PlayerObject::setVertices(const Vec2& vertices)
{
    _vertices = vertices;
}

void PlayerObject::setPosition(const Vec2& position)
{
    _position = position;
}

const Vec2& PlayerObject::getVertices() const
{
    return _vertices;
}

const Vec2& PlayerObject::getPosition() const
{
    return _position;
}
