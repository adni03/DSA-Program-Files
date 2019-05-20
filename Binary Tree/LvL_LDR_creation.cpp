//LEVEL ORDER CREATION USING LDR


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

typedef struct qnode* QPTR;
typedef struct btnode *BTPTR;

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
			cout<<"\n";
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

int find(char LVL[], char LDR[], int l){
	int i=0, j=0, flag=0;
	for(i=0; i<l; i++){
		flag=0;
		for(j=0; j<11; j++){
			if(LVL[i]==LDR[j]){
				flag=2; break;
			}
		}
		if(flag=2)
			break;
	}
	for(i=j; i<11-j; i++)
		LVL[i]=LVL[i+1];
	return j;
}

void create(BTPTR &T, char LVL[], char LDR[], int l, int h, int m){
	if(l<=h){
		int mid=find(LVL,LDR,m);
		if(mid){
			T=new(btnode);
			T->data=LDR[mid];
			T->LC=NULL; T->RC=NULL;
			create(T->LC,LVL,LDR,l,mid-1,mid);
			create(T->RC,LVL,LDR,mid+1,h,mid);
		}
		else
			create(T,LVL,LDR,l,h,mid);
	}
}

int main()
{
	char lvl[]={'A','P','B','M','R','D','E','L','J','N','F','S'};
	char ldr[]={'L','M','J','P','R','A','D','N','B','F','E','S'};
	BTPTR T=NULL;
	Queue A;
	create(T,lvl,ldr,0,11,11);
	cout<<"\nCreated Binary Tree is : "<<endl;
	print_same(A,T);
	return 0;
}
