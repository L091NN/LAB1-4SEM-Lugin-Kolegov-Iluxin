#include "tables.h";

template <class T1, class T2>
void HashTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	int index = Hash(tr.key);
	table[index].push_back(tr);
}

template <class T1, class T2>
void HashTable<T1, T2>::Delete(T1 key)
{
	int index = Hash(key);
	table[index].remove_if([](const TableRecord<T1, T2>& t) {return t.key == key; });
}

template <class T1, class T2>
int HashTable<T1, T2>::Hash(std::string key)
{
	int sum = 0;
	for (int i = 0; i < key.size(); i++)
	{
		sum += key[i];
	}

	return sum % size;
}

template <class T1, class T2>
bool HashTable<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	int index = Hash(key);
	for (auto item : table[index])
	{
		if (item.key == key)
		{
			ret = &item;
			return true;
		}		
	}

	return false;
}