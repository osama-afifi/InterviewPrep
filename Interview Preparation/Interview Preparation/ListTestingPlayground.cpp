#include "All.h"
#include "SingleLinkedList.h"





int main()
{

	SingleLinkedList<int> SLL = SingleLinkedList<int>();
	SingleLinkedList<int> SLL2 = SingleLinkedList<int>();
	SLL.append(1);
	SLL.append(2);
	SLL.append(3);
	SLL.append(4);
	SLL.append(5);

	SLL2.append(6);
	SLL2.append(7);
	SLL2.append(8);
	SLL2.append(9);
	SLL2.append(10);

	SLL.merge(SLL2);
	SLL.reverseList();

	for(int i = 0 ; i<SLL.Length() ;  i++)
		cout << SLL[i] << " ";
	cout<<endl;

}