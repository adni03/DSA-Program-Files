//PRINTS BST LEVEL ORDER + LINE BY LINE + REVERSED LINE BY LINE

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

struct snode{
	struct node *TR;
	struct snode *next;
};

struct stack{
	struct snode *T;
};

typedef struct qnode* QPTR;
typedef struct node *BSTPTR;
typedef struct snode* SPTR;
//RETURNS A POINTER, SIMILAR TO THE DEQ OPERATION FOR QUEUE
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
//ENTERS AN ELEMENT INTO THE QUEUE
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
//USE FOR PRINT AS IT IS, IT NUMBERS THE ELEMENTS I.E. PROVIDES NUMBER OF SPACES AFTER WHICH THE DATA HAS TO BE PRINTED.
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
//PRINTS THE STACK
void print(stack m){
	SPTR TEMP=m.T;
	while(TEMP!=NULL){
		if(TEMP->TR==NULL)	cout<<endl;
		else	cout<<TEMP->TR->data<<" ";
		TEMP=TEMP->next;
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
//1. LEVEL BY LEVEL ON THE SAME LINE
void print_lvl_order(Queue A, BSTPTR T){
	L_enq(A,T);
	do
	{
		T=L_deq(A);
		cout<<T->data<<" ";
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=NULL);
}
//2. LEVEL BY LEVEL ON NEW LINES
void print_line(Queue A, BSTPTR T){
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
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}
//3. LEVEL BY LEVEL ON NEW LINES IN REVERSE ORDER
void print_revline(Queue A, stack m, BSTPTR T){
	L_enq(A,T);
	L_enq(A,NULL);
	do
	{
		T=L_deq(A);
		push(m,T);
		if(T==NULL)
		{
			T=L_deq(A);
			push(m,T);
			L_enq(A,NULL);
		}
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
	print(m);
}
//4. SPIRAL ORDER
void print_spiral(Queue A, stack m, BSTPTR T){
	int flag=-1, cnt=0;
	L_enq(A,T);
	L_enq(A,NULL);
	do
	{
		T=L_deq(A);
		if(T==NULL)
		{
			if(flag!=1)
				cout<<"\n";
			L_enq(A,NULL);
			T=L_deq(A);
			flag*=-1;
			cnt++;
		}
		if(cnt%2==0){
			while(m.T!=NULL){
				BSTPTR Q=pop(m);
				cout<<Q->data<<" ";
			}
			if(cnt!=0)	cout<<endl;
			cnt=0;
		}
		if(flag==-1)
			cout<<T->data<<" ";
		else
			push(m,T);
		if(T->LC) L_enq(A,T->LC);
		if(T->RC) L_enq(A,T->RC);
	}while(A.F!=A.R);
}
//5. PRINTS AS IT IS
void print_same(Queue A, BSTPTR T){
	int i=0,k=1;
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

void min(BSTPTR T, int &mini){
	if(T){
		if(T->data<mini) mini=T->data;
		min(T->LC,mini);
		min(T->RC,mini);
	}
}

void max(BSTPTR T, int &maxi){
	if(T){
		if(T->data>maxi) maxi=T->data;
		max(T->LC,maxi);
		max(T->RC,maxi);	
	}
}

void remove(BSTPTR &TEMP, int k){
	if(TEMP){
		if(TEMP->data==k){
			if(!TEMP->LC && !TEMP->RC){
				TEMP=NULL;
			}
			else if(TEMP->LC && TEMP->RC){
				int n=1000;
				min(TEMP->RC,n);
				remove(TEMP->RC,n);
				TEMP->data=n;
			} 
			else if(TEMP->LC){
				int n;
				max(TEMP->LC,n);
				remove(TEMP->LC,n);
				TEMP->data=n;
			}
			else if(TEMP->RC){
				int n=1000;
				min(TEMP->RC,n);
				remove(TEMP->RC,n);
				TEMP->data=n;
			} 
		}
		if(TEMP){
			if(TEMP->data<=k) remove(TEMP->RC,k);
			else remove(TEMP->LC,k);
		}
	}
}

void inorder(BSTPTR T){
	if(T){
		inorder(T->LC);
		cout<<T->data<<" ";
		inorder(T->RC);
	}
}

void preorder(BSTPTR T){
	if(T){
		cout<<T->data<<" ";
		preorder(T->LC);
		preorder(T->RC);
	}
}

void postorder(BSTPTR T){
	if(T){
		postorder(T->LC);
		postorder(T->RC);
		cout<<T->data<<" ";
	}
}

void print_all_trees(BSTPTR T){
	if(T){
		inorder(T);
		cout<<"\n";
		preorder(T);
		cout<<"\n";
		postorder(T);
		cout<<"\n";
		cout<<T->data<<" ";
		print_all_trees(T->LC);
		print_all_trees(T->RC);
	}
}

int main()
{
	Queue A; A.F=A.R=NULL;
	stack m; m.T=NULL;
	BSTPTR T=NULL;
	int p;
	int a[30], n;
	insert(T, 5);
	insert(T, 3);
	insert(T, 8);
	insert(T, 1);
	insert(T, 4);
	insert(T, 6);
	insert(T, 9);
	insert(T, 2);
	insert(T, 7);
	cout<<"\n->Level order : ";
	print_lvl_order(A,T); //WORKS*/
	cout<<"\n->Line by line : "<<endl;
	print_line(A,T); //WORKS
	cout<<"\n->Reverse line by line : "<<endl;
	print_revline(A,m,T); //WORKS
	cout<<"\n->Spiral order : "<<endl;
	print_spiral(A,m,T); //WORKS
	cout<<"\n->As it is : "<<endl;
	print_same(A,T); //WORKS
	cout<<"\nEnter element to delete : ";
	cin>>p;
	remove(T,p);
	cout<<"The tree is : "<<endl;
	print_same(A,T);
	cout<<"\nAll ways are : "<<endl;
	print_all_trees(T);
	return 0;
}
