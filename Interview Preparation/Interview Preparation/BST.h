#include "All.h"

template<class T>
class BST
{
private:

	template<class T>
	class Node
	{
	public:
		Node<T> *left;
		Node<T> *right;
		Node<T> *parent;
		T data;

		Node(T val , Node<T>*l , Node<T>*r , Node<T>*p)
		{
			data = val;	
			left = l;
			right = r;
			parent = p;
		}
		Node(T val)
		{
			data = val;	
			left = right = parent = NULL;
		}
		Node()
		{
			left = right = parent = NULL;
		}


	};

	Node<T>* root;
	int size;	
	
	void insert(Node<T> * subtree , T val)
	{

		Node<T>* prev  = NULL;
		while(subtree)
		{
			prev = subtree;
			if(val<subtree->data)
				subtree = subtree->left;
			else
				subtree = subtree->right;
		}

		if(prev==NULL) // this is root
		{
			root = new Node<T>(val);
		}
		else
		{
			subtree = new Node<T>(val , NULL , NULL , prev);
			if(prev->data > val)
				subtree->parent->left = subtree;
			else
				subtree->parent->right = subtree;
		}
		++size;
	}



	void deleteNode(Node<T>*subtree , T val)
	{
		if(subtree->left==NULL)
		{
			subtree->right->parent = subtree->parent;
			subtree = subtree->right;
		}
		else if(subtree->right==NULL)
		{
			subtree->right->parent = subtree->parent;
			subtree = subtree->left;
		}


	}

	bool remove(Node<T>*subtree , T val)
	{
		while(subtree)
		{
			if(val==subtree->data)
			{
				deleteNode(subtree);
				return true;
			}
			if(val<subtree->data)
				subtree = subtree->left;
			else if(val>subtree->data)
				subtree = subtree->right;
		}
		if(subtree)return false;
	}

	void inOrderTraverse(Node<T>* subtree)
	{
		if(subtree==NULL)return;
		inOrderTraverse(subtree->left);
		cout<< subtree->data << " ";
		inOrderTraverse(subtree->right);
	}

	int isBalanced(Node<T>* Subtree) // actualy gets heights
	{
		if(Subtree==NULL) return 0;
		int l = isBalanced(Subtree->left);
		if(l==-1)
			return -1;
		int r = isBalanced(Subtree->right);
		if(r==-1)
			return -1;
		if(abs(l-r)<=1) return max(l,r)+1;
		else return -1;		
	}

public:
	BST()
	{
		root = NULL;
		size = 0;
	}


	int getSize()
	{
		return size;
	}

	void insert(T val)
	{

		insert(root , val);

	}

	void remove(T val)
	{
		remove(root , val);
	}

	

	void inOrderTraverse()
	{
		inOrderTraverse(root);
		cout << endl;
	}

	bool isBalanced()
	{
		return (isBalanced(root)!=-1);
	}
};