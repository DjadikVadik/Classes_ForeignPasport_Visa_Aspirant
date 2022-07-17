#pragma once

#include <iostream>

class Pasport
{
protected:
	std::string surname;
	std::string name;
	std::string patronymic;
	std::string birthday;
	std::string address;
	std::string issued_by;
	std::string pasport_number;

public:

	Pasport();
	Pasport(std::string surname);
	Pasport(std::string surname, std::string name);
	Pasport(std::string surname, std::string name, std::string patronymic);

	void set_surname(std::string surname);
	void set_name(std::string name);
	void set_patronymic(std::string patronymic);
	void set_birthday(std::string birthday);
	void set_address(std::string address);
	void set_issued_by(std::string issued_by);
	void set_pasport_number(std::string pasport_number);

	std::string get_surname();
	std::string get_name();
	std::string get_patronymic();
	std::string get_birthday();
	std::string get_address();
	std::string get_issued_by();
	std::string get_pasport_number();
};

