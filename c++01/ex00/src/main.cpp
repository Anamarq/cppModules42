#include "../include/Zombie.h"
int main()
{
	Zombie zombi1("Putrefacto");
	zombi1.announce();

	Zombie *zombi2 = newZombie("Cerebroso");
	zombi2->announce();
	delete(zombi2);

	randomChump("Muertito Feliz");
}