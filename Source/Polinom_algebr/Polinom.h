#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <list>
#include <math.h>
#include "Monom.h"

class Polinom
{
	std::list<Monom> P; // место хранения мономов
	static int ID_gen;
	int ID;

	void recount(); // перезадает номер мономам после удаления/добавления новых мономов, объединяет мономы с одинаковым p !после сортировки!
	void sort(); // сортирует мономы по переменной p (показатели степени)
	void parsing(std::string s); // жопоболь

public:

	Polinom(std::string s = "");
	Polinom(std::list<Monom> P1);
	Polinom(Monom M);
	~Polinom();

	std::list<Monom> GetPolinom();
	std::string GetPolinom_str();
	int GetID();

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

	double count(double x, double y, double z);
};

#endif
