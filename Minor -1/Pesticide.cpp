//5TH PROBLEM

#include<iostream>
using namespace std;

struct lnode{

	int pest,num;
	struct lnode *next;
};

typedef struct lnode* LPTR;

void print(LPTR L){
	if(L != NULL)
	{
		cout<<"("<<L->pest<<","<<L->num<<") ";		
		print(L->next);
	}
}

void insert_f(LPTR &L, int n, int m){
	LPTR T;
	T=new(lnode);
	T->pest=n;
	T->num=m;
	T->next=L;
	L=T;
}

void insert_end(LPTR &L, int n, int m){
	LPTR T, TEMP=L;
	if(L == NULL)
	{
		insert_f(L,n,m);
	}
	else
	{
		while(TEMP->next != NULL)
			TEMP=TEMP->next;
		T=new(lnode);
		T->num = m;
		T->pest=n;
		T->next = NULL;
		TEMP->next=T;
	}
}

void remove(LPTR &L, int x){
	LPTR T=NULL, TEMP=L;
	while(TEMP->next->num != x)
		TEMP=TEMP->next;
	T=TEMP->next;
	TEMP->next = T->next;
	delete(T);
}

void alive_plants(LPTR L){
	int flag;
	LPTR TEMP=L;
	while(1){
		flag=1;
		while(L->next!=NULL){
			if(L->pest < L->next->pest){
				cout<<"\nPlant "<<L->next->num<<" is dead";
				remove(TEMP,L->next->num);
				if(L->next!=NULL)	L=L->next;
				flag=0;
			}
			else if(L->pest > L->next->pest)
				L=L->next;
		}
		L=TEMP;
		if(flag==1)
			break;
	}
}

int main()
{
	LPTR L=NULL;
	int m=0, a, b;
	insert_end(L,6,1);
	insert_end(L,5,2);
	insert_end(L,8,3);
	insert_end(L,4,4);
	insert_end(L,7,5);
	insert_end(L,10,6);
	insert_end(L,9,7);
	alive_plants(L);
	cout<<"\nThe alive plants are : ";
	print(L);
	return 0;
}
