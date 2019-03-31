#include "Polinom.h"
#include <string>

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

void Polinom::recount() // ïåðåçàäàåò íîìåð ìîíîìàì ïîñëå óäàëåíèÿ/äîáàâëåíèÿ íîâûõ ìîíîìîâ, îáúåäèíÿåò ìîíîìû ñ îäèíàêîâûì p !ïîñëå ñîðòèðîâêè!
{
	if (P.size() > 1)
	{
		auto J = P.end();
		J--;
		for (auto I = P.begin(); I != J;)
		{
			auto I1 = I++;
			if (I->Getp() == I1->Getp())
			{
				I1->SetK(I1->GetK() + I->GetK());
				P.erase(I);
				I = I1;
				J = P.end();
				J--;
			}
		}
		J = P.end();
		for (auto I = P.begin(); I != J;)
		{
			auto I1 = I++;
			if ((I1->GetK())*(I1->GetK()) < 0.00000000001)
			{
				P.erase(I1);
			}
		}
	}

	if (P.size() > 0)
	{
		int i = 0;
		for (auto I = P.begin(); I != P.end(); I++)
		{
			I->SetNum(i++);
		}
	}
}

void Polinom::sort() // ñîðòèðóåò ìîíîìû ïî ïåðåìåííîé p (ïîêàçàòåëè ñòåïåíè)
{
	for (int i = 1; i < P.size(); i++) // i - íîìåð ïðîõîäà
	{
		auto I = P.end();
		I--;
		for (auto J = P.begin(); J != I;) // âíóòðåííèé öèêë ïðîõîäà
		{
			auto J1 = J++;
			if (J1->Getp() < J->Getp())
			{
				P.insert(J1, *J);
				P.erase(J);
				J = J1;
				I = P.end();
				I--;
			}

		}
	}
}

void Polinom::parsing(string s) // æîïîáîëü
{
	bool ind_of_monom = 0; // monom begin?
	char check_error_double_symbol = char(1);  // COSTIL---------------------------------------------------
	bool now_k = 0; // now input koefficient?
	bool check_point = 0; // last symbol point?
	char ind_val = ' '; // now x, y or z?
	bool sign = 0; // 0 - plus, 1 - minus
	string buf_of_value = "000"; // s[0] - x s[1] - y s[2] - z
	string buf_of_k = ""; // koef
	Monom M = {}; // monom
	for (int i = 0; i < s.size(); i++) // bust of string
	{
		if (int(s[i]) >= 48 && int(s[i]) <= 57) // if s[i] - number
		{
			check_error_double_symbol = char(0); // COSTIL---------------------------------------------------
			if (!ind_of_monom) // if monom not begin
			{
				ind_of_monom = 1; // then monom begin
				now_k = 1;        // on koef (or value, but THIS ANOTHER STORY)
			}
			if (now_k) // now input koef?
			{
				buf_of_k += s[i];
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
		if (check_error_double_symbol == s[i])
		{
			throw("Error in " + to_string(i) + " symbol: double symbol");
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
				buf_of_value[1] = '1';
			}
			if (ind_val == 'z') // if last symbol z (not number)
			{
				buf_of_value[2] = '1';
			}
			ind_val = 'x'; // now x last symbol
		}
		if (s[i] == 'y' || s[i] == 'Y') // if s[i] - y or Y
		{
			if (buf_of_value[1] != '0') // if y was already 
			{
				throw ("ERROR in " + to_string(i) + " symbol: double input y");
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
				buf_of_value[0] = '1';
			}
			if (ind_val == 'z') // if last symbol z (not number)
			{
				buf_of_value[2] = '1';
			}
			ind_val = 'y'; // now y last symbol
		}
		if (s[i] == 'z' || s[i] == 'Z') // if s[i] - z or Z
		{
			if (buf_of_value[2] != '0') // if z was already 
			{
				throw ("ERROR in " + to_string(i) + " symbol: double input z");
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
				buf_of_value[0] = '1';
			}
			if (ind_val == 'y') // if last symbol y (not number)
			{
				buf_of_value[1] = '1';
			}
			ind_val = 'z'; // now z last symbol
		}
		if (s[i] == '+' || s[i] == '-')
		{
			if (i == 0)
			{
				if (s[i] == '-')
				{
					sign = 1;
				}
			}
			else
			{
				if (check_point)
				{
					check_point = 0;
				}
				if (ind_val == 'x') // if last symbol x (not number)
				{
					buf_of_value[0] = '1';
				}
				if (ind_val == 'y') // if last symbol y (not number)
				{
					buf_of_value[1] = '1';
				}
				if (ind_val == 'z') // if last symbol z (not number)
				{
					buf_of_value[2] = '1';
				}
				M.SetXpower(int(buf_of_value[0]) - 48);
				M.SetYpower(int(buf_of_value[1]) - 48);
				M.SetZpower(int(buf_of_value[2]) - 48);
				if (!sign)
				{
					M.SetK(stod(buf_of_k));
				}
				if (sign)
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
				if (s[i] == '-')
				{
					sign = 1;
				}
				if (s[i] == '+')
				{
					sign = 0;
				}
			}
		}
		if (i == s.size() - 1)
		{
			if ((int(s[i]) >= 48 && int(s[i]) <= 57) || s[i] == 'x' || s[i] == 'X' || s[i] == 'y' || s[i] == 'Y' || s[i] == 'z' || s[i] == 'Z')
			{

			}
			else
			{
				throw("Error in " + to_string(i) + " symbol: incorrect last symbol");
			}
			if (check_point)
			{
				check_point = 0;
			}
			if (ind_val == 'x') // if last symbol x (not number)
			{
				buf_of_value[0] = '1';
			}
			if (ind_val == 'y') // if last symbol y (not number)
			{
				buf_of_value[1] = '1';
			}
			if (ind_val == 'z') // if last symbol z (not number)
			{
				buf_of_value[2] = '1';
			}
			M.SetXpower(int(buf_of_value[0]) - 48);
			M.SetYpower(int(buf_of_value[1]) - 48);
			M.SetZpower(int(buf_of_value[2]) - 48);
			if (!sign)
			{
				M.SetK(stod(buf_of_k));
			}
			if (sign)
			{
				M.SetK(-stod(buf_of_k));
			}
			M.SetNum(P.size());
			P.push_back(M);
		}
		check_error_double_symbol = s[i];
	}
}

string Polinom::GetName()
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
	for (auto I = P.begin(); I != P.end();)
	{
		if (I->GetK() != 1.0 || I->Getp() == 0)
		{
			string buf = "";
			buf = to_string(I->GetK());
			buf.resize(buf.size() - 4);
			Res += buf;
		}
		if (I->GetXpower() > 0)
		{
			if (I->GetXpower() > 1)
			{
				Res += "(x^";
				Res += to_string(I->GetXpower());
				Res += ')';
			}
			else
			{
				Res += 'x';
			}
		}
		if (I->GetYpower() > 0)
		{
			if (I->GetYpower() > 1)
			{
				Res += "(y^";
				Res += to_string(I->GetYpower());
				Res += ')';
			}
			else
			{
				Res += 'y';
			}
		}
		if (I->GetZpower() > 0)
		{
			if (I->GetZpower() > 1)
			{
				Res += "(z^";
				Res += to_string(I->GetZpower());
				Res += ')';
			}
			else
			{
				Res += 'z';
			}
		}
		I++;
		if (I != P.end())
		{
			if (I->GetK() > 0)
			{
				Res += '+';
			}
		}
	}
	return Res;
}

