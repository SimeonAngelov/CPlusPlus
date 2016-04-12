#ifndef CARS_H
#define CARS_H
#include <string>
#include "Owner.h"
#include <vector>

class Cars{
private:
	std::string ID;
	std::string regNum;
	Owner owner;
	
public:
	
	//declare getters
	std::string getID() const;
	std::string getRegNum() const;
	std::string getOwner() const;
	Owner getOwnerTwo() const;

	//declare setters
	void setID(std::string ident);
	void setRegNum(std::string num);
	void setOwner(Owner own);

};
#endif