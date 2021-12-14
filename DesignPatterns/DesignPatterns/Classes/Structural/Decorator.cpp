#include "Decorator.h"
#include "Character.h"
#include <iostream>

Decorator::Decorator(ICharacter* character)
	: _character{ character }
	, _healthPoints{ 0 }
{}

int32_t Decorator::equip()
{
	return _character->equip();
}

void Decorator::equipProtection() {}

HelmetDecorator::HelmetDecorator(ICharacter* character)
	: Decorator(character)
{
	_healthPoints = 15;
}

int32_t HelmetDecorator::equip()
{
	return _character->equip() + _healthPoints;
}

void HelmetDecorator::equipProtection()
{
	_points += _healthPoints;
	_points += _character->getPoints();
}

void HelmetDecorator::printHealth()
{
	_character->printHealth();
}


int32_t HelmetDecorator::getPoints() const
{
	return _points;
}

ArmourDecorator::ArmourDecorator(ICharacter* character)
	: Decorator(character)
{
	_healthPoints = 20;
}

int32_t ArmourDecorator::equip()
{
	return _character->equip() + _healthPoints;
}

void ArmourDecorator::equipProtection()
{
	_points += _healthPoints;
	_points += _character->getPoints();
}

void ArmourDecorator::printHealth()
{
	_character->printHealth();
}

int32_t ArmourDecorator::getPoints() const
{
	return _points;
}
