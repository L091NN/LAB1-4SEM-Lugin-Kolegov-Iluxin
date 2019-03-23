#include "tables.h";

template <class T1, class T2>
void SortedTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	if (size == maxSize)
		return;

	memPack<T1> cell = mem[size];
	cell.key = tr.key;
	table[cell.index] = tr;

	moveLeft(size);

	int i = 0;
	while (mem[i].key < tr.key && i < size)
	{
		i++;
	}

	moveRight(i);
	mem[i] = cell;

	size++;
}

template <class T1, class T2>
int SortedTable<T1, T2>::Search_Binary(T1 key)
{
	int left = 0;
	int right = size;
	int midd = 0;
	while (true)
	{
		midd = (left + right) / 2;

		if (key < mem[midd].key)
			right = midd - 1;
		else if (key > mem[midd].key)
			left = midd + 1;
		else
			return midd;

		if (left > right)
			return -1;
	}
}

template <class T1, class T2>
void SortedTable<T1, T2>::Delete(T1 key)
{
	int index = Search_Binary(key);

	if (index == -1)
		return;

	memPack<T1> cell = mem[index];
	moveLeft(cell);
	mem[maxSize] = cell;
}

template <class T1, class T2>
bool SortedTable<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	int index = Search_Binary(key);
	if (index == -1)
		return false;

	ret = &table[mem[index].index];
	return true;
}