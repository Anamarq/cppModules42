#include "../include/HumanA.h"

//HumanA::HumanA(){}
HumanA::HumanA(const std::string& _name, Weapon& _weapon) : name(_name), weapon(_weapon){}
HumanA::~HumanA(){}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
