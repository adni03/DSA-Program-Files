//DISPLAYS SUM OF COUSINS

#include<iostream>
using namespace std;

struct node{
	int data, space;
	struct node *LC;
	struct node *RC;
};

struct qnode{
	struct node *TEMP;
	struct qnode *next;
};

struct Queue{
	struct qnode *F;
	struct qnode *R;
};

typedef struct node *BSTPTR;
typedef struct qnode* QPTR;

//INSERTS AN ELEMENT INTO BST
void insert(BSTPTR &T, int x){
	if(T==NULL)
	{
		T=new(node);
		T->data=x;
		T->LC=NULL;
		T->RC=NULL;
	}
	else if(T->data > x)
		insert(T->LC,x);
	else if(T->data < x)
		insert(T->RC,x);
	else
		cout<<"\nDuplicate!";
}
//NUMBERS IT
void number_it(BSTPTR T){
	static int i=1;
	if(T==NULL)
		return ;
	else
	{
		number_it(T->LC);
		T->space=i;
		++i;
		number_it(T->RC);
	}
}
//ENTERS AN ELEMENT INTO THE QUEUE
void L_enq(Queue &A, BSTPTR M)
{
	QPTR T, F=A.F;
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
//DELETES AN ELEMENT FROM THE QUEUE
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

void cousin_sum(Queue A, BSTPTR T, int k){
	L_enq(A,T);
	L_enq(A,NULL);
	BSTPTR TEMP;
	//cout<<"\nA";
	int sum=0, flag=1;
	do
	{
		//cout<<"\nB";
		T=L_deq(A);
		if(T!=NULL)
		{
			if(T->data==k)
				flag=-1;
			if(T->LC!=NULL && T->RC!=NULL && flag!=-1)
			{
				if(T->LC->data == k || T->RC->data == k)
				{
					TEMP=T;
					//cout<<"\n"<<TEMP->data;	
				}
			}
		}
		//cout<<"\nC";
		if(T==NULL)
		{
			if(flag==-1)
				break;
			sum=0;
			T=L_deq(A);
			if(T->data==k)
				flag=-1;
			if(T->LC!=NULL && T->RC!=NULL && flag!=-1)
			{
				if(T->LC->data == k || T->RC->data == k)
				{
					TEMP=T;
					//cout<<"\n"<<TEMP->data;	
				}
			}
			L_enq(A,NULL);
		}
		//cout<<"\nD";
		sum+=T->data;
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
	cout<<"\nSum of cousins is : "<<(sum-(TEMP->LC->data+TEMP->RC->data));
}

int main()
{
	Queue A; A.F=A.R=NULL;
	int n;
	BSTPTR T=NULL;
	insert(T, 18);
	insert(T, 10);
	insert(T, 27);
	insert(T, 8);
	insert(T, 16);
	insert(T, 24);
	insert(T, 45);
	insert(T, 12);
	insert(T, 36);
	insert(T, 81);
	insert(T, 63);
	cout<<"\nEnter node data : ";
	cin>>n;
	cousin_sum(A,T,n);
	return 0;
}
