#include "All.h"

class Binode
{
public:
	Binode* node1;
	Binode* node2;
	Binode()
	{}
	Binode(int data)
	{
		this->data = data;
		node1 = NULL;
		node2 = NULL;
	}
	int data;	
};


void append(Binode* &n1 , Binode* &n2)
{
	n1->node2 = n2;
	n2->node1 = n1;
}
pair<Binode* , Binode*>treeToList(Binode* root) //return head & tail
{
	if(root == NULL)
		return make_pair((Binode*)NULL,(Binode*)NULL);
	pair<Binode* , Binode*> left = treeToList(root->node1);
	pair<Binode* , Binode*> right = treeToList(root->node2);
	if(left.second!=NULL)
		append(left.second,root);
	if(right.first!=NULL)
		append(root,right.first);
	Binode* newHead = (left.first) ? left.first : root;
	Binode* newTail = (right.second) ? right.second : root;
	return make_pair(newHead,newTail);	
}

class Tree
{
public:
	Binode* root;
	int size;
	Tree()
	{
		size = 0;
		root = NULL;
	}
	void insert(Binode* &cur , const int &val)
	{
		if(cur==NULL)
		{
			cur = new Binode(val);
			return;
		}
		if(cur->data>=val)
			insert(cur->node1  ,val);
		else 
			insert(cur->node2, val);
	}
	void insert(int val)
	{
		insert(root,val);
		++size;
	}

	void inOrder(Binode* root)
	{
		if(root==NULL)return;
		inOrder(root->node1);
		cout<< root->data  << " ";
		inOrder(root->node2);
	}
	void inOrder()
	{
		inOrder(root);
		cout<<endl;
	}
};

int main()
{
	Tree T;
	T.insert(5);
	T.insert(3);
	T.insert(7);
	T.insert(4);
		T.inOrder();
	pair<Binode* , Binode*> HT = treeToList(T.root);


	Binode* cur = HT.first;
	while(cur!=NULL)
	{
		cout<< cur->data << " "; 
		cur = cur->node2;
	}
	cout<<endl;;
	cur = HT.second;
	while(cur!=NULL)
	{
		cout<< cur->data << " ";
		cur = cur->node1;
	}
	cout<<endl;

	return 0;
}