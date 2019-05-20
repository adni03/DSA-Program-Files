//PALINDROME CHECK LL

#include<iostream>
using namespace std;

struct lnode
{
	int data;
	struct lnode *next;
};

struct stack
{
	int top, ele[50], size;
};

typedef struct lnode* LPTR;

void print(LPTR L)
{
	if(L != NULL)
	{
		cout<<L->data<<" ";		
		print(L->next);
	}
}

void insert_f(LPTR &L, int n)
{
	LPTR T;
	T=new(lnode);
	T->data = n;
	T->next=L;
	L=T;
}

void insert_end(LPTR &L, int n)
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
		T->data = n;
		T->next = NULL;
		TEMP->next=T;
	}
}

void remove(LPTR &L, int x)
{
	LPTR T=NULL, TEMP=L;
	while(TEMP->next->data != x)
		TEMP=TEMP->next;
	T=TEMP->next;
	TEMP->next = T->next;
	delete(T);
}

int count (LPTR L)
{
	if(L == NULL)
		return 0;
	else
		return (1+count(L->next));
}

void push(stack &m, int x)
{
	if(m.top < m.size-1)
		m.ele[++m.top] = x;
	else
		cout<<"\nOverflow";
}

int pop(stack &m)
{
	if(m.top == -1)
		cout<<"\nEmpty";
	else 
		return (m.ele[m.top--]);
}

LPTR find_mid(LPTR L)
{
	LPTR F=L, S=L;
	while(F->next != NULL && F->next->next!=NULL)
	{
		S=S->next;
		F=F->next->next;
	}
	return (S);
}

void pal_chk(LPTR L, stack &m)
{
	LPTR TEMP=L;
	int flag=0;
	while(L != find_mid(TEMP))
	{
		push(m,L->data);
		L=L->next;
	}
	if(count(TEMP)%2!=0)
		L=L->next;
	else
	{
		push(m,L->data);
		L=L->next;
	}
	while(L!=NULL)
	{
		if(pop(m) != L->data)
		{
			flag=1; 
			break;
		}
		else
			L=L->next;
	}
	if(flag == 0)
		cout<<"\nPalindrome!";
	else
		cout<<"\nNot Palindrome!";
}

int main()
{
	struct stack s;
	s.top=-1; s.size=50;
	int n;
	LPTR P=NULL;
	cout<<"\nKeep entering elements in order (-1 to stop) : ";
	cin>>n;
	while(n != -1)
	{
		insert_end(P,n);
		cout<<"\nEnter element : ";
		cin>>n;
	}
	pal_chk(P,s);
	return 0;
}
