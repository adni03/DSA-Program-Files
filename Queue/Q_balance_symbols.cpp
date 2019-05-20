//BALANCES ALL SYMBOLS

#include<iostream>
using namespace std;

struct stack 
{
	int size, top;
	char str[50];
};

void push(stack &m, char x)
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

char terminator(char c)
{
	if(c=='[' || c=='{' || c=='<' || c=='(')
	{
		switch(c)
		{
			case '[': return ']'; break;
			case '{': return '}'; break;
			case '<': return '>'; break;
			case '(': return ')'; break;
		}
	}
	else
		return c;
}

void balance_it(stack &m, char ch[])
{
	int i;
	for(i=0; i<m.size; i++)
	{
		if(i == 0)
			push(m,ch[i]);
		else
		{
			if(ch[i] != terminator(m.str[m.top]))
				push(m,ch[i]);
			else
				pop(m);
		}
	}
	if(m.top > -1)
		cout<<"\nUnbalanced!";
	else
		cout<<"\nBalanced!";
}

int main()
{
	struct stack s;
	s.top=-1;
	cout<<"\nEnter size : ";
	cin>>s.size;
	char c[50];
	cout<<"\nEnter the sequence : "<<endl;
	for(int i=0; i<s.size; i++)
	{
		cin>>c[i];
	}
	balance_it(s,c);
	return 0;
}

