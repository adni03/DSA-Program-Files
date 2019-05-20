//CREATES A BINARY SEARCH TREE FROM A SORTED ARRAY

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

typedef struct node *BSTPTR;
typedef struct qnode* QPTR;

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
//NUMBERS IT
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
//ENTERS AN ELEMENT INTO THE QUEUE
void L_enq(Queue &A, BSTPTR M)
{
	QPTR T, F=A.F;
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
//PRINTS AS IT IS
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
//CREATES A BINARY SEARCH TREE USING A SORTED ARRAY
void insert_sorted(BSTPTR &T,int a[], int l, int h, int n){
	if(l<=h){
		int mid=(l+h)/2;
		insert_sorted(T,a,mid+1,h,n);
		insert(T,a[mid]);
		insert_sorted(T,a,l,mid-1,n);
	}
	else if(l==n-1 && h==n-1)
		insert(T,a[n-1]);
}

void print_line(Queue A, BSTPTR T){
	L_enq(A,T);
	L_enq(A,NULL);
	do
	{
		T=L_deq(A);
		if(T==NULL)
		{
			cout<<endl;
			T=L_deq(A);
			L_enq(A,NULL);
		}
		cout<<T->data<<" ";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

int main()
{
	Queue A; A.F=A.R=NULL;
	BSTPTR T=NULL;
	int a[30]={4,12,10,18,24,22,15,31,44,35,66,90,70,50,25};
	int n;
	insert(T,a[14]);
	insert_sorted(T,a,0,13,15);
	cout<<"\n->BST is : "<<endl;
	print_same(A,T);
	return 0;
}

