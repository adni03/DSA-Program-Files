//ADDITION

#include<iostream>
using namespace std;

struct node{
	int data, space;
	struct node *LC;
	struct node *RC;
};

struct qnode{
	struct node *TEMP;
	struct qnode *next;
};

struct Queue{
	struct qnode *F;
	struct qnode *R;
};

struct snode{
	struct node *TR;
	struct snode *next;
};

struct stack{
	struct snode *T;
};

typedef struct qnode* QPTR;
typedef struct node *BSTPTR;
typedef struct snode* SPTR;
BSTPTR pop(stack &m)
{
	SPTR TEMP=m.T;
	BSTPTR x=TEMP->TR;
	m.T=m.T->next;
	delete(TEMP);
	return x;	
}
void push(stack &m, BSTPTR B)
{
	SPTR TEMP;
	TEMP=new(snode);
	TEMP->TR = B;
	TEMP->next=m.T;
	m.T=TEMP;
}
void insert(BSTPTR &T, int x){
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->LC=NULL;
		T->RC=NULL;
	}
	else if(T->data > x)
		insert(T->LC,x);
	else if(T->data < x)
		insert(T->RC,x);
	else
		cout<<"\nDuplicate!";
}
void L_enq(Queue &A, BSTPTR M)
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
void number_it(BSTPTR T){
	static int i=1;
	if(T==NULL)
		return ;
	else
	{
		number_it(T->LC);
		T->space=i;
		++i;
		number_it(T->RC);
	}
}
BSTPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		BSTPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}
void print_same(Queue A, BSTPTR T){
	int i=0;
	L_enq(A,T);
	L_enq(A,NULL);
	number_it(T);
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
void add_nodes(BSTPTR &T){
	static int sum=0;
	if(T){
		add_nodes(T->RC);
		sum+=T->data;
		T->data=sum;
		add_nodes(T->LC);
	}
}

int main()
{
	BSTPTR T=NULL;
	Queue A; A.F=A.R=NULL;
	stack m; m.T=NULL;
	insert(T,50);
	insert(T,30);
	insert(T,70);
	insert(T,20);
	insert(T,40);
	insert(T,60);
	insert(T,80);
	cout<<"\nOld Binary Search Tree is : "<<endl;
	print_same(A,T);
	add_nodes(T);
	cout<<"\nNew Binary Search Tree is : "<<endl;
	print_same(A,T);
	return 0;
}
