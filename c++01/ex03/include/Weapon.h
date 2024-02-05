#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
class Weapon{
public:
	Weapon();
	Weapon(const std::string& _type);
	~Weapon();
	const std::string& getType();
	void setType(const std::string& newType);
private:
	std::string type;
};

#endif