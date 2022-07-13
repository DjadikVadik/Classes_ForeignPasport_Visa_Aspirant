#include "Student.h"

//конструкторы---------------------------------------------------------------------------------------------------------

inline Student::Student()
{
	surname = "_____";
	name = "_____";
	patronymic = "_____";
	birthday = "_____";
	address = "_____";
	telefon = "_____";
}

Student::Student(std::string surname) : Student() { set_surname(surname); }

Student::Student(std::string surname, std::string name) :Student(surname) { set_name(name); }

Student::Student(std::string surname, std::string name, std::string telefon) :Student(surname, name) { set_telefon(telefon); }

// конструктор копирования---------------------------------------------------------------------------------------------

Student::Student(const Student& other)
{
	surname = other.surname;
	name = other.name;
	patronymic = other.patronymic;
	birthday = other.birthday;
	address = other.address;
	telefon = other.telefon;

	size_ekz = other.size_ekz;
	size_zach = other.size_zach;
	size_kurs = other.size_kurs;

	ekzamen = new int[size_ekz];
	for (int i = 0; i < size_ekz; i++)
		ekzamen[i] = other.ekzamen[i];

	zacheti = new int[size_zach];
	for (int i = 0; i < size_zach; i++)
		zacheti[i] = other.zacheti[i];

	kursovie = new int[size_kurs];
	for (int i = 0; i < size_kurs; i++)
		kursovie[i] = other.kursovie[i];
}

// деструктор класса--------------------------------------------------------------------------------------------------------------------

inline Student::~Student()
{
	if (ekzamen != nullptr) { delete[] ekzamen; ekzamen = nullptr; }
	if (zacheti != nullptr) { delete[] zacheti; zacheti = nullptr; }
	if (kursovie != nullptr) { delete[] kursovie; kursovie = nullptr; }
}

// сеттеры------------------------------------------------------------------------------------------------------------------------------

inline void Student::set_surname(std::string surname)
{
	bool corekted = true;
	for (int i = 0; i < surname.length(); i++)
	{
		if ((surname[i] >= 'a' && surname[i] <= 'z') ||
			(surname[i] >= 'A' && surname[i] <= 'Z') ||
			(surname[i] >= 'а' && surname[i] <= 'я') ||
			(surname[i] >= 'А' && surname[i] <= 'Я'))
			continue;
		else corekted = false;
	}

	if (corekted) this->surname = surname;
	else throw std::exception("Surname is unsuitable!!!");
}

void Student::set_name(std::string name)
{
	bool corekted = true;
	for (int i = 0; i < name.length(); i++)
	{
		if ((name[i] >= 'a' && name[i] <= 'z') ||
			(name[i] >= 'A' && name[i] <= 'Z') ||
			(name[i] >= 'а' && name[i] <= 'я') ||
			(name[i] >= 'А' && name[i] <= 'Я'))
			continue;
		else corekted = false;
	}

	if (corekted) this->name = name;
	else throw std::exception("Name is unsuitable!!!");
}

void Student::set_patronymic(std::string patronymic)
{
	bool corekted = true;
	for (int i = 0; i < patronymic.length(); i++)
	{
		if ((patronymic[i] >= 'a' && patronymic[i] <= 'z') ||
			(patronymic[i] >= 'A' && patronymic[i] <= 'Z') ||
			(patronymic[i] >= 'а' && patronymic[i] <= 'я') ||
			(patronymic[i] >= 'А' && patronymic[i] <= 'Я'))
			continue;
		else corekted = false;
	}

	if (corekted) this->patronymic = patronymic;
	else throw std::exception("Patronymic is unsuitable!!!");
}

void Student::set_birthday(std::string birthday)
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

void Student::set_address(std::string address)
{
	this->address = address;
}

void Student::set_telefon(std::string telefon)
{
	bool corekted = true;
	for (int i = 0; i < telefon.length(); i++)
	{
		if ((telefon[i] >= '0' && telefon[i] <= '9') || telefon[i] == '.' || telefon[i] == '-') continue;
		else corekted = false;
	}

	if (corekted) this->telefon = telefon;
	else throw std::exception("Telefon is unsuitable!!!");
}

// геттеры--------------------------------------------------------------------------------------------------------------

std::string Student::get_surname() const
{
	return surname;
}

std::string Student::get_name() const
{
	return name;
}

std::string Student::get_patronymic() const
{
	return patronymic;
}

std::string Student::get_birthday() const
{
	return birthday;
}

std::string Student::get_address() const
{
	return address;
}

