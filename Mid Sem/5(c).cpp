//INTER-LEAVE

#include<iostream>
using namespace std;

struct queue
{
	int size, f, r, ele[50];
};

struct stack 
{
	int size, top, str[50];
};

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

void print(queue q){
	while(q.f!=q.r)
		cout<<q.ele[q.f++]<<" ";
	cout<<q.ele[q.r];
}

void inter_leave(queue &q){
	stack s; s.top=-1;
	for(int i=0; i<q.size/2; i++) push(s,delq(q));
	while(s.top!=-1) enq(q,pop(s));
	for(int i=0; i<q.size/2; i++) enq(q,delq(q));
	for(int i=0; i<q.size/2; i++) push(s,delq(q));
	while(s.top!=-1){
		enq(q,pop(s));
		enq(q,delq(q));
	}
}

int main()
{
	queue q; q.f=q.r=-1; q.size=10;
	enq(q,11);
	enq(q,12);
	enq(q,13);
	enq(q,14);
	enq(q,15);
	enq(q,16);
	enq(q,17);
	enq(q,18);
	enq(q,19);
	enq(q,20);
	cout<<"Queue is : ";
	print(q);
	inter_leave(q);
	cout<<"\nNew queue is : ";
	print(q);
	return 0;
}

