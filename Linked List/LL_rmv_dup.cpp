//REMOVE DUPLICATED FROM SORTED LIST

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

void rmv_dup(LPTR L)
{
	if(L->next ==  NULL)
		return ;
	else if(L->data == L->next->data)
	{
		remove(L, L->data);
		rmv_dup(L->next);
	}
	else
		rmv_dup(L->next);
}

int main()
{
	int n;
	LPTR P=NULL;
	cout<<"\nKeep entering elements in order (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(P,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nLinked List after duplicate removal : ";
	rmv_dup(P);
	print(P);
	return 0;
}
