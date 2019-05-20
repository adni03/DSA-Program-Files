//MULTILIST THE PROPER WAY

#include<iostream>
#include<ctype.h>
using namespace std;

union u
{
	char c;
	struct node *dlink=NULL;
};

struct node
{
	int tag;
	struct node *next=NULL;
	union u data; 
};

typedef struct node *LPTR;

LPTR create(LPTR L, char ch[], int n){
	static int i=0;
	if(i<n){
		if(ch[i]=='{'){
			L=new(node);
			L->tag=1;
			++i;
			L->data.dlink=create(L->data.dlink,ch,n);
			++i;
			L->next=create(L->next,ch,n);
			return L;
		}
		else if(ch[i]!='}' && ch[i]!='{'){
			L=new(node);
			L->tag=0;
			L->data.c=ch[i++];
			L->next=create(L->next,ch,n);
			return L;
		}
		else if(ch[i]=='}'){
			return NULL;
		}
	}
	return L;
}

void print(LPTR L)
{
	if(L){
		if(L->tag==0){
			cout<<L->data.c<<" ";
			print(L->next);
		}
		else{
			cout<<"{ ";
			print(L->data.dlink);
			cout<<"} ";
			print(L->next);
		}
	}
}

int main()
{
	LPTR M=NULL;
	char ch[20]={'{','a','b','{','c','d','{','e','f','}','g','h','}','i','j','}'};
	M=create(M,ch,16);
	cout<<"Flattened list is : ";
	print(M);
	return 0;
}
