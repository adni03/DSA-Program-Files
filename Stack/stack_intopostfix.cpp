//INFIX TO POSTFIX

#include<iostream>
#include<ctype.h>
using namespace std;


struct stack 
{
	int size, top;
	char elements[50];
};

//function defs

void push(stack &m, char x);
char pop(stack &m);
void convert(stack &m, char c[], int n);
void decide(stack &m, char c);
void pop_dat(stack &m, char c);

int main()
{
	struct stack s;
	int l=0;
	char ch[50];
	s.size = 50;
	s.top= -1;
	cout<<"\nEnter length of expression : ";
	cin>>l;
	cout<<"\nEnter expression : ";
	for(int i=0; i<l; i++)
	{
		cin>>ch[i];	
	}
	convert(s,ch,l);
	return 0;
}

void push(stack &m, char x)
{
	if(m.top < m.size-1)
		m.elements[++m.top] = x;
	else
		cout<<"\nOverflow";
}

char pop(stack &m)
{
	if(m.top == -1)
		cout<<"\nEmpty";
	else 
		return (m.elements[m.top--]);
}

void decide(stack &m, char c)
{
	if(m.top == -1)
		push(m,c);
	else if(c == '*')
	{
		char t = m.elements[m.top];
		switch(t)
			{
				case '*':	cout<<pop(m)<<" "; push(m,c); break;
				case '/':	cout<<pop(m)<<" "; push(m,c); break;
				case '+':	push(m,c); break;
				case '-':	push(m,c); break;
				case '(':	push(m,c); break;
			}
	}
	else if(c == '/')
	{
		char t = m.elements[m.top];
		switch(t)
			{
				case '*':	cout<<pop(m)<<" "; push(m,c); break;
				case '/':	cout<<pop(m)<<" "; push(m,c); break;
				case '+':	push(m,c); break;
				case '-':	push(m,c); break;
				case '(':	push(m,c); break;
			}	
	}
	else if(c == '+')
	{
		char t;
		int i=m.top, flag=1;
		while(i>-1)
		{
			t = m.elements[m.top];
			switch(t)
			{
				case '*':	cout<<pop(m)<<" "; break;
				case '/':	cout<<pop(m)<<" "; break;
				case '+':	cout<<pop(m)<<" "; break;
				case '-':	cout<<pop(m)<<" "; break;
				case '(':	push(m,c); flag=0; break;
			}
			i--;
		}
		if(flag)
			push(m,c);		
	}
	else if(c == '-')
	{
		char t;
		int i=m.top, flag=1;
		while(i>-1)
		{
			t = m.elements[m.top];
			switch(t)
			{
				case '*':	cout<<pop(m)<<" "; break;
				case '/':	cout<<pop(m)<<" "; break;
				case '+':	cout<<pop(m)<<" "; break;
				case '-':	cout<<pop(m)<<" "; break;
				case '(':	push(m,c); flag=0; break;
			}
			i--;
		}
		if(flag)
			push(m,c);		
	}
	else if(c == '(')
		push(m,c);
	else if(c == ')')
	{
		while(m.elements[m.top] != '(')
		{
			cout<<pop(m)<<" ";
		}
		m.top--;
	}
}
void convert(stack &m, char c[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(!isalpha(c[i]))
		{
			decide(m,c[i]);
		}
		else
		{
			cout<<c[i]<<" ";
		}
	}
	if(m.top > -1)
	{
		while(m.top > -1)
		{
			cout<<pop(m)<<" ";
		}
	}
}
