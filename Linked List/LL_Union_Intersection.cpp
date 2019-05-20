//UNION AND INTERSECTION OF 2 LLs

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

int find(LPTR &L, int x)
{
	LPTR TEMP=L;
	if(TEMP->data == x)
		return 1;
	else if(TEMP->next == NULL && TEMP->data != x)
		return 0;
	else
		find(TEMP->next, x);		
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

void remove(LPTR &L, int x)
{
	LPTR T=NULL, TEMP=L;
	while(TEMP->next->data != x)
		TEMP=TEMP->next;
	T=TEMP->next;
	TEMP->next = T->next;
	delete(T);
}

void Union(LPTR L1, LPTR L2)
{
	LPTR L3;
	L3=NULL;
	while(L1 != NULL)
	{
		insert_f(L3,L1->data);
		L1=L1->next;
	}
	while(L2 != NULL)
	{
		if(!find(L3,L2->data))
		{
			insert_f(L3,L2->data);
			L2=L2->next;
		}
		else
			L2=L2->next;
	}
	print(L3);
}

void intersection(LPTR L1, LPTR L2)
{
	LPTR L3=NULL, T2=L2;
	while(L1 != NULL)
	{
		while(L2 != NULL)
		{
			if(L2->data == L1->data)
			{
				insert_f(L3,L2->data);
				L2=L2->next;
			}
			else
				L2=L2->next;
		}
		L2=T2;
		L1=L1->next;
	}
	print(L3);
}

int main()
{
	LPTR P,Q;
	P=NULL;
	Q=NULL;
	int n,a;
	cout<<"\nEnter number of elements for LL 1 : ";
	cin>>n;
	while(n > 0)
	{
		cout<<"\nEnter element : ";
		cin>>a;
		insert_f(P,a);
		n--;
	}
	cout<<"\nEnter number of elements for LL 2 : ";
	cin>>n;
	while(n > 0)
	{
		cout<<"\nEnter element : ";
		cin>>a;
		insert_f(Q,a);
		n--;
	}
	cout<<"\nUnion is : "<<endl;
	Union(P,Q);
	cout<<"\nIntersection is : "<<endl;
	intersection(P,Q);
	return 0;
}
