#include "../include/HumanB.h"

//HumanB::HumanB() {}
HumanB::HumanB(const std::string& _name) : name(_name) 
{

}
HumanB::~HumanB() {}

void HumanB::attack()
{
	if (weapon->getType().empty())
	{
		std::cout << name << " attacks with their arms (doesnt have any weapon)" << std::endl;
	}
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}
