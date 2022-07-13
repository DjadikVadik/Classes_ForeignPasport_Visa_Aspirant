#pragma once
#include "Pasport.h"
#include "Visa.h"
#include <vector>

class ForeignPasport : public Pasport
{
	std::vector<Visa> visas;
	std::string patronymic;

public:

	ForeignPasport() : Pasport() {}
	ForeignPasport(std::string surname) : Pasport(surname) {}
	ForeignPasport(std::string surname, std::string name) : Pasport(surname, name) {}

	void set_new_visa(std::string cuntry, std::string date_start, std::string date_finish)
	{
		Visa vs;
		vs.set_cuntry(cuntry);
		vs.set_date_start(date_start);
		vs.set_date_finish(date_finish);
		visas.push_back(vs);
	}

	void show_visas()
	{
		for (auto i : visas)
			i.show_visa();
		std::cout << "\n";
	}
};
