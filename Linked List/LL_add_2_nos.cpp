//ADDITION OF TWO NUMBERS

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

int gen_num(LPTR L)
{
	int sum=0;
	while(L!=NULL)
	{
		sum=sum*10 + L->data;
		L=L->next;
	}
	return sum;
}

void fill(LPTR A, LPTR B)
{
	LPTR TEMP=NULL;
	int n1=gen_num(A), n2=gen_num(B), sum=(n1+n2);
	while(sum>0)
	{
		insert_f(TEMP,sum%10);
		sum/=10;
	}
	cout<<"\nList 3: ";
	print(TEMP);
}

int main()
{
	LPTR L=NULL, M=NULL;
	int n;
	cout<<"\nEnter elements for list 1 (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(L,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nEnter elements for list 2 (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(M,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nList 1: ";
	print(L);
	cout<<"\nList 2: ";
	print(M);
	fill(L,M);
	return 0;
}
