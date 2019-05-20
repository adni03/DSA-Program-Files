//TREAP

#include<iostream>
using namespace std;

struct tnode{
	struct tnode *LC=NULL;
	struct tnode *RC=NULL;
	char k1; //search property
	int k2; //heap property
	int space;
};

struct qnode{
	struct tnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct tnode *BTPTR;
typedef struct qnode *QPTR;

int chk_treap(BTPTR T){
	if(T){
		if(T->LC && T->RC){
			if(T->k1 > T->LC->k1 && T->k1 < T->RC->k1 && T->k2 < T->LC->k2 && T->k2 < T->RC->k2){
				chk_treap(T->LC);
				chk_treap(T->RC);
				return 1;
			}
			else return 0;
		}
		else if(T->LC){
			if(T->k1 > T->LC->k1 && T->k2 < T->LC->k2){
				chk_treap(T->LC);
				return 1;
			}
			else return 0;
		}
		else if(T->RC){
			if(T->k1 < T->RC->k1 && T->k2 < T->RC->k2){
				chk_treap(T->RC);
				return 1;
			}
			else return 0;
		}
		else return 1;
	}
	else return 1;
}

BTPTR insert(BTPTR T, char x, int k){
	static BTPTR K1=NULL, K2=NULL;
	if(T==NULL){
		T=new(tnode);
		T->k1=x;
		T->k2=k;
		K2=T;
		return T;
	}
	else if(T->k1 > x){
		T->LC=insert(T->LC,x,k);
	}
	else if(T->k1 < x){
		T->RC=insert(T->RC,x,k);
	}
	if(!chk_treap(T)){
		K1=T;
		if(K1->k1 > K2->k1){
			K1->LC=K2->RC;
			K2->RC=K1;
			return K2;
		}
		else{
			K1->RC=K2->LC;
			K2->LC=K1;
			return K2;
		}
	}
	return T;
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
		cout<<"("<<T->k1<<","<<T->k2<<")";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

int main()
{
	BTPTR T=NULL;
	Queue A;
	T=insert(T,'H',22);
	T=insert(T,'K',27);
	T=insert(T,'R',52);
	T=insert(T,'S',55);
	T=insert(T,'N',5);
	print_same(A,T);
	return 0;
}
