#include "Polinom.h";
#include "tables.cpp"
#include <stack>
#include <time.h>

ArrayTable<std::string, std::string> at;
ListTable<std::string, std::string> lt;
SortedTable<std::string, std::string> st(1000);
TreeTable<std::string, std::string> tt;
HashTable<std::string, std::string> ht(1000);
HashTableList<std::string, std::string> htl(1000);


void Insert();
void Find();
void All();
void Delete();
void plus();
void minus();
void mult();
void div();
void mod();
void dx();
void dy();
void dz();
void Ix();
void Iy();
void Iz();
void count();
void calculate();


int main(int argc, char** argv) 
{
	std::string command;	
	std::cout << "USER>";
	std::getline(std::cin, command);
	while (command != "close")
	{
		if (command == "insert")
		{
			Insert();
		}
		if (command == "find")
		{
			Find();
		}
		if (command == "all")
		{
			All();
		}
		if (command == "delete")
		{
			Delete();
		}
		if (command == "plus")
		{
			plus();
		}
		if (command == "minus")
		{
			minus();
		}
		if (command == "mult")
		{
			mult();
		}
		if (command == "div")
		{
			div();
		}
		if (command == "mod")
		{
			mod();
		}
		if (command == "dx")
		{
			dx();
		}
		if (command == "dy")
		{
			dy();
		}
		if (command == "dz")
		{
			dz();
		}
		if (command == "Ix")
		{
			Ix();
		}
		if (command == "Iy")
		{
			Iy();
		}
		if (command == "Iz")
		{
			Iz();
		}
		if (command == "count")
		{
			count();
		}
		if (command == "calculate")
		{
			calculate();
		}

		std::cout << "USER>";
		std::getline(std::cin, command);
	}
}

void Insert()
{
	std::string name;
	std::string pol;

	std::cout << "Name: \n";
	std::getline(std::cin, name);

	std::cout << "Polynom: \n";
	std::getline(std::cin, pol);

	Polinom P(pol);
	pol = P.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	at.Insert(tr);
	lt.Insert(tr);
	st.Insert(tr);
	tt.Insert(tr);
	ht.Insert(tr);
	htl.Insert(tr);
}

void Find()
{
	std::string key;
	TableRecord<std::string, std::string> tr;

	std::cout << "Key: ";
	std::getline(std::cin, key);

	std::cout << "ArrayTable\n";
	if (at.Find(key, &tr))
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	else
		std::cout << "None\n";
	std::cout << "------------------------\n\n";


	std::cout << "SortedTable\n";
	if (st.Find(key, &tr))
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	else
		std::cout << "None\n";
	std::cout << "------------------------\n\n";

	std::cout << "ListTable\n";
	if (lt.Find(key, &tr))
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	else
		std::cout << "None\n";
	std::cout << "------------------------\n\n";

	std::cout << "TreeTable\n";
	if (tt.Find(key, &tr))
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	else
		std::cout << "None\n";
	std::cout << "------------------------\n\n";

	std::cout << "HashTable\n";
	if (ht.Find(key, &tr))
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	else
		std::cout << "None\n";
	std::cout << "------------------------\n\n";

	std::cout << "HashTableList\n";
	if (htl.Find(key, &tr))
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	else
		std::cout << "None\n";
	std::cout << "------------------------\n\n";
}

void All()
{
	std::cout << "ArrayTable\n";
	for (auto tr : at.GetAll())
	{
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	}
	std::cout << "------------------------\n\n";


	std::cout << "SortedTable\n";
	for (auto tr : st.GetAll())
	{
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	}
	std::cout << "------------------------\n\n";

	std::cout << "ListTable\n";
	for (auto tr : lt.GetAll())
	{
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	}
	std::cout << "------------------------\n\n";

	std::cout << "TreeTable\n";
	for (auto tr : tt.GetAll())
	{
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	}
	std::cout << "------------------------\n\n";

	std::cout << "HashTable\n";
	for (auto tr : ht.GetAll())
	{
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	}
	std::cout << "------------------------\n\n";

	std::cout << "HashTableList\n";
	for (auto tr : htl.GetAll())
	{
		std::cout << "\t" << tr.key + "\t|\t" + tr.data + "\n";
	}
	std::cout << "------------------------\n\n";
}

void Delete()
{
	std::string key;
	std::string table;

	std::cout << "Key: ";
	std::getline(std::cin, key);
	std::cout << "Table name: ";
	std::getline(std::cin, table);	

	if (table == "at")
	{
		at.Delete(key);
	}
	if (table == "st")
	{
		st.Delete(key);
	}
	if (table == "lt")
	{
		lt.Delete(key);
	}
	if (table == "ht")
	{
		ht.Delete(key);
	}
	if (table == "tt")
	{
		tt.Delete(key);
	}
	if (table == "htl")
	{
		htl.Delete(key);
	}
}