int Polinom::GetID()
{
	return ID;
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
	Polinom PP(P);
	list<Monom> W = this->GetPolinom();
	list<Monom> D = PP.GetPolinom();
	string str_D = PP.GetPolinom_str();
	char val = '0';
	for (int sim = 0; sim < str_D.size(); sim++)
	{
		if (str_D[sim] == 'x' || str_D[sim] == 'X')
		{
			val = 'x';
			break;
		}
		if (str_D[sim] == 'y' || str_D[sim] == 'Y')
		{
			val = 'y';
			break;
		}
		if (str_D[sim] == 'z' || str_D[sim] == 'Z')
		{
			val = 'z';
			break;
		}
	}
	list<Monom> Res;
	Monom M0(0.0, 0, 0, 0);
	Res.push_back(M0);
	if (val == 'x')
	{
		list<Monom> W_begin = W;
		auto I1 = W.begin();
		auto I2 = D.begin();
		auto I3 = Res.begin();
		for (; W.begin()->GetXpower() >= D.begin()->GetXpower();)
		{
			I1 = W.begin();
			int x_now = W.begin()->GetXpower();
			for (; I1->GetXpower() == x_now;)
			{
				int RMPX = I1->GetXpower() - I2->GetXpower(); // Res monom power X 
				int RMPY = I1->GetYpower() - I2->GetYpower(); // Res monom power Y 
				int RMPZ = I1->GetZpower() - I2->GetZpower(); // Res monom power Z 
				double RMK = I1->GetK() / I2->GetK(); // Res monom koef 
				Monom RM(RMK, RMPX, RMPY, RMPZ);
				Res.push_back(RM);
				I1++;
			}
			Polinom P1(W);
			I3++;
			for (; I3 != Res.end();)
			{
				Polinom P2(*I3);
				for (; I2 != D.end();)
				{
					Polinom P3(*I2);
					P1 = P1 - (P2 * P3);
					I2++;
				}
				I2 = D.begin();
				I3++;
			}
			W = P1.GetPolinom();
			I3--;
			if (!W.size())
			{
				break;
			}
		}
		if (W.size())
		{
			if (W.begin()->GetXpower() == W_begin.begin()->GetXpower())
				if (W.begin()->GetK() == W_begin.begin()->GetK())
				{
					Polinom RES;
					return RES;
				}
		}
		Polinom PRES(Res);
		return PRES;
	}
	if (val == 'y')
	{
		// coming soon 
	}
	if (val == 'z')
	{
		// coming soon 
	}
	if (val == '0')
	{
		for (auto I = W.begin(); I != W.end(); I++)
		{
			I->SetK(I->GetK() / D.begin()->GetK());
		}
		Polinom RESP(W);
		return RESP;
	}
}

