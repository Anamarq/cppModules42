#include "../include/PhoneBook.h"

int main()
{
	std::cout << "Welcolme to the most xula phone book!" << std::endl;
	std::cout << "ADD: Add new contact" << std::endl;
	std::cout << "SEARCH: search a contact" << std::endl;
	std::cout << "EXIT: exit the phone book" << std::endl;
	std::string option;
	int index = 0;
	PhoneBook phoneBook;
	do{
		std::cout << "Enter an option: ";
		if (!getline(std::cin, option))
			break;
		if (option.empty())
			continue;
		if (option == "ADD")
		{
			if (index == total)
				index = 0;
			phoneBook.addUser(index);
			++index;
		}
		else if (option == "SEARCH")
			phoneBook.showContacts();
		else if(option != "EXIT")
			std::cerr << "Invalid option. Try again"  << std::endl;
	} while (option != "EXIT");
	std::cout << "Closing phone book! See u next time" << std::endl;
	return 0;
}