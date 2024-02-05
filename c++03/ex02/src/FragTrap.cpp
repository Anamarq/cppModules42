#include "../include/FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 10;
	attackDamage = 30;
	std::cout << "FragTrap constructor called" << std::endl;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " high fives!" << std::endl;
}