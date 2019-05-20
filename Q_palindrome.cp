//CHECKS IF STACK IS PALLINDROME OR NOT USING QUEUE

#include<iostream>
using namespace std;

struct stack 
{
	int size, top, str[50];
};

struct queue
{
	int size, f, r, ele[50];
};

void push(stack &m, int x);
int pop(stack &m);
void enq(queue &q, int x);
int delq(queue &q);
void pallindrome(stack &m, queue &q);

int main()
{
	struct stack s;
	struct queue qu;
	int a;
	s.top = -1;
	qu.f = qu.r = -1;
	cout<<"\nEnter size : ";
	cin>>s.size;
	qu.size = s.size;
	cout<<"\nEnter elements : ";
	for(int i=0; i<s.size; i++)
	{
		cin>>a;
		push(s,a);
	}
	pallindrome(s,qu);
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

void enq(queue &q, int x)
{
	if(q.f == (q.r +1)%q.size)
		cout<<"\nFull!";
	else
	{
		if(q.f == -1)
			q.f=0;
		q.r=(q.r + 1)%q.size;
		q.ele[q.r] = x;
	}		
}

int delq(queue &q)
{
	int t;
	if(q.f == -1)
		cout<<"\nEmpty!";
	else
	{
		t=q.ele[q.r];
		if(q.f == q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
			q.f=(q.f+1)%q.size;
		return t;
	}
}
