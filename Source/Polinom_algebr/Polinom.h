#ifndef __POLINOM_H__
#define __POLINOM_H__

#include <list>
#include <math.h>


class Monom
{
	double k; // коэффицент монома
	int p; // показатели степени монома
	int Number; // номер в полиноме


public:
	Monom(double k = 1.0, int x = 0, int y = 0, int z = 0);
	~Monom();

	void SetXpower(int x);
	void SetYpower(int y);
	void SetZpower(int z);
	int GetXpower();
	int GetYpower();
	int GetZpower();
	void SetK(double k);
	double GetK();
	int Getp();

	void SetNum(int N);
	int GetNum();

	bool operator==(const Monom &M); // сравнивает только показатели степени
	bool operator!=(const Monom &M);
	Monom& operator=(const Monom &M);
	Monom operator+(const Monom &M); // складывает только коэффиценты
};







class Polinom
{
	std::list<Monom> P; // ìåñòî õðàíåíèÿ ìîíîìîâ
	std::string Name; // name of polinom
	static int ID_gen;
	int ID;

	void recount(); 
	void sort(); 
	void parsing(std::string s); 

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