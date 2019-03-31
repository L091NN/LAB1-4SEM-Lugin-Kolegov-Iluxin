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

	TableRecord() { }

	bool operator==(const TableRecord<TKey,TValue>& tr)
	{
		return key == tr.key;
	}
	bool operator!=(const TableRecord<TKey, TValue> &tr)
	{
		return !(*this == tr);
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
	ArrayTable()
	{
		size = 0;
		table = new TableRecord<T1, T2>[memSize];
	}
	ArrayTable(const ArrayTable<T1, T2>& t)
	{
		table = new TableRecord<T1, T2>[t.memSize];
		size = t.size;
		memSize = t.memSize;

		Copy(table, t.table, size);
	}

	

	~ArrayTable()
	{
		delete[] table;
	}

	void Insert(TableRecord<T1, T2> tr);
	bool Find(T1 key, TableRecord<T1, T2>* ret);
	void Delete(T1 key);

	std::list<TableRecord<T1, T2>> GetAll()
	{
		std::list<TableRecord<T1, T2>> tmp;
		for (int i = 0; i < size; i++)
			tmp.push_back(table[i]);

		return tmp;
	}
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

	std::list<TableRecord<T1, T2>> GetAll()
	{
		//???
		std::list<TableRecord<T1, T2>> tmp(table);
		return tmp;
	}
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

		memPack() {}
	};	

	int maxSize;
	int size;
	TableRecord<T1, T2>* table;
	memPack<T1>* mem;

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
		mem = new memPack<T1>[maxSize];

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

	std::list<TableRecord<T1, T2>> GetAll()
	{
		std::list<TableRecord<T1, T2>> tmp;
		for (int i = 0; i < size; i++) 
		{
			tmp.push_back(table[mem[i].index]);
		}

		return tmp;
	}
};

#pragma endregion

#pragma region TreeTable

template <class T1, class T2>
class TreeTable
{
	struct Node
	{
		TableRecord<T1, T2> data;
		Node* left = nullptr;
		Node* right = nullptr;
	};
	int eventCount = 0;
	Node* table = nullptr;
	Node* DeleteNode(Node* parent, T1 key)
	{
		if (parent == nullptr) return parent;
		else if (key < parent->data.key)
			parent->left = DeleteNode(parent->left, key);
		else if (key > parent->data.key)
			parent->right = DeleteNode(parent->right, key);
		else
		{
			if (parent->right == nullptr && parent->left == nullptr)
			{
				delete parent;
				parent = nullptr;
			}
			else if (parent->right == nullptr)
			{
				Node* temp = parent;
				parent = parent->left;
				delete temp;
			}
			else if (parent->left == nullptr)
			{
				Node* temp = parent;
				parent = parent->right;
				delete temp;
			}
			else
			{
				Node* temp;
				if (parent == nullptr)
					temp = nullptr;

				while (parent->right != nullptr)
				{
					parent = parent->right;
				}

				temp = parent;

				parent->data = temp->data;
				parent->left = DeleteNode(parent->left, temp->data.key);
			}
		}
		return parent;
	}

	void AddToExport(std::list<TableRecord<T1, T2>>* list, Node* n)
	{
		if (n == nullptr)
			return;
		list->push_back(n->data);
		AddToExport(list, n->left);
		AddToExport(list, n->right);
	}

	void FreeMem(Node* parent)
	{
		if (parent == nullptr)
			return;

		FreeMem(parent->left);
		FreeMem(parent->right);
		delete parent;
	}

public:


	void Insert(TableRecord<T1, T2> tr);
	bool Find(T1 key, TableRecord<T1, T2>* ret);
	void Delete(T1 key);

	std::list<TableRecord<T1, T2>> GetAll()
	{
		std::list<TableRecord<T1, T2>> tmp;
		AddToExport(&tmp, table);

		return tmp;
	}

	~TreeTable()
	{
		FreeMem(table);
	}
};
#pragma endregion

#pragma region HashTable

template <class T1, class T2>
class HashTable
{
	TableRecord<T1, T2> EMPTY;

	int size;
	TableRecord<T1, T2>* table;
	int Hash(std::string key);
public:
	HashTable(int s)
	{
		size = s;
		table = new TableRecord<T1, T2>[size];

		for (int i = 0; i < s; i++)
			table[i] = EMPTY;
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

	std::list<TableRecord<T1, T2>> GetAll()
	{
		std::list<TableRecord<T1, T2>> tmp;
		for (int i = 0; i < size; i++)
			if(table[i] != EMPTY)
				tmp.push_back(table[i]);

		return tmp;
	}
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

	std::list<TableRecord<T1, T2>> GetAll()
	{
		std::list<TableRecord<T1, T2>> tmp;
		for (int i = 0; i < size; i++)
			if (table[i].size() != 0 )
				for (auto item : table[i])
					tmp.push_back(item);

		return tmp;
	}
};

#pragma endregion