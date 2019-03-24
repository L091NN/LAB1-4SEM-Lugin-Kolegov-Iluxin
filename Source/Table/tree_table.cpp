#include "tables.h";

template <class T1, class T2>
void TreeTable<T1, T2>::Insert(TableRecord<T1, T2> tr)
{
	if (table == nullptr)
	{
		table = new Node();
		table->data = tr;
	}

	Node* current = table;
	while (true)
	{
		if (current->data->key > tr.key)
		{
			if (current->left == nullptr)
			{
				Node* l = new Node();
				l.data = tr;
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
				l.data = tr;
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
void* TreeTable<T1, T2>::DeleteNode(TreeTable<T1, T2>::Node* parent, T1 key)
{
	if (parent == nullptr) return parent;
	else if (key < parent->data->key)
		parent->left = DeleteNode(parent->left, key);
	else if (key > parent->data->key)
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
			parent->left = DeleteNode(parent->left, temp->data->key);
		}
	}
	return parent;
}

template <class T1, class T2>
bool TreeTable<T1, T2>::Find(T1 key, TableRecord<T1, T2>* ret)
{
	if (key == table->data->key)
	{
		ret = table->data;
		return true;
	}

	Node* current = table;
	while (true)
	{
		if (current == nullptr)
			return false;
		if (current->data->key == key)
		{
			ret = current->data;
			return true;
		}
		else if(current->data->key > key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	
}