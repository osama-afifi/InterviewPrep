#include "All.h"


template<class T>
class HashTable
{
private:
	struct Key_Val
	{
		string key;
		T val;
		Key_Val(string key , T val)
		{
			(*this).key = key;
			(*this).val = val;
		}
	};
	struct node
	{
		Key_Val data;
		node* next;	
		node()
		{next = NULL;}
		node(Key_Val data)
		{
			(*this).data = data;
			next = NULL;
		}
		{next = NULL}
	};
	node** table;
	const static int base = 131;
	int hash(const string &key);
	bool find(const int &hash , int valPtr);
	int size;
	int keys;
public:
	HashTable() : size(base) , keys(0)
	{
		table = new node[base];
	}
	HashTable(int n) : size(n) , keys(0)
	{
		table = new node[n];
	}
	void insert(const string &key, const T &val);
	T retrieve(const string &key);
	void remove(const string &key);
	T &operator[](const string &key);
};


template<class T>
int HashTable::hash(const string &key)
{
	long long h = 0;
	for(int i = 0 ; i< key.length() ; i++)
		h = (h*base + key[i])%size;
	return (int)h;
}

template<class T>
void HashTable::find(const string &key, const int &hash , T* & valPtr)
{
	node* cur = table[hash];
	while(cur!=NULL)
	{
		if()
		cur = cur->next;
	}
}

template<class T>
void HashTable::insert(string key , T val)
{
	table[hash(key)].append(Key_Val(key,val));
}

template<class T>
T HashTable::retrieve(string key)
{
	T* valPtr = NULL;
	int hashIndex = hash(key);
	find(key, hash, valPtr);
	assert(valPtr!=NULL);
	table[hashIndex];
	return val; 
}



