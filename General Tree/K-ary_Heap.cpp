// K-ary Heap

#include<iostream>
using namespace std;

struct khnode{
	int data;
	int cnt;
	int space;
	struct khnode *PPTR=NULL;
	struct khnode* PTR[3];
};

struct qnode{
	struct khnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct qnode *QPTR;
typedef struct khnode *KPTR;

void enq(Queue &q, KPTR M){
	QPTR TEMP=NULL;
	TEMP=new(qnode);
	TEMP->TEMP=M;
	if(!q.F){
		q.F=q.R=TEMP;
	}
	else{
		q.R->next=TEMP;
		q.R=TEMP;
	}
}

KPTR deq(Queue &q){
	QPTR T=q.F;
	if(!q.F) return NULL;
	else{
		KPTR K=T->TEMP;
		q.F=q.F->next;
		delete(T);
		return K;
	}
}

void print_line(Queue A, KPTR T){
	enq(A,T);
	enq(A,NULL);
	do
	{
		T=deq(A);
		if(T==NULL)
		{
			cout<<endl;
			T=deq(A);
			enq(A,NULL);
		}
		cout<<T->data<<" ";
		int i=0;
		while(T->PTR[i] && i<3){
			enq(A,T->PTR[i]);
			i++;
		}
	}while(A.F!=A.R);
}

void insert(KPTR &T, int k, KPTR P=NULL){
	if(!T){
		T=new(khnode);
		T->data=k;
		T->cnt=0;
		T->PPTR=P;
		for(int i=0; i<3; i++) T->PTR[i]=NULL;
	}
	else{
		if(T->cnt < 3){
			int i=0;
			T->cnt++;
			while(T->PTR[i]) i++;
			insert(T->PTR[i],k,T);
		}
		else insert(T->PTR[0],k,T);
	}
	if(T->PPTR){
		if(T->PPTR->PPTR){
			KPTR K=T->PPTR->PPTR;
			int max=-1, i=0, pos=0;
			while(K->PTR[i] && i<3){
				if(K->PTR[i]->data > max){
					max=K->PTR[i]->data;
					pos=i;
				}
				i++;
			}
			int temp=K->PTR[pos]->data;
			K->PTR[pos]->data=T->data;
			T->data=temp;
		}
		else{
			if(T->PPTR->data > T->data){
				int temp=T->data;
				T->data=T->PPTR->data;
				T->PPTR->data=temp;
			}
		}
	}
}

int main()
{
	KPTR T=NULL;
	int a[11]={21,20,19,18,17,16,15,14,13,12,11};
	Queue A;
	for(int i=0; i<11; i++){
		insert(T,a[i]);
	}
	cout<<"The tree is : \n";
	print_line(A,T);
	return 0;
}
