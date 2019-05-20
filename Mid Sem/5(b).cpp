//5(b)

#include<iostream>
#include<string.h>
using namespace std;

struct kdnode{
	int num[2];
	char ch[2];
	char str[2][10];
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
		cout<<"( ";
		for(int i=0; i<2; i++) cout<<T->num[i]<<" ";
		cout<<")";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}

void insert(KDPTR &K, int num[], char ch[], char str[][10], int k, int i){
	if(i==k) i=0;
	if(!K){
		K=new(kdnode);
		K->LC=K->RC=NULL;
		for(int j=0; j<k; ++j){
			K->num[j]=num[j];
			K->ch[j]=ch[j];
			strcpy(K->str[j],str[j]);
		}
	}
	else{
		if(num[i]<=K->num[i]) insert(K->LC,num,ch,str,k,++i);
		else insert(K->RC,num,ch,str,k,++i);
	}
}

void find(KDPTR K, int num[], int k, int i){
	if(K){
		if(i==k) i=0;
		if(K->num[i] == num[i]){
			if(K->num[(i+1)%2] == num[(i+1)%2]){
				for(int j=0; j<2; j++) cout<<K->num[j]<<" ";
				cout<<endl;
				for(int j=0; j<2; j++) cout<<K->ch[j]<<" ";
				cout<<endl;
				for(int j=0; j<2; j++) cout<<K->str[j]<<" ";
			}
			else{
				if(num[i+1]<=K->num[i+1]) find(K->RC,num,k,++i);
				else find(K->LC,num,k,++i);
			}
		}
		else{
			if(num[i]<=K->num[i]) find(K->LC,num,k,++i);
			else find(K->RC,num,k,++i);
		}
	}
}

int main()
{
	KDPTR K=NULL;
	Queue A;
	int a[4][2]={{20,15},{10,70},{90,25},{15,45}};
	char ch[4][2]={{'a','b'},{'c','d'},{'e','f'},{'g','h'}};
	char str[2][10];
	strcpy(str[0],"india");
	strcpy(str[1],"uae");
	insert(K,a[0],ch[0],str,2,0);
	insert(K,a[1],ch[1],str,2,0);
	insert(K,a[2],ch[2],str,2,0);
	insert(K,a[3],ch[3],str,2,0);
	cout<<"\nThe tree is : "<<endl;
	print_line(A,K);
	cout<<"\nEnter key to be found : ";
	int key[2]={90,25};
	find(K,key,2,0);
	return 0;
}
