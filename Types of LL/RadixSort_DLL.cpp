//RADIX SORT using DOUBLY LINKED LIST wihout radix

#include<iostream>
using namespace std;

typedef struct node* LPTR;

struct Bucket
{
	struct node *BKT;
	struct Bucket *R;
	struct Bucket *L;
};
struct node
{
	int data;
	struct node *next;
};

typedef struct Bucket* BPTR;

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

BPTR find(BPTR B, int x)
{
	while(x>0)
	{
		B=B->R;
		--x;
	}
	return B;
}

int pop(BPTR &B)
{
	LPTR TEMP=B->BKT;
	if(TEMP==NULL)
		return -1;
	else
	{
		int x=TEMP->data;
		B->BKT=B->BKT->next;
		delete(TEMP);
		return x;
	}
}

void push(BPTR &B, int n)
{
	LPTR TEMP, A=B->BKT;
	TEMP=new(node);
	TEMP->data = n;
	if(B->BKT == NULL)
	{
		TEMP->next=NULL;
		B->BKT=TEMP;
	}
	else
	{
		while(A->next!=NULL)
			A=A->next;
		TEMP->next=NULL;
		A->next=TEMP;
	}
}

void c_bckt(BPTR &B)
{
	BPTR T, TEMP=B;
	T=new(Bucket);
	T->BKT=NULL;
	if(B==NULL)
	{
		T->R=NULL;
		T->L=NULL;
		B=T;
	}
	else
	{
		while(TEMP->R!=NULL)
			TEMP=TEMP->R;
		T->R=NULL;
		T->L=TEMP;
		TEMP->R=T;
	}	
}

void countSort(int a[], int n, int e)
{
	BPTR B=NULL, T;
	int m, j=0; 
	for(int i=0; i<10; i++) //initializes everything 
		c_bckt(B);
	for(int i=0; i<n; i++)
	{
		T=find(B,(a[i]/e)%10);
		push(T,a[i]); 
	}
	j=0;
	for(BPTR I=B; I!=NULL; I=I->R)
	{
		m=pop(I);
		while(m!=-1)
		{
			a[j++]=m;
			m=pop(I);
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
	cout<<"\nEnter number of elements : ";
	cin>>n;
	cout<<"\nEnter elements : ";
	for(int i=0; i<n; i++)
		cin>>a[i];
	radixSort(a,n);
	cout<<"\nSorted list is : ";
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	return 0;
}
