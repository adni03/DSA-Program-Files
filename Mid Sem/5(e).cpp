//5)e)

#include<iostream>
using namespace std;

struct lnode
{
	int data;
	struct lnode *next;
};

typedef struct lnode* LPTR;

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

int count (LPTR L)
{
	if(L == NULL)
		return 0;
	else
		return (1+count(L->next));
}

void heap(LPTR H){
	LPTR I=H, J=H, P=H;
	int flag=-1;
	for(int i=0; i<count(H)/2; i++){
		for(int j=0; j<2*i+1; j++) I=I->next;
		J=I->next;
		if(P->data > I->data || P->data > J->data){
			flag=0; break;
		}
		else{
			P=P->next;
			I=H; J=H;
		}
	}
	if(flag==0) cout<<"Not heap!";
	else cout<<"Heap!";
}

int main()
{
	LPTR H=NULL;
	int arr[11]={3,6,4,8,9,7,5,10,18,20,15};
	for(int i=0; i<11; i++)
		insert_end(H,arr[i]);
	heap(H);
	return 0;
}
