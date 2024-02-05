#include "../include/Zombie.h"
//Crea una zombi, dale un nombre, y devuélvelo para que puedas usarlo fuera del
//alcance de la función.
Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}