void plus()
{
	std::string name;
	std::string pol;
	std::string table;

	std::cout << "Polynom 1: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Polynom 2: \n";
	std::getline(std::cin, pol);
	Polinom P2(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	Polinom P3((P1 + P2).GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P3.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void minus()
{
	std::string name;
	std::string pol;
	std::string table;

	std::cout << "Polynom 1: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Polynom 2: \n";
	std::getline(std::cin, pol);
	Polinom P2(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	Polinom P3((P1 - P2).GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P3.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void mult()
{
	std::string name;
	std::string pol;
	std::string table;

	std::cout << "Polynom 1: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Polynom 2: \n";
	std::getline(std::cin, pol);
	Polinom P2(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	Polinom P3((P1 * P2).GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P3.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void div() // only on x
{
	std::string name;
	std::string pol;
	std::string table;

	std::cout << "Polynom 1: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Polynom 2: \n";
	std::getline(std::cin, pol);
	Polinom P2(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	Polinom P3((P1 / P2).GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P3.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void mod() // only on x
{
	std::string name;
	std::string pol;
	std::string table;

	std::cout << "Polynom 1: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Polynom 2: \n";
	std::getline(std::cin, pol);
	Polinom P2(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	Polinom P3((P1 % P2).GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P3.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void dx()
{
	std::string name;
	std::string pol;
	std::string table;

	std::cout << "Polynom: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	Polinom P2(P1.dx().GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P2.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void dy()
{
	std::string name;
	std::string pol;
	std::string table;

	std::cout << "Polynom: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	Polinom P2(P1.dy().GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P2.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void dz()
{
	std::string name;
	std::string pol;
	std::string table;

	std::cout << "Polynom: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	Polinom P2(P1.dz().GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P2.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void Ix()
{
	std::string name;
	std::string pol;
	std::string table;
	double C;

	std::cout << "Polynom: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	std::cout << "value of const: \n";
	std::getline(std::cin, name);
	C = std::stod(name);

	Polinom P2(P1.Ix(C).GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P2.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void Iy()
{
	std::string name;
	std::string pol;
	std::string table;
	double C;

	std::cout << "Polynom: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	std::cout << "value of const: \n";
	std::getline(std::cin, name);
	C = std::stod(name);

	Polinom P2(P1.Iy(C).GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P2.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void Iz()
{
	std::string name;
	std::string pol;
	std::string table;
	double C;

	std::cout << "Polynom: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "Name of new polinom: \n";
	std::getline(std::cin, name);

	std::cout << "value of const: \n";
	std::getline(std::cin, name);
	C = std::stod(name);

	Polinom P2(P1.Iz(C).GetPolinom_str(), name);

	std::cout << "Table name: ";
	std::getline(std::cin, table);

	pol = P2.GetPolinom_str();
	TableRecord<std::string, std::string> tr;
	tr.key = name;
	tr.data = pol;

	if (table == "at")
	{
		at.Insert(tr);
	}
	if (table == "st")
	{
		st.Insert(tr);
	}
	if (table == "lt")
	{
		lt.Insert(tr);
	}
	if (table == "ht")
	{
		ht.Insert(tr);
	}
	if (table == "tt")
	{
		tt.Insert(tr);
	}
	if (table == "htl")
	{
		htl.Insert(tr);
	}

}

void count()
{
	std::string name;
	std::string pol;
	std::string table;
	double X;
	double Y;
	double Z;

	std::cout << "Polynom: \n";
	std::getline(std::cin, pol);
	Polinom P1(pol);
	pol = "";

	std::cout << "value of x: \n";
	std::getline(std::cin, name);
	X = std::stod(name);
	name = "";

	std::cout << "value of y: \n";
	std::getline(std::cin, name);
	Y = std::stod(name);
	name = "";

	std::cout << "value of z: \n";
	std::getline(std::cin, name);
	Z = std::stod(name);
	name = "";

	std::cout << "Count in (" << X << ',' << Y << ',' << Z << ") equals: " << std::to_string(P1.count(X, Y, Z)) << std::endl;

}

std::string ToPostfix(std::string localInfix, std::string infix = "")
{
	bool top = false;
	if (localInfix == "...")
	{
		top = true;
		localInfix = infix;


		int i;
		while ((i = localInfix.find(' ')) != std::string::npos)
			localInfix.erase(i, 1);

	}


	if (localInfix[0] == '(')
	{
		int count = 1;
		int i;
		for (i = 1; i < localInfix.length(); i++)
		{
			if (localInfix[i] == '(')
				count++;


			if (localInfix[i] == ')')
				count--;

			if (count == 0)
				break;
		}

		if (i == localInfix.length() - 1)
			localInfix = localInfix.substr(1, localInfix.length() - 2);


		if (count != 0)
			throw "Error";
	}



	int operatorIndex = -1;
	int insideBrackets = 0;

	char triggers[] = { '+','-' };

	int j = 0;

	do
	{
		for (int i = localInfix.length() - 1; i >= 0; i--)
		{
			if (localInfix[i] == ')') {
				insideBrackets++;
				continue;
			}
			if (localInfix[i] == '(') {

				if (insideBrackets == 0)
					throw "Error";

				insideBrackets--;
				continue;
			}
			if (((localInfix[i] == triggers[0]) || (localInfix[i] == triggers[1])) && (insideBrackets == 0))
			{
				operatorIndex = i;
				break;
			}
		}

		triggers[0] = '*';
		triggers[1] = '/';

		j++;

	} while (operatorIndex == -1 && j != 2);


	if (insideBrackets != 0)
		throw "Error";

	if (operatorIndex == -1)

		return localInfix;

	std::string res = ToPostfix(localInfix.substr(0, operatorIndex)) + " " + ToPostfix(localInfix.substr(operatorIndex + 1, localInfix.length() - operatorIndex)) + " " + localInfix[operatorIndex];

	return res + " ";

}

void calculate()
{
	std::string exp;
	std::string table;

	std::cout << "Enter expression: \n";
	std::getline(std::cin, exp);

	std::cout << "Enter table: \n";
	std::getline(std::cin, table);


	std::string postfix;
	try {
		postfix = ToPostfix("...", exp);
	}
	catch(...) {
		std::cout << "Wrong expression";
		return;
	}


	std::stack<Polinom> stack;
	int index = 0;

	for (int i = 0; i < postfix.length(); i++)
	{
		if (postfix[i] == ' ')
		{
			std::string token = postfix.substr(index, i - index);
			index = i + 1;

			//Если оператор

			if (token.length() == 1 && (token[0] > 39 && token[0] < 48))
			{
				Polinom t2 = stack.top();
				stack.pop();
				Polinom t1 = stack.top();
				stack.pop();

				switch (token[0])
				{
				case '*':
					stack.push(t1 * t2);
					break;
				case '/':
					stack.push(t1 / t2);
					break;
				case '%':
					stack.push(t1 % t2);
					break;
				case '+':
					stack.push(t1 + t2);
					break;
				case '-':
					stack.push(t1 - t2);
					break;
				}

				continue;
			}

			//Если переменая
			if ((token.length() == 1 && (token[0] > 96 && token[0] < 123)
				|| (token[0] > 64 && token[0] < 91)) || token.length() > 1)
			{
				TableRecord<std::string, std::string> t;
				if (table == "at")
				{
					if (!at.Find(token, &t))
					{
						std::cout << "Wrong table\n";
						return;
					}
				}
				if (table == "st")
				{
					if (!st.Find(token, &t))
					{
						std::cout << "Wrong table\n";
						return;
					}
				}
				if (table == "lt")
				{
					if (!lt.Find(token, &t))
					{
						std::cout << "Wrong table\n";
						return;
					}
				}
				if (table == "ht")
				{
					if (!ht.Find(token, &t))
					{
						std::cout << "Wrong table\n";
						return;
					}
				}
				if (table == "tt")
				{
					if (!tt.Find(token, &t))
					{
						std::cout << "Wrong table\n";
						return;
					}
				}
				if (table == "htl")
				{
					if (!htl.Find(token, &t))
					{
						std::cout << "Wrong table\n";
						return;
					}
				}

				stack.push(t.data);
			}

		}
	}

	Polinom res = stack.top();
	stack.pop();

	std::cout << "Answer: \n";
	std::cout << res.GetPolinom_str() << "\n";

	std::cout << "Save? (Y/N) ";

	std::string anw;
	std::getline(std::cin, anw);

	if (anw == "Y" || anw == "y" || anw == "yes")
	{
		TableRecord<std::string, std::string> tr;
		time_t ti;
		time(&ti);
		tr.key = "CALC" + std::to_string(ti);
		tr.data = res.GetPolinom_str();

		at.Insert(tr);
		lt.Insert(tr);
		st.Insert(tr);
		tt.Insert(tr);
		ht.Insert(tr);
		htl.Insert(tr);
	}
}