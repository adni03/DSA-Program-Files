//CONVERT BST TO BT

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

struct btnode{
	int data, space;
	struct btnode *LC=NULL;
	struct btnode *RC=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct qnode* QPTR;
typedef struct node *BSTPTR;
typedef struct btnode *BTPTR;

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

void inOrder(BTPTR T, int a[],int &n){
	static int i=-1;
	if(T==NULL)
		return ;
	else
	{
		inOrder(T->LC,a,n);
		a[++i]=T->data;
		++n;
		inOrder(T->RC,a,n);
	}
}

void sort(int a[], int n){
	int min, temp, pos;
	for(int i=0; i<n-1; i++){
		min=a[i]; pos=i;
		for(int j=i+1; j<n; j++){
			if(a[j] < min){
				min=a[j];
				pos=j;
			}
		}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
}

void insert_sorted(BSTPTR &T,int a[], int l, int h){
	if(l<=h){
		int mid=(l+h)/2;
		insert(T,a[mid]);
		insert_sorted(T,a,l,mid-1);
		insert_sorted(T,a,mid+1,h);
	}
}

void convert(BTPTR M, BSTPTR &N){
	int a[30];
	int cnt=0;
	inOrder(M,a,cnt);
	sort(a,cnt);
	insert_sorted(N,a,0,cnt-1);
}

int main()
{
	BTPTR M=NULL;
	BSTPTR N=NULL;
	Queue A; A.F=A.R=NULL;
	M=new(btnode);
	M->data=30;
	M->LC=new(btnode);
	M->LC->data=20;
	M->RC=new(btnode);
	M->RC->data=18;
	M->LC->LC=new(btnode);
	M->LC->LC->data=9;
	M->RC->RC=new(btnode);
	M->RC->RC->data=3;
	M->LC->RC=new(btnode);
	M->LC->RC->data=45;
	M->LC->LC->RC=new(btnode);
	M->LC->LC->RC->data=5;
	convert(M,N);
	cout<<"BST is : "<<endl;
	print_same(A,N);
	return 0;
}
