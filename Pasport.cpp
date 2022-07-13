#include "Pasport.h"

Pasport::Pasport()
{
	surname = "_____";
	name = "_____";
	patronymic = "_____";
	birthday = "_____";
	address = "_____";
	issued_by = "_____";
    pasport_number = "_____";
}

Pasport::Pasport(std::string surname) : Pasport()
{
	set_surname(surname);
}

Pasport::Pasport(std::string surname, std::string name) : Pasport(surname)
{
	set_name(name);
}

Pasport::Pasport(std::string surname, std::string name, std::string patronymic) : Pasport(surname, name)
{
	set_patronymic(patronymic);
}

void Pasport::set_surname(std::string surname)
{
	bool corekted = true;
	for (int i = 0; i < surname.length(); i++)
	{
		if ((surname[i] >= 'a' && surname[i] <= 'z') ||
			(surname[i] >= 'A' && surname[i] <= 'Z') ||
			(surname[i] >= 'à' && surname[i] <= 'ÿ') ||
			(surname[i] >= 'À' && surname[i] <= 'ß'))
			continue;
		else corekted = false;
	}

	if (corekted) this->surname = surname;
	else throw std::exception("Surname is unsuitable!!!");
}

void Pasport::set_name(std::string name)
{
	bool corekted = true;
	for (int i = 0; i < name.length(); i++)
	{
		if ((name[i] >= 'a' && name[i] <= 'z') ||
			(name[i] >= 'A' && name[i] <= 'Z') ||
			(name[i] >= 'à' && name[i] <= 'ÿ') ||
			(name[i] >= 'À' && name[i] <= 'ß'))
			continue;
		else corekted = false;
	}

	if (corekted) this->name = name;
	else throw std::exception("Name is unsuitable!!!");
}

void Pasport::set_patronymic(std::string patronymic)
{
	bool corekted = true;
	for (int i = 0; i < patronymic.length(); i++)
	{
		if ((patronymic[i] >= 'a' && patronymic[i] <= 'z') ||
			(patronymic[i] >= 'A' && patronymic[i] <= 'Z') ||
			(patronymic[i] >= 'à' && patronymic[i] <= 'ÿ') ||
			(patronymic[i] >= 'À' && patronymic[i] <= 'ß'))
			continue;
		else corekted = false;
	}

	if (corekted) this->patronymic = patronymic;
	else throw std::exception("Patronymic is unsuitable!!!");
}

void Pasport::set_birthday(std::string birthday)
{
	bool corekted = true;
	for (int i = 0; i < birthday.length(); i++)
	{
		if ((birthday[i] >= '0' && birthday[i] <= '9') || birthday[i] == '.' || birthday[i] == '-') continue;
		else corekted = false;
	}

	if (corekted) this->birthday = birthday;
	else throw std::exception("Birthday is unsuitable!!!");
}

void Pasport::set_address(std::string address)
{
	this->address = address;
}

void Pasport::set_issued_by(std::string issued_by)
{
	this->issued_by = issued_by;
}

void Pasport::set_pasport_number(std::string pasport_number)
{
	this->pasport_number = pasport_number;
}

std::string Pasport::get_surname() { return surname; }

std::string Pasport::get_name() { return name; }

std::string Pasport::get_patronymic() { return patronymic; }

std::string Pasport::get_birthday() { return birthday; }

std::string Pasport::get_address() { return address; }

std::string Pasport::get_issued_by() { return issued_by; }

std::string Pasport::get_pasport_number() { return pasport_number; }