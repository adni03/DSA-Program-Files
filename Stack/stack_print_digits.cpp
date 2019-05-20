//PRINT DIGITS OF A NUMBER USING STACK

#include<iostream>
using namespace std;

struct stack 
{
	int size, top, elements[50];
};
void push(stack &m, int x);
int pop(stack &m);
void digit(stack &m, int x);

int main()
{
	struct stack s;
	int num;
	s.size = 50;
	s.top= -1;
	cout<<"\nEnter number : ";
	cin>>num;
	digit(s,num);
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

void digit(stack &m, int x)
{
	while(x != 0)
	{
		push(m,x%10);
		x/=10;
	}
	cout<<"\nThe digits are : "<<endl;
	while(m.top != -1)
	{
		cout<<pop(m)<<" ";
	}
}
