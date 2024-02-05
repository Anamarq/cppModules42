#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	~MateriaSource();
	MateriaSource& operator=(const MateriaSource& other);

	void learnMateria(AMateria* materia);
	AMateria* createMateria(std::string const& type);
private:
	AMateria* materias[4];
};

#endif