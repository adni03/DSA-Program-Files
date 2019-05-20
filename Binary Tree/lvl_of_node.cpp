
#include<iostream>
using namespace std;

struct node{
	int data, lvl;
	struct node *LC;
	struct node *RC;
};

typedef struct node *BSTPTR;

void insert(BSTPTR &T, int x, int lvl){
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->lvl=lvl;
		T->LC=NULL;
		T->RC=NULL;
	}
	else if(T->data > x)
		insert(T->LC,x,++lvl);
	else if(T->data < x)
		insert(T->RC,x,++lvl);
	else
		cout<<"\nDuplicate!";
}

void find(BSTPTR T, int k){
	if(T->data < k)
		find(T->RC,k);
	else if(T->data > k)
		find(T->LC,k);
	else if(T->data == k)
		cout<<"The level is : "<<T->lvl;
}

int main()
{
	BSTPTR T=NULL;
	insert(T, 18,0);
	insert(T, 10,0);
	insert(T, 27,0);
	insert(T, 8,0);
	insert(T, 16,0);
	insert(T, 24,0);
	insert(T, 45,0);
	insert(T, 12,0);
	insert(T, 36,0);
	insert(T, 81,0);
	insert(T,63,0);
	find(T,8);
	return 0;
}
