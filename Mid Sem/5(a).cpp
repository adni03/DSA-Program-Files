//5(a)

#include<iostream>
#include<string.h>
using namespace std;

struct hfcnode{
	char c;
	int space;
	struct hfcnode *RC=NULL;
	struct hfcnode *LC=NULL;
	struct hfcnode *next=NULL;
};

struct qnode{
	struct hfcnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

struct code{
	char c;
	char ch[4];
};

typedef struct hfcnode *HPTR;
typedef struct qnode *QPTR;

void L_enq(Queue &A, HPTR M)
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

HPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		HPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}

void number_it(HPTR T, int &i){
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

void print_same(Queue A, HPTR T){
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
		cout<<T->c;
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

void create(HPTR &T, char c[], char k, int i){
	if(i<=strlen(c)){
		if(!T) T=new(hfcnode);
		if(i==strlen(c)){
			T->c=k;
		}
		else{
			if(c[i]=='0'){
				T->c='.'; ++i;
				create(T->LC,c,k,i);
			}
			else if(c[i]=='1'){
				T->c='.'; ++i;
				create(T->RC,c,k,i);
			}
			
		}
	}
}

int main()
{
	HPTR T=NULL;
	Queue A;
	struct code C[4];
	C[0].c='A'; strcpy(C[0].ch,"000");
	C[1].c='G'; strcpy(C[1].ch,"01");
	C[2].c='T'; strcpy(C[2].ch,"101");
	C[3].c='D'; strcpy(C[3].ch,"111");
	for(int i=0; i<4; i++)
		create(T,C[i].ch,C[i].c,0);
	cout<<"Tree is : "<<endl;
	print_same(A,T);
	return 0;
}


