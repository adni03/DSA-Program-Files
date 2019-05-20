//HIDDEN VIEW

#include<iostream>
using namespace std;

struct btnode{
	char data;
	int space, hd;
	struct btnode *next;
	struct btnode *LC=NULL;
	struct btnode *RC=NULL;
};

struct qnode{
	struct btnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct qnode* QPTR;
typedef struct btnode *BTPTR;

void insert(BTPTR &T, char x[], int &i, int n){
	if(T==NULL)
	{
		if(x[i]!='.'){
			T=new(btnode);
			T->data=x[i];
			T->hd=n;
			T->next=NULL;
			T->LC=NULL;
			T->RC=NULL;
			++i;
		}
	}
	if(x[i]!='.'){
		--n;
		insert(T->LC,x,i,n);
	}
	else ++i;
	if(x[i]!='.'){
		n+=2;
		insert(T->RC,x,i,n);
	}
	else ++i;
}

void L_enq(Queue &A, BTPTR M)
{
	QPTR T=NULL, F=A.F;
	T=new(qnode);
	T->TEMP=M;
	if(A.F == NULL)
	{
		A.F=T;
		A.R=T;
		T->next=NULL;
	}	
	else
	{
		while(F!=A.R)
			F=F->next;
		T->next=NULL;
		F->next=T;
		A.R=T;
	}
}

void number_it(BTPTR T, int &i){
	if(T==NULL)
		return ;
	else
	{
		number_it(T->LC,i);
		T->space=i;
		++i;
		number_it(T->RC,i);
	}
}

BTPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		BTPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}

void print_same(Queue A, BTPTR T){
	int i=0, k=1;
	L_enq(A,T);
	L_enq(A,NULL);
	number_it(T,k);
	do
	{
		T=L_deq(A);
		if(T==NULL)
		{
			cout<<endl;
			T=L_deq(A);
			L_enq(A,NULL);
			i=0;
		}
		for(int j=T->space-1; j>i; --j) cout<<" ";
		i=T->space;
		cout<<T->data;
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

void min_hd(BTPTR T, int &n){
	if(T){
		if(T->hd<n) n=T->hd;
		min_hd(T->LC,n);
		min_hd(T->RC,n);
	}
}

void max_hd(BTPTR T, int &n){
	if(T){
		if(T->hd > n) n=T->hd;
		max_hd(T->RC,n);
		max_hd(T->LC,n);
	}
}

void v_enq(BTPTR T,Queue Q[], int s){
	if(T){
		L_enq(Q[T->hd - s],T);
		v_enq(T->LC,Q,s);
		v_enq(T->RC,Q,s);
	}
}

void print_hidden(Queue Q[], BTPTR T, int t){
	int i=0;
	while(i<t){
		L_deq(Q[i]);
		while(Q[i].F){
			if(Q[i].F!=Q[i].R) cout<<L_deq(Q[i])->data<<" ";
			else break;
		}
		++i;
	}
}
int main()
{
	BTPTR T1=NULL;
	Queue A, Q[10];
	int i=0,min=0,max=0;
	char c1[]={'A','D','E','G','.','H','I','.','.','J','.','.','F','.','.','M','.','.','P','.','N','L','.','.','S','.','.'};
	insert(T1,c1,i,0);
	cout<<"Original Binary Tree is : "<<endl;
	print_same(A,T1);
	min_hd(T1,min);
	max_hd(T1,max);
	v_enq(T1,Q,min);
	cout<<"\nHidden view is : ";
	print_hidden(Q,T1,max-min+1);
	return 0;
}
