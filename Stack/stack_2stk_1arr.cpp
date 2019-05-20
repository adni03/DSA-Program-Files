//2 STACK 1 ARRAY

#include<iostream>
using namespace std;

struct stack1 
{
	int size, elements;
	int *top;
};
struct stack2 
{
	int size, elements;
	int *top;
};

void push(stack1 &m, int x, int a[]);
int pop(stack1 &m, int a[]);
void push(stack1 &p, stack2 &m, int x, int a[]);
int pop(stack1 &p, stack2 &m, int a[]);


int main()
{
	struct stack1 s1;
	struct stack2 s2;
	int array[52];
	cout<<"\nEnter size of stack 1 : ";
	cin>>s1.size;
	cout<<"\nEnter size of stack 2 : ";
	cin>>s2.size;
	s1.top = &array[0];
	s2.top = &array[52];
	cout<<"\nEnter elements for array 1 : ";
	while(s1.top < &array[s1.size])
	{
		cin>>s1.elements;
		push(s1,s1.elements,array);
	}
	cout<<"\nEnter elements for array 2 : ";
	while(s2.top > &array[52-s2.size])
	{
		cin>>s2.elements;
		push(s1,s2,s2.elements,array);
	}
	cout<<"\nElements of stack 1 : ";
	while(s1.top > &array[0])
	{
		cout<<pop(s1,array)<<" ";
	}
	cout<<"\nElements of stack 2 : ";
	while(s2.top < &array[52])
	{
		cout<<pop(s1,s2,array)<<" ";
	}
	return 0;
}

void push(stack1 &m, int x, int a[])
{
	if(m.top == &a[0])
	{
		++m.top;
		*m.top = x;	
	}
	else if(m.top < &a[m.size])
	{
		m.top++;
		*m.top = x;
	}
	else
		cout<<"\nOverflow";
}

int pop(stack1 &m, int a[])
{
	if(m.top == &a[0])
		cout<<"\nEmpty";
	else 
		return (*m.top--);
}

void push(stack1 &p, stack2 &m, int x, int a[])
{
	if(m.top == &a[52])
	{
		--m.top;
		*m.top = x;	
	}
	else if(m.top > &a[52-p.size])
	{
		--m.top;
		*m.top = x;
	}
	else
		cout<<"\nOverflow";
}

int pop(stack1 &p, stack2 &m, int a[])
{
	if(m.top == &a[52])
		cout<<"\nEmpty";
	else 
		return (*m.top++);
}


