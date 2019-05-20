//PALINDROME SENTENCE

#include<iostream>
#include<string.h>
using namespace std;

struct lnode
{
	char data[30];
	struct lnode *next;
};

struct stack 
{
	int top, size;
	char c[75];
};

typedef struct lnode* LPTR;

int count (LPTR L)
{
	if(L == NULL)
		return 0;
	else
		return (1+count(L->next));
}

void push(stack &m, char x)
{
	if(m.top < m.size-1)
		m.c[++m.top] = x;
	else
		cout<<"\nOverflow";
}

char pop(stack &m)
{
	if(m.top == -1)
		cout<<"\nEmpty";
	else 
		return (m.c[m.top--]);
}

void print(LPTR L)
{
	if(L != NULL)
	{
		cout<<L->data<<" ";		
		print(L->next);
	}
}

void insert_f(LPTR &L, char n[])
{
	LPTR T;
	T=new(lnode);
	strcpy(T->data, n);
	T->next=L;
	L=T;
}

void insert_end(LPTR &L, char n[])
{
	LPTR T, TEMP=L;
	if(L == NULL)
	{
		insert_f(L,n);
	}
	else
	{
		while(TEMP->next != NULL)
			TEMP=TEMP->next;
		T=new(lnode);
		strcpy(T->data,n);
		T->next = NULL;
		TEMP->next=T;
	}
}

void add_stack(LPTR L, stack &m, char c[])
{
	int i=0;
	for(i=0; c[i]!='\0'; i++)
	{
		push(m,c[i]);
	}
}

void pal_chk(stack &m, char c[])
{
	int flag=0;
	for(int i=0; c[i]!='\0' && m.top>-1; i++)
	{
		if(pop(m) != c[i])
		{
			flag=1;
			break;
		}
	}
	if(flag == 0)
		cout<<"\nPalindrome!";
	else 
		cout<<"\nNot Palindrome!";
}

int main()
{
	char word[10], sent[75];
	LPTR A=NULL;
	struct stack s;
	s.top=-1; s.size=75;
	cout<<"\nEnter words of the sentence one by one (enter stop to stop): ";
	cin>>word;
	while(strcmp(word,"stop")!=0) 
	{
		strcat(sent,word);
		insert_end(A,word);
		add_stack(A,s,word);
		cout<<"\nEnter next word : ";
		cin>>word;
	}
	pal_chk(s,sent);
	return 0;
}
