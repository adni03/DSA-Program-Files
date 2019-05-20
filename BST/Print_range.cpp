//PRINTS RANGE OF VALUES

#include<iostream>
using namespace std;

struct node{
	int data, space, min, max;
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
//RETURNS A POINTER, SIMILAR TO THE DEQ OPERATION FOR QUEUE
void insert(BSTPTR &T, int x){
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->min=0;
		T->max=500;
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
//ENTERS AN ELEMENT INTO THE QUEUE
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
//USE FOR PRINT AS IT IS, IT NUMBERS THE ELEMENTS I.E. PROVIDES NUMBER OF SPACES AFTER WHICH THE DATA HAS TO BE PRINTED.
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
//PRINTS THE STACK
void print(stack m){
	SPTR TEMP=m.T;
	while(TEMP!=NULL){
		if(TEMP->TR==NULL)	cout<<endl;
		else	cout<<TEMP->TR->data<<" ";
		TEMP=TEMP->next;
	}
}
//DELETES AN ELEMENT FROM THE QUEUE
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
		cout<<"("<<T->min<<","<<T->max<<")";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

int min(BSTPTR T){
	if(T->LC==NULL)
		return T->data;
	else
		min(T->LC);
}

int max(BSTPTR T){
	if(T->RC==NULL)
		return T->data;
	else
		max(T->RC);
}

void give_range(BSTPTR T, int s, int l){
	if(T){
		T->min=s;
		T->max=l;
		if(T->LC)	T->min=max(T->LC)+1;
		if(T->RC)	T->max=min(T->RC)-1;
		give_range(T->LC,s,T->data-1);
		give_range(T->RC,T->data+1,l);
	}
}

int main()
{
	Queue A; A.F=A.R=NULL;
	stack m; m.T=NULL;
	BSTPTR T=NULL;
	insert(T,18);
	insert(T,10);
	insert(T,27);
	insert(T,8);
	insert(T,16);
	insert(T,20);
	insert(T,45);
	insert(T,12);
	insert(T,36);
	insert(T,81);
	cout<<"\nBST with range is : "<<endl;
	give_range(T,0,500);
	print_same(A,T);
	return 0;
}
