#include "All.h"

template<class T>
class Stack
{
private:
	template<class T>
	class Node
	{
	public:
		Node* next;
		T data;
		Node(T vv)
		{ 
			data= vv;
		}
		Node()
		{
		}
	};
	Node<T> * top;
	int size;
public:

	Stack()
	{
		top = NULL;
		size = 0;
	}
	void push( T val)
	{
		Node<T>* NewNode = new Node<T>(val);
		NewNode->next = top;
		top = NewNode;
		++size;
	}
	T pop()
	{
		assert(top!=NULL);
		T returnedVal = top->data;
		Node<T> * temp = top;
		top = top->next;
		delete temp;
		temp = NULL;
		--size;
		return returnedVal;
	}
	T peek()
	{
		assert(top!=NULL);
		return top->data;;	
	}
	bool isEmpty()
	{
		return (size==0);
	}
	int length()
	{
	return size;
	}

};

