//GENERIC STACK

#include<iostream>
#include<string.h>
using namespace std;

union u 
{
	int u1;
	float u2;
	char u3, u4[10];
};
struct stack 
{
	int size, top, tag[50];
	union u elements[50];
};
void push(stack &m, int x);
void push(stack &m, float x);
void push(stack &m, char x);
void push(stack &m, char x[]);
void pop(stack &m, int a);
int get_top(stack &m);
void sw(stack &m, int a);

int main()
{
	struct stack s;
	s.size = 50;
	s.top= -1;
	cout<<"\nEnter information : ";
	cout<<"\n1. Integer\n2. Float\n3. Character\n4. Character array";
	for(int i=0; i<3; i++)
	{
		cout<<"\nEnter choice : ";
		cin>>s.tag[i];
		sw(s,s.tag[i]);
	}
	for(int i=2; i>=0; i--)
	{
		pop(s,s.tag[i]);
	}
	return 0;
}

void push(stack &m, int x)
{
	if(m.top < m.size-1)
		m.elements[++m.top].u1 = x;
	else
		cout<<"\nOverflow";
}

void push(stack &m, float x)
{
	if(m.top < m.size-1)
		m.elements[++m.top].u2 = x;
	else
		cout<<"\nOverflow";
}

void push(stack &m, char x)
{
	if(m.top < m.size-1)
		m.elements[++m.top].u3 = x;
	else
		cout<<"\nOverflow";
}

void push(stack &m, char x[])
{
	if(m.top < m.size-1)
		strcpy(m.elements[++m.top].u4,x);
	else
		cout<<"\nOverflow";
}

void pop(stack &m, int a)
{
	if(m.top == -1)
		cout<<"\nEmpty";
	else
	{
	 	switch(a)
		 {
		  	case 1:  cout<<m.elements[m.top--].u1<<endl; break;
		  	case 2:	 cout<<m.elements[m.top--].u2<<endl; break;
		  	case 3:  cout<<m.elements[m.top--].u3<<endl; break;
		  	case 4:  cout<<m.elements[m.top--].u4<<endl; break;
		}
	}
}

void sw(stack &m, int a)
{
	int cnt=0;
	float cnt2;
	char cnt3, cnt4[10];
	switch(a)
	{
		case 1: 
				cout<<"\nEnter integer : ";
				cin>>cnt;
				push(m,(int)cnt);
				break;
		case 2:
				cout<<"\nEnter fraction : ";
				cin>>cnt2;
				push(m,cnt2);
				break;
		case 3:
				cout<<"\nEnter character : ";
				cin>>cnt3;
				push(m,cnt3);
				break;
		case 4:
				cout<<"\nEnter string : ";
				cin.ignore();
				cin.get(cnt4,10);
				push(m,cnt4);
				break;
				
	}
}

