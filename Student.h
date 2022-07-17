#pragma once
#include <iostream>
#include <string>

//  Реализовать класс Student, который содержит поля для хранения фамилии, 
//  имени, отчества, даты рождения, домашнего адреса, телефонного номера.
//  Также за каждым студентом закреплены 3 динамических массива оценок – 
//  зачёты, курсовые работы, экзамены.Обязательные методы : 2 - 3 версии 
//  конструктора с параметрами, геттеры и сеттеры для всех полей, 
//  показ всех данных о студенте.

class Student {
protected:

	std::string surname;
	std::string name;
	std::string patronymic;
	std::string birthday;
	std::string address;
	std::string telefon;

	int size_ekz = 0;
	int* ekzamen = nullptr;

	int size_zach = 0;
	int* zacheti = nullptr;

	int size_kurs = 0;
	int* kursovie = nullptr;

public:

	//конструкторы:

	Student();
	Student(std::string surname);
	Student(std::string surname, std::string name);
	Student(std::string surname, std::string name, std::string telefon);

	// конструктор копирования:

	Student(const Student& other);

	// деструктор класса:

	~Student();

	//сеттеры:

	void set_surname(std::string surname);
	void set_name(std::string name);
	void set_patronymic(std::string  patronymic);
	void set_birthday(std::string  birthday);
	void set_address(std::string  address);
	void set_telefon(std::string  telefon);

	// геттеры:

	std::string get_surname() const;
	std::string get_name()const;
	std::string get_patronymic()const;
	std::string get_birthday()const;
	std::string get_address()const;
	std::string get_telefon()const;

	// методы:

	void AddEkzamen(int rate);
	void AddZacheti(int rate);
	void AddKursovie(int rate);

	void set_info_student(); // метод заполнения информации о студенте
	void set_info_ocenki();  // метод изменения оценок студента

	void print_info_student() const;  // метод получения информации о студенте
	void print_info_ocenki() const;   // метод получения информации о оценках студента
};