std::string Student::get_telefon() const
{
	return telefon;
}

// методы----------------------------------------------------------------------------------------------------------

void Student::AddEkzamen(int rate)
{
	int* temp = new int[size_ekz + 1];

	for (int i = 0; i < size_ekz; i++)
		temp[i] = ekzamen[i];

	temp[size_ekz] = rate;
	delete[] ekzamen;
	ekzamen = temp;
	size_ekz++;
}

void Student::AddZacheti(int rate)
{
	int* temp = new int[size_zach + 1];

	for (int i = 0; i < size_zach; i++)
		temp[i] = zacheti[i];

	temp[size_zach] = rate;
	delete[] zacheti;
	zacheti = temp;
	size_zach++;
}

void Student::AddKursovie(int rate)
{
	int* temp = new int[size_kurs + 1];

	for (int i = 0; i < size_kurs; i++)
		temp[i] = kursovie[i];

	temp[size_kurs] = rate;
	delete[] kursovie;
	kursovie = temp;
	size_kurs++;
}

void Student::set_info_student()
{
	std::string value;
	std::cout << "Введите фамилию студента : ";
	std::getline(std::cin, value);
	set_surname(value);

	std::cout << "Введите имя студента : ";
	std::getline(std::cin, value);
	set_name(value);

	std::cout << "Введите отчество студента : ";
	std::getline(std::cin, value);
	set_patronymic(value);

	std::cout << "Введите дату рождения студента цифрами : ";
	std::getline(std::cin, value);
	set_birthday(value);

	std::cout << "Введите адресс проживания студента : ";
	std::getline(std::cin, value);
	set_address(value);

	std::cout << "Введите телефон студента (только цифры) : ";
	std::getline(std::cin, value);
	set_telefon(value);
}

void Student::set_info_ocenki()
{
	std::cout << "Выбирите наименование работы:\n1 - экзамены\n2 - зачеты\n3 - курсовые\n";
	int n;
	std::cin >> n;

	if (n == 1)
	{
		std::cout << "Введите номер экзамена : ";
		int x;
		std::cin >> x;

		std::cout << "Введите оценку за экзамен (1 - 12) : ";
		int y;
		std::cin >> y;

		if (size_ekz > 0 && x <= size_ekz && x >= 1 && y <= 12 && y >= 1)
			this->ekzamen[x - 1] = y;

		else std::cout << "Вы ввели некоректные значения!!!\n";
	}

	else if (n == 2)
	{
		std::cout << "Введите номер зачета : ";
		int x;
		std::cin >> x;

		std::cout << "Введите оценку за зачет (1 - 12) : ";
		int y;
		std::cin >> y;

		if (size_zach > 0 && x <= size_zach && x >= 1 && y <= 12 && y >= 1)
			this->zacheti[x - 1] = y;

		else std::cout << "Вы ввели некоректные значения!!!\n";
	}

	else if (n == 3)
	{
		std::cout << "Введите номер курсовой работы : ";
		int x;
		std::cin >> x;

		std::cout << "Введите оценку за курсовую работу (1 - 12) : ";
		int y;
		std::cin >> y;

		if (size_kurs > 0 && x <= size_kurs && x >= 1 && y <= 12 && y >= 1)
			this->kursovie[x - 1] = y;

		else std::cout << "Вы ввели некоректные значения!!!\n";
	}

	else std::cout << "Вы ввели некоректные значения!!!\n";
}

void Student::print_info_student() const
{
	std::cout << "\nФамилия : \t" << surname << "\n";
	std::cout << "Имя : \t\t" << name << "\n";
	std::cout << "Отчество : \t" << patronymic << "\n";
	std::cout << "Дата рождения : " << birthday << "\n";
	std::cout << "Адресс : \t" << address << "\n";
	std::cout << "Телефон : \t" << telefon << "\n";
}

void Student::print_info_ocenki() const
{
	std::cout << "\nпорядковый номер:\t";

	for (int i = 1; i <= 5; i++)
		std::cout << i << "\t";

	std::cout << "\n\nоценки за экзамены:\t";

	for (int i = 0; i < size_ekz; i++)
		std::cout << ekzamen[i] << "\t";

	std::cout << "\n\nоценки за зачеты:\t";

	for (int i = 0; i < size_zach; i++)
		std::cout << zacheti[i] << "\t";

	std::cout << "\n\nоценки за курсовые:\t";

	for (int i = 0; i < size_kurs; i++)
		std::cout << kursovie[i] << "\t";

	std::cout << "\n\n";
}
