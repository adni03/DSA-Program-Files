//MERGE TWO BSTs

#include<iostream>
using namespace std;

struct node{
	int data, space;
	struct node *LC;
	struct node *RC;
};

struct snode{
	struct node *TR;
	struct snode *next;
};

struct stack{
	struct snode *T;
};

typedef struct node *BSTPTR;
typedef struct snode* SPTR;

BSTPTR pop(stack &m)
{
	SPTR TEMP=m.T;
	BSTPTR x=TEMP->TR;
	m.T=m.T->next;
	delete(TEMP);
	return x;	
}
//STACK OPERATION
void push(stack &m, BSTPTR B)
{
	SPTR TEMP;
	TEMP=new(snode);
	TEMP->TR = B;
	TEMP->next=m.T;
	m.T=TEMP;
}

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

void merge(BSTPTR T1, BSTPTR T2){
	stack m1, m2;
	m1.T=NULL; m2.T=NULL;
	int flag=0;
	while(1)
	{
		if(T1){
			push(m1,T1);
			T1=T1->LC;
		}
		else if(T2){
			push(m2,T2);
			T2=T2->LC;
		}
		else if(!T1 || !T2 || m1.T || m2.T){
			if(m1.T) T1=m1.T->TR;
			if(m2.T) T2=m2.T->TR;
			if(T1->data == T2->data){
				pop(m1); pop(m2);
				T1=T1->RC;
				T2=T2->RC;
			}
			else if(T1->data < T2->data){
				cout<<pop(m1)->data<<" ";
				T1=T1->RC;
				T2=NULL;
			}
			else if(T1->data > T2->data){
				cout<<pop(m2)->data<<" ";
				T2=T2->RC;
				T1=NULL;
			}
			flag=1;
		}
		else break;
	}
}

int main()
{
	BSTPTR T1=NULL, T2=NULL;
	insert(T1,5);
	insert(T1,3);
	insert(T1,1);
	insert(T1,2);
	insert(T2,4);
	insert(T2,7);
	insert(T2,6);
	cout<<"Merged BST is : ";
	merge(T1,T2);
	return 0;
}
