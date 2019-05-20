// VERTICAL SUM 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct btnode{
	char data;
	int space, hd;
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

typedef struct qnode *QPTR;
typedef struct btnode *BTPTR;

void serial(BTPTR &T, char x[], int &i, int n){
	if(T==NULL)
	{
		if(x[i]!='.'){
			T=new(btnode);
			T->data=x[i];
			T->hd=n;
			T->LC=NULL;
			T->RC=NULL;
			++i;
		}
	}
	if(x[i]!='.'){
		--n;
		serial(T->LC,x,i,n);
	}
	else ++i;
	if(x[i]!='.'){
		n+=2;
		serial(T->RC,x,i,n);
	}
	else ++i;
}

void L_enq(Queue &A, BTPTR M){
	QPTR T=NULL, F=A.F;
	T=new(qnode);
	T->TEMP=M;
	if(A.F == NULL){
		A.F=T;
		A.R=T;
		T->next=NULL;
	}	
	else{
		while(F!=A.R)
			F=F->next;
		T->next=NULL;
		F->next=T;
		A.R=T;
	}
}

BTPTR L_deq(Queue &A){
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

void number_it(BTPTR T, int &i){
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

void print_same(Queue A, BTPTR T){
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

void verticalSum(BTPTR T, map<int,int> &sum){
	if(T){
		if(sum.find(T->hd)!=sum.end()) sum[T->hd]+=T->data-'0';
		else sum.insert(make_pair(T->hd,T->data-'0'));
		verticalSum(T->LC,sum);
		verticalSum(T->RC,sum);
	}
}

int main()
{
	char c1[]={'1','2','4','.','.','5','.','.','3','6','.','.','7','.','.'};
	int i=0;
	BTPTR T=NULL;
	Queue A;
	map<int,int> sum;
	serial(T,c1,i,0);
	cout<<"The tree is : \n";
	print_same(A,T);
	cout<<"\nvertical Sum : \n";
	verticalSum(T,sum);
	map<int,int> :: iterator itr;
	for(itr=sum.begin(); itr!=sum.end(); itr++)
		cout<<itr->second<<"\n";
	return 0;
}

