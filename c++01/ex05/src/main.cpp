#include "../include/Harl.h"

int main()
{
    std::string opcion;
    std::cout << "Choose a complain (DEBUG, INFO, WARNING, ERROR): ";
    std::cin >> opcion;

    Harl harl;
    harl.complain(opcion);
    return 0;
}