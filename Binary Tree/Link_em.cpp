//LINKING EVERY LEVEL IN A BINARY TREE

#include<iostream>
using namespace std;

struct btnode{
	char data;
	int space, p;
	struct btnode *next;
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

void insert(BTPTR &T, char ch[]){
	static int i=0;
	if(ch[i]!='\0'){
		if(ch[i]!='.'){
			T=new(btnode);
			T->LC=T->RC=T->next=NULL;
			T->data=ch[i++];
			T->p=0;
			insert(T->LC,ch);
			i++;
			insert(T->RC,ch);
		}
	}
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

void print_line(Queue A, BTPTR T){
	L_enq(A,T);
	L_enq(A,NULL);
	while(A.F!=A.R){
		BTPTR TEMP=L_deq(A);
		if(!TEMP){
			cout<<"\n";
			TEMP=L_deq(A);
			L_enq(A,NULL);
		}
		cout<<TEMP->data<<" ";
		if(TEMP->LC) L_enq(A,TEMP->LC);
		if(TEMP->RC) L_enq(A,TEMP->RC);
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

void link_em(BTPTR T, BTPTR P=NULL){
	if(T){
		if(P==NULL) P=T;
		else{
			BTPTR TEMP=T;
			if(P->RC && TEMP->data!=P->RC->data){
				TEMP->next=P->RC;
				TEMP=TEMP->next;
			}
			if(P->next){
				P=P->next;
				while(P){
					if(P->LC){
						TEMP->next=P->LC;
						TEMP=TEMP->next;
					}
					if(P->RC){
						TEMP->next=P->RC;
						TEMP=TEMP->next;
					}
					P=P->next;
				}
			}
			P=T;
		}
		link_em(T->LC,T);
		link_em(T->RC,T);
	}
}

void print_links(BTPTR T){
	if(T!=NULL){
		BTPTR P=T;
		while(P){
			if(P->p<1) cout<<P->data<<" ";
			P->p++;
			P=P->next;
		}
		if(T->p==1) cout<<endl;
		print_links(T->LC);
		print_links(T->RC);
	}
}

int main()
{
	BTPTR T1=NULL;
	Queue A;
	int i=0;
	char c1[]={'A','B','C','.','.','F','G','.','.','.','H','I','.','J','.','.','K','.','L','M','.','.','N','.','.'};
	insert(T1,c1);
	cout<<"\nPrinting Binary Tree using print_same function : "<<endl;
	print_same(A,T1);
	link_em(T1);
	cout<<"\nPrinting Binary Tree using level links : "<<endl;
	print_links(T1);
	cout<<"Line by line : \n";
	print_line(A,T1);
	return 0;
}
