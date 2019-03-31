#include "tables.h"

#pragma region ArrayTable

template <class T1, class T2>
void ArrayTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
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
			*ret = table[i];
			return true;
		}
	}

	return false;
}

#pragma endregion

#pragma region ListTable

template <class T1, class T2>
void ListTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	table.push_back(tr);
}

template <class T1, class T2>
void ListTable<T1, T2>::Delete(T1 key)
{
	table.remove_if([&](const TableRecord<T1,T2>& t) { return key == t.key; });
}

template <class T1, class T2>
bool ListTable<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	for (auto item : table)
	{
		if (item.key == key)
		{
			*ret = item;
			return true;
		}
	}

	return false;
}

#pragma endregion

#pragma region SortedTable

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
	moveLeft(index);
	mem[maxSize-1] = cell;
	
	size--;
}

template <class T1, class T2>
bool SortedTable<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	int index = Search_Binary(key);
	if (index == -1)
		return false;

	*ret = table[mem[index].index];
	return true;
}

#pragma endregion

#pragma region TreeTable

template <class T1, class T2>
void TreeTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	if (table == nullptr)
	{
		table = new Node();
		table->data = tr;
		table->left = table->right = nullptr;
		return;
	}

	Node* current = table;
	while (true)
	{
		if (current->data.key > tr.key)
		{
			if (current->left == nullptr)
			{
				Node* l = new Node();
				l->data = tr;
				l->left = l->right = nullptr;
				current->left = l;
				return;
			}
			else
			{
				current = current->left;
			}
		}
		else
		{
			if (current->right == nullptr)
			{
				Node* l = new Node();
				l->data = tr;
				l->left = l->right = nullptr;
				current->right = l;
				return;
			}
			else
			{
				current = current->right;
			}
		}
	}

	eventCount++;
}

template <class T1, class T2>
void TreeTable<T1, T2>::Delete(T1 key)
{
	DeleteNode(table, key);
	eventCount++;
}

template <class T1, class T2>
bool TreeTable<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	if (key == table->data.key)
	{
		*ret = table->data;
		return true;
	}

	Node* current = table;
	while (true)
	{
		if (current == nullptr)
			return false;
		if (current->data.key == key)
		{
			*ret = current->data;
			return true;
		}
		else if (current->data.key > key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

}

#pragma endregion

#pragma region HashTable

template <class T1, class T2>
void HashTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	int offset = 0;
	int index = Hash(tr.key);
	while (table[(index + offset) % size] != EMPTY)
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
	while (table[(index + offset) % size].key != key && offset < size)
	{
		offset++;
	}
	if (offset >= size)
		return;
	table[(index + offset) % size] = EMPTY;
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
	*ret = table[(index + offset) % size];
	return true;
}

#pragma endregion

#pragma region HashTableList

template <class T1, class T2>
void HashTableList<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	int index = Hash(tr.key);
	table[index].push_back(tr);
}

template <class T1, class T2>
void HashTableList<T1, T2>::Delete(T1 key)
{
	int index = Hash(key);
	table[index].remove_if([&](const TableRecord<T1, T2>& t) {return t.key == key; });
}

template <class T1, class T2>
int HashTableList<T1, T2>::Hash(std::string key)
{
	int sum = 0;
	for (int i = 0; i < key.size(); i++)
	{
		sum += key[i];
	}

	return sum % size;
}

template <class T1, class T2>
bool HashTableList<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	int index = Hash(key);
	for (auto item : table[index])
	{
		if (item.key == key)
		{
			*ret = item;
			return true;
		}
	}

	return false;
}

#pragma endregion




