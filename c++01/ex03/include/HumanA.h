#ifndef HUMANA_H
#define HUMANA_H
#include "Weapon.h"
class HumanA
{
public:
	//HumanA();
	HumanA(const std::string& _name, Weapon& _weapon);
	~HumanA();
	void attack();
private:
	std::string name;
	Weapon &weapon;
};

#endif