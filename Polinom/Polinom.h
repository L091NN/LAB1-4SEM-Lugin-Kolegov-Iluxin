#ifndef __POLINOM_H__
#define __POLINOM_H__

#include<list>
#include"Monom.h"

class Polinom
{
	std::list<Monom> P; // ����� �������� �������
	std::string Name;

	void recount(); // ���������� ����� ������� ����� ��������/���������� ����� �������, ���������� ������ � ���������� p !����� ����������!
	void sort(); // ��������� ������ �� ���������� p (���������� �������)
	void parsing(std::string s); // ��������

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
