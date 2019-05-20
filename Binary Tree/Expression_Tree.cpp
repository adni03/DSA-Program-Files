//EXPRESSION TREE

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
			ETPTR T2=pop(m), T1=pop(m);
			T=new(etnode);
			T->data.opt=u1[i].opt;
			T->tag=1;
			T->LC=T1;
			T->RC=T2;
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

void number_it(ETPTR T, int &i){
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

void print_same(Queue A, ETPTR T){
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
		if(T->tag==0) cout<<T->data.opd;
		else	cout<<T->data.opt;
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
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

int eval(ETPTR T){
	if(T){
		if(!T->LC && !T->RC)
			return T->data.opd;
		else
			return(calc(eval(T->RC),eval(T->LC),T->data.opt));
	}
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
	print_same(A,T);
	cout<<"\nEvaluating the postfix expression gives : "<<eval(T);
	return 0;
}


