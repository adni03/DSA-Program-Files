//RADIX SORT

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct Queue
{
	struct node *F;
	struct node *R;
};

typedef struct node* QPTR;

int max(int a[], int n)
{
	int max=a[0];
	for(int i=0; i<n; i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

void L_enq(Queue &A, int x)
{
	QPTR T=NULL, TEMP=A.F;
	T=new(node);
	T->data=x;
	if(A.F == NULL)
	{
		A.F=T;
		A.R=T;
		T->next=NULL;
	}	
	else
	{
		while(TEMP!=A.R)
			TEMP=TEMP->next;
		T->next=NULL;
		TEMP->next=T;
		A.R=T;
	}
}

int L_deq(Queue &A)
{
	int t=0;
	QPTR TEMP;
	if(A.F == NULL)
		return -1;
	else
	{
		t=A.F->data;
		TEMP=A.F;
		A.F=A.F->next;
		delete(TEMP);
		return t;
	}
}

void countSort(int a[], int n, int e)
{
	Queue q[10];
	int m, j=0; 
	for(int i=0; i<10; i++) //initializes everything 
		q[i].F=q[i].R=NULL;
	for(int i=0; i<n; i++)
	{
		L_enq(q[(a[i]/e)%10],a[i]); 
	}
	for(int i=0; i<10; i++)
	{
		m=L_deq(q[i]);
		while(m!=-1)
		{
			a[j++]=m;
			m=L_deq(q[i]);
		}
	}
}

void radixSort(int a[], int n)
{
	int m=max(a,n);
	for(int exp=1; m/exp>0; exp*=10)
		countSort(a,n,exp);
}

int main()
{
	int a[100], n;
	cout<<"Enter number of elements : ";
	cin>>n;
	cout<<"Enter elements : ";
	for(int i=0; i<n; i++)
		cin>>a[i];
	radixSort(a,n);
	cout<<"\nSorted list is : ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}
