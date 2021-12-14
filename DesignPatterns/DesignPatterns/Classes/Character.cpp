#include "Character.h"
#include <iostream>

void ICharacter::addHealth(int32_t healthPoints)
{
	_health += healthPoints;
	_healthPointsAdded += healthPoints;
}

int32_t Teenager::equip()
{
	return _health;
}

void Teenager::equipProtection()
{
	std::cout << "";
}

void Teenager::printHealth()
{
	std::cout << "[Teenager] Health = " << _health << "\n";
}

void Teenager::addHealth(int32_t healthPoints)
{
	ICharacter::addHealth(healthPoints);
}

int32_t Teenager::getPoints() const 
{
	return _points;
}


