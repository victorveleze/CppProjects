#include <iostream>
#include <memory>
#include <vector>
#include "State.h"
#include "SmartState.h"

struct Player
{
    Player()
    {
        _smartStateMachine = std::make_unique<SmartStateMachine>(std::make_shared<IdleState>());
        _stateMachine = std::make_unique<StateMachine>(new Idle{});
    }

    void startMachine()
    {
        _stateMachine->process();
        std::cout << "**** **** **** ****\n";
        _smartStateMachine->process();
        std::cout << "**** **** **** ****\n";
    }

    std::unique_ptr<SmartStateMachine> _smartStateMachine;
    std::unique_ptr<StateMachine> _stateMachine;
};

int main()
{
    Player player;
    player.startMachine();
}

