// FLIPPING A BINARY TREE

#include<iostream>
using namespace std;

struct btnode{
	char data;
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
typedef struct btnode* BTPTR;

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

void insert(BTPTR &T, char ch[]){
	static int i=0;
	if(ch[i]!='\0'){
		if(ch[i]!='.'){
			T=new(btnode);
			T->data=ch[i++];
			T->LC=T->RC=NULL;
			insert(T->LC,ch);
			i++;
			insert(T->RC,ch);
		}
	}
}

void Flip(BTPTR T, BTPTR P, BTPTR &TEMP){
	if(T){
		Flip(T->LC,T,TEMP);
		if(P){
			T->LC=P->RC;
			T->RC=P;
			P->LC=P->RC=NULL;
		}
	}
	else TEMP=P;
}

void print_line(Queue A, BTPTR T){
	L_enq(A,T);
	L_enq(A,NULL);
	while(A.F!=A.R){
		T=L_deq(A);
		if(!T){
			cout<<"\n";
			T=L_deq(A);
			L_enq(A,NULL);
		}
		cout<<T->data<<" ";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}
}

int main()
{
	char ch[]={'1','2','4','8','.','.','.','5','9','.','.','0','.','.','3','6','.','.','7','.','.'};
	BTPTR T=NULL, Q=NULL;
	Queue A;
	int i=0;
	insert(T,ch);
	cout<<"Tree before flipping : \n";
	print_line(A,T);
	cout<<"\nTree after flipping : \n";
	Flip(T,NULL,Q);
	T=Q;
	print_line(A,T);
	return 0;
}


