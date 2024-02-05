#include "../include/Harl.h"

void Harl::debug(void)
{
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) 
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) 
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void Harl::error(void) 
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(){}

Harl::~Harl(){}

void    Harl::complain(std::string level)
{
    /*void(Harl:: * ptr)() = &Harl::debug;
    (harl.*ptr)();*/
    std::map<std::string, void (Harl::*)()> funcionMap;
    funcionMap["DEBUG"] = &Harl::debug;
    funcionMap["INFO"] = &Harl::info;
    funcionMap["WARNING"] = &Harl::warning;
    funcionMap["ERROR"] = &Harl::error;

    // Verificar si la opción está en el mapa y llamar a la función miembro correspondiente.
    if (funcionMap.find(level) != funcionMap.end()) {
        (this->*(funcionMap[level]))();
    }
    else {
        std::cout << "Invalid option." << std::endl;
    }
}