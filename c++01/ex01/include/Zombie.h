#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
class Zombie{
public:
	Zombie(){}
	Zombie(const std::string& _name);
	~Zombie();
	void announce(void);
	void setName(const std::string& newName);
private:
	std::string name;
};
Zombie* zombieHorde(int N, std::string name);
#endif