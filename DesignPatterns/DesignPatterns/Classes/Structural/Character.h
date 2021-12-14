#pragma once
#include <cstdint>

class ICharacter
{
public:
	virtual ~ICharacter() = default;
	virtual int32_t equip() = 0;
	virtual void equipProtection() = 0;
	virtual void addHealth(int32_t healthPoints);
	virtual void printHealth() = 0;
	virtual int32_t getPoints() const { return 0; }
	

protected:
	int32_t _health = 100;
	int32_t _healthPointsAdded = 0;
	int32_t _points = 0;
};

class Teenager : public ICharacter
{
public:
	int32_t equip() override;
	void equipProtection() override;
	void printHealth() override;
	void addHealth(int32_t healthPoints) override;
	int32_t getPoints() const override;
};

