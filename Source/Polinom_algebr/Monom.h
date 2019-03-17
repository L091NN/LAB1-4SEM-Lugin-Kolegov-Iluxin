#ifndef __MONOM_H__
#define __MONOM_H__

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

#endif
