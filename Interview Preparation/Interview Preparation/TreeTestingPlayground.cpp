#include "All.h"
#include "BST.h"

int main()
{
	
	BST<int> T;
	T.insert(1);
	T.insert(5);
	T.insert(7);
	T.insert(-2);

	T.inOrderTraverse();
	if(T.isBalanced())
		cout << "Tree is Balanced" <<endl;
	else cout<< "Tree is not balanced" <<endl;

}