#include "../include/Character.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++) {
        materias[i] = NULL;
    }
}
Character::Character(const std::string& _name) : name(_name)
{
    for (int i = 0; i < 4; i++) {
        materias[i] = NULL;
    }
}
Character::Character(const Character& other)
{
    *this = other;
}
Character::~Character(){}
Character& Character::operator=(const Character& other)
{
    if (this == &other)
        return *this;
    name = other.name;
    for (int i = 0; i < 4; ++i)
        materias[i] = other.materias[i];
    return *this;
}

std::string const& Character::getName() const
{
    return name;
}
void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
    {
        if (materias[i] == NULL)
        {
            materias[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx)
{
    if (idx < 0 && idx >= 4)
        return;
    if (materias[idx] == NULL)
        return;
    materias[idx] = NULL;
}
void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4)
        return;
    if (materias[idx] != NULL)
    {
        materias[idx]->use(target);
    }
}