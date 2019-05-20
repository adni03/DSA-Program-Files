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
void write_erase(stack &m, queue &q);
void pal_chk(stack &m, queue &q);

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
	write_erase(s,qu);
	return 0;
}

void push(stack &m, int x)
{
	if(m.top < m.size-1)
		m.str[++m.top] = x;
	else
		cout<<"\nOverflow";
}

int pop(stack &m)
{
	if(m.top == -1)
		cout<<"\nEmpty";
	else 
		return (m.str[m.top--]);
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
		t=q.ele[q.f];
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

void write_erase(stack &m, queue &q)
{
	while(m.top > -1)
	{
		int a;
		a=pop(m);
		enq(q,a);
	}
	if(m.size%2 == 0)
	{
		while(q.f < q.size/2)
		{
			int a;
			a=delq(q);
			push(m,a);
		}
		pal_chk(m,q);
	}
	else
	{
		while(q.f < q.size/2)
		{
			int a;
			a=delq(q);
			push(m,a);
		}
		delq(q);
		pal_chk(m,q);
	}
}

void pal_chk(stack &m, queue &q)
{
	int flag=-1;
	while(m.top > -1)
	{
		if(m.str[m.top] == q.ele[q.f])
		{
			pop(m);
			delq(q);
		}
		else
		{
			flag=0; 
			break;
		}
	}
	if(flag == -1)
		cout<<"\nPallindrome!";
	else 
		cout<<"\nNot Pallindrome!";
}

