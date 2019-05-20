//TST

#include<iostream>
using namespace std;

struct tstnode{
	char data;
	int end;
	struct tstnode *LC=NULL;
	struct tstnode *MC=NULL;
	struct tstnode *RC=NULL;
};

struct qnode{
	struct tstnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct qnode* QPTR;
typedef struct tstnode* TSTPTR;

void L_enq(Queue &A, TSTPTR M)
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

TSTPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		TSTPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}

void print_line(Queue A, TSTPTR T){
	L_enq(A,T);
	L_enq(A,NULL);
	do
	{
		T=L_deq(A);
		if(T==NULL)
		{
			cout<<endl;
			T=L_deq(A);
			L_enq(A,NULL);
		}
		cout<<T->data<<" ";
		if(T->LC) L_enq(A,T->LC);
		if(T->MC) L_enq(A,T->MC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

TSTPTR insert(TSTPTR T, char c[], int i){
	if(c[i]!='\0'){
		if(!T){
			T=new(tstnode);
			T->data=c[i];
			if(c[i+1]=='\0') T->end=1;
			else T->end=0;
			insert(T,c,i+1);
			return T;
		}
		else{
			if(c[i] > T->data) T->RC=insert(T->RC,c,i);
			else if(c[i] < T->data) T->LC=insert(T->LC,c,i);
			else{
				T->data=c[i];
				T->MC=insert(T->MC,c,i+1);
			}
		}
		return T;
	}
}

int search(TSTPTR T, char c[], int i){
	if(T){
		if(T->data==c[i]){
			if(T->end && c[i+1] == '\0' ) return 1;
			else search(T,c,i+1);
		}
		else if(T->data > c[i]) search(T->LC,c,i);
		else if(T->data < c[i]) search(T->RC,c,i);
		else search(T->MC,c,i);
	}
}

/*int search(TSTPTR T, char c[], int i){
	if(T){
		if(T->data==c[i]){
			if(T->LC){
				if(T->LC->data==c[i]) search(T->LC,c,++i);
			}
			else if(T->MC){
				if(T->MC->data==c[i]) search(T->MC,c,++i);
			}
			else if(T->RC){
				if(T->RC->data==c[i]) search(T->RC,c,++i);
			}
			else return 0;
		}
		else if(T->data > c[i]) search(T->LC,c,i);
		else if(T->data < c[i]) search(T->RC,c,i);
		else return 0;
	}
}*/

int main()
{
	TSTPTR T=NULL;	
	Queue A;
	char a[9][3]={{"in"},{"is"},{"as"},{"at"},{"be"},{"by"},{"of"},{"on"},{"to"}};
	char b[5]={"four"};
	for(int i=0; i<9; i++){
		T=insert(T,a[i],0);
		print_line(A,T);
		cout<<"\n------------------------\n";
	}
	cout<<"The tree is : "<<endl;
	print_line(A,T);
	if(search(T,b,0)!=0) cout<<"\nFound!";
	else cout<<"\nNot found!";
	return 0;
}
