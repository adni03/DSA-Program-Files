//SERIALIZE AND DE-SERIALIZE

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

void insert(BTPTR &T, char x[], int &i){
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
	if(x[i]!='.')insert(T->LC,x,i);
	else ++i;
	if(x[i]!='.')insert(T->RC,x,i);
	else ++i;
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

void print_seq(BTPTR T){
	if(T){
		cout<<T->data<<" ";
		print_seq(T->LC);
		print_seq(T->RC);
	}
	else
		cout<<". ";
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

int main()
{
	char c[]={'A','J','R','T','.','.','S','.','.','.','M','.','P','Q','.','.','.'};
	//char ch[]={'A','M','P','E','.','F','.','.','Q','.','R','G','.','H','.','I','.','.','.','J','.','K','S','.','D','K','L','.','.','.','.','X','.','.'};
	BTPTR T=NULL;
	Queue A;
	int i=0;
	insert(T,c,i);
	cout<<"\nBinary Tree is : "<<endl;
	print_same(A,T);
	cout<<endl;
	cout<<"\nSequence is : ";
	print_seq(T);
	return 0;
}


