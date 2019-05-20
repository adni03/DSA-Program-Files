//REMOVING DUPLICATES FROM UNSORTED LL

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

int chk(LPTR L, int x)
{
	if(L == NULL)
		return 0;
	else if(L->data == x)
		return 1;
	else
		chk(L->next,x);
}

void rmv_dup(LPTR L, LPTR M)
{
	if(L==NULL)
		print(M);
	else if(chk(M,L->data)==0)
	{
		insert_end(M,L->data);
		rmv_dup(L->next,M);
	}
	else if(chk(M,L->data)==1)
		rmv_dup(L->next,M);
}

int main()
{
	LPTR A=NULL, B=NULL;
	int n;
	cout<<"\nEnter elements for list 1 (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(A,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nUnsorted list without duplicates is : ";
	rmv_dup(A,B);
	return 0;
}
