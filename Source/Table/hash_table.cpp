#include "tables.h";

template <class T1, class T2>
void HashTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	int offset = 0;
	int index = Hash(tr.key);
	while (table[(index + offset) % size] != nullptr)
	{
		offset++;
	}
	table[(index + offset) % size] = tr;
}

template <class T1, class T2>
void HashTable<T1, T2>::Delete(T1 key)
{
	int offset = 0;
	int index = Hash(key);
	while (table[(index + offset)%size].key != key && offset < size)
	{
		offset++;
	}
	if (offset >= size)
		return;
	table[(index + offset) % size] = nullptr;
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
	int offset = 0;
	int index = Hash(key);
	while (table[(index + offset) % size].key != key && offset < size)
	{
		offset++;
	}
	if (offset >= size)
		return false;
	ret = &table[(index + offset) % size];
	return true;
}