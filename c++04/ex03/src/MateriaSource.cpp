
#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		materias[i] = NULL;
	}
}
MateriaSource::MateriaSource(const MateriaSource& other)
{
	*this = other;
}
MateriaSource::~MateriaSource(){}
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return *this;
	for (int i = 0; i < 4; ++i)
	{
		materias[i] = other.materias[i];
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i] == NULL)
		{
			materias[i] = materia;
			return;
		}
	}
}
AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return 0;
}