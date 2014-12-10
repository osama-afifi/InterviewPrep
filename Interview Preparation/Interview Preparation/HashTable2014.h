#include<iostream>
#include <vector>


using namespace std;

template<class T>
class HashTable
{
private:
	struct node
	{
		node* next;
		string key;
		T data;
		node(string key, T data) : key(key) , data(data)
		{
			next = NULL;
		}
	};
	const int base = 263;
	int elements;
	vector<node*> table;
	int hashVal(const string &s)
	{
		long long h=0;
		for(int i = 0 ; i< s.size() ; i++)
			h = h*263 + s[i] , h%=size();
		return h;
	}

	inline void expand()
	{

	}

	__inline int size()
	{
		return table.size();
	}

public:

	HashTable()
	{
		elements = 0;
		table.clear();
		table.resize(263,NULL);
		for(int i = 0 ; i<table.size() ; i++)
			table[i] = new node("",-1);
	}

	~HashTable()
	{
	}
	T retrieveElement(const string &key)
	{
		int hashIndex = hashVal(key);
		node* cur = table[hashIndex];
		cur = cur->next;
		while(cur!=NULL)
		{
			if(cur->key == key)
			{
				return cur->data;
			}
			cur = cur->next;
		}
		assert(cur!=NULL);
	}

	void insertElement(const string &key, const T &data)
	{
		if(elements*2>size())
			expand();
		int hashIndex = hashVal(key);
		node* cur = table[hashIndex];
		while(cur->next!=NULL)
		{
			if(cur->next->key == key)
			{
				cur->next->data = data;
				return;
			}
			cur = cur->next;
		}
		cur->next = new node(key,data);
		elements++;
		return;
	}

	T operator [](const string &key)
	{
		return retrieveElement(key);
	}

};


