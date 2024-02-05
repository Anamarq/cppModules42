#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap
{
public:
    DiamondTrap(const std::string& _name);
    ~DiamondTrap();
    void whoAmI(void);
    using ScavTrap::attack; //Usa el attack de scavTrap
private:
    std::string name;
};

#endif