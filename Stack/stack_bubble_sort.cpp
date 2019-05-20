// BUBBLE SORT W/ 2 STACKS 5 VARIABLES

#include<iostream>
using namespace std;

struct stk1 
{
	int size, top, elements[5];
};
struct stk2
{
	int size, top, elements[5];
};

void push(stk1 &m, int x);
int pop(stk1 &m);
void push(stk1 &m, int x);
int pop(stk1 &m);
void bubble_sort(stk1 &m, stk2 &p, int n[]);
void empty_it(stk2 &m, int n[]);

int main()
{
	struct stk1 s1;
	struct stk2 s2;
	int seq[5], l=5;
	s1.size = 5;	s2.size = 5;
	s1.top= -1; 	s2.top = -1;
	cout<<"\nEnter sequence : ";
	for(int i=0; i<5; i++)
		cin>>seq[i];
	bubble_sort(s1,s2,seq);
	return 0;
}

void push(stk1 &m, int x)
{
	if(m.top < m.size-1)
		m.elements[++m.top] = x;
	else
		cout<<"\nOverflow";
}

int pop(stk1 &m)
{
	if(m.top == -1)
		cout<<"\nEmpty";
	else 
		return (m.elements[m.top--]);
}

void push(stk2 &m, int x)
{
	if(m.top < m.size-1)
		m.elements[++m.top] = x;
	else
		cout<<"\nOverflow";
}

int pop(stk2 &m)
{
	if(m.top == -1)
		cout<<"\nEmpty";
	else 
		return (m.elements[m.top--]);
}
void empty_it(stk2 &m, int n[])
{
	int i=m.top;
	while(i>-1)
	{
		n[i] = pop(m);
		i--;
	}
}

void bubble_sort(stk1 &m, stk2 &p, int n[])
{
	int i,j;
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			if(m.top == -1)
				push(m,n[j]);
			else if(n[j] > m.elements[m.top])
			{
				int a;
				a = pop(m);
				push(m,n[j]);
				push(p,a);
			}
			else if(n[j] < m.elements[m.top])
			{
				push(p,n[j]);
			}
		}
		while(m.top > -1)
		{
			int a;
			a = pop(m);
			push(p,a);
		}
		empty_it(p,n);
	}
	cout<<"\nResult is : ";
	for(i=0; i<5; i++)
	{
		cout<<n[i]<<" ";
	}
}
