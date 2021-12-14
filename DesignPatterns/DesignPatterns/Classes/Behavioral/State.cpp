#include <iostream>
#include "State.h"

State::~State()
{
	std::cout << "Deleteing State\n";
}

Idle::Idle()
{
	_name = STATE::Idle;
}

Idle::~Idle()
{
	std::cout << "Deleting Idle \n";
}

void Idle::exec()
{
	std::cout << "Entering a Idle\n";
	if (!_nextState)
	{
		_nextState = new Run{};
	}

	_shouldGoNextState = true;
}

Run::Run()
{
	_name = STATE::Running;
}

Run::~Run()
{
	std::cout << "Deleting Run \n";
}

void Run::exec()
{
	std::cout << "Entering a Run\n";
	if (!_nextState)
	{
		_nextState = new Idle{};
	}

	_shouldGoNextState = true;
	_finishProcess = true;
}

StateMachine::StateMachine(State* state)
	: _currentState{state}
	, _nextState{nullptr}
	, _stateCounter{ 0 }
	, _MAX_ITERARIONS{ 4 }
{}

StateMachine::~StateMachine()
{
	delete _currentState->getNextState();
	delete _currentState;
}

void StateMachine::setState(State* state)
{
	_nextState = state;
}

void StateMachine::process()
{
	while (_stateCounter != _MAX_ITERARIONS)
	{
		_currentState->exec();

		if (_currentState->getFinishProcess())
		{
			break;
		}

		if (_currentState->getShouldGoNextState())
		{
			State* nextState = _currentState->getNextState();
			delete _currentState;
			_currentState = nextState;
			std::cout << "[STATE_COUNTER] " << _stateCounter++ << "\n";
		}
	}
}

