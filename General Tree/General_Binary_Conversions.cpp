//N-ary tree to Binary Tree and Splitting a general tree

#include<iostream>
using namespace std;

struct gtnode{
	char data;
	int visited, used;
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
typedef struct btnode* BTPTR;

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

TPTR serialize(TPTR &T, char ch[], int n){
	static int i=0;
	if(i<n){
		if(ch[i]!='.'){
			T=new(gtnode);
			T->data=ch[i++];
			T->used=T->visited=0;
			T->FC=serialize(T->FC,ch,n);
			++i;
			T->NS=serialize(T->NS,ch,n);
			return T;
		}
		else return NULL;
	}
	return T;
}

void print_line_BT(Queue A, TPTR T){
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
		if(T->FC) L_enq(A,T->FC);
		if(T->NS) L_enq(A,T->NS);
	}while(A.F!=A.R);
}

void print_line_GT(Queue A, TPTR T){
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

TPTR convertizo(TPTR T, TPTR R){
	if(T){
		R=new(gtnode);
		R->data=T->data;
		R->FC=convertizo(T->FC,R->FC);
		R->NS=convertizo(T->NS,R->NS);
		return R;
	}
	else return NULL;	
}

TPTR backConvertizo(TPTR T, TPTR R){
	if(T){
		R=new(gtnode);
		R->data=T->data;
		R->FC=backConvertizo(T->FC,R->FC);
		R->NS=backConvertizo(T->NS,R->NS);
		return R;
	}
	else return NULL;
}

int isVisited(TPTR T){
	while(T){
		if(!T->visited) return 0;
		T=T->NS;
	}
	return 1;
}

TPTR split(TPTR T, TPTR R){
	if(T && !T->visited){ //node isnt visited
		R=new(gtnode);
		R->data=T->data;
		T->used=1;
		R->FC=split(T->FC,R->FC);
		if(isVisited(T->FC)) T->visited=1;
		else T->visited=0;
		if(!T->FC) R->NS=NULL;
		else{
			TPTR TEMP=T->FC;
			while(TEMP){
				if(!TEMP->visited && !TEMP->used) break;
				TEMP=TEMP->NS;
			}
			R->NS=split(TEMP,R->NS);
			if(isVisited(T->FC)) T->visited=1;
			else T->visited=0;
		}
		return R;
	}
	else if(T){ //node is visited but its next sibling, down the line isnt visited
		if(T->visited){
			TPTR TEMP=T;
			while(TEMP){
				if(!TEMP->visited) break;
				TEMP=TEMP->NS;
			}
			split(TEMP,R);	
		}
	}
	else return NULL;
}

void splitDriver(TPTR T){
	if(!T->visited){
		Queue A;
		TPTR R=NULL;
		R=split(T,R);
		cout<<"\nTree is : \n";
		print_line_BT(A,R);
		splitDriver(T);
	}
}

int main()
{
	char ch[]={'A','B','C','D','.','E','.','.','F','.','G','H','.','I','.','J','.','.','.','K','.','L','M','.','N','O','P','.','.','.','.','Q','.','.'};
	//char ch[]={'A','B','C','.','D','.','.','E','F','.','.','G','.','H','I','.','J','.','K','.','.','.'};
	TPTR T=NULL;
	TPTR R=NULL;
	TPTR Q=NULL;
	Queue A;
	T=serialize(T,ch,34);
	cout<<"The tree is : \n";
	print_line_GT(A,T);
	R=convertizo(T,R);
	cout<<"\nThe Binary Tree is : \n";
	print_line_BT(A,R);
	Q=backConvertizo(T,Q);
	cout<<"\nThe tree is : \n";
	print_line_GT(A,Q);
	cout<<"\nGeneral tree split into binary tree : ";
	splitDriver(T);
	return 0;
}
