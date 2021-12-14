#pragma once
#include <memory>
class SmartState
{
public:
	virtual ~SmartState();
	virtual void exec() = 0;
	bool getFinishProcess() const { return _finishProcess; }
	bool getShouldGoNextState() const { return _shouldGoNextState; }
	std::shared_ptr<SmartState> getNextState() const { return _nextState; }

protected:
	bool _finishProcess = false;
	bool _shouldGoNextState = false;
	std::shared_ptr<SmartState> _nextState;
};

class IdleState : public SmartState
{
public:
	~IdleState();
	void exec() override;
};

class RunState : public SmartState
{
public:
	~RunState();
	void exec() override;
};

class SmartStateMachine
{
public:
	SmartStateMachine(std::shared_ptr<SmartState> state);
	void process();

private:
	std::shared_ptr<SmartState> _currentState;
	size_t _stateCounter;
	const size_t _MAX_ITERATIONS;
};

