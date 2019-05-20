//DIGITAL TREE

#include<iostream>
using namespace std;

struct node{
	int data[6], m, space;
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

BSTPTR insert(BSTPTR T, int x[5], int m){
	if(!T){
		T = new(node);
		for(int i=0; i<m; i++){
			T->data[i]=x[i];
		}
		T->m=m;
	}
	else{
		int flag=0;
		for(int i=0; i<m && i<T->m; i++){
			if(T->data[i] < x[i]){
				flag=1;
				T->RC=insert(T->RC,x,m);
				break;
			}
			else if(T->data[i] > x[i]){
				flag=1;
				T->LC=insert(T->LC,x,m);
				break;
			}
		}
		if(!flag){
			T->RC=insert(T->RC,x,m);
		}
	}
	return T;
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
	int i=0,k=1;
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
		for(int i=0; i<T->m; i++) cout<<T->data[i];
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

int main()
{
	BSTPTR T=NULL;
	Queue A;
	int x[6][5] = {{1,0,1,1,0},{0,1,1,0,1},{1,1,0,1},{0,0,0,1},{1,0,1,1},{1,0,1,1,1}};
	T=insert(T,x[0],5);
	T=insert(T,x[1],5);
	T=insert(T,x[2],4);
	T=insert(T,x[3],4);
	T=insert(T,x[4],4);
	T=insert(T,x[5],5);
	cout<<"The tree is : "<<endl;
	print_same(A,T);
	return 0;
}

