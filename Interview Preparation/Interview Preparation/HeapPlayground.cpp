#include "All.h"
#include "heap.h"

int main()
{

	Heap H;
	H.insert(1);
	H.insert(7);
	H.insert(10);
	H.insert(3);
	H.insert(15);
	for(int i = 20 ; i<50 ; i++)
		H.insert(i);
	while(H.length()>0)
		cout << H.pop() << " ";
		cout<<endl;


}