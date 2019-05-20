//Basic Linked List Program

#include<iostream>
using namespace std;

struct lnode
{
	int data;
	struct lnode *next;
};

typedef struct lnode* LPTR;

int count (LPTR L)
{
	if(L == NULL)
		return 0;
	else
		return (1+count(L->next));
}

void print(LPTR L)
{
	if(L != NULL)
	{
		cout<<L->data<<" ";		
		print(L->next);
	}
}

int find(LPTR L, int x)
{
	if(L->data == x)
		return 1;
	else if(L->next == NULL && L->data != x)
		return 0;
	else
		find(L->next, x);		
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
	if(L->data == x)
		insert_f(L,y);
	else
	{
		while(TEMP->next->data != x)
			TEMP=TEMP->next;
		T=new(lnode);
		T->data = y;
		T->next = TEMP->next;
		TEMP->next=T;
	}
}

void remove(LPTR &L, int x)
{
	LPTR T=NULL, TEMP=L;
	while(TEMP->next->data != x)
		TEMP=TEMP->next;
	T=TEMP->next;
	TEMP->next = T->next;
	delete(T);
}

int main()
{
	LPTR L1;
	L1=NULL;
	int a;
	cout<<"\nEnter 6 elements : ";
	for(int i=0; i<6; i++)
	{
		cin>>a;
		insert_end(L1,a);
	}
	cout<<"\nBefore Delete: ";
	print(L1);
	cout<<"Deleted 5"<<endl;
	remove(L1,5);
	insert_bf(L1,10,1);
	print(L1);
	return 0;
}
