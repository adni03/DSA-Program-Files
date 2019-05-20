//LEFT AND RIGHT VIEW

#include<iostream>
using namespace std;

struct btnode{
	char data;
	int space, hd;
	struct btnode *next=NULL;
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

void insert(BTPTR &T, char ch[], int n){
	static int i=0;
	if(ch[i]!='\0'){
		if(ch[i]!='.'){
			T=new(btnode);
			T->LC=T->RC=T->next=NULL;
			T->data=ch[i++];
			T->hd=n;
			insert(T->LC,ch,n-1);
			i++;
			insert(T->RC,ch,n+1);
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

void link_em(BTPTR T){
	static BTPTR P=NULL;
	if(T!=NULL){
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
		if(T->LC) link_em(T->LC);
		else link_em(T->RC);
	}
}

void print_links(BTPTR T, int ch){
	if(T!=NULL){
		BTPTR P=T,TEMP=NULL;
		if(ch==0){
			cout<<P->data<<endl;
		}
		else{
			int max=P->hd;
			while(P->next){
				P=P->next;
			}
			cout<<P->data<<endl;
		}
		if(T->LC) print_links(T->LC,ch);
		else if(T->RC) print_links(T->RC,ch);
	}
}

int main()
{
	BTPTR T1=NULL;
	Queue A;
	int i=0;
	char c1[]={'A','J','R','T','.','.','S','.','.','.','M','.','P','Q','.','.','.'};
	insert(T1,c1,0);
	link_em(T1);
	cout<<"Original Binary Tree is : "<<endl;
	print_same(A,T1);
	cout<<"\nLeft view is : "<<endl;
	print_links(T1,0);
	cout<<"Right view is : "<<endl;
	print_links(T1,1);
	return 0;
}
