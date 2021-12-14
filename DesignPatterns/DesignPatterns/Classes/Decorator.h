#pragma once
#include "Character.h"

class Decorator : public ICharacter
{
public:
	Decorator(ICharacter* character);
	int32_t equip() override;
	void equipProtection() override;

protected:
	ICharacter* _character;
	int32_t _healthPoints;
};

class HelmetDecorator : public Decorator
{
public:
	HelmetDecorator(ICharacter* character);
	int32_t equip() override;
	void equipProtection() override;
	void printHealth() override;
	int32_t getPoints() const override;
};

class ArmourDecorator : public Decorator
{
public:
	ArmourDecorator(ICharacter* character);
	int32_t equip() override;
	void equipProtection() override;
	void printHealth() override;
	int32_t getPoints() const override;
};


