#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(const std::string& _name);
	Character(const Character& other);
	~Character();
	Character& operator=(const Character& other);

	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	AMateria* materias[4];
	std::string name;
};

#endif