#include "tables.h"
#include "Polinom.h"


ArrayTable<std::string, Polinom> at;
ListTable<std::string, Polinom> lt;
SortedTable<std::string, Polinom> st(1000);
TreeTable<std::string, Polinom> tt;
HashTable<std::string, Polinom> ht(1000);
HashTableList<std::string, Polinom> htl(1000);

int main(int argc, char** argv)
{
	
}
