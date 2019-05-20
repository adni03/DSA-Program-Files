//Pairwise swap

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

void swap(LPTR Q)
{
	LPTR S1=Q, S2=Q->next;
	int p=0;
	while(S1!=NULL && S2!=NULL)
	{
		p=S1->data;
		S1->data = S2->data;
		S2->data = p;
		S1=S1->next->next;
		if(S2->next!=NULL)
			S2=S2->next->next;
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
	cout<<"\nSwapped! : ";
	swap(L);
	print(L);
	return 0;
}
