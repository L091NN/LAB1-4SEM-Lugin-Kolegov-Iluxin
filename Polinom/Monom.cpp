#include "Monom.h"

Monom::Monom(double k, int x, int y, int z)
{
	SetK(k);
	SetXpower(x);
	SetYpower(y);
	SetZpower(z);
}

Monom::~Monom()
{

}

void Monom::SetXpower(int x)
{
	if (x < 0 || x > 9)
	{
		throw("x incorrect");
	}
	p = p % 100 + x * 100;
}
void Monom::SetYpower(int y)
{
	if (y < 0 || y > 9)
	{
		throw("y incorrect");
	}
	p = p - ((p % 100) / 10) * 10 + y * 10;
}
void Monom::SetZpower(int z)
{
	if (z < 0 || z > 9)
	{
		throw("y incorrect");
	}
	p = p - (p % 100) % 10 + z;
}

int Monom::GetXpower()
{
	return p / 100;
}

int Monom::GetYpower()
{
	return (p % 100) / 10;
}

int Monom::GetZpower()
{
	return (p % 100) % 10;
}

void Monom::SetK(double k)
{
	if (k*k < 0.000000001)
	{
		p = 0;
	}
	this->k = k;
}

double Monom::GetK()
{
	return k;
}

void Monom::SetNum(int N)
{
	Number = N;
}

int Monom::GetNum()
{
	return Number;
}

bool Monom::operator==(const Monom &M) // ���������� ������ ���������� �������
{
	if (this->p == M.p)
	{
		return 1;
	}
	return 0;
}

bool Monom::operator!=(const Monom &M)
{
	return !(*this == M);
}

Monom& Monom::operator=(const Monom &M)// number don't change
{
	if (this != &M)
	{
		this->k = M.k;
		this->p = M.p;
	}
	return *this;
}

Monom Monom::operator+(const Monom &M) // ���������� ������ �����������
{
	Monom M1(*this);
	M1.k = this->k + M.k;
	return M1;
}