//LINKED LIST STACK

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct stack
{
	struct node *T;
};

typedef struct node* SPTR;

int pop(stack &m)
{
	SPTR TEMP=m.T;
	int x=TEMP->data;
	m.T=m.T->next;
	delete(TEMP);
	return x;	
}

void push(stack &m, int n)
{
	SPTR TEMP;
	TEMP=new(node);
	TEMP->data = n;
	TEMP->next=m.T;
	m.T=TEMP;
}

void print(stack m)
{
	SPTR TEMP=m.T;
	while(TEMP!=NULL)
	{
		cout<<TEMP->data<<" ";
		TEMP=TEMP->next;
	}
}

int main()
{
	struct stack s;
	s.T=NULL;
	int i=0, n=0;
	cout<<"\nEnter elements and -1 to stop : ";
	cin>>n;
	while(n != -1)
	{
		push(s,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	pop(s);
	pop(s);
	cout<<"\nPopped twice!";
	cout<<endl;
	print(s);
	return 0;
}
