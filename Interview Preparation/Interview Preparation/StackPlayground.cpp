#include "All.h"
#include "Stack.h"





int main()
{

Stack<int> S = Stack<int>();
S.push(1);
S.push(2);
S.push(3);
S.push(4);

while(!S.isEmpty())
	cout <<S.pop() <<endl;


return 0 ;
}