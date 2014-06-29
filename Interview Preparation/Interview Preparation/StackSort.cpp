#include "All.h"
#include "Stack.h"


inline int getMax(Stack<int> &S , Stack<int> &S2 , int count)
{
	int maxVal = -(1<<25);
	while(!S.isEmpty())
	{
		int val = S.pop();
		maxVal = max(maxVal  , val);
		S2.push(val);
	}
	bool maxFound = false;
	while(S2.length()>count)
		if(S2.peek()==maxVal && !maxFound)
			maxFound = true , S2.pop();
			else S.push(S2.pop()); 

	return maxVal;
}

void StackSort(Stack<int> &S)
{
	Stack<int> S2;
	int initialLen = S.length();
	for(int i = 0 ; i< initialLen ; i++)
	{
		int val = getMax(S , S2 , i);
		S2.push(val);
	}

	while(!S2.isEmpty())
		S.push(S2.pop());
}

int main()
{

	Stack<int>S;
	S.push(5);
	S.push(2);
	S.push(7);
	S.push(3);
	S.push(4);
	S.push(1);
	
	StackSort(S);

	while(!S.isEmpty())
		cout<< S.pop() <<endl;


return 0;
}