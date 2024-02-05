#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& _name) : name(_name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Constructor called" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
}
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	return *this;

}
void ClapTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has not enough energy" << std::endl;
		return;
	}
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is DIED,cant attack" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	--energyPoints;
	std::cout << "ClapTrap " << name << " has now " << hitPoints << " points of life and " << energyPoints << " points of energy" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " DIED" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	hitPoints -= amount;
	std::cout << "ClapTrap " << name << " has now " << hitPoints << " points of life and " << energyPoints << " points of energy" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has not enough energy" << std::endl;
		return;
	}
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is DIED,cant recover" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " recovers " << amount << " points of health!" << std::endl;
	hitPoints += amount;
	--energyPoints;
	std::cout << "ClapTrap " << name << " has now " << hitPoints << " points of life and " << energyPoints << " points of energy" << std::endl;
}