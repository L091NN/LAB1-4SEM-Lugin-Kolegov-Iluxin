#include"Polinom.h"
#include<string>

using namespace std;

int Polinom::ID_gen = 1;

Polinom::Polinom(string s, string Name)
{
	parsing(s);
	sort();
	recount();
	this->Name = Name;
	ID = ID_gen++;
}

Polinom::Polinom(list<Monom> P1, string Name)
{
	P = P1;
	sort();
	recount();
	this->Name = Name;
	ID = ID_gen++;
}

Polinom::Polinom(Monom M, string Name)
{
	P.push_back(M);
	this->Name = Name;
	ID = ID_gen++;
}

Polinom::~Polinom()
{

}

void Polinom::recount() // ���������� ����� ������� ����� ��������/���������� ����� �������, ���������� ������ � ���������� p !����� ����������!
{
	for (auto I = P.begin(); I != --P.end();)
	{
		auto I1 = I++;
		if (I->Getp() == I1->Getp())
		{
			I1->SetK(I1->GetK() + I->GetK());
			P.erase(I);
			I = I1;
			I++;
		}
	}
	int i = 0;
	for (auto I = P.begin(); I != P.end(); I++)
	{
		I->SetNum(i++);
	}
}

void Polinom::sort() // ��������� ������ �� ���������� p (���������� �������)
{
	for (int i = 0; i < P.size() - 1; i++) // i - ����� �������
	{
		for (auto J = P.begin(); J != --P.end();) // ���������� ���� �������
		{
			auto J1 = J++;
			if (J1->Getp() < J->Getp())
			{
				P.insert(J1, *J);
				P.erase(J);
			}
		}
	}
}

void Polinom::parsing(string s) // ��������
{
	bool ind_of_monom = 0; // monom begin?
	bool now_k = 0; // now input koefficient?
	bool check_point = 0; // last symbol point?
	char ind_val = ' '; // now x, y or z?
	string buf_of_value = "000"; // s[0] - x s[1] - y s[2] - z
	string buf_of_k = ""; // koef
	Monom M = {}; // monom
	for (int i = 0; i < s.size(); i++) // bust of string
	{
		if (int(s[i]) >= 48 && int(s[i]) <= 57) // if s[i] - number
		{
			if (!ind_of_monom) // if monom not begin
			{
				ind_of_monom = 1; // then monom begin
				now_k = 1;        // on koef (or value, but THIS ANOTHER STORY)
			}
			if (now_k) // now input koef?
			{
				buf_of_k += s[i];
				if (check_point)
				{
					check_point = 0;
				}
			}
			if (ind_val == 'x') // last symbol x?(or x^)
			{
				buf_of_value[0] = s[i];
				ind_val = ' ';
			}
			if (ind_val == 'y') // last symbol y?(or y^)
			{
				buf_of_value[1] = s[i];
				ind_val = ' ';
			}
			if (ind_val == 'z') // last symbol z?(or z^)
			{
				buf_of_value[2] = s[i];
				ind_val = ' ';
			}

		}
		if (s[i] == '.') // if s[i] - point
		{
			if (check_point) // the point was already
			{
				throw ("ERROR in " + to_string(i) + " symbol: double point");
			}
			if (now_k) // if point in koef then norm
			{
				buf_of_k += '.';
				check_point = 1;
			}
			else // if point in otherwheres then abnormally
			{
				throw ("ERROR in " + to_string(i) + " symbol: incorrect point");
			}
		}
		if (s[i] == 'x' || s[i] == 'X') // if s[i] - x or X
		{
			if (buf_of_value[0] != '0') // if x was already 
			{
				throw ("ERROR in " + to_string(i) + " symbol: double input x");
			}
			if (check_point)
			{
				throw ("ERROR in " + to_string(i) + " symbol: incorrect point");
			}
			if (!ind_of_monom)
			{
				ind_of_monom = 1;
				buf_of_k = "1.0";
			}
			if (now_k)
			{
				now_k = 0;
			}
			if (ind_val == 'y') // if last symbol y (not number)
			{
				buf_of_value[1] = 1;
			}
			if (ind_val == 'z') // if last symbol z (not number)
			{
				buf_of_value[2] = 1;
			}
			ind_val = 'x'; // now x last symbol
		}
		if (s[i] == 'y' || s[i] == 'Y') // if s[i] - y or Y
		{
			if (buf_of_value[1] != '0') // if y was already 
			{
				throw ("ERROR in " + to_string(i) + " symbol: double input y");
			}
			if (check_point)
			{
				throw ("ERROR in " + to_string(i) + " symbol: incorrect point");
			}
			if (!ind_of_monom)
			{
				ind_of_monom = 1;
				buf_of_k = "1.0";
			}
			if (now_k)
			{
				now_k = 0;
			}
			if (ind_val == 'x') // if last symbol x (not number)
			{
				buf_of_value[0] = 1;
			}
			if (ind_val == 'z') // if last symbol z (not number)
			{
				buf_of_value[2] = 1;
			}
			ind_val = 'y'; // now y last symbol
		}
		if (s[i] == 'z' || s[i] == 'Z') // if s[i] - z or Z
		{
			if (buf_of_value[2] != '0') // if z was already 
			{
				throw ("ERROR in " + to_string(i) + " symbol: double input z");
			}
			if (check_point)
			{
				throw ("ERROR in " + to_string(i) + " symbol: incorrect point");
			}
			if (!ind_of_monom)
			{
				ind_of_monom = 1;
				buf_of_k = "1.0";
			}
			if (now_k)
			{
				now_k = 0;
			}
			if (ind_val == 'x') // if last symbol x (not number)
			{
				buf_of_value[0] = 1;
			}
			if (ind_val == 'y') // if last symbol y (not number)
			{
				buf_of_value[1] = 1;
			}
			ind_val = 'z'; // now z last symbol
		}
		if (s[i] == '+' || s[i] == '-')
		{
			M.SetXpower(int(buf_of_value[0]) - 48);
			M.SetYpower(int(buf_of_value[1]) - 48);
			M.SetZpower(int(buf_of_value[2]) - 48);
			if (s[i] == '+')
			{
				M.SetK(stod(buf_of_k));
			}
			if (s[i] == '-')
			{
				M.SetK(-stod(buf_of_k));
			}
			M.SetNum(P.size());
			P.push_back(M);
			M = {};
			buf_of_k = {};
			buf_of_value = "000";
			ind_of_monom = 0;
			ind_val = ' ';
		}
	}
}

