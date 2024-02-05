#include "../include/Zombie.h"

//Zombie* zombieHorde(int N, std::string name)
//{
//	Zombie* zombis = new Zombie[N];
//	for (int i = 0; i < N; ++i)
//	{
//		zombis[i] = Zombie(name);
//	}
//	return (zombis);
//}
Zombie* zombieHorde(int N, std::string name)
{
	Zombie* zombis = new Zombie[N];
	for (int i = 0; i < N; ++i)
	{
		zombis[i].setName(name);
	}
	return (zombis);
}