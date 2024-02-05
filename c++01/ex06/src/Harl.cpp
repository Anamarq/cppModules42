#include "../include/Harl.h"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) 
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) 
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming foryears whereas you started working here since last month." << std::endl;
}

void Harl::error(void) 
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(){}

Harl::~Harl(){}

void    Harl::complain(std::string level)
{
    std::map<std::string, int> switchMap;
    switchMap["DEBUG"] = 0;
    switchMap["INFO"] = 1;
    switchMap["WARNING"] = 2;
    switchMap["ERROR"] = 3;
    if (switchMap.find(level) == switchMap.end()) {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }
    for (int i = switchMap[level]; i <= 3; ++i)
    {
        switch (i)
        {
        case 0:
            debug();
            break;
        case 1:
            info();
            break;
        case 2:
            warning();
            break;
        case 3:
            error();
            break;
        default:
            break;
        }
    }
}