#include "../include/Weapon.h"

Weapon::Weapon(){}
Weapon::~Weapon(){}
Weapon::Weapon(const std::string& _type) : type(_type) {}
const std::string& Weapon::getType()
{
	return type;
}
void Weapon::setType(const std::string& newType)
{
	type = newType;
}
