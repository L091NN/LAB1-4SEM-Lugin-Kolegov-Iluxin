#include <string>
#include <iostream> 
#include <list> 
#include <iterator> 


template <class TKey, class TValue>
struct TableRecord
{
	TKey key;
	TValue data;

	TableRecord(TKey ikey, TValue idata)
	{
		key = ikey;
		data = idata;
	}
};

#pragma region ArrayTable

template <class T1, class T2>
class ArrayTable 
{
	TableRecord<T1, T2>* table;
	int size;
	int memSize = 10;

	void Copy(TableRecord<T1,T2>* a1, TableRecord<T1, T2>* a2, int s)
	{
		for (int i = 0; i < s; i++)
			a1[i] = a2[i];
	}
public:
	ArrayTable(const ArrayTable<T1, T2>& t)
	{
		table = new TableRecord<T1, T2>[t.memSize];
		size = t.size;
		memSize = t.memSize;

		Copy(table, t.table, size);
	}

	ArrayTable()
	{
		size = 0;
		table = TableRecord<T1, T2>[memSize];
	}

	~ArrayTable()
	{
		delete[] table;
	}

	void Insert(TableRecord<T1, T2> tr);
	bool Find(T1 key, TableRecord<T1, T2>* ret);
	void Delete(T1 key);
};

#pragma endregion

#pragma region ListTable

template <class T1, class T2>
class ListTable 
{
	std::list<TableRecord<T1,T2>> table;
public:
	void Insert(TableRecord<T1, T2> tr);
	bool Find(T1 key, TableRecord<T1, T2>* ret);
	void Delete(T1 key);
};

#pragma endregion

#pragma region SortedTable

template <class T1, class T2>
class SortedTable
{
	template <class Tk>
	struct memPack
	{
		int index;
		Tk key;
	};	

	int maxSize;
	int size;
	TableRecord<T1, T2>* table;
	memPack* mem;

	void moveLeft(int index)
	{
		for (int i = index; i < maxSize - 1; i++)
		{
			mem[i] = mem[i + 1];
		}
	}

	void moveRight(int index)
	{
		for (int i = maxSize - 1; i > index; i--)
		{
			mem[i] = mem[i - 1];
		}
	}
	int Search_Binary(T1 key);
public:
	SortedTable(int s) 
	{
		maxSize = s;
		size = 0;
		table = new TableRecord<T1, T2>[maxSize];
		mem = new memPack[maxSize];

		for (int i = 0; i < maxSize; i++)
		{
			mem[i].index = i;
		}
	}
	SortedTable(const SortedTable<T1,T2>& st)
	{
		maxSize = st.maxSize;
		size = st.size;
		table = new TableRecord<T1, T2>[maxSize];
		mem = new int[maxSize];

		for (int i = 0; i < maxSize; i++)
		{
			table[i] = st.table[i];
			mem[i] = st.mem[i];
		}
	}
	~SortedTable()
	{
		delete[] table;
		delete[] mem;
	}
	void Insert(TableRecord<T1, T2> tr);
	bool Find(T1 key, TableRecord<T1, T2>* ret);
	void Delete(T1 key);
};

#pragma endregion

#pragma region TreeTable

template <class T1, class T2>
class TreeTable
{
	struct Node
	{
		TableRecord<T1, T2> data;
		Node* left, *right;
	};
	int eventCount = 0;
	Node* table;
	void* DeleteNode(Node* parent, T1 key);
public:
	void Insert(TableRecord<T1, T2> tr);
	bool Find(T1 key, TableRecord<T1, T2>* ret);
	void Delete(T1 key);	
};
#pragma endregion

#pragma region HashTable

template <class T1, class T2>
class HashTable
{
	int size;
	TableRecord<T1, T2>* table;
	int Hash(std::string key);
public:
	HashTable(int s)
	{
		size = s;
		table = new TableRecord<T1, T2>[size];

		for (int i = 0; i < size; i++)
			table[i] = nullptr;
	}
	HashTable(const HashTable<T1,T2>& ht)
	{
		size = ht.size;
		table = new TableRecord<T1, T2>[size];
		for (int i = 0; i < size; i++)
			table[i] = ht.table[i];
	}
	~HashTable()
	{
		delete[] table;
	}

	void Insert(TableRecord<T1, T2> tr);
	bool Find(T1 key, TableRecord<T1, T2>* ret);
	void Delete(T1 key);
};

#pragma endregion

#pragma region HashTableList

template <class T1, class T2>
class HashTableList
{
	int size;
	std::list<TableRecord<T1, T2>>* table;
	int Hash(std::string key);
public:
	HashTableList(int s)
	{
		size = s;
		table = new std::list<TableRecord<T1, T2>>[size];
	}
	HashTableList(const HashTable<T1, T2>& ht)
	{
		size = ht.size;
		table = new std::list<TableRecord<T1, T2>>[size];
		for (int i = 0; i < size; i++)
			table[i] = ht.table[i];
	}
	~HashTableList()
	{
		delete[] table;
	}

	void Insert(TableRecord<T1, T2> tr);
	bool Find(T1 key, TableRecord<T1, T2>* ret);
	void Delete(T1 key);
};

#pragma endregion