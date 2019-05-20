//FINDING MIDDLE LINKED LIST

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

void find_mid(LPTR L)
{
	LPTR F=L, S=L;
	while(F->next != NULL && F->next->next!=NULL)
	{
		S=S->next;
		F=F->next->next;
	}
	cout<<"\nMiddle element is : "<<S->data;
}

int main()
{
	int n;
	LPTR P=NULL;
	int cnt=0;
	cout<<"\nKeep entering elements in order (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		cnt++;
		insert_end(P,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	if(cnt%2==0)
		cout<<"\nNo middle!";
	else
		find_mid(P);
	return 0;
}
