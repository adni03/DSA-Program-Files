//SORT EVEN ODD 

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

LPTR find_mid(LPTR L)
{
	LPTR F=L, S=L;
	while(F->next != NULL && F->next->next!=NULL)
	{
		S=S->next;
		F=F->next->next;
	}
	return(S);
}

void swap(LPTR Q, int a, int b)
{
	LPTR S1=Q, S2=Q;
	while(S1!=NULL && S2!=NULL)
	{
		if(S1->data != a)
			S1=S1->next;
		if(S2->data != b)
			S2=S2->next;
		else
			break;
	}
	int p=0;
	p=S1->data;
	S1->data = S2->data;
	S2->data = p;
}

void seg(LPTR L)
{
	LPTR TEMP=L, M;
	M=find_mid(L);
	if(count(L)%2==0)
		M=M->next;
	while(L!=NULL && M!=NULL)
	{
		if(L==M)
			M=M->next;
		else if(L->data%2==0 && M->data%2!=0)
		{
			L=L->next;
			M=M->next;
		}
		else if(L->data%2==0 && M->data%2==0)
			L=L->next;
		else if(L->data%2!=0 && M->data%2!=0)
			M=M->next;
		else if(L->data%2!=0 && M->data%2==0)
		{
			swap(TEMP,L->data,M->data);
			L=L->next;
			M=M->next;
		}
	}
	print(TEMP);	
}

int main()
{
	int n;
	LPTR P=NULL;
	cout<<"\nKeep entering elements (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(P,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	seg(P);
	return 0;
}
