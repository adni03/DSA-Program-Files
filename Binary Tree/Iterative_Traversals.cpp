//ITERATIVE INORDER, PREORDER AND POSTORDER TRAVERSALS

#include<iostream>
using namespace std;

struct btnode{
	char data;
	int space;
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

struct snode{
	struct btnode *TR=NULL;
	struct snode *next=NULL;
};

struct stack{
	struct snode *T=NULL;
};

typedef struct qnode* QPTR;
typedef struct btnode *BTPTR;
typedef struct snode *SPTR;

void insert(BTPTR &T, char x[]){
	static int i=0;
	if(T==NULL)
	{
		if(x[i]!='.'){
			T=new(btnode);
			T->data=x[i];
			T->LC=NULL;
			T->RC=NULL;
			++i;
		}
	}
	if(x[i]!='.')insert(T->LC,x);
	else ++i;
	if(x[i]!='.')insert(T->RC,x);
	else ++i;
}

BTPTR pop(stack &m)
{
	SPTR TEMP=m.T;
	BTPTR x=TEMP->TR;
	m.T=m.T->next;
	delete(TEMP);
	return x;	
}

void push(stack &m, BTPTR B)
{
	SPTR TEMP;
	TEMP=new(snode);
	TEMP->TR = B;
	TEMP->next=m.T;
	m.T=TEMP;
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

void number_it(BTPTR T){
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

void Iinorder(BTPTR T, stack m){
	while(1){
		if(T!=NULL){
			push(m,T);
			T=T->LC;
		}
		else if(T==NULL && m.T){
			T=pop(m);
			cout<<T->data<<" ";
			T=T->RC;
		}
		else break;
	}
}

void Ipreorder(BTPTR T, stack m){
	while(1){
		if(T==NULL && m.T){
			T=pop(m);
			T=T->RC;
		}
		else if(T!=NULL){
			cout<<T->data<<" ";
			push(m,T);
			T=T->LC;
		}
		else break;
	}
}

void Ipostorder(BTPTR T, stack m1, stack m2){
	push(m1,T);
	BTPTR TEMP=NULL;
	while(m1.T){
		TEMP=pop(m1);
		push(m2,TEMP);
		if(TEMP->LC) push(m1,TEMP->LC);
		if(TEMP->RC) push(m1,TEMP->RC);
	}
	while(m2.T)
		cout<<pop(m2)->data<<" ";
}

int main()
{
	char c[]={'A','P','M','L','.','.','J','.','.','R','.','.','B','D','.','N','.','.','E','F','.','.','S','.','.'};
	BTPTR T=NULL;
	Queue A;
	stack m,n;
	int i=0;
	insert(T,c);
	cout<<"\nBinary Tree is : "<<endl;
	print_same(A,T);
	cout<<endl;
	cout<<"\nIterative Inorder traversal gives : ";
	Iinorder(T,m);
	cout<<"\nIterative Preorder traversal gives : ";
	Ipreorder(T,m);
	cout<<"\nIterative Postorder traversal gives : ";
	Ipostorder(T,m,n);
	return 0;
}


