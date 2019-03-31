#include "Polinom.h";
#include "tables.cpp"

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