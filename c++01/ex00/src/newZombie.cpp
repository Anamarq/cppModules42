#include "../include/Zombie.h"
//Crea una zombi, dale un nombre, y devu�lvelo para que puedas usarlo fuera del
//alcance de la funci�n.
Zombie* newZombie(std::string name)
{
	return new Zombie(name);
}