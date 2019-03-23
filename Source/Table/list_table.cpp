#include "tables.h";

template <class T1, class T2>
void ListTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	table.push_back(tr);
}

template <class T1, class T2>
void ListTable<T1, T2>::Delete(T1 key)
{
	table.remove_if([](const TableRecord& t) { return key == t.key; });
}

template <class T1, class T2>
bool ListTable<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].key == key)
		{
			ret = &table[i];
			return true;
		}
	}

	return false;
}