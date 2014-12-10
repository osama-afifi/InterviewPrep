#include "All.h"
#include "Stack.h"

	Stack<int> S[3];

	void moveTower(int n , int origin, int dest, int temp) // a = org , b = dest , c = buffer
	{
		if(n==0)return;
		moveTower(n-1 , origin , temp , dest);
		int topVal = S[origin].pop();
		S[dest].push(topVal);
		moveTower(n-1 , temp , dest , origin);
	}


int main()
{
	int TowerSize = 20;
	for(int i = TowerSize ; i>=1; i--)
		S[0].push(i);
	moveTower(TowerSize, 0, 2, 1);
	while(!S[2].isEmpty())
	{
		cout<< S[2].pop() <<endl;		
	}
}