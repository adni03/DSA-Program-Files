//COMMON NODES OF TWO BSTs

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

//RETURNS A POINTER, SIMILAR TO THE DEQ OPERATION FOR QUEUE
BSTPTR pop(stack &m)
{
	SPTR TEMP=m.T;
	BSTPTR x=TEMP->TR;
	m.T=m.T->next;
	delete(TEMP);
	return x;	
}
//STACK OPERATION
void push(stack &m, BSTPTR B)
{
	SPTR TEMP;
	TEMP=new(snode);
	TEMP->TR = B;
	TEMP->next=m.T;
	m.T=TEMP;
}
//INSERTS AN ELEMENT INTO BST
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
//ENTERS AN ELEMENT INTO THE QUEUE
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
//DELETES AN ELEMENT FROM THE QUEUE
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

void merge(BSTPTR T1, BSTPTR T2){
	stack m1, m2;
	m1.T=NULL; m2.T=NULL;
	while(1){
		if(T1){
			push(m1,T1);
			T1=T1->LC;
		}
		else if(T2){
			push(m2,T2);
			T2=T2->LC;
		}
		else if(m1.T && m2.T){
				T1=m1.T->TR;
				T2=m2.T->TR;	
			if(T1->data==T2->data){
				cout<<T1->data<<" ";
				pop(m1); pop(m2);
				T1=T1->RC;
				T2=T2->RC;
			}
			else if(T1->data < T2->data){
				pop(m1);
				T1=T1->RC;
				T2=NULL;
			}
			else{
				pop(m2);
				T2=T2->RC;
				T1=NULL;
			}
		}
		else break;
	}
}

int main()
{
	BSTPTR T1=NULL, T2=NULL;
	insert(T1,5);
	insert(T1,3);
	insert(T1,6);
	insert(T1,1);
	insert(T1,2);
	insert(T2,4);
	insert(T2,2);
	insert(T2,6);
	insert(T2,7);
	cout<<"The common nodes are : ";
	merge(T1,T2);
	return 0;
}
