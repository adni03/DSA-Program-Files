//lOOP 

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

LPTR find(LPTR L, int x)
{
	if(L->data == x)
		return(L);
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

void join(LPTR &L, int a)
{
	LPTR TEMP=L;
	while(TEMP->next != NULL)
		TEMP=TEMP->next;
	TEMP->next=find(L,a);
}

LPTR is_loop(LPTR L)
{
	LPTR S=L, F=L;
	int flag=0;
	do
	{
		S=S->next;
		F=F->next->next;
		if(F == NULL)
		{
			flag=1;
			break;
		}
	}while(S != F);
	if(flag == 0)
		return(S);
	else
		return 0;
}

LPTR find_meet(LPTR L)
{
	LPTR M=is_loop(L), N=L;
	while(M != N)
	{
		N=N->next;
		M=M->next;
	}
	return M;
}

void find_len(LPTR L)
{
	LPTR M, N;
	M=find_meet(L);
	N=find_meet(L);
	int cnt;
	do
	{
		M=M->next;
		cnt++;
	}while(M != N);
	cout<<"\nLength of the loop is : "<<cnt;
}

int main()
{
	int n;
	LPTR P=NULL, T;
	cout<<"\nKeep entering elements in order (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(P,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nEnter rendezvous element : ";
	cin>>n;
	join(P,n);
	if(!is_loop(P))
		cout<<"\nNo loop!";
	else
		cout<<"\nLoop!";
	T=find_meet(P);
	cout<<"\nData at meeting point : "<<T->data;;
	find_len(P);
	return 0;
}
