// maximum path sum in binary tree

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

int find_max_sum(BTPTR T, int &msum){
	if(T){
		if(!T->LC && !T->RC) return T->data-'0';
		int lsum=find_max_sum(T->LC,msum);
		int rsum=find_max_sum(T->RC,msum);
		if(T->LC && T->RC){
			msum=max(msum,lsum+rsum+T->data-'0');
			return max(lsum,rsum)+T->data-'0';
		}
		return (T->LC?lsum+T->data-'0':rsum+T->data-'0');
	}
	else return 0;
}

int main()
{
	char ch[]={'1','2','4','8','.','.','.','5','9','.','.','1','.','.','3','6','.','.','7','.','.'};
	BTPTR T=NULL;
	Queue A;
	int msum=0;
	insert(T,ch);
	cout<<"Tree is : \n";
	print_line(A,T);
	find_max_sum(T,msum);
	cout<<"\nSum : "<<msum;
	return 0;
}
