//Huffman Code Tree

#include<iostream>
using namespace std;

struct hfcnode{
	char c;
	int f;
	long code;
	struct hfcnode *RC=NULL;
	struct hfcnode *LC=NULL;
	struct hfcnode *next=NULL;
};

struct data{
	char c;
	int f;
};

struct qnode{
	struct hfcnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
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

void print_line(Queue A, HPTR T){
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
		cout<<"("<<T->c<<","<<T->f<<","<<T->code<<") ";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

void insert_f(HPTR &T, int f, char c){
	HPTR TEMP=new(hfcnode);
	TEMP->next=T;
	TEMP->f=f;
	TEMP->c=c;
	T=TEMP;
}

void remove(HPTR &T){
	HPTR P=T;
	T=T->next;
	P->next=NULL;	
}

HPTR insert(HPTR &L, HPTR T1, HPTR T2){
	HPTR T=new(hfcnode);
	T->f= T1->f + T2->f;
	T->c='.';
	if(T1->f <= T2->f){
		T->LC=T1;
		T->RC=T2;
	}
	else{
		T->LC=T2;
		T->RC=T1;	
	}
	remove(L); remove(L);
	T->next=L;
	L=T;
}

void make_tree(HPTR &T){
	HPTR T1=NULL, T2=NULL;
	while(T->next){
		T1=T;
		T2=T->next;
		insert(T,T1,T2);
	}
}

void encode(HPTR &T, long c){
	if(T){
		T->code=c;
		encode(T->LC,c*10);
		encode(T->RC,c*10+1);
	}
}

void decode(HPTR T, char a[], int k){
	static int i=0;
	if(i<k){
		if(!T->LC && !T->RC){
			cout<<T->c;
		}
		else{
			if(a[i]=='1'){
				i++;
				decode(T->RC,a,k);
			} 
			else if(a[i]=='0'){
				i++;
				decode(T->LC,a,k);
			}
		}
	}
}

int main()
{
	HPTR T=NULL;
	Queue A;
	data d[7];
	char a[9]={'1','1','0','0','0','1','1','0'};
	d[0].c='s'; d[0].f=2;
	d[1].c='t'; d[1].f=3;
	d[2].c='j'; d[2].f=5;
	d[3].c='p'; d[3].f=10;
	d[4].c='a'; d[4].f=25;
	d[5].c='m'; d[5].f=40;
	d[6].c='v'; d[6].f=50;
	for(int i=6; i>=0; --i)
		insert_f(T,d[i].f,d[i].c);
	make_tree(T);
	encode(T,0);
	cout<<"\nTree is (character, frequency, code) : "<<endl;
	print_line(A,T);
	cout<<"\nDecoded string : ";
	decode(T,a,9);
	return 0;
}

