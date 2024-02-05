#ifndef CLAPTRAP_HPP
#define	CLAPTRAP_HPP

#include <iostream>
class ClapTrap
{
public:
	ClapTrap(const std::string& _name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& other);
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
};

#endif