//#include "All.h"


template <class T>
class ListNode
{
public:
	T data;
	ListNode* next;
	ListNode(T element): data(element), next(NULL)
	{}
	ListNode():next(NULL)
	{}
};


template <class T>
class SingleLinkedList
{
private:
	ListNode<T>* head;
	ListNode<T>* tail;
	int length;

public:



	SingleLinkedList()
	{
		length = 0;
		head = new ListNode<T>(-1);
		tail = new ListNode<T>(-1);
		head->next  = tail;
	}
	~SingleLinkedList()
	{
		clear();
		delete head;
		delete tail;
		head = tail = NULL;
	}

	int Length()
	{
		return length;
	}
	void insertItem( int index ,  T val)
	{
		assert(index<=length && index >=0);
		ListNode<T> *cur = head;
		while(index>0)
		{
			--index;
			cur = cur->next;
		}	
		ListNode<T> *NewNode = new ListNode<T>(val);
		NewNode->next = cur->next;
		cur->next = NewNode;
		++length;
	}

	void deleteItem(T val)
	{
		assert(index<length && index >=0);
		ListNode<T>*cur = head;
		while(cur->next!=tail)
		{			
			if(cur->next->data == val)
			{
				ListNode<T> *deleted = cur->next;
				cur->next = cur->next->next;	
				delete deleted;
				deleted = null;
				//break;  // for one deletion only
			}
			else
				cur  = cur->next;
		}
		--length;
		if(length==0)head==NULL;
	}

		// delete a Node where we already point at it
	void deleteNode(ListNode<T>*deleted)
	{
		assert(deleted!=NULL);
		length--;	
		if(deleted->next==tail)
		{
			delete tail;
			tail = deleted;
			return;
		}
		deleted->data = deleted->next->data;
		ListNode<T> *temp = deleted->next;
		deleted->next = deleted->next->next;
		delete temp;
		temp = NULL;
	}

	void append(T val)
	{
		insertItem(length , val);
	}
	void insert_front(T val)
	{
		insertItem(0 , val);
	}
	void delete_front()
	{
		assert(length);
		ListNode<T>* deleted = head->next;
		head->next = head->next->next;
		delete deleted;
		deleted  = NULL;
		length--;
	}

	T & operator[] (int i)
	{
		return at(i);	
	}
	T &at(int index)
	{
		assert(index<length && index>=0);
		ListNode<T>* cur = head->next;
		while(index--)
			cur = cur->next;
		return cur->data;
	}

	void clear()
	{
		ListNode<T>* cur = head->next;
		while(cur!=tail)
		{
			ListNode<T>* temp = cur;
			cur = cur->next;
			delete temp;
			temp = NULL;
		}
		head->next = tail;
		length = 0;
	}
	void merge(SingleLinkedList<T> L2)
	{
		ListNode<T>*temp1 = tail;
		ListNode<T>*temp2 = L2.head;
		tail->data = L2.head->next->data;
		tail->next = L2.head->next->next;
		tail = L2.tail;
		length = length + L2.length;

	}

	void reverseList()
	{
		ListNode<T>*nxt = head->next;
		ListNode<T>*cur = head;
		ListNode<T>*to = NULL;
			while(nxt)	
			{
				nxt = cur->next;
				cur->next = to;
				to = cur;
				cur = nxt;
			}
			nxt = head;
			head = tail;
			tail = nxt;
	}
};

