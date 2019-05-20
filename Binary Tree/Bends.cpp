// No. of bends in a Binary Tree

#include<iostream>
using namespace std;

struct btnode{
	char data;
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
typedef struct btnode* BTPTR;

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

void insert(BTPTR &T, char ch[]){
	static int i=0;
	if(ch[i]!='\0'){
		if(ch[i]!='.'){
			T=new(btnode);
			T->data=ch[i++];
			T->LC=T->RC=NULL;
			insert(T->LC,ch);
			i++;
			insert(T->RC,ch);
		}
	}
}

void print_line(Queue A, BTPTR T){
	L_enq(A,T);
	L_enq(A,NULL);
	while(A.F!=A.R){
		T=L_deq(A);
		if(!T){
			cout<<"\n";
			T=L_deq(A);
			L_enq(A,NULL);
		}
		cout<<T->data<<" ";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}
}

void Bends(BTPTR T, int a, int &b, int dir=-1, int cnt=0){
	if(T){
		if(T->data == a) b=cnt;
		else{
			if(dir==-1) Bends(T->LC,a,b,-1,cnt);
			else Bends(T->LC,a,b,-1,cnt+1);
			if(dir==1) Bends(T->RC,a,b,1,cnt);
			else Bends(T->RC,a,b,1,cnt+1);
		}
	}
}


int main()
{
	char ch[]={'1','2','4','8','.','.','.','5','9','.','.','0','.','.','3','6','.','.','7','.','.'};
	BTPTR T=NULL;
	Queue A;
	int a1=0, b1=0;
	char a, b;
	insert(T,ch);
	cout<<"Tree is : \n";
	print_line(A,T);
	cout<<"\nEnter 2 numbers from the tree : ";
	cin>>a>>b;
	Bends(T,a,a1);
	Bends(T,b,b1);
	cout<<"The number of bends : "<<(a1+b1);
	return 0;
}
