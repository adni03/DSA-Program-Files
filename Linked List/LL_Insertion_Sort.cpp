//INSERTION SORT

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

void chk(LPTR &L, int x)
{
	LPTR TEMP=L;
	if(TEMP == NULL)
		insert_f(L,x);
	else
	{
		while(TEMP!=NULL)
		{
			if(TEMP->data >= x)
			{
				insert_bf(L,x,TEMP->data);
				break;
			}
			else if(TEMP->data < x && TEMP->next!=NULL)
				TEMP=TEMP->next;
			else 
			{
				insert_end(L,x);
				break;
			}
		}
	}
}

void sort(LPTR L, LPTR &M)
{
	if(L==NULL)
		print(M);
	else 
	{
		chk(M,L->data);
		sort(L->next, M);
	}
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
	cout<<"\nSorted list is : ";
	sort(A,B);
	return 0;
}
