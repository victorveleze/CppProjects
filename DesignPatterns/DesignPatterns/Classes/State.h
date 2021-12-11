#pragma once
#include <memory>

class State : public std::enable_shared_from_this<State>
{
public:
	enum class STATE { Idle, Walking, Running };
	bool getShouldGoNextState() const { return _shouldGoNextState; }
	bool getFinishProcess() const { return _finishProcess; }
	State* getNextState() const { return _nextState; }
	virtual void exec() = 0;
	virtual ~State();

protected:
	STATE _name;
	State* _nextState = nullptr;
	bool _shouldGoNextState = false;
	bool _finishProcess = false;
};

class Idle : public State
{
public:
	Idle();
	~Idle();
	void exec() override;
};

class Run : public State
{
public:
	Run();
	~Run();
	void exec() override;
};

class StateMachine
{
public:
	StateMachine(State* state);
	~StateMachine();
	void setState(State* state);
	void process();

private:
	State* _currentState;
	State* _nextState;
	int32_t _stateCounter;
	const int32_t _MAX_ITERARIONS;
};

