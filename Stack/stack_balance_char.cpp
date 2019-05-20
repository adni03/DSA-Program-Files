//BALANCING CHARACTERS USING STACK	


#include<iostream>
using namespace std;

struct stack 
{
	int size, top;
	char elements[50];
};
void push(stack &m, char x);
char pop(stack &m);
void balance(stack &m, char c[]);

int main()
{
	struct stack s;
	char str[6];
	s.size = 50;
	s.top= -1;
	cout<<"\nEnter the string : ";
	for(int i=0; i<6; i++)
	{
		cin>>str[i];
	}
	balance(s,str);
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

void balance(stack &m, char c[])
{
	int i=0, flag=-1;
	while(c[i] != '\0')
	{
		if(c[i] == '{')
			push(m,c[i]);
			
		if(m.top > -1 && c[i+1] == '\0' && c[i] == '{')
			cout<<"\nNot balanced!";
		else if(c[i] == '}')
		{
			pop(m);
			if(m.top < -1 && c[i+1] != '\0')
			{
				cout<<"\nNot balanced!";
				flag=0;
				break;
			}
			else if(m.top > -1 && c[i+1] == '\0')
				cout<<"\nNot Balanced!";
			else if(m.top == -1 && c[i+1] == '\0')
				cout<<"\nBalanced!";
		}
		i++;
	}	
}
