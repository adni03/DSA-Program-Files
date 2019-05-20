//AVL TREE

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
typedef struct node *BSTPTR;

int height(BSTPTR T){
	if(T==NULL)
		return -1;
	else
		return(1+max(height(T->LC),height(T->RC)));
}

void min(BSTPTR T, int &mini){
	if(T){
		if(T->data < mini) mini=T->data;
		min(T->LC,mini);
		min(T->RC,mini);
	}
}

void max(BSTPTR T, int &maxi){
	if(T){
		if(T->data > maxi) maxi=T->data;
		max(T->LC,maxi);
		max(T->RC,maxi);
	}
}

void insert(BSTPTR &T, int x){
	static BSTPTR K1=NULL, K2=NULL, K3=NULL;
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->LC=NULL;
		T->RC=NULL;
		K2=T;
	}
	else if(T->data > x)
		insert(T->LC,x);
	else if(T->data < x)
		insert(T->RC,x);
	else
		cout<<"\nDuplicate!";
	int n1=height(T->LC);
	int n2=height(T->RC);
	if(n1-n2 < -1 || n1-n2 > 1){
		K1=T;
		//DOUBLE 
		if(K2->data > K1->data && K2->data < K3->data || K2->data < K1->data && K2->data > K3->data){
			if(K2->data < K1->data){
				K3->RC=K2->LC;
				K2->LC=K3;
				//right
				K1->LC=K2->RC;
				K2->RC=K1;
			}
			else if(K2->data > K1->data){
				K3->LC=K2->RC;
				K2->RC=K3;
				//left
				K1->RC=K2->LC;
				K2->LC=K1;
			}
			T=K2;
		}
		else{
			//SINGLE
			if(K2->data > K1->data && K2->data > K3->data){//LEFT ROTATE
				K1->RC=K3->LC;
				K3->LC=K1;
			}
			else if(K2->data < K1->data && K2->data < K3->data){//RIGHT ROTATE
				K1->LC=K3->RC;
				K3->RC=K1;
			}
			T=K3;
		}
	}
	else K3=T;
}

void remove(BSTPTR &T, int k){
	static BSTPTR K1=NULL, K2=NULL, K3=NULL;
	if(T){
		if(T->data==k){
			if(!T->LC && !T->RC) T=NULL;
			else{
				if(T->LC && T->RC){
					int n=62000; K1=T;
					min(T->RC,n);
					remove(T->RC,n);
					T->data=n;
				}
				else if(!T->LC){
					int n=62000; K1=T;
					min(T->RC,n);
					remove(T->RC,n);
					T->data=n;
				}
				else{
					int n=-1; K1=T;
					max(T->LC,n);
					remove(T->LC,n);
					T->data=n;
				}
			}
		}
		else if(T->data > k) remove(T->LC,k);
		else remove(T->RC,k);
		if(T){
			if(!K1) K1=T;
			int n1=height(T->LC);
			int n2=height(T->RC);
			if(n1-n2 < -1 || n1-n2 > 1){
				K3=(K1->LC) ? K1->LC : K1->RC;
				K2=(K3->LC) ? K3->LC : K3->RC;
				//DOUBLE 
				if(K2->data > K1->data && K2->data < K3->data || K2->data < K1->data && K2->data > K3->data){
					if(K2->data < K1->data){
						K3->RC=K2->LC;
						K2->LC=K3;
						//right
						K1->LC=K2->RC;
						K2->RC=K1;
					}
					else if(K2->data > K1->data){
						K3->LC=K2->RC;
						K2->RC=K3;
						//left
						K1->RC=K2->LC;
						K2->LC=K1;
					}
					T=K2;
				}
				else{
					//SINGLE
					if(K2->data > K1->data && K2->data > K3->data){//LEFT ROTATE
						K1->RC=K3->LC;
						K3->LC=K1;
					}
					else if(K2->data < K1->data && K2->data < K3->data){//RIGHT ROTATE
						K1->LC=K3->RC;
						K3->RC=K1;
					}
					T=K3;
				}
			}
			else K3=T;
		}
	}
}

void L_enq(Queue &A, BSTPTR M)
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

BSTPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		BSTPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}

void number_it(BSTPTR T, int &i){
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

void print_same(Queue A, BSTPTR T){
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

int main()
{
	BSTPTR T=NULL;
	Queue A;
	int k;
	int a[9]={5,10,1,3,4,8,9,2,7};
	for(int i=0; i<9; i++)
		insert(T,a[i]);
	cout<<"The tree is : "<<endl;
	print_same(A,T);
	cout<<"\nEnter node to delete : ";
	cin>>k;
	remove(T,k);
	cout<<"The tree is : "<<endl;
	print_same(A,T);
	return 0;
}
