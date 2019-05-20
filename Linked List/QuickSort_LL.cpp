//QUICKSORT ON LL

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
int length (LPTR L, LPTR R = NULL)
{
	if(L==R)
		return 0;
	else
		return (1+length(L->next, R));
}

LPTR find_nth(LPTR L, int r, LPTR R = NULL)
{
	LPTR S=L, F=L;
	if(r > length(L,R))
		return NULL;
	while(r>1)
	{
		F=F->next;
		--r;
	}
	while(F->next != R)
	{
		F=F->next;
		S=S->next;
	}
	return S;
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

void swap(LPTR &L1, LPTR &L2)
{
	int temp=0;
	temp=L1->data;
	L1->data=L2->data;
	L2->data=temp;
}

LPTR part(LPTR L, LPTR H)
{
	int pivot=H->data;
	LPTR T=NULL, TEMP=L;
	while(TEMP < H)
	{
		if(TEMP->data <= pivot)
		{
			T=(T==NULL)?L:T->next;
			swap(T,TEMP);
		}
		TEMP=TEMP->next;
	}
	T=(T==NULL) ? L : T->next;
	swap(T,H);
	return T;
}

void quicksort(LPTR L, LPTR H)
{
	LPTR P;
	if(L!=H && H!=NULL && L!=H->next)
	{
		P=part(L,H);
		quicksort(L,find_nth(L, 1, P));
		quicksort(P->next,H);
	}
}

int main()
{
	LPTR A=NULL;
	int n;
	cout<<"\nEnter element (-1 to stop) : ";
	cin>>n;
	while(n!=-1)
	{
		insert_end(A,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nEntered list is : ";
	print(A);
	LPTR T2=A;
	while(T2->next!=NULL)
		T2=T2->next;
	quicksort(A,T2);
	cout<<"\nSorted list is : ";
	print(A);
	return 0;
}

