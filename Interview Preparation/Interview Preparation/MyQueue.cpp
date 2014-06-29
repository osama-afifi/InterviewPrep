#include "All.h"
#include "Stack.h"


class MyQueue
{
private:
	Stack<int>A;
	Stack<int>B;

	 void reverse()
	{
		while(!A.isEmpty())
				 B.push(A.pop());
	}

public:
	void enqueue(int val)
	{
		A.push(val);
	}

	int dequeue()
	{
		assert(!isEmpty());
		if(B.isEmpty())
		{
			reverse();	
			return B.pop();
		}
		else
			return B.pop();	
	}

	int length()
	{
		return A.length() + B.length();	
	}
	bool isEmpty()
	{
		return ((A.length() + B.length())==0);
	}

};




int main()
{
	MyQueue Q;
	for(int i = 1 ; i<=10 ; i++)
		Q.enqueue(i);
	while(!Q.isEmpty())
		cout << Q.dequeue() <<endl;
	Q.enqueue(5);
	Q.enqueue(7);
	Q.dequeue();
	Q.enqueue(10);

		while(!Q.isEmpty())
		cout << Q.dequeue() <<endl;

return 0;
}