#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // Para exit() y EXIT_FAILURE

void replaceWords(const std::string& str1, const std::string& str2, const std::string& fich1, const std::string& fich2)
{
	std::ifstream entrada(fich1.c_str());
	if (!entrada.is_open()) {
		std::cerr << "The file could not be opened." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::ofstream salida(fich2.c_str());
	if (!salida.is_open()) {
		std::cerr << "The file could not be opened." << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	while (getline(entrada, line))
	{
		int pos = line.find(str1);
		while (pos != -1)
		{
			line.erase(pos, str1.length());
			line.insert(pos, str2);
			pos = line.find(str1);
		}
		salida << line << std::endl;
	}
	entrada.close();
	salida.close();
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "ERROR! Enter <archive name> <str1> <str2>" << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string fich1 = argv[1];
	std::string fich2 = fich1 + ".replace";
	
	replaceWords(argv[2], argv[3], fich1, fich2);

	std::cout << "Content has been successfully copied and replaced." << std::endl;
	return 0;
}
