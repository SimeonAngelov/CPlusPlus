#ifndef OWNER_H
#define OWNER_H
#include <string>

class Owner
{
private:
	std::string name;
	int carsPower = 0;

public:
	std::string getName() const;
	int getCarsPower() const;

	void setCarsPower(int hp);
	void setName(std::string str);
};
#endif