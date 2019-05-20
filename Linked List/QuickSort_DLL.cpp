//QUICKSORT ON D_LL

#include<iostream>
using namespace std;

struct lnode
{
	int data;
	struct lnode *L;
	struct lnode *R;
};

typedef struct lnode* DPTR;

void print(DPTR L)
{
	if(L != NULL)
	{
		cout<<L->data<<" ";		
		print(L->R);
	}
}

void add_f(DPTR &D, int n)
{
	DPTR T;
	T=new(lnode);
	T->data=n;
	T->R=D;
	T->L=NULL;
	D=T;
}

void add_end(DPTR &D, int n)
{
	DPTR T, TEMP=D;
	if(D==NULL)
		add_f(D,n);
	else
	{
		while(TEMP->R!=NULL)
			TEMP=TEMP->R;
		T=new(lnode);
		T->data=n;
		T->R=NULL;
		T->L=TEMP;
		TEMP->R=T;
	}	
}

void swap(DPTR &L1, DPTR &L2)
{
	int temp=0;
	temp=L1->data;
	L1->data=L2->data;
	L2->data=temp;
}

DPTR part(DPTR L, DPTR H)
{
	int pivot=H->data;
	DPTR T=L->L, TEMP=L;
	while(TEMP!=H)
	{
		if(TEMP->data <= pivot)
		{
			T=(T==NULL)?L:T->R;
			swap(T,TEMP);
		}
		TEMP=TEMP->R;
	}
	T=(T==NULL)?L:T=T->R;
	swap(T,H);
	return (T);
}

void quicksort(DPTR L, DPTR H)
{
	DPTR P;
	if(L!=H && H!=NULL && L!=H->R)
	{
		P=part(L,H);
		quicksort(L,P->L);
		quicksort(P->R,H);
	}
}

int main()
{
	DPTR A=NULL;
	int n;
	cout<<"\nEnter element (-1 to stop) : ";
	cin>>n;
	while(n!=-1)
	{
		add_end(A,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nEntered list is : ";
	print(A);
	DPTR T1=A, T2=A;
	while(T2->R!=NULL)
		T2=T2->R;
	quicksort(T1,T2);
	cout<<"\nSorted list is : ";
	print(A);
	return 0;
}

