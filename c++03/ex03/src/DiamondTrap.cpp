#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string& _name) : ClapTrap(_name), ScavTrap(_name), FragTrap(_name)
{
	name = _name;
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;

	std::cout << "DiamondTrap constructor called" << std::endl;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "Hi, i am " << name << " and my Clap name is " << ClapTrap::name << std::endl;
}