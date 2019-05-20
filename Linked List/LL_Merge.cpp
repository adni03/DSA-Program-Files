//MERGING 2 LISTS

#include<iostream>
using namespace std;

struct lnode
{
	int data;
	struct lnode *next;
};

typedef struct lnode* LPTR;

void print(LPTR L)
{
	if(L != NULL)
	{
		cout<<L->data<<" ";		
		print(L->next);
	}
}

void insert_f(LPTR &L, int n)
{
	LPTR T;
	T=new(lnode);
	T->data = n;
	T->next=L;
	L=T;
}

void insert_end(LPTR &L, int n)
{
	LPTR T, TEMP=L;
	if(L == NULL)
	{
		insert_f(L,n);
	}
	else
	{
		while(TEMP->next != NULL)
			TEMP=TEMP->next;
		T=new(lnode);
		T->data = n;
		T->next = NULL;
		TEMP->next=T;
	}
}

void insert_af(LPTR &L, int y, int x)
{
	LPTR T, TEMP=L;
	while(TEMP->next->data != x)
		TEMP=TEMP->next;
	T=new(lnode);
	T->data = y;
	T->next = TEMP->next;
	TEMP->next=T;	
}

void insert_bf(LPTR &L, int y, int x)
{
	LPTR T, TEMP=L;
	while(TEMP->data != x)
		TEMP=TEMP->next;
	T=new(lnode);
	T->data = y;
	T->next = TEMP->next;
	TEMP->next=T;	
}

void merge(LPTR L1, LPTR L2)
{
	LPTR TEMP=L1;
	while(L2!=NULL && TEMP!=NULL)
	{
		if(TEMP->data < L2->data)
			TEMP=TEMP->next;
		else 
		{
			insert_bf(L1,L2->data,TEMP->data);
			L2=L2->next;
		}
	}
	while(L2 != NULL)
	{
		insert_end(L1,L2->data);
		L2=L2->next;
	}
	print(L1);
}

int main()
{
	LPTR P=NULL, Q=NULL;
	int n,a;
	cout<<"\nEnter number of elements for LL 1 : ";
	cin>>n;
	while(n > 0)
	{
		cout<<"\nEnter element : ";
		cin>>a;
		insert_end(P,a);
		n--;
	}
	cout<<"\nEnter number of elements for LL 2 : ";
	cin>>n;
	while(n > 0)
	{
		cout<<"\nEnter element : ";
		cin>>a;
		insert_end(Q,a);
		n--;
	}
	merge(P,Q);
	return 0;
}
