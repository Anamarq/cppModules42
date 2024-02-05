
#include "../include/PhoneBook.h"

void writeContact(const std::string &text, int longi)
{
	if ((int)text.length() >= longi)
		std::cout << text.substr(0, longi - 1) << ".|";
	else
		std::cout << std::right << std::setw(longi) << text << "|";
}

void PhoneBook::loadContact(int numContacts)
{
	int index = 0;
	bool correctInput = false;
	do {
		std::cout << "Index of contact: ";
		if (std::cin >> index)
		{
			correctInput = true;
			if (index >= 0 && index < numContacts)
			{
				std::cout << "NAME: " << contacts[index].getFirstName() << std::endl;
				std::cout << "LAST NAME: " << contacts[index].getLastName() << std::endl;
				std::cout << "NICKNAME: " << contacts[index].getNick() << std::endl;
				std::cout << "PHONE NUMBER: " << contacts[index].getPhone() << std::endl;
				std::cout << "DARKEST SECRET: " << contacts[index].getSecret() << std::endl;
			}
			else
				std::cerr << "Invalid index" << std::endl;
			std::cin.clear(); 
			std::cin.ignore(); // Limpiar el buffer de entrada
		}
		else
		{
			correctInput = false;
			std::cin.clear(); // Restaurar el estado de std::cin después de un error
			//estamos utilizando std::cin.ignore() para eliminar todos los caracteres no válidos en el búfer de entrada hasta que se encuentre un carácter de nueva línea('\n').
			//Esto permite que el programa acepte una nueva entrada después de un error.
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada
			std::cerr << "Invalid input. Please enter a valid number." << std::endl;
		}
	} while (!correctInput || index < 0 || index >= numContacts);
}

void PhoneBook::showContacts()
{
	if (numContacts > 0)
	{
		const int longi = 10;
		std::cout << "   Index  |First Name|Last Name | Nickname |" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		for (int i = 0; i < numContacts; ++i)
		{
			// Imprimir cada campo con formato
			std::cout << std::right << std::setw(longi) << i << "|";
			writeContact(contacts[i].getFirstName(), longi);
			writeContact(contacts[i].getLastName(), longi);
			writeContact(contacts[i].getNick(), longi);
			std::cout << std::endl;
		}
		std::cout << "--------------------------------------------" << std::endl;
		loadContact(numContacts);
	}
	else
		std::cout << "Empty phone book!" << std::endl;
}

void PhoneBook::setContacts(int index, Contact newContact)
{
	contacts[index] = newContact;
}

std::string readInput(const std::string& text)
{
	std::string input;
	do {
		std::cout << text;
		getline(std::cin, input);
	} while (input.empty());
	return input;
}

void PhoneBook::addUser(int index)
{
	std::string name, lastName, nick, secret, phone;
	if (numContacts < total)
		++numContacts;
	name = readInput("NAME: ");
	lastName = readInput("LAST NAME: ");
	nick = readInput("NICKNAME: ");
	phone = readInput("PHONE NUMBER: ");
	secret = readInput("DARKEST SECRET: ");
	Contact contact(name, lastName, nick, phone, secret);
	setContacts(index, contact);
}
