#include "../include/Zombie.h"

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
Zombie:: ~Zombie()
{
	std::cout << "Zombie " << name << " is OUT" << std::endl;
}
Zombie::Zombie(const std::string& _name) : name(_name) {}
void Zombie::setName(const std::string& newName)
{
	name = newName;
}