#ifndef __POLINOM_H__
#define __POLINOM_H__

#include<list>
#include"Monom.h"

class Polinom
{
	std::list<Monom> P; // место хранения мономов
	std::string Name;

	void recount(); // перезадает номер мономам после удаления/добавления новых мономов, объединяет мономы с одинаковым p !после сортировки!
	void sort(); // сортирует мономы по переменной p (показатели степени)
	void parsing(std::string s); // жопоболь

public:

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

	Polinom Ix(double C = 0);//C-const
	Polinom Iy(double C = 0);//C-const
	Polinom Iz(double C = 0);//C-const


	



};

#endif
