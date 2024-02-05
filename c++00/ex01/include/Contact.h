#ifndef  CONTACT_H
#define CONTACT_H

#include<iostream>

class Contact {
public:
	Contact(){}
	Contact(std::string _firstName, std::string _lastName, std::string _nickname, std::string _phoneNumber, std::string _darkestSecret)
		:firstName(_firstName), lastName(_lastName), nickname(_nickname), phoneNumber(_phoneNumber), darkestSecret(_darkestSecret){}
	~Contact(){}
	std::string getFirstName();
	std::string getLastName();
	std::string getNick();
	std::string getPhone();
	std::string getSecret();
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif // ! CONTACT_H
