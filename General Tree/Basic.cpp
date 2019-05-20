//GENERAL TREE

#include<iostream>
using namespace std;

struct gtnode{
	char data;
	struct gtnode* NS=NULL;
	struct gtnode* FC=NULL;
};

struct qnode{
	struct gtnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct qnode* QPTR;
typedef struct gtnode* TPTR;

void L_enq(Queue &A, TPTR M){
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

TPTR L_deq(Queue &A){
	int t=0;
	QPTR TEMP;
	if(A.F == NULL) cout<<"\nEmpty!";
	else{
		TPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}

TPTR serialize(TPTR &T, char ch[]){
	static int i=0;
	if(ch[i]!='\0'){
		if(ch[i]!='.'){
			T=new(gtnode);
			T->data=ch[i++];
			T->FC=serialize(T->FC,ch);
			++i;
			T->NS=serialize(T->NS,ch);
			return T;
		}
		else return NULL;
	}
	return T;
}

void print(TPTR T){
	if(T){
		cout<<T->data<<" ";
		if(T->FC){
			cout<<"{ ";
			print(T->FC);
		}
		print(T->NS);
	}
	else cout<<"} ";
}

void vertical_print(TPTR T, int cnt=0){
	if(T){
		for(int i=cnt; i>0; --i) cout<<" ";
		cout<<T->data;
		if(T->FC){
			cout<<"\n";
			vertical_print(T->FC,cnt+2);
		}
		cout<<"\n";
		vertical_print(T->NS,cnt);
	}
}

void print_line(Queue A, TPTR T){
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
		if(T->FC){
			TPTR TEMP=T->FC;
			while(TEMP){
				L_enq(A,TEMP);
				TEMP=TEMP->NS;
			}
		}
	}while(A.F!=A.R);
}

void height(TPTR T, int &h, int cnt=0){
	if(T && T->data!=-1){
		TPTR P=T;
		++cnt;
		if(cnt > h) h=cnt;
		while(P && P->data!=-1){
			height(P->FC,h,cnt);
			P=P->NS;
		}
	}
}

int main()
{
	char ch[]={'A','M','P','E','.','F','.','.','Q','.','R','G','.','H','.','I','.','.','.','J','.','K','S','.','D','K','L','.','.','.','.','X','.','.'};
	TPTR T=NULL;
	Queue A;
	int h=0;
	T=serialize(T,ch);
	cout<<"The tree is : ";
	cout<<"{ ";
	print(T);
	cout<<"}";
	cout<<"\nThe tree in vertical order is : \n";
	vertical_print(T);
	cout<<"The tree in level order is : \n";
	print_line(A,T);
	//height(T,h);
	cout<<"\nHeight : "<<h;
	return 0;
}
