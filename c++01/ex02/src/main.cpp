#include <iostream>
int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Dirección de memoria del string original: " << &str << std::endl;
	std::cout << "Dirección de memoria del stringPTR: " << stringPTR << std::endl;
	std::cout << "Dirección de memoria del stringREF: " << &stringREF << std::endl;

	std::cout << "Valor del string original: " << str << std::endl;
	std::cout << "Valor apuntado por stringPTR: " << *stringPTR << std::endl;
	std::cout << "Valor apuntado por stringREF: " << stringREF << std::endl;
}