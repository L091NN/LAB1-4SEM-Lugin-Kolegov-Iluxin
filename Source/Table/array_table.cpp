#include "tables.h";

template <class T1, class T2>
void ArrayTable<T1, T2>::Insert(TableRecord<T1,T2> tr)
{
	if (size == memSize)
	{
		memSize += 10;
		TableRecord<T1, T2>* tmp = new TableRecord<T1, T2>[memSize];
		Copy(tmp, table, size);
		delete[] table;
		table = tmp;
	}

	table[size] = tr;
	size++;
}

template <class T1, class T2>
void ArrayTable<T1, T2>::Delete(T1 key)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].key == key)
		{
			table[i] = table[size - 1];
			size--;
			break;
		}
	}

	if (memSize - size >= 10 && size != 0)
	{
		memSize -= 10;
		TableRecord<T1, T2>* tmp = new TableRecord<T1, T2>[memSize];
		Copy(tmp, table, size);
		delete[] table;
		table = tmp;
	}
}

template <class T1, class T2>
bool ArrayTable<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i].key == key)
		{
			TableRecord<T1, T2>* tmp = &table[i];
			ret = tmp;
			return true;
		}
	}

	return false;
}