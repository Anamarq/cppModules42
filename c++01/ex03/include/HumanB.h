#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.h"
class HumanB
{
public:
	//HumanB();
	HumanB(const std::string& _name);
	~HumanB();
	void attack();
	void setWeapon(Weapon &newWeapon);
private:
	std::string name;
	Weapon *weapon;
};

#endif