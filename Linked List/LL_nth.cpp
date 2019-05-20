//FINDS NTH ELEMENT FROM THE END OF THE LINKED LIST

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

void find_nth(LPTR L, int r, LPTR R = NULL)
{
	LPTR S=L, F=L;
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
	cout<<"\n The element is : "<<S->data;
}

int main()
{
	int n;
	LPTR P=NULL;
	cout<<"\nKeep entering elements in order (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_f(P,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nEnter r : ";
	cin>>n;
	find_nth(P,n);
	return 0;
}
