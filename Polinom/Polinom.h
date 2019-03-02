#ifndef __POLINOM_H__
#define __POLINOM_H__

#include<list>
#include"Monom.h"

class Polinom
{
	std::list<Monom> P; // место хранения мономов
	std::string Name;

public:
	void recount(); // перезадает номер мономам после удаления/добавления новых мономов, объединяет мономы с одинаковым p !после сортировки!
	void sort(); // сортирует мономы по переменной p (показатели степени)

	void parsing(); // жопоболь

	Polinom(std::string s);
	Polinom(std::list<Monom> P1);
	Polinom(Monom M);
	~Polinom();

	std::string GetName();

	Polinom& operator=(const Polinom &P);
	Polinom operator+(const Polinom &P);
	Polinom operator-(const Polinom &P);
	Polinom operator*(const Polinom &P);
	Polinom operator/(const Polinom &P);
	Polinom operator%(const Polinom &P);
	
	Polinom dx();
	Polinom dy();
	Polinom dz();

	



};

#endif
