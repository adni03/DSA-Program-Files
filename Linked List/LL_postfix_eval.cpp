//POSTFIX EVAL USING STACK

#include<iostream>
#include<ctype.h>
using namespace std;

union un
{
	int a;
	char b;
};
struct stack 
{
	struct node *T;
};
struct node
{
	int data;
	struct node *next;
};

typedef struct node* LPTR;

//function defs

void push(stack &m, int x);
int pop(stack &m);
int eval(int op1, int op2, char opt);
void eval_post(stack &m, un u1[], int t[]);

int main()
{
	struct stack s;
	s.T=NULL;
	union un u1[50];
	int tag[50];
	eval_post(s,u1,tag);
	return 0;
}

int pop(stack &m)
{
	LPTR TEMP=m.T;
	int x=TEMP->data;
	m.T=m.T->next;
	delete(TEMP);
	return x;	
}

void push(stack &m, int n)
{
	LPTR TEMP;
	TEMP=new(node);
	TEMP->data = n;
	TEMP->next=m.T;
	m.T=TEMP;
}

int eval(int op1, int op2, char opt)
{
	switch(opt)
	{
		case '*': return (op2*op1); 
		case '/': return (op2/op1);
		case '+': return (op2+op1);
		case '-': return (op2-op1);
	}
}

void eval_post(stack &m, un u1[], int t[])
{
	int i=0, l;
	cout<<"\nEnter length of expression : ";
	cin>>l;
	cout<<"\nEnter expression : ";
	cout<<"\n1.Integer\n2. Character";
	for(int i=0; i<l; i++)
	{
		cout<<"\nEnter option : ";
		cin>>t[i];
		cout<<"\nEnter : ";
		switch(t[i])
		{
			case 1: cin>>u1[i].a; break;
			case 2: cin>>u1[i].b; break;	
		}
		if(t[i] == 1)
			push(m,u1[i].a);
		else
		{
			int a=0,b=0;
			a = pop(m);
			b = pop(m);
			push(m,eval(a,b,u1[i].b));
		}
	}
	cout<<"Result is  : "<<pop(m);
}


