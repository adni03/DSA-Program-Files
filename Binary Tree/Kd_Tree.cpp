//Kd TREES

#include<iostream>
using namespace std;

struct kdnode{
	int data[2];
	struct kdnode *LC=NULL;
	struct kdnode *RC=NULL;
};

struct qnode{
	struct kdnode *TEMP=NULL;
	struct qnode *next=NULL;
};

struct Queue{
	struct qnode *F=NULL;
	struct qnode *R=NULL;
};

typedef struct kdnode *KDPTR;
typedef struct qnode *QPTR;

void L_enq(Queue &A, KDPTR M)
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

KDPTR L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		cout<<"\nEmpty!";
	else
	{
		KDPTR P=A.F->TEMP;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return P;
	}
}

void print_line(Queue A, KDPTR T){
	L_enq(A,T);
	L_enq(A,NULL);
	do
	{
		T=L_deq(A);
		if(T==NULL)
		{
			cout<<"\n";
			T=L_deq(A);
			L_enq(A,NULL);
		}
		cout<<"("<<T->data[0]<<","<<T->data[1]<<")";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

void insert(KDPTR &K, int a[], int k, int i){
	if(i==k) i=0;
	if(!K){
		K=new(kdnode);
		for(int j=0; j<k; ++j)
			K->data[j]=a[j];
	}
	else{
		if(a[i]<=K->data[i]) insert(K->LC,a,k,i+1);
		else insert(K->RC,a,k,i+1);
	}
}

int isEqual(int a1[], int a2[], int k){
	for(int i=0; i<k; i++){
		if(a1[i]!=a2[i]) return 0;
	}
	return 1;
}

void find(KDPTR K, int a[], int k, int i, int &y){
	if(K){
		if(i==k) i=0;
		if(isEqual(K->data,a,k)) y=1;
		else{
			if(a[i]<=K->data[i]) find(K->LC,a,k,i+1,y);
			else find(K->RC,a,k,i+1,y);
		}
	}
}

void find_min(KDPTR T, int k, int n, int &min){
	if(T){
		if(T->data[k-n]<min) min=T->data[k-n];
		find_min(T->LC,k,n,min);
		find_min(T->RC,k,n,min);
	}
}

void find_max(KDPTR T, int k, int n, int &max){
	if(T){
		if(T->data[k-n]>max) max=T->data[k-n];
		find_max(T->LC,k,n,max);
		find_max(T->RC,k,n,max);
	}	
}

int main()
{
	KDPTR K=NULL;
	Queue A;
	int n=0, min=100, max=0, b[2], y=0;
	int a[9][2]={{20,15},{10,70},{90,25},{15,45},{40,7},{60,30},{20,25},{76,3},{50,2}};
	for(int i=0; i<9; i++)
		insert(K,a[i],2,0);
	cout<<"Kd Tree is : "<<endl;
	print_line(A,K);
	cout<<"\nEnter element to be found : ";
	for(int i=0; i<2; i++)
		cin>>b[i];
	find(K,b,2,0,y);
	if(y) cout<<"Element found!";
	else cout<<"Element not found!";
	find_min(K,2,2,min);
	cout<<"\nMinimum x co-ordinate is : "<<min;
	min=100;
	find_min(K,2,1,min);
	cout<<"\nMinimum y co-ordinate is : "<<min;
	find_max(K,2,2,max);
	cout<<"\nMaximum x co-ordinate is : "<<max;
	max=0;
	find_max(K,2,1,max);
	cout<<"\nMaximum y co-ordinate is : "<<max;
	return 0;
}
