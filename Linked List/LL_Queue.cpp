//QUEUE AS A LINKED LIST

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct Queue
{
	struct node *F;
	struct node *R;
};

typedef struct node* QPTR;

void L_enq(Queue &A, int x)
{
	QPTR T=NULL, TEMP=A.F;
	T=new(node);
	T->data=x;
	if(A.F == NULL)
	{
		A.F=T;
		A.R=T;
		T->next=NULL;
	}	
	else
	{
		while(TEMP!=A.R)
			TEMP=TEMP->next;
		T->next=NULL;
		TEMP->next=T;
		A.R=T;
	}
}

void L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		t=A.F->data;
		TEMP=A.F;
		A.F=A.F->next;
		cout<<"\nElement deleted : "<<t;
		delete(TEMP);
	}
}

void L_print(Queue A)
{
	QPTR TEMP=A.F;
	while(TEMP!=NULL)
	{
		cout<<TEMP->data<<" ";
		TEMP=TEMP->next;
	}
}

int main()
{
	Queue Q;
	Q.F=NULL;
	Q.R=NULL;
	int n=0;
	cout<<"\nEnter elements and -1 to stop : ";
	cin>>n;
	while(n != -1)
	{
		L_enq(Q,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	cout<<"\nList is : ";
	L_print(Q);
	cout<<"\nElement removed!";
	L_deq(Q);
	L_deq(Q);
	L_deq(Q);
	cout<<"\nList is : ";
	L_print(Q);
	return 0;
}
