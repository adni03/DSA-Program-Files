//MULTINODE

#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *rptr;
	struct node *next;
};

typedef struct node* LPTR;

void print(LPTR L)
{
	if(L != NULL)
	{
		cout<<L->rptr->data<<" ";		
		print(L->next);
	}
}

LPTR find(LPTR L, int x)
{
	if(L->data == x)
		return L;
	else if(L->next == NULL && L->data != x)
		return 0;
	else
		find(L->next, x);		
}

void insert_f(LPTR &L, int n)
{
	LPTR T;
	T=new(node);
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
		T=new(node);
		T->data = n;
		T->next = NULL;
		TEMP->next=T;
	}
}

void point(LPTR L)
{
	LPTR TEMP=L, P=NULL;
	int n=0;
	while(TEMP!=NULL)
	{
		cout<<"\nEnter element you want rptr to point to : ";
		cin>>n;
		P=find(L,n);
		TEMP->rptr = P;
		TEMP=TEMP->next;
	}
}

int main()
{
	LPTR L=NULL;
	int n;
	cout<<"\nEnter elements (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(L,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	point(L);
	cout<<"\nRandom pointer points and the output is : ";
	print(L);
	return 0;
}
