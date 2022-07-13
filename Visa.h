#pragma once
#include <iostream>

class Visa
{
	std::string cuntry;
	std::string date_start;
	std::string date_finish;

public:

	void set_cuntry(std::string cuntry) { this->cuntry = cuntry; }
	void set_date_start(std::string date_start) { this->date_start = date_start; }
	void set_date_finish(std::string date_finish) { date_finish = date_finish; }

	std::string get_cuntry() { return cuntry; }
	std::string get_date_start() { return date_start; }
	std::string get_date_finish() { return date_finish; }

	void show_visa()
	{
		std::cout << cuntry << " (";
		std::cout << date_start << " - ";
		std::cout << date_finish << ")\n";
	}

};

