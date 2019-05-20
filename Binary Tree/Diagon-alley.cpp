//DIAGON-ALLEY

#include<iostream>
using namespace std;

struct btnode{
	char data;
	int space, q, hd;
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
			T->q=0;
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

/*void level_up(BTPTR T, int n){
	if(T){
		T->level=n++;
		level_up(T->LC,n);
		level_up(T->RC,n);
	}
}*/

void min_hd(BTPTR T, int &n){
	if(T){
		if(T->hd<n) n=T->hd;
		min_hd(T->LC,n);
		min_hd(T->RC,n);
	}
}

void max_hd(BTPTR T, int &n){
	if(T){
		if(T->hd > n) n=T->hd;
		max_hd(T->RC,n);
		max_hd(T->LC,n);
	}
}

void link_em(BTPTR T, BTPTR P=NULL){
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
		link_em(T->LC,T);
		link_em(T->RC,T);
	}
}

void v_enq(BTPTR T, Queue Q[], int min){
	if(T!=NULL){
		BTPTR P=T;
		while(P){
			if(!P->q) L_enq(Q[P->hd - min],P);
			P->q=1;
			P=P->next;
		}
		v_enq(T->LC,Q,min);
		v_enq(T->RC,Q,min);
	}
}

void print_vertical(BTPTR T, Queue Q[], int t){
	int i=0;
	while(i<t){
		while(Q[i].F){
			cout<<L_deq(Q[i])->data<<" ";
		}
		++i;
		cout<<"\n";
	}
}

void diagonally(BTPTR T, Queue Q[], int end, int start){
	int i=-1*start, j=i;
	while(i>=0){
		j=i;
		while(j<end){
			if(Q[j].F)
				cout<<L_deq(Q[j])->data<<" ";
			++j;
		}
		cout<<"\n";
		--i;
	}
	if(Q[0].F!=NULL) cout<<L_deq(Q[0])->data<<" ";
}

int main()
{
	BTPTR T1=NULL;
	Queue A, Q[20];
	int i=0, min=0, max=0;
	char c1[]={'A','B','C','.','.','F','G','.','.','.','H','I','.','J','.','.','K','.','L','M','.','.','N','.','.'};
	insert(T1,c1,0);
	//level_up(T1,0);
	cout<<"Printing Binary Tree using print_same function : "<<endl;
	print_same(A,T1);
	min_hd(T1,min); max_hd(T1,max);
	link_em(T1);
	v_enq(T1,Q,min);
	cout<<"\nDiagon-alley : "<<endl;
	diagonally(T1,Q,max-min+1,min);
	return 0;
}
