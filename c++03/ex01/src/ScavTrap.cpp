#include "../include/ScavTrap.hpp"

//ScavTrap::ScavTrap(const std::string& name) : CapTrap(name), hitPoints(100), energyPoints(50), attackDamage(20)
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " has not energy left !!" << std::endl;
		return;
	}
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " is DIED, cant attack" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
	std::cout << "ScavTrap " << name << " has now " << hitPoints << " points of life and " << energyPoints << " points of energy" << std::endl;
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << "ScavTrap is now in Gate keeper mode" << std::endl;
}