std::string Polinom::GetName()
{
	return Name;
}

list<Monom> Polinom::GetPolinom()
{
	return P;
}
string Polinom::GetPolinom_str()
{
	string Res = "";
	for (auto I = P.begin(); I != P.end(); I++)
	{
		string buf = "";

	}
}

Polinom& Polinom::operator=(const Polinom &P)
{
	if (this != &P)
	{
		this->P = P.P;
		this->Name = P.Name;
	}
	return *this;
}

Polinom Polinom::operator+(const Polinom &P)
{
	Polinom Res;
	for (auto I = P.P.begin(); I != P.P.end(); I++)
	{
		Res.P.push_back(*I);
	}
	for (auto I = this->P.begin(); I != this->P.end(); I++)
	{
		Res.P.push_back(*I);
	}
	Res.sort();
	Res.recount();
	return Res;
}

Polinom Polinom::operator-(const Polinom &P)
{
	Polinom Res;
	for (auto I = P.P.begin(); I != P.P.end(); I++)
	{
		Res.P.push_back(*I);
	}
	for (auto I = Res.P.begin(); I != Res.P.end(); I++)
	{
		I->SetK(-I->GetK());
	}
	for (auto I = this->P.begin(); I != this->P.end(); I++)
	{
		Res.P.push_back(*I);
	}
	Res.sort();
	Res.recount();
	return Res;
}

Polinom Polinom::operator*(const Polinom &P)
{
	Polinom Res;
	for (auto I = this->P.begin(); I != this->P.end(); I++)
	{
		for (auto J = P.P.begin(); J != P.P.end(); J++)
		{
			Monom M(*J);
			Monom ResM(I->GetK() * M.GetK(), I->GetXpower() + M.GetXpower(), I->GetYpower() + M.GetYpower(), I->GetZpower() + M.GetZpower());
			Res.P.push_back(ResM);
		}
	}
	Res.sort();
	Res.recount();
	return Res;
}

Polinom Polinom::operator/(const Polinom &P)
{
	return *this;
}

Polinom Polinom::operator%(const Polinom &P)
{
	return *this;
}

Polinom Polinom::dx()
{
	Polinom Res;
	for (auto I = this->P.begin(); I != P.end(); I++)
	{
		if (I->GetXpower() != 0)
		{
			Monom M(*I);
			M.SetK(M.GetK() * M.GetXpower());
			M.SetXpower(M.GetXpower() - 1);
			Res.P.push_back(M);
		}
	}
	Res.sort();
	Res.recount();
	return Res;
}

Polinom Polinom::dy()
{
	Polinom Res;
	for (auto I = this->P.begin(); I != P.end(); I++)
	{
		if (I->GetYpower() != 0)
		{
			Monom M(*I);
			M.SetK(M.GetK() * M.GetYpower());
			M.SetYpower(M.GetYpower() - 1);
			Res.P.push_back(M);
		}
	}
	Res.sort();
	Res.recount();
	return Res;
}

Polinom Polinom::dz()
{
	Polinom Res;
	for (auto I = this->P.begin(); I != P.end(); I++)
	{
		if (I->GetZpower() != 0)
		{
			Monom M(*I);
			M.SetK(M.GetK() * M.GetZpower());
			M.SetZpower(M.GetZpower() - 1);
			Res.P.push_back(M);
		}
	}
	Res.sort();
	Res.recount();
	return Res;
}

Polinom Polinom::Ix(double C)//C-const
{
	Polinom Res;
	for (auto I = this->P.begin(); I != P.end(); I++)
	{
		Monom M(*I);
		M.SetXpower(M.GetXpower() + 1);
		M.SetK(M.GetK() / M.GetXpower());
		Res.P.push_back(M);
	}
	Monom M(C, 0, 0, 0);
	Res.P.push_back(M);
	Res.sort();
	Res.recount();
	return Res;
}
Polinom Polinom::Iy(double C)//C-const
{
	Polinom Res;
	for (auto I = this->P.begin(); I != P.end(); I++)
	{
		Monom M(*I);
		M.SetYpower(M.GetYpower() + 1);
		M.SetK(M.GetK() / M.GetYpower());
		Res.P.push_back(M);
	}
	Monom M(C, 0, 0, 0);
	Res.P.push_back(M);
	Res.sort();
	Res.recount();
	return Res;
}
Polinom Polinom::Iz(double C)//C-const
{
	Polinom Res;
	for (auto I = this->P.begin(); I != P.end(); I++)
	{
		Monom M(*I);
		M.SetZpower(M.GetZpower() + 1);
		M.SetK(M.GetK() / M.GetZpower());
		Res.P.push_back(M);
	}
	Monom M(C, 0, 0, 0);
	Res.P.push_back(M);
	Res.sort();
	Res.recount();
	return Res;
}