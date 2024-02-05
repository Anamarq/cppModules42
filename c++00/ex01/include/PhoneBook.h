#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include <string>
#include <iomanip>
#include <limits>
#include "Contact.h"
//#include "colors.h"
const int total = 8;

class PhoneBook {
private:
	Contact contacts[total];
	int numContacts;
public:
	PhoneBook() : numContacts(0) {}
	PhoneBook(Contact _contacts[total]) {
		for (int i = 0; i < total; i++) {
			contacts[i] = _contacts[i];
		}
	}
	~PhoneBook(){};
	void showContacts();
	void setContacts(int index, Contact newContact);
	void addUser(int index);
	//void showOneContact(int index);
	void loadContact(int numContacts);
};

#endif