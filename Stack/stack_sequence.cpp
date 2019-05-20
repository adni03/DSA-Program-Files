//SEQUENCE 

#include<iostream>
using namespace std;

struct stack 
{
	int size, top, elements[50];
};

int os[6]={1,2,3,4,5,6};

void push(stack &m, int x);
int pop(stack &m);
void see_rest(stack &m, int n[]);
void chk_seq(stack &m, int n[], int &t);

int main()
{
	struct stack s;
	int seq[6],cur=0;
	s.size = 50;
	s.top= -1;
	cout<<"\nEnter sequence : ";
	for(int i=0; i<6; i++)
	{
		cin>>seq[i];
	}
	chk_seq(s,seq,cur);
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

void see_rest(stack &m, int n[], int &t)
{
	int i,k=t;
	for(i=m.top; i>-1; i--, k++)
	{
		if(m.elements[i] == n[k])
		{
			pop(m);
			t++;
		}
	}
}
void chk_seq(stack &m, int n[], int &t)
{
	int i=0;
	for(i=0; i<6; i++)
	{
		if(os[i] != n[t])
			push(m,os[i]);
		else
		{
			t++;
			see_rest(m,n,t);
		}
	}
	if(t==6 && m.top == -1)
		cout<<"\nValid Sequence!";
	else
		cout<<"\nInvalid Sequence!";
}
