//MINOR STACK PROBLEM

#include<iostream>
#include<ctype.h>
#include<string.h>
using namespace std;

struct stack 
{
	int size, top;
	char elements[50];
};

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

void decode(stack m1, char ch[])
{
	int i=0,j=0,k=0;
	char c[20];
	while(ch[i]!='\0')
	{
		if(ch[i]!=']')
		{
			push(m1,ch[i]);
			++i;
		}
		else if(ch[i]==']')
		{
			k=0;
			//cout<<"m1.top: "<<m1.top<<endl;
			while(m1.elements[m1.top]!='[')
			{
				c[k]=pop(m1);
				++k;
			}
			pop(m1);
			int n=(int)pop(m1) - (int)'0';
			int len=strlen(c);
			for(j=n; j>0; --j)
			{
				for(k=len-1; k>=0; --k)
					push(m1,c[k]);
			}
			++i;
		}
	}
	k=0; j=0;
	while(m1.top!=-1)
	{
		c[k]=pop(m1);
		++k; ++j;
	}
	for(i=j-1; i>=0; --i)
		cout<<c[i];
}

int main()
{
	char c[20]={'3','[','a','2','[','c',']',']','d','e'};
	stack m1, m2;
	m1.top=-1; m1.size=50;
	//m2.top=-1; m2.size=50;
	cout<<"\nDecoded string is : ";
	decode(m1,c);
	return 0;
}
