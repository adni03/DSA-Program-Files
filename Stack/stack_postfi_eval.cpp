//POSTFIX EVALUATION 

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
	int size, top;
	int elements[50];
};

//function defs

void push(stack &m, int x);
int pop(stack &m);
int eval(int op1, int op2, char opt);
void eval_post(stack &m, un u1[], int t[]);

int main()
{
	struct stack s;
	union un u1[50];
	int tag[50];
	s.size = 50;
	s.top= -1;
	eval_post(s,u1,tag);
	return 0;
}

void push(stack &m, int x)
{
	if(m.top < m.size-1)
		m.elements[++m.top] = x;
	else
		cout<<"\nOverflow";
}

int pop(stack &m)
{
	if(m.top == -1)
		cout<<"\nEmpty";
	else 
		return (m.elements[m.top--]);
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


