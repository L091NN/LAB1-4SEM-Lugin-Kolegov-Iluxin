#ifndef __POLINOM_H__
#define __POLINOM_H__

#include<list>
#include"Monom.h"

class Polinom
{
	std::list<Monom> P; // ����� �������� �������
	std::string Name;

public:
	void recount(); // ���������� ����� ������� ����� ��������/���������� ����� �������, ���������� ������ � ���������� p !����� ����������!
	void sort(); // ��������� ������ �� ���������� p (���������� �������)

	void parsing(); // ��������

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
