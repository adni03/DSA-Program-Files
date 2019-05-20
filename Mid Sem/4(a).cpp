//4(a)

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

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct qnode* QPTR;
typedef struct node *BTPTR;

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
		cout<<T->data;
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

int find(int post[], int pre[], int x){
	for(int i=0; i<9; i++){
		if(post[i]==x && i-1>=0){
			for(int j=0; j<9; j++){
				if(pre[j]==post[i-1]) return j;
			}	
		}
	}
	return -1;
}

void create(BTPTR &T, int post[], int pre[], int l, int h){
	if(!T && l<h && l!=-1){
		T=new(node);
		T->data=pre[l];
		int j=find(post,pre,pre[l]);
		if(j<l || j>h) j=-1;
		create(T->LC,post,pre,++l,j);
		create(T->RC,post,pre,j,h);
	}
}

int main()
{
	int pre[9]={1,2,4,8,9,5,3,6,7};
	int post[9]={8,9,4,5,2,6,7,3,1};
	BTPTR T=NULL;
	Queue A;
	create(T,post,pre,0,9);
	cout<<"The tree is : "<<endl;
	print_same(A,T);
	return 0;
}
