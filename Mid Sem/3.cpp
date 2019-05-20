//3

#include<iostream>
#include<ctype.h>
using namespace std;

union u{
	char opt;
	int opd;
};

struct etnode{
	union u data;
	int tag, space;
	struct etnode *LC=NULL;
	struct etnode *RC=NULL;
};

struct snode{
	struct etnode *TR=NULL;
	struct snode *next=NULL;
};

struct stack{
	struct snode *T=NULL;
};

struct qnode{
	struct etnode *TR=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct qnode* QPTR;
typedef struct etnode* ETPTR;
typedef struct snode* SPTR;

ETPTR pop(stack &m)
{
	SPTR TEMP=m.T;
	ETPTR x=TEMP->TR;
	m.T=m.T->next;
	delete(TEMP);
	return x;	
}

void push(stack &m, ETPTR B)
{
	SPTR TEMP;
	TEMP=new(snode);
	TEMP->TR = B;
	TEMP->next=m.T;
	m.T=TEMP;
}

void insert(ETPTR &T, u u1[], int n, int tag[], stack m){
	static int i=0;
	if(i<n){
		if(tag[i]==0){
			ETPTR TEMP=new(etnode);
			TEMP->data.opd=u1[i].opd;
			TEMP->tag=0;
			TEMP->LC=TEMP->RC=NULL;
			push(m,TEMP);
			++i;
			insert(T,u1,n,tag,m);
		}
		else if(tag[i]==1){
			ETPTR T1=pop(m), T2=pop(m);
			T=new(etnode);
			T->data.opt=u1[i].opt;
			T->tag=1;
			T->LC=T2;
			T->RC=T1;
			push(m,T);
			++i;
			insert(T,u1,n,tag,m);
		}
	}
}

void L_enq(Queue &A, ETPTR M)
{
	QPTR T=NULL, F=A.F;
	T=new(qnode);
	T->TR=M;
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

ETPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		ETPTR P=A.F->TR;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}

int calc(int op1, int op2, char opt)
{
	switch(opt)
	{
		case '*': return (op2*op1); 
		case '/': return (op2/op1);
		case '+': return (op2+op1);
		case '-': return (op2-op1);
	}
}

void qthatish(Queue &A, stack &m, ETPTR T){
	L_enq(A,T);
	do
	{
		T=L_deq(A);
		if(T){
			push(m,T);
			if(T->LC) L_enq(A,T->LC);
			if(T->RC) L_enq(A,T->RC);
		}
	}while(A.F!=NULL);
	while(m.T) L_enq(A,pop(m));
}

int eval(Queue &A){
	int flag=1;
	while(A.F->next){
		if(A.F->next->next){
			ETPTR T1=L_deq(A);
			ETPTR T2=L_deq(A);
			ETPTR T3=L_deq(A);
			if(T1->tag==0 && T2->tag==0 && T3->tag==1){
				ETPTR T4=new(etnode);
				T4->tag=0;
				T4->data.opd=calc(T1->data.opd,T2->data.opd,T3->data.opt);
				L_enq(A,T4);
			}
			else{
				if(flag==1){
					L_enq(A,T3);
					L_enq(A,T2);
					L_enq(A,T1);
				}
				else{
					L_enq(A,T1);
					L_enq(A,T2);
					L_enq(A,T3);
				}
				flag*=-1;
			}
		}
		else break;
	}
	return L_deq(A)->data.opd;
}

int main()
{
	ETPTR T=NULL;
	union u u1[50];
	int tag[50], ch, n=0;
	stack m;
	Queue A;
	cout<<"1. Integer\n2. Character\n3. Stop";
	cout<<"\nEnter choice : ";
	cin>>ch;
	while(ch!=3){
		switch(ch){
			case 1: cout<<"Enter integer : ";
					cin>>u1[n].opd;
					tag[n]=0; n++; break;
			case 2: cout<<"Enter character : ";
					cin>>u1[n].opt;
					tag[n]=1; n++; break;
		}
		cout<<"Enter choice : ";
		cin>>ch;
	}
	insert(T,u1,n,tag,m);
	qthatish(A,m,T);
	cout<<"Answer is : "<<eval(A);
	return 0;
}
