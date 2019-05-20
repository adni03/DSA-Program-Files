//ROOT TO LEAF PATH

#include<iostream>
using namespace std;

struct node{
	int data, space;
	struct node *LC=NULL;
	struct node *RC=NULL;
};

struct qnode{
	struct node *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct qnode* QPTR;
typedef struct node *BSTPTR;

void L_enq(Queue &A, BSTPTR M){
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

BSTPTR L_deq(Queue &A){
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

void insert(BSTPTR &T, int x){
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->space=0;
	}
	else if(T->data > x)
		insert(T->LC,x);
	else if(T->data < x)
		insert(T->RC,x);
}

void number_it(BSTPTR T, int &i){
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

void print_same(Queue A, BSTPTR T){
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

void find_sum(BSTPTR T, Queue A, int sum, int tot=0){
	if(T){
		if(tot + T->data == sum){
			L_enq(A,T);
			cout<<"Path is : ";
			while(A.F) cout<<L_deq(A)->data<<" ";
			return ;
		}
		else{
			L_enq(A,T);
			find_sum(T->LC,A,sum,tot+T->data);
			find_sum(T->RC,A,sum,tot+T->data);
		}
	}
}

int main()
{
	BSTPTR T=NULL;
	int n;
	Queue A;
	insert(T, 18);
	insert(T, 10);
	insert(T, 27);
	insert(T, 8);
	insert(T, 16);
	insert(T, 24);
	insert(T, 45);
	insert(T, 12);
	insert(T, 36);
	insert(T, 81);
	insert(T, 63);
	cout<<"Tree is :\n";
	print_same(A,T);
	cout<<"\nEnter sum : ";
	cin>>n;
	find_sum(T,A,n);
	return 0;
}

