#include "Owner.h"

std::string Owner:: getName() const
{
	return name;
}

int Owner:: getCarsPower() const
{
	return carsPower;
}

void Owner::setCarsPower(int hp)
{
	carsPower += hp;
}

void Owner::setName(std::string str)
{
	name = str;
}