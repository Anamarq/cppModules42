#include "../include/AMateria.hpp"
AMateria::AMateria(){}
AMateria::AMateria(std::string const& type)
{
	this->type = type;
}
AMateria::AMateria(const AMateria& other)
{
	type = other.type;
}
AMateria::~AMateria(){}
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this == &other)
		return *this;
	type = other.type;
	return *this;
}
std::string const& AMateria::getType() const //Returns the materia type
{
	return type;
}
//AMateria* AMateria::clone() const
//{
//	//return new AMateria(*this);
//}

void AMateria::use(ICharacter& target)
{
	std::cout << "Used inexisting materia on " << target.getName() << std::endl;
}