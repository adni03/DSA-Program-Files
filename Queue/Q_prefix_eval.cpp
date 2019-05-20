//PREFIX EVALUATION

#include<iostream>
using namespace std;

union u
{
	int a;
	char b;
};

struct queue
{
	int size, f, r;
	int tag[50];
	union u ele[50];
};

void enqi(queue &q, int x)
{
	if(q.f == (q.r +1)%q.size)
		cout<<"\nFull!";
	else
	{
		if(q.f == -1)
			q.f=0; 
		q.r=(q.r + 1)%q.size;
		q.ele[q.r].a = x;
	}		
}

void enqc(queue &q, char x)
{
	if(q.f == (q.r +1)%q.size)
		cout<<"\nFull!";
	else
	{
		if(q.f == -1)
			q.f=0;
		q.r=(q.r + 1)%q.size;
		q.ele[q.r].b = x;
	}		
}

int delqi(queue &q)
{
	int t;
	if(q.f == -1)
		cout<<"\nEmpty!";
	else
	{
		t=q.ele[q.f].a;
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

char delqc(queue &q)
{
	char t;
	if(q.f == -1)
		cout<<"\nEmpty!";
	else
	{
		t=q.ele[q.f].b;
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

void eval_prefix(queue &m, queue &n)
{
	int flag=1, i=0;
	if(m.f != m.r)
	{
		while(i<m.r)
		{
			flag=1;
			if(m.tag[m.f] == 2)
			{
				if(m.tag[m.f+1]==1 && m.tag[m.f+2]==1)
					flag=0;
				if(flag == 0)
				{
					int n1=0,n2=0;
					char c;
					c=delqc(m);
					n1=delqi(m);
					n2=delqi(m);
					enqi(n,eval(n2,n1,c));
					n.tag[n.r] = 1;
				}
				else
				{
					enqc(n,delqc(m));
					n.tag[n.r] = 2;
				}
			}
			else if(m.tag[m.f] == 1)
			{
				enqi(n,delqi(m));
				n.tag[n.r] = 1;
			}
			i++;
		}
		eval_prefix(n,m);
	}
	else if(m.f == 0 && m.r == 0)
	{
		cout<<"\nThe result is : "<<delqi(m);
	}
}

int main()
{
	struct queue q1,q2;
	q1.f=q1.r=-1;
	q2.f=q2.r=-1;
	int i, ch;
	char c;
	cout<<"\nEnter length of the sequence : ";
	cin>>q1.size;
	cout<<"\n1. Integer\n2. Character";
	for(i=0; i<q1.size; i++)
	{
		cout<<"\nEnter choice : ";
		cin>>q1.tag[i];
		cout<<"\nEnter element : ";
		switch(q1.tag[i])
		{
			case 1: cin>>ch; enqi(q1,ch); break;
			case 2: cin>>c; enqc(q1,c); break;
		}
	}
	eval_prefix(q1,q2);
	return 0;
}
