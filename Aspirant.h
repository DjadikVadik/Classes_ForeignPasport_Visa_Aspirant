#pragma once
#include "Student.h"

class Aspirant : public Student
{
	std::string PhD_topic;

public:
	Aspirant() : Student() {}
	Aspirant(std::string surname) : Student(surname) {}
	Aspirant(std::string surname, std::string name) : Student(surname, name) {}
	Aspirant(std::string surname, std::string name, std::string telefon) : Student(surname, name, telefon) {}

	void set_work_theme(std::string work_theme) { PhD_topic = work_theme; }
	std::string get_work_theme() { return PhD_topic; }
};

