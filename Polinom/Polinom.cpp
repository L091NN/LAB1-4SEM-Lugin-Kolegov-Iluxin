#include"Polinom.h"

using namespace std;

Polinom::Polinom(string s)
{

}

Polinom::Polinom(list<Monom> P1)
{

}

Polinom::Polinom(Monom M)
{

}

Polinom::~Polinom()
{

}

void Polinom::recount() // перезадает номер мономам после удаления/добавления новых мономов, объединяет мономы с одинаковым p !после сортировки!
{

}

void Polinom::sort() // сортирует мономы по переменной p (показатели степени)
{

}

void Polinom::parsing(string s) // жопоболь
{
	bool ind_of_monom = 0;
	bool ind_of_value = 0;
	string bufxyz;
	string bufnum;
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case 'x':
		{

		}
		case 'y':
		{

		}
		case 'z':
		{

		}
		case '+':
		{

		}
		case '-':
		{

		}
		case '0':
		{

		}
		case '1':
		{

		}
		case '2':
		{

		}
		case '3':
		{

		}
		case '4':
		{

		}
		case '5':
		{

		}
		case '6':
		{

		}
		case '7':
		{

		}
		case '8':
		{

		}
		case '9':
		{

		}
		default:
			break;
		}
	}
}

std::string Polinom::GetName()
{

}

Polinom& Polinom::operator=(const Polinom &P)
{

}

Polinom Polinom::operator+(const Polinom &P)
{

}

Polinom Polinom::operator-(const Polinom &P)
{

}

Polinom Polinom::operator*(const Polinom &P)
{

}

Polinom Polinom::operator/(const Polinom &P)
{

}

Polinom Polinom::operator%(const Polinom &P)
{

}

Polinom Polinom::dx()
{

}

Polinom Polinom::dy()
{

}

Polinom Polinom::dz()
{

}

Polinom Polinom::Ix(double C)//C-const
{

}
Polinom Polinom::Iy(double C)//C-const
{

}
Polinom Polinom::Iz(double C)//C-const
{

}