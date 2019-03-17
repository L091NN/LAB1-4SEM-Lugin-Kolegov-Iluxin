#ifndef __POLINOM_H__
#define __POLINOM_H__

#include<list>
#include<math.h>
#include"Monom.h"

class Polinom
{
	std::list<Monom> P; // ����� �������� �������
	std::string Name; // name of polinom
	static int ID_gen;
	int ID;

	void recount(); // ���������� ����� ������� ����� ��������/���������� ����� �������, ���������� ������ � ���������� p !����� ����������!
	void sort(); // ��������� ������ �� ���������� p (���������� �������)
	void parsing(std::string s); // ��������

public:

	Polinom(std::string s = "", std::string Name = "NULL");
	Polinom(std::list<Monom> P1, std::string Name = "NULL");
	Polinom(Monom M, std::string Name = "NULL");
	~Polinom();

	std::string GetName();
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
