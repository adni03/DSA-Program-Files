//MERGER

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

LPTR find_nth(LPTR L, int r)
{
	LPTR S=L, F=L;
	while(r>0)
	{
		F=F->next;
		--r;
	}
	while(F->next != NULL)
	{
		F=F->next;
		S=S->next;
	}
	return S;
}

void join(LPTR L, LPTR &M, int n)
{
	LPTR T2=M;
	while(T2->next != NULL)
		T2=T2->next;
	T2->next = find(L,n);
	cout<<"\nJoined!";
}

void find_int(LPTR L, LPTR M)
{
	int l1=0, l2=0;
	while(l1<count(L) && l2<count(M))
	{
		if(find_nth(L,l1) != find_nth(M,l2))
		{
			cout<<"\nData at merging point is : "<<find_nth(M,--l2)->data;
			break;
		}
		else 
		{
			l1++;
			l2++;
		}
	}	
}

int main()
{
	int n;
	LPTR P=NULL, Q=NULL;
	cout<<"\nKeep entering elements for list 1 (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(P,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nKeep entering elements for list 2 (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(Q,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nEnter rendezvous element : ";
	cin>>n;
	join(P,Q,n);
	cout<<"\nQ is : ";
	print(Q);
	find_int(P,Q);
	return 0;
}
