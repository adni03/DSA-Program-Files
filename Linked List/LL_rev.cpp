//REVERSES A LINKED LIST

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

void remove(LPTR &L, int x)
{
	LPTR T=NULL, TEMP=L;
	while(TEMP->next->data != x)
		TEMP=TEMP->next;
	T=TEMP->next;
	TEMP->next = T->next;
	delete(T);
}

void reverse(LPTR L)
{
	LPTR R, TEMP=L;
	while(TEMP!= NULL)
	{
		insert_f(R,TEMP->data);
		TEMP=TEMP->next;
	}
	print(R);
}

int main()
{
	LPTR P=NULL;
	int n;
	cout<<"\nKeep entering elements in order (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(P,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nList: ";
	print(P);
	cout<<endl;
	cout<<"\nReversed list: ";
	reverse(P);
	return 0;
}
