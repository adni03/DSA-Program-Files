//STUDENT STRUCTURE PROBLEM

#include<iostream>
#include<string.h>
using namespace std;

union u
{
	struct outnode *ST;
	struct innode *D;
};

struct outnode
{
	int n;
	struct innode *C;
	struct outnode *next;
};

struct innode
{
	union u p1, p2;
	int tag1, tag2;
};

typedef struct outnode* OPTR;
typedef struct innode* IPTR;

OPTR find(OPTR L, int x)
{
	OPTR TEMP=L;
	cout<<"\nFINDING..";
	while(TEMP->n!=x && TEMP!=NULL)
		TEMP=TEMP->next;
	return TEMP;
}

void insert_end(OPTR &L, int x)
{
	OPTR T, TEMP=L;
	if(L == NULL)
	{
		T=new(outnode);
		T->n=x;
		T->C=NULL;
		T->next=NULL;
		L=T;
	}
	else
	{
		while(TEMP->next != NULL)
			TEMP=TEMP->next;
		T=new(outnode);
		T->C=NULL;
		T->n=x;
		T->next = NULL;
		TEMP->next=T;
	}
}

void course(OPTR &C)
{
	int n;
	cout<<"\nEnter course number : ";
	cin>>n;
	insert_end(C,n);
}

void create_innodes(OPTR &A, OPTR &B)
{
	IPTR T;
	T=new(innode);
	if(A->C==NULL)
	{
		T->tag1=1;
		T->tag2=1;
		T->p1.ST=A;
		T->p2.ST=B;
		A->C=T;
		B->C=T;
	}
	else
	{
		IPTR T1=A->C;
		IPTR T2=B->C;
		while(T1->tag1!=1)
			T1=T1->p1.D;
		if(T2!=NULL)
		{
			while(T2->tag2!=1)
				T2=T2->p2.D;
		}
		else
			T2=T;
		T->tag1=1;
		T->tag2=1;
		T1->tag1=0;
		T1->tag2=0;
		T1->p1.ST=NULL;
		T1->p2.ST=NULL;
		T1->p1.D=T;
		T->p1.ST=A;
		T->p2.ST=B;
	}
}

void create_outnodes(OPTR &S, OPTR &C)
{
	OPTR TEMP;
	int n;
	cout<<"\nEnter student number : ";
	cin>>n;
	insert_end(S,n);
	cout<<"\nEnter number of courses : ";
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cout<<"\nEnter course number : ";
		int n;
		cin>>n;
		TEMP=find(C,n);
		create_innodes(S,TEMP);
	}
}

void s_print(OPTR L, OPTR M, int n)
{
	IPTR T1=L->C, T2=M->C;
	if(n==1)
	{
		cout<<"\nCourses taken are : ";
		while(T1!=NULL)
		{
			T2=M->C;
			while(T2!=NULL)
				T2=T2->p2.D;
			cout<<"C"<<T2->p2.ST->n<<" ";
			T1=T1->p1.D;
		}
		if(T1->tag1==1)
			cout<<"C"<<T2->p2.ST->n<<" ";	
	}
	else
	{
		cout<<"\nStudents enrolled in this course are : ";
		while(T1->tag1!=1)
		{
			T2=L->C;
			while(T2->p1.D!=NULL)
				T2=T2->p1.D;
			cout<<"S"<<T2->p1.ST->n<<" ";
			T1=T1->p2.D;
		}
	}
}

void print(OPTR A, OPTR B, int n)
{
	OPTR TEMP;
	int t=0,a;
	if(n==1)
	{
		while(t!=-1)
		{
			cout<<"\nEnter number of student : ";
			cin>>a;
			cout<<endl;
			TEMP=find(A,a);
			s_print(TEMP,B,n);
			cout<<"\nContinue? : ";
			cin>>t;
		}
	}
	else
	{
		while(t!=-1)
		{
			cout<<"\nEnter name of course : ";
			cin>>a;
			cout<<endl;
			TEMP=find(B,a);
			s_print(TEMP,A,n);
			cout<<"\nContinue? : ";
			cin>>t;
		}
	}
}

int main()
{
	
	return 0;
}
