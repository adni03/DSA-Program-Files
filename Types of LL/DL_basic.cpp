//BASIC DOUBLY LINKED LIST

#include<iostream>
using namespace std;

struct dlnode
{
	int data;
	struct dlnode *R;
	struct dlnode *L;
};

typedef struct dlnode* DPTR;

void rprint(DPTR D)
{
	if(D!=NULL)
	{
		cout<<D->data<<" ";
		rprint(D->R);
	}
}

void add_f(DPTR &D, int n)
{
	DPTR T;
	T=new(dlnode);
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
		T=new(dlnode);
		T->data=n;
		T->R=NULL;
		T->L=TEMP;
		TEMP->R=T;
	}	
}

void add_bf(DPTR &D, int y, int x)
{
	DPTR TEMP=D, T;
	while(TEMP->data!=x)
		TEMP=TEMP->R;
	T=new(dlnode);
	T->data=y;
	T->R=TEMP;
	T->L=TEMP->L;
	TEMP->L->R=T;
	TEMP->L=T;
}

void add_af(DPTR &D, int y, int x)
{
	DPTR TEMP=D, T;
	while(TEMP->data!=x)
		TEMP=TEMP->R;
	T=new(dlnode);
	T->data=y;
	T->L=TEMP;
	T->R=TEMP->R;
	TEMP->R->L=T;
	TEMP->R=T;
}

void del(DPTR &D, int x)
{
	DPTR TEMP=D;
	while(TEMP->data!=x)
		TEMP=TEMP->R;
	TEMP->L->R=TEMP->R;
	TEMP->R->L=TEMP->L;
	delete(TEMP);	
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
	rprint(A);
	add_bf(A,10,4);
	add_af(A,11,5);
	cout<<"\nUpdated list : ";
	rprint(A);
	return 0;
}


