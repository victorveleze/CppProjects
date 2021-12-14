#include "SmartState.h"
#include <iostream>

SmartState::~SmartState()
{
	std::cout << "Deleting SmartState \n";
}

IdleState::~IdleState()
{
	std::cout << "Deleting IdleState \n";
}

void IdleState::exec()
{
	std::cout << "Entering IdleState \n";
	if (!_nextState)
	{
		_nextState = std::make_shared<RunState>();
	}
	_shouldGoNextState = true;
}

RunState::~RunState()
{
	std::cout << "Deleting RunState \n";
}

void RunState::exec()
{
	std::cout << "Entering RunState \n";
	if (!_nextState)
	{
		_nextState = std::make_shared<IdleState>();
	}
	_shouldGoNextState = true;
	_finishProcess = true;
}

SmartStateMachine::SmartStateMachine(std::shared_ptr<SmartState> initalState)
	: _currentState{ initalState }
	, _stateCounter{ 0 }
	, _MAX_ITERATIONS{ 4 }
{}

void SmartStateMachine::process()
{
	while (_stateCounter < _MAX_ITERATIONS)
	{
		_currentState->exec();

		if (_currentState->getFinishProcess())
		{
			break;
		}

		if (_currentState->getShouldGoNextState())
		{
			_currentState = _currentState->getNextState();
			std::cout << "[SMART_STATE_COUNTER] " << _stateCounter++ << "\n";
		}
	}
}