Polinom Polinom::operator%(const Polinom &P)
{
	Polinom PP(P);
	list<Monom> W = this->GetPolinom();
	list<Monom> D = PP.GetPolinom();
	string str_D = PP.GetPolinom_str();
	char val = '0';
	for (int sim = 0; sim < str_D.size(); sim++)
	{
		if (str_D[sim] == 'x' || str_D[sim] == 'X')
		{
			val = 'x';
			break;
		}
		if (str_D[sim] == 'y' || str_D[sim] == 'Y')
		{
			val = 'y';
			break;
		}
		if (str_D[sim] == 'z' || str_D[sim] == 'Z')
		{
			val = 'z';
			break;
		}
	}
	list<Monom> Res;
	Monom M0(0.0, 0, 0, 0);
	Res.push_back(M0);
	if (val == 'x')
	{
		list<Monom> W_begin = W;
		auto I1 = W.begin();
		auto I2 = D.begin();
		auto I3 = Res.begin();
		for (; W.begin()->GetXpower() >= D.begin()->GetXpower();)
		{
			I1 = W.begin();
			int x_now = W.begin()->GetXpower();
			for (; I1->GetXpower() == x_now;)
			{
				int RMPX = I1->GetXpower() - I2->GetXpower(); // Res monom power X 
				int RMPY = I1->GetYpower() - I2->GetYpower(); // Res monom power Y 
				int RMPZ = I1->GetZpower() - I2->GetZpower(); // Res monom power Z 
				double RMK = I1->GetK() / I2->GetK(); // Res monom koef 
				Monom RM(RMK, RMPX, RMPY, RMPZ);
				Res.push_back(RM);
				I1++;
			}
			Polinom P1(W);
			I3++;
			for (; I3 != Res.end();)
			{
				Polinom P2(*I3);
				for (; I2 != D.end();)
				{
					Polinom P3(*I2);
					P1 = P1 - (P2 * P3);
					I2++;
				}
				I2 = D.begin();
				I3++;
			}
			W = P1.GetPolinom();
			I3--;
			if (!W.size())
			{
				break;
			}
		}
		if (W.size())
		{
			if (W.begin()->GetXpower() == W_begin.begin()->GetXpower())
				if (W.begin()->GetK() == W_begin.begin()->GetK())
				{
					Polinom RES(W);
					return RES;
				}
		}
		Polinom PRES(W);
		return PRES;
	}
	if (val == 'y')
	{
		// coming soon 
	}
	if (val == 'z')
	{
		// coming soon 
	}
	if (val == '0')
	{
		Polinom RESP;
		return RESP;
	}
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
		else
		{
			I->SetK(0.0);
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
		else
		{
			I->SetK(0.0);
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
		else
		{
			I->SetK(0.0);
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

double Polinom::count(double x, double y, double z)
{
	double Res = 0.0;
	for (auto I = P.begin(); I != P.end(); I++)
	{
		double Mon = I->GetK();
		Mon *= pow(x, I->GetXpower());
		Mon *= pow(y, I->GetYpower());
		Mon *= pow(z, I->GetZpower());
		Res += Mon;
	}
	return Res;
}








Monom::Monom(double k, int x, int y, int z)
{
	this->k = 0.0;
	p = 0;
	Number = 0;
	SetXpower(x);
	SetYpower(y);
	SetZpower(z);
	SetK(k);
}

Monom::~Monom()
{

}

void Monom::SetXpower(int x)
{
	if (x < 0 || x > 9)
	{
		throw("x power incorrect");
	}
	p = p % 100 + x * 100;
}
void Monom::SetYpower(int y)
{
	if (y < 0 || y > 9)
	{
		throw("y power incorrect");
	}
	p = p - ((p % 100) / 10) * 10 + y * 10;
}
void Monom::SetZpower(int z)
{
	if (z < 0 || z > 9)
	{
		throw("z power incorrect");
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

int Monom::Getp()
{
	return p;
}

void Monom::SetNum(int N)
{
	Number = N;
}

int Monom::GetNum()
{
	return Number;
}

bool Monom::operator==(const Monom &M) // сравнивает только показатели степени
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

Monom Monom::operator+(const Monom &M) // складывает только коэффиценты
{
	if (this->p == M.p)
	{
		Monom M1(*this);
		M1.k = this->k + M.k;
		return M1;
	}
	throw("ERROR, powers not equal");
}