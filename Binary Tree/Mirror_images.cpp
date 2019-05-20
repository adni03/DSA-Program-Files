//CHECK IF TWO TREES ARE MIRROR IMAGES

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

int i=0;

BTPTR insert(BTPTR T, char x[], int n){
	if(i<n){
		if(x[i]!='.'){
			T=new(btnode);
			T->data=x[i++];
			T->LC=insert(T->LC,x,n);
			i++;
			T->RC=insert(T->RC,x,n);
			return T;
		}
		else return NULL;
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

void mirror_chk(BTPTR T1, BTPTR T2, int &flag){
	if(T1!=NULL && T2!=NULL){
		if(T1->data==T2->data){
			mirror_chk(T1->LC,T2->RC,flag); //GO LEFT
			mirror_chk(T1->RC,T2->LC,flag); //GO RIGHT
		}
		else flag=1;
	}
}

void equivalent_chk(BTPTR T1, BTPTR T3, int &flag){
	if(T1!=NULL && T3!=NULL){
		if(T1->data==T3->data){
			equivalent_chk(T1->LC,T3->LC,flag);
			equivalent_chk(T1->RC,T3->RC,flag);
		}
		else flag=1;
	}
}

int main()
{
	BTPTR T1=NULL, T2=NULL, T3=NULL;
	char c1[]={'A','M','P','.','Q','.','.','.','J','.','R','S','.','.','T','.','.'};
	char c2[]={'A','J','R','T','.','.','S','.','.','.','M','.','P','Q','.','.','.'};
	char c3[]={'A','M','P','.','Q','.','.','.','J','.','R','S','.','.','T','.','.'};
	int n=17;
	T1=insert(T1,c1,n);
	i=0;
	T2=insert(T2,c2,n);
	i=0;
	T3=insert(T3,c3,n);
	Queue A;
	int ck=0;
	cout<<"Tree one : "<<endl;
	print_same(A,T1);
	cout<<"\nTree two : "<<endl;
	print_same(A,T2);
	mirror_chk(T1,T2,ck);
	if(ck==1)	cout<<"\nNot mirror images!";
	else	cout<<"\nMirror images!";
	ck=0;
	cout<<"\nTree one : "<<endl;
	print_same(A,T1);
	cout<<"\nTree three : "<<endl;
	print_same(A,T3);
	equivalent_chk(T1,T3,ck);
	if(ck==1)	cout<<"\nNot equal!";
	else	cout<<"\nEqual!";
	return 0;
}
