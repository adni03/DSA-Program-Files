//MULTILIST THE PROPER WAY

#include<iostream>
#include<ctype.h>
using namespace std;

struct node
{
	char data;
	struct node *L;
	struct node *R;
	struct node *dlink;
};

typedef struct node *LPTR;

void create(LPTR &L, char ch[])
{
	static int i=0;
	if(ch[i]=='\0')
		return ;
	else if(ch[i]=='{')
	{
		if(i==0)
		{
			++i;
			create(L,ch);
		}
		else
		{
			LPTR T=new(node);
			LPTR TEMP=L;
			TEMP->R=T;	
			T->L=TEMP;
			T->R=NULL;
			T->dlink=NULL;
			++i;
			create(T->dlink,ch);
			create(T->R,ch);
		}	
	}
	else if(isalpha(ch[i]))
	{
		LPTR T=new(node);
		T->data=ch[i];
		if(L==NULL)
		{
			T->R=NULL;
			T->L=NULL;
			T->dlink=NULL;
			L=T;
			++i;
			create(L,ch);
		}
		else
		{
			LPTR TEMP=L;
			TEMP->R=T;
			T->R=NULL;
			T->L=TEMP;
			T->dlink=NULL;
			++i;
			create(T,ch);
		}
	}
	else if(ch[i]=='}')
	{
		++i;
		return ;
	}
}

void print(LPTR L)
{
	if(L==NULL)
		return ;
	else if(L->dlink==NULL)
	{
		cout<<L->data<<" ";
		print(L->R);
	}
	else if(L->dlink!=NULL) 
	{
		cout<<"{ ";
		print(L->dlink);
		cout<<"} ";
		print(L->R);
	}
}

int main()
{
	LPTR M=NULL;
	char ch[20]={'{','a','b','{','c','d','{','e','f','}','g','h','}','i','j','}'};
	create(M,ch);
	cout<<"{";
	print(M);
	cout<<"}";
	return 0;
}
