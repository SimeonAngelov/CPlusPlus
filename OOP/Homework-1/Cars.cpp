#include "Cars.h"
#include "Owner.h"
#include <iostream>
using namespace std;

string Cars::getID() const
{
	return ID;
}
//return owner name
std::string Cars::getOwner() const
{
	return owner.getName();
}

std::string Cars::getRegNum() const
{
	return regNum;
}

void Cars::setID(string ident)
{
	ID = ident;
}

void Cars::setRegNum(std::string num)
{
	regNum = num;
}

void Cars::setOwner(Owner own)
{
	owner = own;
}
//return the actual owner
Owner Cars::getOwnerTwo()
{
	return owner;
}

