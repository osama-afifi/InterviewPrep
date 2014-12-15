#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i = (a) ; i<b ; i++)
#define Set(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
typedef long long LL;
using namespace std;

struct node
{
    int data;
    node *next,*prev,*child;
    node()
    {
        next = prev = child = NULL;
    }

    node(int data) : data(data)
    {
        next = prev = child = NULL;
    }
    node(int data,node *next,node *prev,node *child): data(data), next(next), prev(prev), child(child)
    {

    }
};

void flatten(node* head, node* &tail)
{
    node* cur = head;
    while(cur)
    {
        if(cur->child)
        {
            node* curChild = cur->child;
            while(curChild->next)
                curChild = curChild->next;
            tail->next = cur->child;
            cur->child->prev = tail;
            tail = curChild;
        }
        cur = cur->next;
    }
}


int main()
{
    freopen("input.in", "r", stdin);

    //
    node* head = new node(5);
    node* n1 = new node(33);
    node* n2 = new node(17);
    node* n3 = new node(2);
    node* n4 = new node(1);

    node* tail = n4;
    head->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n1->prev = head;
    n2->prev = n1;
    n3->prev = n2;
    n4->prev = n3;


    node* n5 = new node(6);
    node* n6 = new node(25);
    node* n7 = new node(6);
    node* n8 = new node(2);
    node* n9 = new node(7);

    head->child = n5;
    n3->child = n8;
    n5->next = n6;
    n6->prev = n5;
    n6->next = n7;
    n7->prev = n6;

    n8->next = n9;
    n9->prev = n8;

    node* nx = new node(8);
    node* n10 = new node(9);
    node* n11 = new node(12);
    node* n12 = new node(5);

    n6->child = nx;
    n7->child = n10;
    n8->child = n11;
    n11->next = n12;
    n12->prev = n11;

    node* n13 = new node(7);
    node* n14 = new node(21);
    node* n15 = new node(3);

    //

    node* cur = head;
    while(cur)
    {
        cout << cur->data <<" ";
        cur = cur->next;
    }
    cout <<endl;

    flatten(head,tail);

    cur = head;
    while(cur)
    {
        cout << cur->data << " " ;
        cur = cur->next;
    }
    cout <<endl;

    return 0;
}
