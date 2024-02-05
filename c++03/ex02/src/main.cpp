#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
int main()
{
	ClapTrap clap1("kirby");
	clap1.attack("pikachu");
	clap1.takeDamage(3);
	clap1.beRepaired(2);
	ScavTrap clap2("pipo");
	clap2.attack("sonic");
	clap2.takeDamage(3);
	clap2.beRepaired(2);
	clap2.guardGate();
	FragTrap clap3("fragy");
	clap3.attack("mario bros");
	clap3.takeDamage(3);
	clap3.beRepaired(2);
	clap3.highFivesGuys();
	
}