#include "../include/Zombie.h"
void    randomChump(std::string name)
{
	Zombie zombi(name);
	zombi.announce();
}